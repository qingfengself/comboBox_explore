#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComboBox()
{
    ui->cBBox_1->addItem(QStringLiteral("A"));
    ui->cBBox_1->addItem(QStringLiteral("B"));
    ui->cBBox_1->setEditable(true);
}

void MainWindow::on_pB_clear_clicked()
{
    ui->cBBox_1->clearEditText();
    ui->cBBox_1->setItemText(1, QStringLiteral("change"));
}
