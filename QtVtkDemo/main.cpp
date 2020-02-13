#include <QtGui/QSurfaceFormat>
#include "mainwindow.h"
#include <QApplication>

#include "QVTKOpenGLWidget.h"
int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLWidget::defaultFormat());
    QApplication a(argc, argv);
     QVTKOpenGLWidget widget;
    QApplication::setStyle("fusion");
    MainWindow w;
    w.show();
    return a.exec();
}
