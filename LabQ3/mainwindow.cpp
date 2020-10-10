#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect( ui->searchButton, &QPushButton::clicked, this, &MainWindow::getInfo );
    connect( ui->searchButton, &QPushButton::clicked, this, &MainWindow::getFrinds );
}

MainWindow::~MainWindow()
{
    delete ui;
}
