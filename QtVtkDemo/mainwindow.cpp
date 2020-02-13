#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QVTKWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bExit_clicked()
{
    this->close();
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
