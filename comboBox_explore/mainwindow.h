#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_pB_clear_clicked();
    void show_comboBoxContextMenu(const QPoint&);

    void on_pushBtn_add_clicked();
    void on_treeWidget_clicked(QTreeWidgetItem *item, int colum);
    void on_treeWidget_doubleClicked(QTreeWidgetItem *item, int colum);

    void on_pushBtn_delete_clicked();

    void on_pushBtn_addRoot_clicked();

private:
    void initComboBox();
    void initTreeWidget();

private:
    Ui::MainWindow *ui;
    QTreeWidgetItem* lastClickedItem;
};

#endif // MAINWINDOW_H
