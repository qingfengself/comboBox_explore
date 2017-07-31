#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* init comboBox */
    initComboBox();
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
}

#if 0
void MainWindow::customContextMenuRequested(const QPoint &pos)
{
    QCursor* cursor = new QCursor();

    if (ui->cBBox_1->hasFocus()) {
         QMenu *menu = new QMenu(ui->cBBox_1);
        menu->addAction(new QAction(tr("edit")));
        menu->exec(cursor->pos());
    } else {
       // menu->addAction(new QAction(tr("right menu")));
    }

    //delete menu;
}
#endif
