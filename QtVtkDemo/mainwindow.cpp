#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QVTKOpenGLNativeWidget.h"
#include "QVTKWidget.h"
#include "vtkGenericOpenGLRenderWindow.h"

#include <vtkAutoInit.h>


#include "vtkRegressionTestImage.h"
#include "vtkTestUtilities.h"

#include <vtkVectorText.h>
#include "vtkElevationFilter.h"
#include "vtkCamera.h"
#include "vtkDICOMImageReader.h"
#include "vtkImageData.h"
#include "vtkImageProperty.h"
#include "vtkImageReader2.h"
#include "vtkImageSliceMapper.h"
#include "vtkImageSlice.h"
#include "vtkInteractorStyleImage.h"
#include "vtkRenderWindow.h"
#include "vtkRenderWindowInteractor.h"
#include "vtkRenderer.h"
#include <Windows.h>
#include "vtkAutoInit.h"
#include "vtkPolyDataMapper.h"
#include "vtkCellPicker.h"
#include "vtkImagePlaneWidget.h"
#include "vtkResliceCursorWidget.h"
#include "vtkResliceCursorLineRepresentation.h"
#include "vtkResliceCursorActor.h"
#include "vtkResliceCursorPolyDataAlgorithm.h"
#include "vtkResliceCursor.h"
#include "vtkProperty.h"
#include "vtkPlane.h"
#include "vtkPlaneSource.h"
#include "vtkImageReslice.h"
#include "vtkImageMapToColors.h"
#include "vtkGDCMImageReader.h"
#include "vtkStringArray.h"
#include "gdcmDirectory.h"
#include "gdcmReader.h"
#include "gdcmMediaStorage.h"
#include "vtkMarchingCubes.h"
#include "vtkStripper.h"
#include "vtkOutlineFilter.h"

#include "gdcmDICOMDIR.h"

#include <itkGDCMSeriesFileNames.h>

VTK_MODULE_INIT(vtkRenderingOpenGL2)
VTK_MODULE_INIT(vtkInteractionStyle)

#ifdef vtkRenderingCore_AUTOINIT_INCLUDE
#include vtkRenderingCore_AUTOINIT_INCLUDE
#endif
#ifdef vtkRenderingCore_AUTOINIT
#include "vtkAutoInit.h"
VTK_MODULE_AUTOINIT(vtkRenderingCore)
#endif

using NamesGeneratorType = itk::GDCMSeriesFileNames;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   /* QVTKOpenGLWidget *vtkWidget = new QVTKOpenGLWidget();
    vtkWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->vlVtk->addWidget(vtkWidget);

    vtkNew<vtkVectorText> text;
    text->SetText("VTK and Qt!");
    vtkNew<vtkElevationFilter> elevation;
    elevation->SetInputConnection(text->GetOutputPort());
    elevation->SetLowPoint(0, 0, 0);
    elevation->SetHighPoint(10, 0, 0);

    // Mapper
    vtkNew<vtkPolyDataMapper> mapper;
    mapper->SetInputConnection(elevation->GetOutputPort());

    // Actor in scene
    vtkNew<vtkActor> actor;
    actor->SetMapper(mapper);

    // VTK Renderer
    vtkNew<vtkRenderer> ren;

    // Add Actor to renderer
    ren->AddActor(actor);

    // VTK/Qt wedded
    vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
    vtkWidget->setRenderWindow(renderWindow);
    vtkWidget->renderWindow()->AddRenderer(ren);
*/
    LoadDicom("D:\\PDImage\\FZS\\FZS CTAfter\\A\\A\\A\\A");
}


