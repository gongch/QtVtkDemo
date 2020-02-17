QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RootPath=D:\Source\Github\QtVtkDemo\QtVtkDemo
INCLUDEPATH += include/itk\
            include/vtk\
            include/gdcm
CONFIG(debug, debug|release) {
LIBS += -L$${RootPath}\lib\vtk\
        -L$${RootPath}\lib\itk_debug\
        -L$${RootPath}\lib\gdcm_debug\
        -lvtkRenderingImage-8.90d\
        -lvtkFiltersModeling-8.90d\
        -lvtkImagingSources-8.90d\
        -lvtkInteractionStyle-8.90d\
        -lvtkRenderingOpenGL2-8.90d\
        -lvtkTestingRendering-8.90d\
        -lvtkglew-8.90d\
        -lvtkIOImage-8.90d\
        -lvtkImagingCore-8.90d\
        -lvtkRenderingCore-8.90d\
        -lvtkFiltersSources-8.90d\
        -lvtkFiltersGeneral-8.90d\
        -lvtkFiltersCore-8.90d\
        -lvtkCommonExecutionModel-8.90d\
        -lvtkCommonDataModel-8.90d\
        -lvtkCommonMisc-8.90d\
        -lvtkCommonTransforms-8.90d\
        -lvtkCommonMath-8.90d\
        -lvtkCommonCore-8.90d\
        -lvtksys-8.90d\
        -lvtkViewsQt-8.90d\
        -lvtkRenderingQt-8.90d\
        -lvtkGUISupportQt-8.90d\
        -lvtkInteractionWidgets-8.90d\
        -lvtkRenderingFreeType-8.90d\
        -lopengl32
}else {
LIBS += -L$${RootPath}\lib\vtk\
        -L$${RootPath}\lib\itk_release\
        -L$${RootPath}\lib\gdcm_release\
        -lvtkCommonCore-8.90\
        -lvtkIOImage-8.90\
        -lvtkRenderingImage-8.90\
        -lvtkFiltersModeling-8.90\
        -lvtkImagingSources-8.90\
        -lvtkInteractionStyle-8.90\
        -lvtkRenderingOpenGL2-8.90\
        -lvtkTestingRendering-8.90\
        -lvtkglew-8.90\
        -lvtkImagingCore-8.90\
        -lvtkRenderingCore-8.90\
        -lvtkFiltersSources-8.90\
        -lvtkFiltersGeneral-8.90\
        -lvtkFiltersCore-8.90\
        -lvtkCommonExecutionModel-8.90\
        -lvtkCommonDataModel-8.90\
        -lvtkCommonMisc-8.90\
        -lvtkCommonTransforms-8.90\
        -lvtkCommonMath-8.90\
        -lvtksys-8.90\
        -lvtkViewsQt-8.90\
        -lvtkRenderingQt-8.90\
        -lvtkGUISupportQt-8.90\
        -lvtkInteractionWidgets-8.90\
        -lvtkRenderingFreeType-8.90\
        -lopengl32
}

LIBS +=-litkgdcmCommon-5.1\
    -lvtkgdcm\
    -litkgdcmDSED-5.1\
    -litkzlib-5.1\
    -lITKCommon-5.1\
    -litkgdcmMSFF-5.1\
    -litksys-5.1\
    -litkgdcmIOD-5.1\
    -litkIOGDCM-5.1\
    -litkgdcmDICT-5.1\
    -litkgdcmcharls-5.1\
    -litkopenjpeg-5.1\
    -litkjpeg-5.1\
    -lITKIOJPEG-5.1\
    -litkgdcmjpeg8-5.1\
    -litkgdcmjpeg12-5.1\
    -litkgdcmjpeg16-5.1\
    -litkgdcmopenjp2-5.1\
    -lITKEXPAT-5.1\
    -lAdvapi32\
    -lws2_32


CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    QtVtkDemo_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
