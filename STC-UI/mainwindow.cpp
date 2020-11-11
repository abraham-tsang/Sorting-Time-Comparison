#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

std::vector<int> MainWindow::quicksort(std::vector<int> list_){
    if(list_.size() < 2){
        return list_;
    }
    int pivot = list_[0];
    for(int i = 1; i < list_.size(); i++){
        if(list_[i] < pivot){
            list_.insert(list_.begin(), list_[i]);
            list_.erase(list_.begin()+i+1);
        }
    }
    std::vector<int> left;
    std::vector<int> right;
    int pivoti;
    for(int i = 0; i < list_.size(); i++){
        if(list_[i] != pivot){
            left.push_back(list_[i]);
        }
        else{
            pivoti = i;
            break;
        }
    }
    for(int i = pivoti+1; i < list_.size(); i++){
        right.push_back(list_[i]);
    }
    left = quicksort(left);
    right = quicksort(right);
    for(int i = 0; i < list_.size(); i++){
        if(i < pivoti){
            list_[i] = left[i];
        }
        else if(i == pivoti){
            list_[i] = pivot;
        }
        else if(i > pivoti){
            list_[i] = right[i-pivoti];
        }
    }
    return list_;
}

void MainWindow::on_enterButton_clicked()
{
    QString qstr = ui->listInput->toPlainText();
    std::string str = qstr.toStdString();
    ui->label->setText(qstr);
    std::vector<std::string> strs;
    std::string empty = "";
    strs.push_back(empty);
    unsigned long long str_size = str.size();
    for(unsigned long long i = 0; i < str_size; i++){
        if(str[i] == ' '){
            strs.push_back(empty);
        }
        else{
            strs[strs.size()-1].push_back(str[i]);
        }
    }
    int temp = 0;
    unsigned long long strs_size = strs.size();
    for(unsigned long long i = 0; i < strs_size; i++){
        std::stringstream ss(strs[i]);
        ss >> temp;
        list.push_back(temp);
    }
    list = quicksort(list);
    for(int i = 0; i < list.size(); i++){
        std::cout << list[i] << std::endl;
    }
}


