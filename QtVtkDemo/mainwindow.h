#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
    int rotateX;
    int rotateY;
    int rotateZ;
    int opacitySkin;
    int opacityMusle;
    int opacitySkull;
    int opacityBrain;
    int opacityElectrode;
};
#endif // MAINWINDOW_H
