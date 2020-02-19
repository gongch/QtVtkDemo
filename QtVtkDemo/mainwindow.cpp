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
#include "vtkTransform.h"
#include "gdcmDICOMDIR.h"
#include "vtkImageShrink3D.h"
#include <itkGDCMSeriesFileNames.h>
#include "vtkDecimatePro.h"
#include "vtkSmoothPolyDataFilter.h"
#include "vtkPolyDataNormals.h"
#include "vtkImageViewer2.h"


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
                double* normals= ps->GetNormal();
                double* normals2 = rc->GetPlane(i)->GetNormal();

                if(fabs(normals[0]-normals2[0])+ fabs(normals[1] - normals2[1])+ fabs(normals[2] - normals2[2])>0.01)
                {
                    ps->SetNormal(rc->GetPlane(i)->GetNormal());
                    needToUpdate = true;
                }
                double* centers = ps->GetCenter();
                double* centers2 = rc->GetPlane(i)->GetOrigin();
                if (fabs(centers[0] - centers2[0]) + fabs(centers[1] - centers2[1]) + fabs(centers[2] - centers2[2]) > 0.01)
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

    vtkSmartPointer<vtkImageShrink3D> shrink = vtkImageShrink3D::New();//抽取样点，显示数量减少速达加快

    shrink->SetShrinkFactors(4, 4, 1);

    shrink->AveragingOn();
    shrink->SetInputConnection(reader->GetOutputPort());

    outlineMapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    outlineMapper->SetInputConnection(shrink->GetOutputPort());

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
        imageViewer2[i] = vtkSmartPointer< vtkImageViewer2>::New();
        imageViewer2[i]->SetInputConnection(reader->GetOutputPort());
        imageViewer2[i]->SetRenderWindow(renWin);
        imageViewer2[i]->SetRenderer(ren[i]);
        imageViewer2[i]->SetColorLevel(500);
        imageViewer2[i]->SetColorWindow(2000);
        int min;
        int max;
        switch (i)
        {
        case 0:
            imageViewer2[i]->SetSliceOrientationToYZ();
            min = imageViewer2[i]->GetSliceMin();
            max = imageViewer2[i]->GetSliceMax();
            centerX = (max + min) / 2;
            ui->hsOffsetX->setMinimum(min - centerX);
            ui->hsOffsetX->setMaximum(max - centerX);
            ui->hsOffsetX->setValue(0);
            break;
        case 1:
            imageViewer2[i]->SetSliceOrientationToXZ();
            min = imageViewer2[i]->GetSliceMin();
            max = imageViewer2[i]->GetSliceMax();
            centerY = (max + min) / 2;
            ui->hsOffsetY->setMinimum(min - centerY);
            ui->hsOffsetY->setMaximum(max - centerY);
            ui->hsOffsetY->setValue((max + min) / 2 - centerY);
            break;
        case 2:
            imageViewer2[i]->SetSliceOrientationToXY();
            min = imageViewer2[i]->GetSliceMin();
            max = imageViewer2[i]->GetSliceMax();
            centerZ = (max + min) / 2;
            ui->hsOffsetZ->setMinimum(min - centerZ);
            ui->hsOffsetZ->setMaximum(max - centerZ);
            ui->hsOffsetZ->setValue((max + min) / 2 - centerZ);
            break;
        }
        imageViewer2[i]->Render();
        imageViewer2[i]->GetRenderer()->SetBackground(1, 1, 1);
        imageViewer2[i]->GetRenderWindow()->SetWindowName("ImageViewer2D");


    }

    skinExtractor = vtkSmartPointer<vtkMarchingCubes>::New();

    //建立一个Marching Cubes 算法的对象，从CT切片数据中提取出皮肤

    skinExtractor->SetValue(0, 500); //提取出CT 值为300

    skinExtractor->SetInputConnection(shrink->GetOutputPort());

    vtkDecimatePro* deci = vtkDecimatePro::New(); //减少数据读取点，以牺牲数据量加速交互
    deci->SetTargetReduction(0.3);
    deci->SetInputConnection(skinExtractor->GetOutputPort());
    vtkSmoothPolyDataFilter* smooth =  vtkSmoothPolyDataFilter::New();  //使图像更加光滑
    smooth->SetInputConnection(deci->GetOutputPort());
    smooth->SetNumberOfIterations(200);
    vtkPolyDataNormals* skinNormals = vtkPolyDataNormals::New();  //求法线
    skinNormals->SetInputConnection(smooth->GetOutputPort());
    skinNormals->SetFeatureAngle(60.0);
    skinStripper = vtkSmartPointer<vtkStripper>::New();
    skinStripper->SetInputConnection(skinNormals->GetOutputPort());
    skinMapper = vtkSmartPointer< vtkPolyDataMapper>::New();
    skinMapper->SetInputConnection(skinStripper->GetOutputPort());
    skinMapper->ScalarVisibilityOff();

    skin = vtkSmartPointer< vtkActor>::New();
    skin->SetMapper(skinMapper);
    skin->GetProperty()->SetDiffuseColor(255 / 256.0, 125 / 256.0, 64 / 256.0);
    skin->GetProperty()->SetSpecular(.3);
    skin->GetProperty()->SetSpecularPower(20);
    skin->GetProperty()->SetOpacity(.3);



     boneExtractor = vtkSmartPointer< vtkMarchingCubes>::New();
    boneExtractor->SetInputConnection(shrink->GetOutputPort());
    boneExtractor->SetValue(0, 1150);

    vtkDecimatePro* boneDeci = vtkDecimatePro::New(); //减少数据读取点，以牺牲数据量加速交互
    boneDeci->SetTargetReduction(0.3);
    boneDeci->SetInputConnection(boneExtractor->GetOutputPort());
    vtkSmoothPolyDataFilter* boneSmooth = vtkSmoothPolyDataFilter::New();  //使图像更加光滑
    boneSmooth->SetInputConnection(boneDeci->GetOutputPort());
    boneSmooth->SetNumberOfIterations(200);
    vtkPolyDataNormals* boneNormals = vtkPolyDataNormals::New();  //求法线
    boneNormals->SetInputConnection(boneSmooth->GetOutputPort());
    boneNormals->SetFeatureAngle(60.0);

     boneStripper = vtkSmartPointer< vtkStripper>::New();
    boneStripper->SetInputConnection(boneExtractor->GetOutputPort());

     boneMapper = vtkSmartPointer< vtkPolyDataMapper>::New();
    boneMapper->SetInputConnection(boneStripper->GetOutputPort());
    boneMapper->ScalarVisibilityOff();

    bone = vtkSmartPointer< vtkActor>::New();
    bone->SetMapper(boneMapper);
    bone->GetProperty()->SetDiffuseColor(255 / 256.0, 255 / 256.0, 240 / 256.0);
    bone->GetProperty()->SetOpacity(.5);

    

    aCamera = vtkSmartPointer<vtkCamera>::New();
    aCamera->SetViewUp(0, 0, -2);
    aCamera->SetPosition(0, -2, 0);
    aCamera->SetFocalPoint(0, 0, 0);
    aCamera->ComputeViewPlaneNormal();
    aCamera->Azimuth(30.0);
    aCamera->Elevation(30.0);



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
    int i = 1;
    
    double selPt[3] = { 0,value , 0 }; // 平移的目标位置
    double center[3];

    imageViewer2[0]->SetSlice(value+centerX);



}

