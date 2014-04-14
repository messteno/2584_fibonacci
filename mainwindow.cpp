#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    field_ = new Field();
    setCentralWidget(field_);
    setFixedSize(400, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}
