#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <pthread.h>

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
    std::vector<int> left;
    std::vector<int> right;
    for(int i = 1; i < list_.size(); i++){
        if(list_[i] < pivot){
            left.push_back(list_[i]);
        }
        else{
            right.push_back(list_[i]);
        }
        list_.erase(list_.begin()+i);
        i--;
    }
    list_.erase(list_.begin());
    left = quicksort(left);
    right = quicksort(right);
    int i = 0;
    while(i < left.size()){
        list_.push_back(left[i]);
        i++;
    }
    list_.push_back(pivot);
    i = 0;
    while(i < right.size()){
        list_.push_back(right[i]);
        i++;
    }
    return list_;
}

std::vector<int> MainWindow::mergesort(std::vector<int> list_){
    if(list_.size() < 2){
        return list_;
    }
    std::vector<int> left;
    std::vector<int> right;
    int half = list_.size()/2;
    for(int i = 0; i < half; i++){
        left.push_back(list_[i]);
    }
    for(int i = half; i < list_.size(); i++){
        right.push_back(list_[i]);
    }
    left = mergesort(left);
    right = mergesort(right);
    int lefti = 0;
    int righti = 0;

    for(int i = 0; i < list_.size(); i++){
        if(left.size() == lefti && right.size() == righti){
            break;
        }
        else if(left.size() == lefti){
            while(righti < right.size()){
                list_[i] = right[righti];
                righti++;
                i++;
            }
            break;
        }
        else if(right.size() == righti){
            while(lefti < left.size()){
                list_[i] = left[lefti];
                lefti++;
                i++;
            }
            break;
        }
        else if(left[lefti] < right[righti]){
            list_[i] = left[lefti];
            lefti++;
        }
        else{
            list_[i] = right[righti];
            righti++;
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

    std::vector<int> quickSortedList = quicksort(list);
    std::vector<int> mergeSortedList = mergesort(list);
    for(int i = 0; i < quickSortedList.size(); i++){
        std::cout << quickSortedList[i] << std::endl;
    }
}


