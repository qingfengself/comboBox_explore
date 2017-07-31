#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    ui->treeW_CmdList->setColumnCount(3);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 3; ++i)
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    ui->treeW_CmdList->insertTopLevelItems(0, items);
    for (int i = 3; i < 6; ++i)
          items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    ui->treeW_CmdList->insertTopLevelItems(2, items);
    ui->treeW_CmdList->setHeaderLabel(QString("cmd"));
}
