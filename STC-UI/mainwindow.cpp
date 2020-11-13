#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <pthread.h>

#include <QObject>
#include <QtCore>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>


//Have to add endl to threads with Qt!!!!
typedef void * (*THREADFUNCPTR)(void *);
std::vector<std::vector<int>> MainWindow::quickSortGroup;
std::vector<std::vector<int>> MainWindow::mergeSortGroup;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    manager = new QNetworkAccessManager();
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(gettime(QNetworkReply*)));
    request.setUrl(QUrl("http://worldclockapi.com/api/json/est/now"));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void * MainWindow::quicksort(void * index){
    int k = *((int *)index);

    if(quickSortGroup[k].size() < 2){
        return index;
    }

    int pivot = quickSortGroup[k][0];
    std::vector<int> temp;
    int lefti = quickSortGroup.size();
    quickSortGroup.push_back(temp);
    int righti = quickSortGroup.size();
    quickSortGroup.push_back(temp);
    for(int i = 1; i < quickSortGroup[k].size(); i++){
        if(quickSortGroup[k][i] < pivot){
            quickSortGroup[lefti].push_back(quickSortGroup[k][i]);
        }
        else{
            quickSortGroup[righti].push_back(quickSortGroup[k][i]);
        }
        quickSortGroup[k].erase(quickSortGroup[k].begin()+i);
        i--;
    }
    quickSortGroup[k].erase(quickSortGroup[k].begin());

    int threadNum = 2;
    pthread_t threads[threadNum];
    pthread_create(&threads[0], NULL, &MainWindow::quicksort, &lefti);
    pthread_create(&threads[1], NULL, &MainWindow::quicksort, &righti);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    int i = 0;
    while(i < quickSortGroup[lefti].size()){
        quickSortGroup[k].push_back(quickSortGroup[lefti][i]);
        i++;
    }
    quickSortGroup[k].push_back(pivot);
    i = 0;

    while(i < quickSortGroup[righti].size()){
        quickSortGroup[k].push_back(quickSortGroup[righti][i]);
        i++;
    }

    return index;
}


void * MainWindow::mergesort(void * index){
    int k = *((int *)index);

    if(mergeSortGroup[k].size() < 2){
        return index;
    }

    std::vector<int> temp;
    int lefti = mergeSortGroup.size();
    mergeSortGroup.push_back(temp);
    int righti = mergeSortGroup.size();
    mergeSortGroup.push_back(temp);

    int half = mergeSortGroup[k].size()/2;
    while(half > 0){
        mergeSortGroup[lefti].push_back(mergeSortGroup[k][0]);
        mergeSortGroup[k].erase(mergeSortGroup[k].begin());
        half--;
    }
    while(mergeSortGroup[k].size() > 0){
        mergeSortGroup[righti].push_back(mergeSortGroup[k][0]);
        mergeSortGroup[k].erase(mergeSortGroup[k].begin());
    }


    int threadNum = 2;
    pthread_t threads[threadNum];
    pthread_create(&threads[0], NULL, &MainWindow::mergesort, &lefti);
    pthread_create(&threads[1], NULL, &MainWindow::mergesort, &righti);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);



    while(!(mergeSortGroup[lefti].size() == 0 && mergeSortGroup[righti].size() == 0)){
        if(mergeSortGroup[lefti].size() == 0){
            while(mergeSortGroup[righti].size() > 0){
                mergeSortGroup[k].push_back(mergeSortGroup[righti][0]);
                mergeSortGroup[righti].erase(mergeSortGroup[righti].begin());
            }
        }
        else if(mergeSortGroup[righti].size() == 0){
            while(mergeSortGroup[lefti].size() > 0){
                mergeSortGroup[k].push_back(mergeSortGroup[lefti][0]);
                mergeSortGroup[lefti].erase(mergeSortGroup[lefti].begin());
            }
        }
        else if(mergeSortGroup[lefti][0] < mergeSortGroup[righti][0]){
            mergeSortGroup[k].push_back(mergeSortGroup[lefti][0]);
            mergeSortGroup[lefti].erase(mergeSortGroup[lefti].begin());
        }
        else{
            mergeSortGroup[k].push_back(mergeSortGroup[righti][0]);
            mergeSortGroup[righti].erase(mergeSortGroup[righti].begin());
        }
    }

    return index;
}

void MainWindow::gettime(QNetworkReply * reply){
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }
    QString answer = reply->readAll();
    std::string time = answer.toStdString();
    time = time.substr(189, 18);
    std::cout << time << std::endl;
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

    mergeSortGroup.push_back(list);
    quickSortGroup.push_back(list);
    int index = 0;
    int threadNum = 2;
    pthread_t threads[threadNum];
    pthread_create(&threads[0], NULL, &MainWindow::mergesort, &index);
    pthread_create(&threads[1], NULL, &MainWindow::quicksort, &index);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    manager->get(request);

    std::cout << std::endl;
}


