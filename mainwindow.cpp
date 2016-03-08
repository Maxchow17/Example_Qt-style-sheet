#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QPalette palette;
//    palette.setColor(QPalette::Highlight,  Qt::red);
//    ui->dial->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}
