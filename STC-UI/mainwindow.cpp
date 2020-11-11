#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <string>
#include <vector>

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
    std::string temp;
    strs.push_back(temp);
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            strs.push_back(temp);
        }
        else{
            strs[strs.size()-1].push_back(str[i]);
        }
    }
    for(int i = 0; i < strs.size(); i++){
        std::cout << strs[i] << std::endl;
    }
}
