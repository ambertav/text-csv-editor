#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label = new QLabel("Hello World!", this);
    label->move(100, 100);
    label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete label;
}
