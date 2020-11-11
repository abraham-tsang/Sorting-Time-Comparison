#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <pthread.h>

typedef void * (*THREADFUNCPTR)(void *);
std::vector<std::vector<int>> MainWindow::sortGroup;

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





//Have to add endl to threads!!!!

void * MainWindow::mergesort(void * index){
    int k = *((int *)index);

    if(sortGroup[k].size() == 0){
        return index;
    }

    std::vector<int> temp;
    int lefti = sortGroup.size();
    sortGroup.push_back(temp);
    int righti = sortGroup.size();
    sortGroup.push_back(temp);

    int half = sortGroup[k].size()/2;
    while(half > 0){
        sortGroup[lefti].push_back(sortGroup[k][0]);
        sortGroup[k].erase(sortGroup[k].begin());
        half--;
    }
    while(sortGroup[k].size() > 0){
        sortGroup[righti].push_back(sortGroup[k][0]);
        sortGroup[k].erase(sortGroup[k].begin());
    }

/*
    int threadNum = 2;
    pthread_t threads[threadNum];
    pthread_create(&threads[0], NULL, &MainWindow::mergesort, &lefti);
    pthread_create(&threads[1], NULL, &MainWindow::mergesort, &righti);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    */


    while(!(sortGroup[lefti].size() == 0 && sortGroup[righti].size() == 0)){
        if(sortGroup[lefti].size() == 0){
            while(sortGroup[righti].size() > 0){
                sortGroup[k].push_back(sortGroup[righti][0]);
                sortGroup[righti].erase(sortGroup[righti].begin());
            }
        }
        else if(sortGroup[righti].size() == 0){
            while(sortGroup[lefti].size() > 0){
                sortGroup[k].push_back(sortGroup[lefti][0]);
                sortGroup[lefti].erase(sortGroup[lefti].begin());
            }
        }
        else if(sortGroup[lefti][0] < sortGroup[righti][0]){
            sortGroup[k].push_back(sortGroup[lefti][0]);
            sortGroup[lefti].erase(sortGroup[lefti].begin());
        }
        else{
            sortGroup[k].push_back(sortGroup[righti][0]);
            sortGroup[righti].erase(sortGroup[righti].begin());
        }
    }
    for(int i = 0; i < sortGroup[k].size(); i++){
        std::cout << sortGroup[k][i] << " ";
    }
    std::cout << std::endl;

    return index;
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

    sortGroup.push_back(list);

    int index = 0;
    int threadNum = 2;
    pthread_t threads[threadNum];
    pthread_create(&threads[0], NULL, &MainWindow::mergesort, &index);
    pthread_join(threads[0], NULL);

    std::vector<int> quickSortedList = quicksort(list);
    //std::vector<int> mergeSortedList = mergesort(list);
    for(int i = 0; i < sortGroup[0].size(); i++){
        //std::cout << sortGroup[0][i] << std::endl;
    }
}


