#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* init comboBox */
    initComboBox();

    /* init tree widget */
    initTreeWidget();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initComboBox()
{
    /* init comboBox */
    ui->cBBox_1->addItem(QStringLiteral("A"));
    ui->cBBox_1->addItem(QStringLiteral("B"));

    /* right clicked menu */
    ui->cBBox_1->setContextMenuPolicy(Qt::CustomContextMenu); /* set policy */
    connect(ui->cBBox_1, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(show_comboBoxContextMenu(const QPoint&)));


}

void MainWindow::on_pB_clear_clicked()
{
    //setContextMenuPolicy(Qt::DefaultContextMenu);
    ui->cBBox_1->clearEditText();
    //ui->cBBox_1->setItemText(1, QStringLiteral("change"));
}

void MainWindow::show_comboBoxContextMenu(const QPoint&)
{
    QMenu *menu = new QMenu(ui->cBBox_1);
    menu->addAction(new QAction(tr("edit")));
    menu->exec(QCursor::pos());
    delete menu;
}

void MainWindow::initTreeWidget()
{
    ui->treeW_CmdList->setColumnCount(2);
    ui->treeW_CmdList->setHeaderLabels(QStringList()<<"meaning"<<"value");
    lastClickedItem = NULL;
    /* tree widget */
    connect(ui->treeW_CmdList, SIGNAL(itemClicked(QTreeWidgetItem *, int)), this, SLOT(on_treeWidget_clicked(QTreeWidgetItem *, int)));
    connect(ui->treeW_CmdList, SIGNAL(itemDoubleClicked(QTreeWidgetItem *, int)), this, SLOT(on_treeWidget_doubleClicked(QTreeWidgetItem *, int)));
#if 0
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 3; ++i)
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    ui->treeW_CmdList->insertTopLevelItems(0, items);
    for (int i = 3; i < 6; ++i)
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    ui->treeW_CmdList->insertTopLevelItems(2, items);
#endif
}

void MainWindow::on_treeWidget_clicked(QTreeWidgetItem * item, int colum)
{
    if (item == NULL) {
        qDebug("cliced no item");
    } else {
        lastClickedItem = item;
    }
}

void MainWindow::on_treeWidget_doubleClicked(QTreeWidgetItem *item, int colum)
{
    item->setFlags(item->flags() | Qt::ItemIsEditable);
}

void MainWindow::on_pushBtn_add_clicked()
{
    if (lastClickedItem == NULL) {
        QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->treeW_CmdList);
        newItem->setText(0, tr("item"));
        newItem->setText(1, tr("0x0"));
    } else {
        QTreeWidgetItem *newItem = new QTreeWidgetItem(lastClickedItem);
        newItem->setText(0, tr("item"));
        newItem->setText(1, tr("0x0"));
    }

 #if 0
    //QTreeWidgetItem *item = new QTreeWidgetItem();
    ui->treeW_CmdList->itemAt();
    QTreeWidgetItem *top = new QTreeWidgetItem(ui->treeW_CmdList);
    cities->setText(0, tr("Cities"));
    QTreeWidgetItem *osloItem = new QTreeWidgetItem(cities);
    osloItem->setText(0, tr("Oslo"));
    osloItem->setText(1, tr("Yes"));
#endif
}

void MainWindow::on_pushBtn_delete_clicked()
{
    if (lastClickedItem == NULL) {
        qDebug("has no item select");
    } else {
       delete lastClickedItem;
       lastClickedItem = NULL;
    }
}

void MainWindow::on_pushBtn_addRoot_clicked()
{
    QTreeWidgetItem *newItem = new QTreeWidgetItem(ui->treeW_CmdList);
    newItem->setText(0, tr("item"));
    newItem->setText(1, tr("0x0"));
}

void MainWindow::saveSettings()
{
    QSettings settings("./config/settins.txt", QSettings::IniFormat);
    settings.beginGroup(ui->treeW_CmdList->objectName());

    settings.setValue(QString("header1"), 6);

    settings.endGroup();

    qDebug()<< "save settings";
}

void MainWindow::on_pushBtn_save_clicked()
{
    saveSettings();
}
