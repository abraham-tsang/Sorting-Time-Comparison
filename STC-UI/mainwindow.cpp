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

void MainWindow::on_enterButton_clicked()
{
    QString qstr = ui->listInput->toPlainText();
    std::string str = qstr.toStdString();
    ui->label->setText(qstr);
    std::vector<std::string> strs;
    std::string empty = "";
    strs.push_back(empty);
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            strs.push_back(empty);
        }
        else{
            strs[strs.size()-1].push_back(str[i]);
        }
    }
    int temp = 0;
    for(int i = 0; i < strs.size(); i++){
        std::stringstream ss(strs[i]);
        ss >> temp;
        list.push_back(temp);
        //std::cout << list[i] << std::endl;
    }
}