void MainWindow::on_hsOffsetY_valueChanged(int value)
{
    this->offsetY = value;
    ui->lOffsetY->setText(tr("%1").arg(value));
    imageViewer2[1]->SetSlice(value + centerY);
}

void MainWindow::on_hsOffsetZ_valueChanged(int value)
{
    this->offsetZ = value;
    ui->lOffsetZ->setText(tr("%1").arg(value));
    imageViewer2[2]->SetSlice(value + centerZ);
}

void MainWindow::on_hsRotateX_valueChanged(int value)
{
    this->rotateX = value;
    ui->lRotateX->setText(tr("%1").arg(value));
    double * position = skin->GetPosition();
    double* origin = skin->GetOrigin();
    vtkTransform* myTrans = vtkTransform::New();
    myTrans->Translate(position[0], position[1], position[2]);
    myTrans->Translate(origin[0], origin[1], origin[2]);
    myTrans->RotateX(value);
    myTrans->Translate(-origin[0], -origin[1], -origin[2]);

    skin->SetUserTransform(myTrans);
    bone->SetUserTransform(myTrans);
    ren[3]->ResetCamera();
    //skin->RotateWXYZ(value, 1, 0, 0);
    //bone->RotateWXYZ(value, 1, 0, 0);
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
    skin->GetProperty()->SetOpacity(value/100.0);
    ren[3]->ResetCamera();
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
