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
    std::vector<int> quicksort(std::vector<int> list_);
    static void * mergesort(void * list_thread_pointer);
    void test();
    ~MainWindow();

private slots:
    void on_enterButton_clicked();

private:

    Ui::MainWindow *ui;
    std::vector<int> list;
    static std::vector<std::vector<int>> sortGroup;
};

#endif // MAINWINDOW_H
