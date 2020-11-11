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
    std::vector<int> mergesort(std::vector<int> list_);
    void test();
    ~MainWindow();

private slots:
    void on_enterButton_clicked();

private:

    Ui::MainWindow *ui;
    std::vector<int> list;
};

#endif // MAINWINDOW_H
