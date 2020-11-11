#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    static void * quicksort(void * index);
    static void * mergesort(void * index);
    void test();
    ~MainWindow();

private slots:
    void on_enterButton_clicked();

private:

    Ui::MainWindow *ui;
    std::vector<int> list;
    static std::vector<std::vector<int>> mergeSortGroup;
    static std::vector<std::vector<int>> quickSortGroup;
};

#endif // MAINWINDOW_H
