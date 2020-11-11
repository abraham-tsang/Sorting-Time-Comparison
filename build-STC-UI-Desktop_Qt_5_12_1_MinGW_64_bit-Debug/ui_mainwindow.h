/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *listInputLabel;
    QLabel *mergeSortLabel;
    QLabel *quickSortLabel;
    QTextEdit *listInput;
    QLabel *mergeSortedListLabel;
    QLabel *quickSortedListLabel;
    QLabel *mergeTimeUsedLabel;
    QLabel *quickTimeUsedLabel;
    QPushButton *enterButton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(730, 526);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        listInputLabel = new QLabel(centralWidget);
        listInputLabel->setObjectName(QString::fromUtf8("listInputLabel"));
        listInputLabel->setGeometry(QRect(10, 30, 251, 16));
        mergeSortLabel = new QLabel(centralWidget);
        mergeSortLabel->setObjectName(QString::fromUtf8("mergeSortLabel"));
        mergeSortLabel->setGeometry(QRect(130, 80, 121, 16));
        quickSortLabel = new QLabel(centralWidget);
        quickSortLabel->setObjectName(QString::fromUtf8("quickSortLabel"));
        quickSortLabel->setGeometry(QRect(490, 80, 111, 16));
        listInput = new QTextEdit(centralWidget);
        listInput->setObjectName(QString::fromUtf8("listInput"));
        listInput->setGeometry(QRect(280, 20, 271, 31));
        mergeSortedListLabel = new QLabel(centralWidget);
        mergeSortedListLabel->setObjectName(QString::fromUtf8("mergeSortedListLabel"));
        mergeSortedListLabel->setGeometry(QRect(30, 120, 91, 16));
        quickSortedListLabel = new QLabel(centralWidget);
        quickSortedListLabel->setObjectName(QString::fromUtf8("quickSortedListLabel"));
        quickSortedListLabel->setGeometry(QRect(370, 140, 81, 16));
        mergeTimeUsedLabel = new QLabel(centralWidget);
        mergeTimeUsedLabel->setObjectName(QString::fromUtf8("mergeTimeUsedLabel"));
        mergeTimeUsedLabel->setGeometry(QRect(30, 160, 81, 16));
        quickTimeUsedLabel = new QLabel(centralWidget);
        quickTimeUsedLabel->setObjectName(QString::fromUtf8("quickTimeUsedLabel"));
        quickTimeUsedLabel->setGeometry(QRect(370, 170, 61, 16));
        enterButton = new QPushButton(centralWidget);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(570, 20, 75, 23));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 240, 271, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 730, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        listInputLabel->setText(QApplication::translate("MainWindow", "Give a list of numbers (seperated with whitespaces): ", nullptr));
        mergeSortLabel->setText(QApplication::translate("MainWindow", "Merge Sort", nullptr));
        quickSortLabel->setText(QApplication::translate("MainWindow", "Quick Sort", nullptr));
        mergeSortedListLabel->setText(QApplication::translate("MainWindow", "Sorted list: ", nullptr));
        quickSortedListLabel->setText(QApplication::translate("MainWindow", "Sorted list: ", nullptr));
        mergeTimeUsedLabel->setText(QApplication::translate("MainWindow", "Time used: ", nullptr));
        quickTimeUsedLabel->setText(QApplication::translate("MainWindow", "Time used: ", nullptr));
        enterButton->setText(QApplication::translate("MainWindow", "Enter", nullptr));
        label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
