#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vtkSmartPointer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QVTKOpenGLNativeWidget;
class vtkGDCMImageReader;
class vtkPolyDataMapper;
class vtkActor;
class vtkCellPicker;
class vtkProperty;
class vtkProperty;
class vtkImagePlaneWidget;
class vtkGenericOpenGLRenderWindow;
class vtkRenderer;
class vtkInteractorStyle;
class vtkResliceCursorCallback;
class vtkResliceCursor;
class vtkResliceCursorWidget;
class vtkResliceCursorLineRepresentation;
class vtkMarchingCubes;
class vtkStripper;
class vtkRenderWindowInteractor;
class vtkOutlineFilter;
class vtkCamera;
class vtkVectorText;
class vtkElevationFilter;
class vtkImageViewer2;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bExit_clicked();

    void on_hsOffsetX_valueChanged(int value);

    void on_hsOffsetY_valueChanged(int value);

    void on_hsOffsetZ_valueChanged(int value);

    void on_hsRotateX_valueChanged(int value);

    void on_hsRotateY_valueChanged(int value);

    void on_hsRotateZ_valueChanged(int value);

    void on_hsSkin_valueChanged(int value);

    void on_hsMusle_valueChanged(int value);

    void on_hsSkull_valueChanged(int value);

    void on_hsBrain_valueChanged(int value);

    void on_hsElectrode_valueChanged(int value);

private:
    void LoadDicom(QString file);

private:
    Ui::MainWindow *ui;
    int offsetX;
    int offsetY;
    int offsetZ;
    int centerX;
    int centerY;
    int centerZ;
    int rotateX;
    int rotateY;
    int rotateZ;
    int opacitySkin;
    int opacityMusle;
    int opacitySkull;
    int opacityBrain;
    int opacityElectrode;

    QVTKOpenGLNativeWidget* vtkWidget;
    vtkSmartPointer< vtkGDCMImageReader > reader;
    vtkSmartPointer<vtkPolyDataMapper> outlineMapper;
    vtkSmartPointer<vtkActor> outlineActor;
    vtkSmartPointer<vtkCellPicker> picker;
    vtkSmartPointer<vtkProperty> ipwProp;
    vtkSmartPointer<vtkImagePlaneWidget> planeWidget[3];
    vtkSmartPointer<vtkImageViewer2> imageViewer2[3];
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> renWin;
    // VTK Renderer
    vtkSmartPointer<vtkRenderer> ren[4];

    vtkSmartPointer< vtkRenderWindowInteractor> iren;
    vtkSmartPointer < vtkInteractorStyle> style;
    vtkSmartPointer<vtkResliceCursorCallback> cbk;
    vtkSmartPointer< vtkResliceCursor > resliceCursor;

    vtkSmartPointer< vtkResliceCursorWidget > resliceCursorWidget[3];
    vtkSmartPointer< vtkResliceCursorLineRepresentation > resliceCursorRep[3];
    vtkSmartPointer< vtkMarchingCubes> skinExtractor;
    vtkSmartPointer<vtkStripper> skinStripper;
    vtkSmartPointer< vtkPolyDataMapper> skinMapper;
    vtkSmartPointer< vtkActor> skin;
    vtkSmartPointer< vtkMarchingCubes> boneExtractor;
    vtkSmartPointer< vtkStripper> boneStripper;
    vtkSmartPointer< vtkPolyDataMapper> boneMapper;
    vtkSmartPointer< vtkActor> bone;
    vtkSmartPointer< vtkOutlineFilter> outlineData;
    vtkSmartPointer< vtkPolyDataMapper> mapOutline;
    vtkSmartPointer< vtkActor> outline;
    vtkSmartPointer< vtkCamera> aCamera;
    // Actor in scene
    vtkNew<vtkActor> actor;


};
#endif // MAINWINDOW_H