class vtkResliceCursorCallback : public vtkCommand
{
public:
    static vtkResliceCursorCallback* New()
    {
        return new vtkResliceCursorCallback;
    }
    void Execute(vtkObject* caller, unsigned long, void* callData) override
    {
        vtkImagePlaneWidget* ipw = dynamic_cast<vtkImagePlaneWidget*>(caller);
        if (ipw)
        {
            double* wl = static_cast<double*>(callData);

            if (ipw == this->IPW[0])
            {
                this->IPW[1]->SetWindowLevel(wl[0], wl[1], 1);
                this->IPW[2]->SetWindowLevel(wl[0], wl[1], 1);
            }
            else if (ipw == this->IPW[1])
            {
                this->IPW[0]->SetWindowLevel(wl[0], wl[1], 1);
                this->IPW[2]->SetWindowLevel(wl[0], wl[1], 1);
            }
            else if (ipw == this->IPW[2])
            {
                this->IPW[0]->SetWindowLevel(wl[0], wl[1], 1);
                this->IPW[1]->SetWindowLevel(wl[0], wl[1], 1);
            }
        }
        vtkResliceCursorWidget* rcw = dynamic_cast<vtkResliceCursorWidget*>(caller);
        if (rcw)
        {
            vtkResliceCursorLineRepresentation* rep = dynamic_cast<vtkResliceCursorLineRepresentation*>(rcw->GetRepresentation());
            vtkResliceCursor* rc = rep->GetResliceCursorActor()->GetCursorAlgorithm()->GetResliceCursor();
            for (int i = 0; i < 3; i++)
            {
                vtkPlaneSource* ps = static_cast<vtkPlaneSource*>(this->IPW[i]->GetPolyDataAlgorithm());
                bool needToUpdate = false;
                if (fabs(ps->GetNormal() -rc->GetPlane(i)->GetNormal())>0.01)
                {
                    ps->SetNormal(rc->GetPlane(i)->GetNormal());
                    needToUpdate = true;
                }
                if (fabs(ps->GetCenter() - rc->GetPlane(i)->GetOrigin())>0.01)
                {
                    ps->SetCenter(rc->GetPlane(i)->GetOrigin());
                    needToUpdate = true;
                }
                if (needToUpdate)
                {
                    this->IPW[i]->UpdatePlacement();
                }
            }
        }
        this->RCW[0]->Render();
    }
    vtkResliceCursorCallback() {}
    vtkImagePlaneWidget* IPW[3];
    vtkResliceCursorWidget* RCW[3];
};

