/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *glOffset;
    QSlider *hsOffsetY;
    QLabel *lnRotateZ;
    QLabel *lOffsetY;
    QLabel *lRotateZ;
    QSlider *hsRotateY;
    QLabel *lnRotateY;
    QSlider *hsOffsetX;
    QLabel *lnOffsetZ;
    QLabel *lnRotateX;
    QSlider *hsOffsetZ;
    QLabel *lRotateX;
    QSlider *hsRotateX;
    QLabel *lnOffset;
    QSlider *hsRotateZ;
    QLabel *lOffsetZ;
    QLabel *lOffsetX;
    QLabel *lnOffsetY;
    QLabel *lnOffsetX;
    QLabel *lnRotate;
    QLabel *lRotateY;
    QFrame *line;
    QFrame *line_2;
    QGridLayout *glRotate;
    QLabel *lnOpaticy;
    QLabel *lnSkin;
    QSlider *hsSkin;
    QLabel *lSkin;
    QLabel *lnMusle;
    QSlider *hsMusle;
    QLabel *lMusle;
    QLabel *lnSkull;
    QSlider *hsSkull;
    QLabel *lSkull;
    QLabel *lnBrain;
    QSlider *hsBrain;
    QLabel *lBrain;
    QLabel *lnElectrode;
    QSlider *hsElectrode;
    QLabel *lElectrode;
    QLabel *label_26;
    QFrame *line_3;
    QVBoxLayout *vlVtk;
    QFrame *line_4;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label_27;
    QPushButton *bExit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(808, 638);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        glOffset = new QGridLayout();
        glOffset->setObjectName(QString::fromUtf8("glOffset"));
        glOffset->setSizeConstraint(QLayout::SetMinimumSize);
        hsOffsetY = new QSlider(centralwidget);
        hsOffsetY->setObjectName(QString::fromUtf8("hsOffsetY"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(hsOffsetY->sizePolicy().hasHeightForWidth());
        hsOffsetY->setSizePolicy(sizePolicy);
        hsOffsetY->setMaximumSize(QSize(16777215, 20));
        hsOffsetY->setMinimum(-100);
        hsOffsetY->setMaximum(100);
        hsOffsetY->setOrientation(Qt::Horizontal);

        glOffset->addWidget(hsOffsetY, 2, 1, 1, 1);

        lnRotateZ = new QLabel(centralwidget);
        lnRotateZ->setObjectName(QString::fromUtf8("lnRotateZ"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lnRotateZ->sizePolicy().hasHeightForWidth());
        lnRotateZ->setSizePolicy(sizePolicy1);
        lnRotateZ->setMinimumSize(QSize(30, 0));
        lnRotateZ->setMaximumSize(QSize(30, 20));
        lnRotateZ->setLayoutDirection(Qt::LeftToRight);
        lnRotateZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glOffset->addWidget(lnRotateZ, 8, 0, 1, 1);

        lOffsetY = new QLabel(centralwidget);
        lOffsetY->setObjectName(QString::fromUtf8("lOffsetY"));
        sizePolicy.setHeightForWidth(lOffsetY->sizePolicy().hasHeightForWidth());
        lOffsetY->setSizePolicy(sizePolicy);
        lOffsetY->setMinimumSize(QSize(40, 0));
        lOffsetY->setMaximumSize(QSize(16777215, 20));
        lOffsetY->setAlignment(Qt::AlignCenter);

        glOffset->addWidget(lOffsetY, 2, 2, 1, 1);

        lRotateZ = new QLabel(centralwidget);
        lRotateZ->setObjectName(QString::fromUtf8("lRotateZ"));
        sizePolicy.setHeightForWidth(lRotateZ->sizePolicy().hasHeightForWidth());
        lRotateZ->setSizePolicy(sizePolicy);
        lRotateZ->setMinimumSize(QSize(30, 0));
        lRotateZ->setMaximumSize(QSize(16777215, 20));
        lRotateZ->setAlignment(Qt::AlignCenter);

        glOffset->addWidget(lRotateZ, 8, 2, 1, 1);

        hsRotateY = new QSlider(centralwidget);
        hsRotateY->setObjectName(QString::fromUtf8("hsRotateY"));
        sizePolicy.setHeightForWidth(hsRotateY->sizePolicy().hasHeightForWidth());
        hsRotateY->setSizePolicy(sizePolicy);
        hsRotateY->setMaximumSize(QSize(16777215, 20));
        hsRotateY->setMinimum(-180);
        hsRotateY->setMaximum(180);
        hsRotateY->setOrientation(Qt::Horizontal);

        glOffset->addWidget(hsRotateY, 7, 1, 1, 1);

        lnRotateY = new QLabel(centralwidget);
        lnRotateY->setObjectName(QString::fromUtf8("lnRotateY"));
        sizePolicy.setHeightForWidth(lnRotateY->sizePolicy().hasHeightForWidth());
        lnRotateY->setSizePolicy(sizePolicy);
        lnRotateY->setMinimumSize(QSize(30, 0));
        lnRotateY->setMaximumSize(QSize(30, 20));
        lnRotateY->setLayoutDirection(Qt::LeftToRight);
        lnRotateY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glOffset->addWidget(lnRotateY, 7, 0, 1, 1);

        hsOffsetX = new QSlider(centralwidget);
        hsOffsetX->setObjectName(QString::fromUtf8("hsOffsetX"));
        sizePolicy.setHeightForWidth(hsOffsetX->sizePolicy().hasHeightForWidth());
        hsOffsetX->setSizePolicy(sizePolicy);
        hsOffsetX->setMaximumSize(QSize(16777215, 20));
        hsOffsetX->setMinimum(-100);
        hsOffsetX->setMaximum(100);
        hsOffsetX->setOrientation(Qt::Horizontal);

        glOffset->addWidget(hsOffsetX, 1, 1, 1, 1);

        lnOffsetZ = new QLabel(centralwidget);
        lnOffsetZ->setObjectName(QString::fromUtf8("lnOffsetZ"));
        sizePolicy.setHeightForWidth(lnOffsetZ->sizePolicy().hasHeightForWidth());
        lnOffsetZ->setSizePolicy(sizePolicy);
        lnOffsetZ->setMinimumSize(QSize(30, 0));
        lnOffsetZ->setMaximumSize(QSize(30, 20));
        lnOffsetZ->setLayoutDirection(Qt::LeftToRight);
        lnOffsetZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glOffset->addWidget(lnOffsetZ, 3, 0, 1, 1);

        lnRotateX = new QLabel(centralwidget);
        lnRotateX->setObjectName(QString::fromUtf8("lnRotateX"));
        sizePolicy.setHeightForWidth(lnRotateX->sizePolicy().hasHeightForWidth());
        lnRotateX->setSizePolicy(sizePolicy);
        lnRotateX->setMinimumSize(QSize(30, 0));
        lnRotateX->setMaximumSize(QSize(30, 20));
        lnRotateX->setLayoutDirection(Qt::LeftToRight);
        lnRotateX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glOffset->addWidget(lnRotateX, 6, 0, 1, 1);

        hsOffsetZ = new QSlider(centralwidget);
        hsOffsetZ->setObjectName(QString::fromUtf8("hsOffsetZ"));
        sizePolicy.setHeightForWidth(hsOffsetZ->sizePolicy().hasHeightForWidth());
        hsOffsetZ->setSizePolicy(sizePolicy);
        hsOffsetZ->setMaximumSize(QSize(16777215, 20));
        hsOffsetZ->setMinimum(-100);
        hsOffsetZ->setMaximum(100);
        hsOffsetZ->setOrientation(Qt::Horizontal);

        glOffset->addWidget(hsOffsetZ, 3, 1, 1, 1);

        lRotateX = new QLabel(centralwidget);
        lRotateX->setObjectName(QString::fromUtf8("lRotateX"));
        sizePolicy.setHeightForWidth(lRotateX->sizePolicy().hasHeightForWidth());
        lRotateX->setSizePolicy(sizePolicy);
        lRotateX->setMinimumSize(QSize(30, 0));
        lRotateX->setMaximumSize(QSize(16777215, 20));
        lRotateX->setAlignment(Qt::AlignCenter);

        glOffset->addWidget(lRotateX, 6, 2, 1, 1);

        hsRotateX = new QSlider(centralwidget);
        hsRotateX->setObjectName(QString::fromUtf8("hsRotateX"));
        sizePolicy.setHeightForWidth(hsRotateX->sizePolicy().hasHeightForWidth());
        hsRotateX->setSizePolicy(sizePolicy);
        hsRotateX->setMaximumSize(QSize(16777215, 20));
        hsRotateX->setMinimum(-180);
        hsRotateX->setMaximum(180);
        hsRotateX->setOrientation(Qt::Horizontal);

        glOffset->addWidget(hsRotateX, 6, 1, 1, 1);

        lnOffset = new QLabel(centralwidget);
        lnOffset->setObjectName(QString::fromUtf8("lnOffset"));
        sizePolicy.setHeightForWidth(lnOffset->sizePolicy().hasHeightForWidth());
        lnOffset->setSizePolicy(sizePolicy);
        lnOffset->setMaximumSize(QSize(16777215, 20));

        glOffset->addWidget(lnOffset, 0, 0, 1, 1);

        hsRotateZ = new QSlider(centralwidget);
        hsRotateZ->setObjectName(QString::fromUtf8("hsRotateZ"));
        sizePolicy.setHeightForWidth(hsRotateZ->sizePolicy().hasHeightForWidth());
        hsRotateZ->setSizePolicy(sizePolicy);
        hsRotateZ->setMaximumSize(QSize(16777215, 20));
        hsRotateZ->setMinimum(-180);
        hsRotateZ->setMaximum(180);
        hsRotateZ->setOrientation(Qt::Horizontal);

        glOffset->addWidget(hsRotateZ, 8, 1, 1, 1);

        lOffsetZ = new QLabel(centralwidget);
        lOffsetZ->setObjectName(QString::fromUtf8("lOffsetZ"));
        sizePolicy.setHeightForWidth(lOffsetZ->sizePolicy().hasHeightForWidth());
        lOffsetZ->setSizePolicy(sizePolicy);
        lOffsetZ->setMinimumSize(QSize(40, 0));
        lOffsetZ->setMaximumSize(QSize(16777215, 20));
        lOffsetZ->setAlignment(Qt::AlignCenter);

        glOffset->addWidget(lOffsetZ, 3, 2, 1, 1);

        lOffsetX = new QLabel(centralwidget);
        lOffsetX->setObjectName(QString::fromUtf8("lOffsetX"));
        sizePolicy.setHeightForWidth(lOffsetX->sizePolicy().hasHeightForWidth());
        lOffsetX->setSizePolicy(sizePolicy);
        lOffsetX->setMinimumSize(QSize(40, 0));
        lOffsetX->setMaximumSize(QSize(16777215, 20));
        lOffsetX->setAlignment(Qt::AlignCenter);

        glOffset->addWidget(lOffsetX, 1, 2, 1, 1);

        lnOffsetY = new QLabel(centralwidget);
        lnOffsetY->setObjectName(QString::fromUtf8("lnOffsetY"));
        sizePolicy.setHeightForWidth(lnOffsetY->sizePolicy().hasHeightForWidth());
        lnOffsetY->setSizePolicy(sizePolicy);
        lnOffsetY->setMinimumSize(QSize(30, 0));
        lnOffsetY->setMaximumSize(QSize(30, 20));
        lnOffsetY->setLayoutDirection(Qt::LeftToRight);
        lnOffsetY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glOffset->addWidget(lnOffsetY, 2, 0, 1, 1);

        lnOffsetX = new QLabel(centralwidget);
        lnOffsetX->setObjectName(QString::fromUtf8("lnOffsetX"));
        sizePolicy.setHeightForWidth(lnOffsetX->sizePolicy().hasHeightForWidth());
        lnOffsetX->setSizePolicy(sizePolicy);
        lnOffsetX->setMinimumSize(QSize(30, 0));
        lnOffsetX->setMaximumSize(QSize(30, 20));
        lnOffsetX->setLayoutDirection(Qt::LeftToRight);
        lnOffsetX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glOffset->addWidget(lnOffsetX, 1, 0, 1, 1);

        lnRotate = new QLabel(centralwidget);
        lnRotate->setObjectName(QString::fromUtf8("lnRotate"));
        sizePolicy.setHeightForWidth(lnRotate->sizePolicy().hasHeightForWidth());
        lnRotate->setSizePolicy(sizePolicy);
        lnRotate->setMaximumSize(QSize(16777215, 20));

        glOffset->addWidget(lnRotate, 5, 0, 1, 1);

        lRotateY = new QLabel(centralwidget);
        lRotateY->setObjectName(QString::fromUtf8("lRotateY"));
        sizePolicy.setHeightForWidth(lRotateY->sizePolicy().hasHeightForWidth());
        lRotateY->setSizePolicy(sizePolicy);
        lRotateY->setMinimumSize(QSize(30, 0));
        lRotateY->setMaximumSize(QSize(16777215, 20));
        lRotateY->setAlignment(Qt::AlignCenter);

        glOffset->addWidget(lRotateY, 7, 2, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        glOffset->addWidget(line, 4, 0, 1, 3);


        verticalLayout->addLayout(glOffset);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        glRotate = new QGridLayout();
        glRotate->setObjectName(QString::fromUtf8("glRotate"));
        lnOpaticy = new QLabel(centralwidget);
        lnOpaticy->setObjectName(QString::fromUtf8("lnOpaticy"));
        sizePolicy.setHeightForWidth(lnOpaticy->sizePolicy().hasHeightForWidth());
        lnOpaticy->setSizePolicy(sizePolicy);
        lnOpaticy->setMaximumSize(QSize(16777215, 20));

        glRotate->addWidget(lnOpaticy, 0, 0, 1, 1);

        lnSkin = new QLabel(centralwidget);
        lnSkin->setObjectName(QString::fromUtf8("lnSkin"));
        sizePolicy.setHeightForWidth(lnSkin->sizePolicy().hasHeightForWidth());
        lnSkin->setSizePolicy(sizePolicy);
        lnSkin->setMinimumSize(QSize(30, 0));
        lnSkin->setMaximumSize(QSize(30, 20));
        lnSkin->setLayoutDirection(Qt::LeftToRight);
        lnSkin->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glRotate->addWidget(lnSkin, 1, 0, 1, 1);

        hsSkin = new QSlider(centralwidget);
        hsSkin->setObjectName(QString::fromUtf8("hsSkin"));
        sizePolicy.setHeightForWidth(hsSkin->sizePolicy().hasHeightForWidth());
        hsSkin->setSizePolicy(sizePolicy);
        hsSkin->setMaximumSize(QSize(16777215, 20));
        hsSkin->setMaximum(100);
        hsSkin->setValue(50);
        hsSkin->setOrientation(Qt::Horizontal);

        glRotate->addWidget(hsSkin, 1, 1, 1, 1);

        lSkin = new QLabel(centralwidget);
        lSkin->setObjectName(QString::fromUtf8("lSkin"));
        sizePolicy.setHeightForWidth(lSkin->sizePolicy().hasHeightForWidth());
        lSkin->setSizePolicy(sizePolicy);
        lSkin->setMinimumSize(QSize(30, 0));
        lSkin->setMaximumSize(QSize(30, 20));
        lSkin->setAlignment(Qt::AlignCenter);

        glRotate->addWidget(lSkin, 1, 2, 1, 1);

        lnMusle = new QLabel(centralwidget);
        lnMusle->setObjectName(QString::fromUtf8("lnMusle"));
        sizePolicy.setHeightForWidth(lnMusle->sizePolicy().hasHeightForWidth());
        lnMusle->setSizePolicy(sizePolicy);
        lnMusle->setMinimumSize(QSize(30, 0));
        lnMusle->setMaximumSize(QSize(30, 20));
        lnMusle->setLayoutDirection(Qt::LeftToRight);
        lnMusle->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glRotate->addWidget(lnMusle, 2, 0, 1, 1);

        hsMusle = new QSlider(centralwidget);
        hsMusle->setObjectName(QString::fromUtf8("hsMusle"));
        sizePolicy.setHeightForWidth(hsMusle->sizePolicy().hasHeightForWidth());
        hsMusle->setSizePolicy(sizePolicy);
        hsMusle->setMaximumSize(QSize(16777215, 20));
        hsMusle->setMaximum(100);
        hsMusle->setValue(50);
        hsMusle->setOrientation(Qt::Horizontal);

        glRotate->addWidget(hsMusle, 2, 1, 1, 1);

        lMusle = new QLabel(centralwidget);
        lMusle->setObjectName(QString::fromUtf8("lMusle"));
        sizePolicy.setHeightForWidth(lMusle->sizePolicy().hasHeightForWidth());
        lMusle->setSizePolicy(sizePolicy);
        lMusle->setMinimumSize(QSize(30, 0));
        lMusle->setMaximumSize(QSize(30, 20));
        lMusle->setAlignment(Qt::AlignCenter);

        glRotate->addWidget(lMusle, 2, 2, 1, 1);

        lnSkull = new QLabel(centralwidget);
        lnSkull->setObjectName(QString::fromUtf8("lnSkull"));
        sizePolicy.setHeightForWidth(lnSkull->sizePolicy().hasHeightForWidth());
        lnSkull->setSizePolicy(sizePolicy);
        lnSkull->setMinimumSize(QSize(30, 0));
        lnSkull->setMaximumSize(QSize(30, 20));
        lnSkull->setLayoutDirection(Qt::LeftToRight);
        lnSkull->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glRotate->addWidget(lnSkull, 3, 0, 1, 1);

        hsSkull = new QSlider(centralwidget);
        hsSkull->setObjectName(QString::fromUtf8("hsSkull"));
        sizePolicy.setHeightForWidth(hsSkull->sizePolicy().hasHeightForWidth());
        hsSkull->setSizePolicy(sizePolicy);
        hsSkull->setMaximumSize(QSize(16777215, 20));
        hsSkull->setMaximum(100);
        hsSkull->setValue(50);
        hsSkull->setOrientation(Qt::Horizontal);

        glRotate->addWidget(hsSkull, 3, 1, 1, 1);

        lSkull = new QLabel(centralwidget);
        lSkull->setObjectName(QString::fromUtf8("lSkull"));
        sizePolicy.setHeightForWidth(lSkull->sizePolicy().hasHeightForWidth());
        lSkull->setSizePolicy(sizePolicy);
        lSkull->setMinimumSize(QSize(30, 0));
        lSkull->setMaximumSize(QSize(30, 20));
        lSkull->setAlignment(Qt::AlignCenter);

        glRotate->addWidget(lSkull, 3, 2, 1, 1);

        lnBrain = new QLabel(centralwidget);
        lnBrain->setObjectName(QString::fromUtf8("lnBrain"));
        sizePolicy.setHeightForWidth(lnBrain->sizePolicy().hasHeightForWidth());
        lnBrain->setSizePolicy(sizePolicy);
        lnBrain->setMinimumSize(QSize(30, 0));
        lnBrain->setMaximumSize(QSize(30, 20));
        lnBrain->setLayoutDirection(Qt::LeftToRight);
        lnBrain->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glRotate->addWidget(lnBrain, 4, 0, 1, 1);

        hsBrain = new QSlider(centralwidget);
        hsBrain->setObjectName(QString::fromUtf8("hsBrain"));
        sizePolicy.setHeightForWidth(hsBrain->sizePolicy().hasHeightForWidth());
        hsBrain->setSizePolicy(sizePolicy);
        hsBrain->setMaximumSize(QSize(16777215, 20));
        hsBrain->setMaximum(100);
        hsBrain->setValue(50);
        hsBrain->setOrientation(Qt::Horizontal);

        glRotate->addWidget(hsBrain, 4, 1, 1, 1);

        lBrain = new QLabel(centralwidget);
        lBrain->setObjectName(QString::fromUtf8("lBrain"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lBrain->sizePolicy().hasHeightForWidth());
        lBrain->setSizePolicy(sizePolicy2);
        lBrain->setMinimumSize(QSize(30, 0));
        lBrain->setMaximumSize(QSize(30, 20));
        lBrain->setAlignment(Qt::AlignCenter);

        glRotate->addWidget(lBrain, 4, 2, 1, 1);

        lnElectrode = new QLabel(centralwidget);
        lnElectrode->setObjectName(QString::fromUtf8("lnElectrode"));
        sizePolicy.setHeightForWidth(lnElectrode->sizePolicy().hasHeightForWidth());
        lnElectrode->setSizePolicy(sizePolicy);
        lnElectrode->setMinimumSize(QSize(30, 0));
        lnElectrode->setMaximumSize(QSize(30, 20));
        lnElectrode->setLayoutDirection(Qt::LeftToRight);
        lnElectrode->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        glRotate->addWidget(lnElectrode, 5, 0, 1, 1);

        hsElectrode = new QSlider(centralwidget);
        hsElectrode->setObjectName(QString::fromUtf8("hsElectrode"));
        sizePolicy.setHeightForWidth(hsElectrode->sizePolicy().hasHeightForWidth());
        hsElectrode->setSizePolicy(sizePolicy);
        hsElectrode->setMaximumSize(QSize(16777215, 20));
        hsElectrode->setMaximum(100);
        hsElectrode->setValue(50);
        hsElectrode->setOrientation(Qt::Horizontal);

        glRotate->addWidget(hsElectrode, 5, 1, 1, 1);

        lElectrode = new QLabel(centralwidget);
        lElectrode->setObjectName(QString::fromUtf8("lElectrode"));
        sizePolicy2.setHeightForWidth(lElectrode->sizePolicy().hasHeightForWidth());
        lElectrode->setSizePolicy(sizePolicy2);
        lElectrode->setMinimumSize(QSize(30, 0));
        lElectrode->setMaximumSize(QSize(30, 20));
        lElectrode->setAlignment(Qt::AlignCenter);

        glRotate->addWidget(lElectrode, 5, 2, 1, 1);


        verticalLayout->addLayout(glRotate);

        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(label_26);


        horizontalLayout->addLayout(verticalLayout);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        vlVtk = new QVBoxLayout();
        vlVtk->setObjectName(QString::fromUtf8("vlVtk"));

        horizontalLayout->addLayout(vlVtk);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        pushButton_2->setMaximumSize(QSize(100, 20));

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        pushButton_3->setMaximumSize(QSize(100, 20));

        verticalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);
        pushButton_4->setMaximumSize(QSize(100, 20));

        verticalLayout_2->addWidget(pushButton_4);

        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy4);
        label_27->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(label_27);

        bExit = new QPushButton(centralwidget);
        bExit->setObjectName(QString::fromUtf8("bExit"));
        bExit->setMaximumSize(QSize(100, 16777215));

        verticalLayout_2->addWidget(bExit);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 808, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lnRotateZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        lOffsetY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lRotateZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnRotateY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lnOffsetZ->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        lnRotateX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lRotateX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnOffset->setText(QCoreApplication::translate("MainWindow", "\345\271\263\347\247\273", nullptr));
        lOffsetZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lOffsetX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnOffsetY->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        lnOffsetX->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lnRotate->setText(QCoreApplication::translate("MainWindow", "\346\227\213\350\275\254", nullptr));
        lRotateY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lnOpaticy->setText(QCoreApplication::translate("MainWindow", "\351\200\217\346\230\216\345\272\246", nullptr));
        lnSkin->setText(QCoreApplication::translate("MainWindow", "\347\232\256\350\202\244", nullptr));
        lSkin->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        lnMusle->setText(QCoreApplication::translate("MainWindow", "\350\202\214\350\202\211", nullptr));
        lMusle->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        lnSkull->setText(QCoreApplication::translate("MainWindow", "\351\252\250\351\252\274", nullptr));
        lSkull->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        lnBrain->setText(QCoreApplication::translate("MainWindow", "\350\204\221", nullptr));
        lBrain->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        lnElectrode->setText(QCoreApplication::translate("MainWindow", "\347\224\265\346\236\201", nullptr));
        lElectrode->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_26->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        label_27->setText(QString());
        bExit->setText(QCoreApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
