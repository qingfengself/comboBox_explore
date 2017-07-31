#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    void initComboBox();
    void initTreeWidget();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