void MainWindow::LoadDicom(QString file)
{

    vtkWidget = new QVTKOpenGLNativeWidget();
    vtkWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->vlVtk->addWidget(vtkWidget);
    renWin = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    vtkWidget->setRenderWindow(renWin);
    style = vtkInteractorStyleImage::New();
    vtkWidget->interactor()->SetInteractorStyle(style);

    NamesGeneratorType::Pointer nameGenerator = NamesGeneratorType::New();
    vtkSmartPointer< vtkStringArray > fileArray = vtkSmartPointer< vtkStringArray >::New();

    char sFileName[] = "D:\\PDImage\\FZS\\FZS CTAfter\\A\\A\\A\\A";
    for (int i = 0; i < 11; i++)
    {

        nameGenerator->SetInputDirectory(sFileName);
        nameGenerator->Update();
        sFileName[strlen(sFileName) - 1]++;
        using FileNamesContainer = std::vector<std::string>;
        FileNamesContainer fileNames = nameGenerator->GetInputFileNames();
        for (int j = fileNames.size() -1; j >0; j--)
        {
            fileArray->InsertNextValue(fileNames[j].c_str());

        }
    }
    reader = vtkSmartPointer<vtkGDCMImageReader>::New();
    reader->SetDataByteOrderToLittleEndian();
    reader->SetDataExtent(0, 63, 0, 63, 1, 93);
    reader->SetDataSpacing(3.2, 3.2, 1.5);
    // a nice random-ish origin for testing
    reader->SetDataOrigin(2.5, -13.6, 2.8);

    // reader->SetFilePrefix(fname);
    reader->SetFileNames(fileArray);
    reader->Update();


    outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    outlineMapper->SetInputConnection(reader->GetOutputPort());

    outlineActor = vtkSmartPointer<vtkActor>::New();
    outlineActor->SetMapper(outlineMapper);
    picker = vtkSmartPointer<vtkCellPicker>::New();
    picker->SetTolerance(0.005);

    ipwProp = vtkSmartPointer<vtkProperty>::New();

    int imageDims[3];
    reader->GetOutput()->GetDimensions(imageDims);

    renWin->SetMultiSamples(0);




    for (int i = 0; i < 4; i++)
    {
        ren[i] = vtkSmartPointer<vtkRenderer>::New();
        renWin->AddRenderer(ren[i]);
    }


    //iren = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    //iren->SetRenderWindow(renWin);
    
    //iren->SetRenderWindow(renWin);
    //iren->SetInteractorStyle(style);
    //->SetInteractorStyle(style);


    for (int i = 0; i < 3; i++)
        {
            planeWidget[i] = vtkSmartPointer<vtkImagePlaneWidget>::New();
            planeWidget[i]->SetInteractor(vtkWidget->interactor());
            planeWidget[i]->SetPicker(picker);
            planeWidget[i]->RestrictPlaneToVolumeOn();
            double color[3] = { 0, 0, 0 };
            color[i] = 1;
            planeWidget[i]->GetPlaneProperty()->SetColor(color);
            planeWidget[i]->SetTexturePlaneProperty(ipwProp);
            planeWidget[i]->TextureInterpolateOff();
            planeWidget[i]->SetResliceInterpolateToLinear();
            planeWidget[i]->SetInputConnection(reader->GetOutputPort());
            planeWidget[i]->SetPlaneOrientation(i);
            planeWidget[i]->SetSliceIndex(imageDims[i] / 2);
            planeWidget[i]->DisplayTextOn();
            planeWidget[i]->SetDefaultRenderer(ren[3]);
            planeWidget[i]->SetWindowLevel(1358, -27);
            planeWidget[i]->On();
            planeWidget[i]->InteractionOn();
        }

        planeWidget[1]->SetLookupTable(planeWidget[0]->GetLookupTable());
        planeWidget[2]->SetLookupTable(planeWidget[0]->GetLookupTable());



    cbk = vtkSmartPointer<vtkResliceCursorCallback>::New();
    resliceCursor = vtkSmartPointer< vtkResliceCursor >::New();
    resliceCursor->SetCenter(reader->GetOutput()->GetCenter());
    resliceCursor->SetThickMode(0);
    resliceCursor->SetThickness(10, 10, 10);
    resliceCursor->SetImage(reader->GetOutput());



    double viewUp[3][3] = { { 0, 0, -1 }, { 0, 0, 1 }, { 0, 1, 0 } };
    for (int i = 0; i < 3; i++)
    {
        resliceCursorWidget[i] = vtkSmartPointer< vtkResliceCursorWidget >::New();
        resliceCursorWidget[i]->SetInteractor(vtkWidget->interactor());

        resliceCursorRep[i] = vtkSmartPointer< vtkResliceCursorLineRepresentation >::New();
        resliceCursorWidget[i]->SetRepresentation(resliceCursorRep[i]);
        resliceCursorRep[i]->GetResliceCursorActor()->GetCursorAlgorithm()->SetResliceCursor(resliceCursor);
        resliceCursorRep[i]->GetResliceCursorActor()->GetCursorAlgorithm()->SetReslicePlaneNormal(i);

        const double minVal = reader->GetOutput()->GetScalarRange()[0];
        if (vtkImageReslice* reslice = vtkImageReslice::SafeDownCast(resliceCursorRep[i]->GetReslice()))
        {
            reslice->SetBackgroundColor(minVal, minVal, minVal, minVal);
        }

        resliceCursorWidget[i]->SetDefaultRenderer(ren[i]);
        resliceCursorWidget[i]->SetEnabled(1);

        ren[i]->GetActiveCamera()->SetFocalPoint(0, 0, 0);
        double camPos[3] = { 0, 0, 0 };
        camPos[i] = 1;
        ren[i]->GetActiveCamera()->SetPosition(camPos);
        ren[i]->GetActiveCamera()->ParallelProjectionOn();
        ren[i]->GetActiveCamera()->SetViewUp(viewUp[i][0], viewUp[i][1], viewUp[i][2]);
        ren[i]->ResetCamera();
        cbk->IPW[i] = planeWidget[i];
        cbk->RCW[i] = resliceCursorWidget[i];
        resliceCursorWidget[i]->AddObserver(vtkResliceCursorWidget::ResliceAxesChangedEvent, cbk);
        double range[2];
        reader->GetOutput()->GetScalarRange(range);
        resliceCursorRep[i]->SetWindowLevel(range[1] - range[0], (range[0] + range[1]) / 2.0);
        planeWidget[i]->SetWindowLevel(range[1] - range[0], (range[0] + range[1]) / 2.0);
        resliceCursorRep[i]->SetLookupTable(resliceCursorRep[0]->GetLookupTable());
        planeWidget[i]->GetColorMap()->SetLookupTable(resliceCursorRep[0]->GetLookupTable());
    }


    skinExtractor = vtkSmartPointer<vtkMarchingCubes>::New();
    skinExtractor->SetInputConnection(reader->GetOutputPort());
    skinExtractor->SetValue(0, 500);

    skinStripper = vtkSmartPointer<vtkStripper>::New();
    skinStripper->SetInputConnection(skinExtractor->GetOutputPort());

    skinMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    skinMapper->SetInputConnection(skinStripper->GetOutputPort());
    skinMapper->ScalarVisibilityOff();

    skin = vtkSmartPointer< vtkActor>::New();
    skin->SetMapper(skinMapper);
    skin->GetProperty()->SetDiffuseColor(255 / 256.0, 125 / 256.0, 64 / 256.0);
    skin->GetProperty()->SetSpecular(.3);
    skin->GetProperty()->SetSpecularPower(20);
    skin->GetProperty()->SetOpacity(.3);



     boneExtractor = vtkSmartPointer< vtkMarchingCubes>::New();
    boneExtractor->SetInputConnection(reader->GetOutputPort());
    boneExtractor->SetValue(0, 1150);

     boneStripper = vtkSmartPointer< vtkStripper>::New();
    boneStripper->SetInputConnection(boneExtractor->GetOutputPort());

     boneMapper = vtkSmartPointer< vtkPolyDataMapper>::New();
    boneMapper->SetInputConnection(boneStripper->GetOutputPort());
    boneMapper->ScalarVisibilityOff();

    bone = vtkSmartPointer< vtkActor>::New();
    bone->SetMapper(boneMapper);
    bone->GetProperty()->SetDiffuseColor(255 / 256.0, 255 / 256.0, 240 / 256.0);
    bone->GetProperty()->SetOpacity(.5);



    outlineData = vtkSmartPointer< vtkOutlineFilter>::New();
    outlineData->SetInputConnection(reader->GetOutputPort());

    mapOutline = vtkSmartPointer< vtkPolyDataMapper>::New();
    mapOutline->SetInputConnection(outlineData->GetOutputPort());

     outline = vtkSmartPointer< vtkActor>::New();
    outline->SetMapper(mapOutline);
    outline->GetProperty()->SetColor(0, 0, 0);

     aCamera = vtkSmartPointer<vtkCamera>::New();
    aCamera->SetViewUp(0, 0, -2);
    aCamera->SetPosition(0, -2, 0);
    aCamera->SetFocalPoint(0, 0, 0);
    aCamera->ComputeViewPlaneNormal();
    aCamera->Azimuth(30.0);
    aCamera->Elevation(30.0);


    text->SetText("VTK and Qt!");
    elevation->SetInputConnection(text->GetOutputPort());
    elevation->SetLowPoint(0, 0, 0);
    elevation->SetHighPoint(10, 0, 0);

    mapper->SetInputConnection(elevation->GetOutputPort());

    actor->SetMapper(mapper);




    ren[0]->SetBackground(0.3, 0.1, 0.1);
    ren[1]->SetBackground(0.1, 0.3, 0.1);
    ren[2]->SetBackground(0.1, 0.1, 0.3);
    ren[3]->SetBackground(0.1, 0.1, 0.1);

    // Add Actor to renderer
    ren[3]->AddActor(outline);
    ren[3]->AddActor(skin);
    ren[3]->AddActor(bone);

    ren[0]->SetViewport(0, 0, 0.5, 0.5);
    ren[1]->SetViewport(0.5, 0, 1, 0.5);
    ren[2]->SetViewport(0, 0.5, 0.5, 1);
    ren[3]->SetViewport(0.5, 0.5, 1, 1);

    ren[3]->ResetCamera();
    vtkWidget->setEnabled(true);
    // VTK/Qt wedded
    //if (!iren->GetInitialized())
    {
        //iren->Initialize();
        //iren->Enable();

    }

    //reader->GetOutput()->GetDimensions(imageDims);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bExit_clicked()
{

    //this->close();
}

void MainWindow::on_hsOffsetX_valueChanged(int value)
{
    this->offsetX = value;
    ui->lOffsetX->setText(tr("%1").arg(value));
}

void MainWindow::on_hsOffsetY_valueChanged(int value)
{
    this->offsetY = value;
    ui->lOffsetY->setText(tr("%1").arg(value));
}

void MainWindow::on_hsOffsetZ_valueChanged(int value)
{
    this->offsetZ = value;
    ui->lOffsetZ->setText(tr("%1").arg(value));
}

void MainWindow::on_hsRotateX_valueChanged(int value)
{
    this->rotateX = value;
    ui->lRotateX->setText(tr("%1").arg(value));
}

void MainWindow::on_hsRotateY_valueChanged(int value)
{
    this->rotateY = value;
    ui->lRotateY->setText(tr("%1").arg(value));
}

void MainWindow::on_hsRotateZ_valueChanged(int value)
{
    this->rotateZ = value;
    ui->lRotateZ->setText(tr("%1").arg(value));
}

void MainWindow::on_hsSkin_valueChanged(int value)
{
    this->opacitySkin = value;
    ui->lSkin->setText(tr("%1").arg(value));
}

void MainWindow::on_hsMusle_valueChanged(int value)
{
    this->opacityMusle = value;
    ui->lMusle->setText(tr("%1").arg(value));
}

void MainWindow::on_hsSkull_valueChanged(int value)
{
    this->opacitySkull = value;
    ui->lSkull->setText(tr("%1").arg(value));
}

void MainWindow::on_hsBrain_valueChanged(int value)
{
    this->opacityBrain = value;
    ui->lBrain->setText(tr("%1").arg(value));
}

void MainWindow::on_hsElectrode_valueChanged(int value)
{
    this->opacityElectrode = value;
    ui->lElectrode->setText(tr("%1").arg(value));
}
