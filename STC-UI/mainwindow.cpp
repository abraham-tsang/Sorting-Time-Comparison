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




typedef void * (*THREADFUNCPTR)(void *);
std::vector<std::vector<int>> MainWindow::sortGroup;


void * MainWindow::mergesort(void * list_thread_pointer){
    std::vector<int> list_ = *((std::vector<int> *)list_thread_pointer);
    if(list_.size() < 2){
        return list_thread_pointer;
    }

    std::vector<int> left;
    std::vector<int> right;
    int half = list_.size()/2;
    while(half > 0){
        left.push_back(list_[0]);
        list_.erase(list_.begin());
        half--;
    }
    while(list_.size() > 0){
        right.push_back(list_[0]);
        list_.erase(list_.begin());
    }

    //left = mergesort(left);
    //right = mergesort(right);

    while(!(left.size() == 0 && right.size() == 0)){
        if(left.size() == 0){
            while(right.size() > 0){
                list_.push_back(right[0]);
                right.erase(right.begin());
            }
        }
        else if(right.size() == 0){
            while(left.size() > 0){
                list_.push_back(left[0]);
                left.erase(left.begin());
            }
        }
        else if(left[0] < right[0]){
            list_.push_back(left[0]);
            left.erase(left.begin());
        }
        else{
            list_.push_back(right[0]);
            right.erase(right.begin());
        }
    }

    for(int i = 0; i < list_.size(); i++){
        //std::cout << list_[i] << std::endl;
    }
    sortGroup.push_back(list_);
    return (void *)&list_;
}

void MainWindow::on_enterButton_clicked()
{
    QString qstr = ui->listInput->toPlainText();
    std::string str = qstr.toStdString();
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

    std::vector<int> mergeSortList = list;
    sortGroup.push_back(list);
    int threadNum = 2;
    pthread_t threads[threadNum];
    pthread_create(&threads[0], NULL, &MainWindow::mergesort, &mergeSortList);
    pthread_join(threads[0], NULL);

    std::vector<int> quickSortedList = quicksort(list);
    //std::vector<int> mergeSortedList = mergesort(list);
    for(int i = 0; i < sortGroup[1].size(); i++){
        std::cout << sortGroup[1][i] << std::endl;
    }
}


