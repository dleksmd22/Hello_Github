/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *mainstack;
    QWidget *showsales;
    QLabel *label_6;
    QPushButton *btnBrand;
    QLabel *label_2;
    QLabel *label_5;
    QStackedWidget *connectstdWidget;
    QWidget *page_3;
    QWidget *page_4;
    QLabel *label_9;
    QStackedWidget *menustack;
    QWidget *page_5;
    QStackedWidget *brandstack;
    QWidget *page;
    QLabel *label_12;
    QPushButton *BtnBrand1;
    QLabel *label_13;
    QPushButton *BtnBrand2;
    QPushButton *BtnBrand3;
    QLabel *label_14;
    QPushButton *BtnBrand4;
    QLabel *label_15;
    QPushButton *BtnBrand5;
    QLabel *label_16;
    QPushButton *BtnBrand9;
    QPushButton *BtnBrand7;
    QLabel *label_17;
    QPushButton *BtnBrand8;
    QPushButton *BtnBrand11;
    QPushButton *BtnBrand6;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QWidget *page_2;
    QPushButton *pushButton_16;
    QPushButton *BtnBrand10;
    QLabel *label_22;
    QLabel *label_23;
    QPushButton *Bleft;
    QPushButton *Bright;
    QWidget *page_6;
    QPushButton *Cright;
    QStackedWidget *carstack;
    QWidget *page_9;
    QLabel *label_25;
    QPushButton *BtnCar1;
    QLabel *label_26;
    QPushButton *BtnCar2;
    QPushButton *BtnCar3;
    QLabel *label_27;
    QPushButton *BtnCar4;
    QLabel *label_28;
    QPushButton *BtnCar5;
    QLabel *label_29;
    QPushButton *BtnCar10;
    QPushButton *BtnCar8;
    QLabel *label_30;
    QPushButton *BtnCar9;
    QPushButton *BtnCar7;
    QPushButton *BtnCar6;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QWidget *page_10;
    QPushButton *BtnCar12;
    QPushButton *BtnCar11;
    QLabel *label_35;
    QLabel *label_36;
    QPushButton *Cleft;
    QLabel *label_8;
    QPushButton *btnStackBrand;
    QLabel *label_7;
    QLabel *label_10;
    QLabel *label_11;
    QPushButton *btnStackCar;
    QPushButton *btnModel;
    QPushButton *btnWhole;
    QPushButton *pushButton;
    QWidget *login;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(810, 1000);
        MainWindow->setMinimumSize(QSize(810, 1000));
        MainWindow->setMaximumSize(QSize(810, 1000));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        mainstack = new QStackedWidget(centralwidget);
        mainstack->setObjectName("mainstack");
        showsales = new QWidget();
        showsales->setObjectName("showsales");
        label_6 = new QLabel(showsales);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 40, 61, 41));
        QFont font;
        font.setPointSize(11);
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(4, 4, 4);"));
        label_6->setAlignment(Qt::AlignCenter);
        btnBrand = new QPushButton(showsales);
        btnBrand->setObjectName("btnBrand");
        btnBrand->setGeometry(QRect(270, 90, 271, 24));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        btnBrand->setFont(font1);
        btnBrand->setCursor(QCursor(Qt::PointingHandCursor));
        btnBrand->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;border-color: rgb(143, 143, 143);"));
        label_2 = new QLabel(showsales);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(370, 0, 81, 31));
        QFont font2;
        font2.setPointSize(16);
        font2.setBold(true);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(4, 4, 4);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(showsales);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 130, 811, 91));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/mainad.PNG);\n"
"color: rgb(4, 4, 4);"));
        label_5->setPixmap(QPixmap(QString::fromUtf8(":/resources/mainad.PNG")));
        label_5->setScaledContents(true);
        connectstdWidget = new QStackedWidget(showsales);
        connectstdWidget->setObjectName("connectstdWidget");
        connectstdWidget->setGeometry(QRect(0, 530, 811, 451));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        connectstdWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        connectstdWidget->addWidget(page_4);
        label_9 = new QLabel(showsales);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(210, 40, 101, 41));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(4, 4, 4);"));
        label_9->setAlignment(Qt::AlignCenter);
        menustack = new QStackedWidget(showsales);
        menustack->setObjectName("menustack");
        menustack->setGeometry(QRect(0, 250, 811, 271));
        menustack->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        brandstack = new QStackedWidget(page_5);
        brandstack->setObjectName("brandstack");
        brandstack->setGeometry(QRect(0, 20, 811, 201));
        brandstack->setStyleSheet(QString::fromUtf8("color: rgb(4, 4, 4);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        page = new QWidget();
        page->setObjectName("page");
        label_12 = new QLabel(page);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(80, 80, 61, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"border:0px;"));
        label_12->setAlignment(Qt::AlignCenter);
        BtnBrand1 = new QPushButton(page);
        BtnBrand1->setObjectName("BtnBrand1");
        BtnBrand1->setGeometry(QRect(70, 10, 80, 71));
        BtnBrand1->setCursor(QCursor(Qt::PointingHandCursor));
        BtnBrand1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(255, 255, 255);\n"
"/*border-image: url(:/resources/hyundai.png);*/\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/hyundai.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnBrand1->setIcon(icon);
        BtnBrand1->setIconSize(QSize(200, 200));
        label_13 = new QLabel(page);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(230, 80, 61, 20));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_13->setAlignment(Qt::AlignCenter);
        BtnBrand2 = new QPushButton(page);
        BtnBrand2->setObjectName("BtnBrand2");
        BtnBrand2->setGeometry(QRect(220, 10, 80, 71));
        BtnBrand2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/kia.jpg);"));
        BtnBrand3 = new QPushButton(page);
        BtnBrand3->setObjectName("BtnBrand3");
        BtnBrand3->setGeometry(QRect(370, 10, 80, 71));
        BtnBrand3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/genesis.jpg);"));
        label_14 = new QLabel(page);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(380, 80, 61, 20));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_14->setAlignment(Qt::AlignCenter);
        BtnBrand4 = new QPushButton(page);
        BtnBrand4->setObjectName("BtnBrand4");
        BtnBrand4->setGeometry(QRect(520, 10, 80, 71));
        BtnBrand4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/chevy.png);\n"
""));
        label_15 = new QLabel(page);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(530, 80, 61, 20));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_15->setAlignment(Qt::AlignCenter);
        BtnBrand5 = new QPushButton(page);
        BtnBrand5->setObjectName("BtnBrand5");
        BtnBrand5->setGeometry(QRect(670, 10, 80, 71));
        BtnBrand5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/kg.png);"));
        label_16 = new QLabel(page);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(680, 80, 61, 20));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_16->setAlignment(Qt::AlignCenter);
        BtnBrand9 = new QPushButton(page);
        BtnBrand9->setObjectName("BtnBrand9");
        BtnBrand9->setGeometry(QRect(670, 100, 80, 71));
        BtnBrand9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/lexus.jpg);"));
        BtnBrand7 = new QPushButton(page);
        BtnBrand7->setObjectName("BtnBrand7");
        BtnBrand7->setGeometry(QRect(370, 100, 80, 71));
        BtnBrand7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/benz.jpg);"));
        label_17 = new QLabel(page);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(530, 170, 61, 16));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_17->setAlignment(Qt::AlignCenter);
        BtnBrand8 = new QPushButton(page);
        BtnBrand8->setObjectName("BtnBrand8");
        BtnBrand8->setGeometry(QRect(520, 100, 80, 71));
        BtnBrand8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/audi.jpg);"));
        BtnBrand11 = new QPushButton(page);
        BtnBrand11->setObjectName("BtnBrand11");
        BtnBrand11->setGeometry(QRect(220, 100, 80, 71));
        BtnBrand11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/bmw.jpg);"));
        BtnBrand6 = new QPushButton(page);
        BtnBrand6->setObjectName("BtnBrand6");
        BtnBrand6->setGeometry(QRect(70, 100, 80, 71));
        BtnBrand6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/renault.png);"));
        label_18 = new QLabel(page);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(230, 170, 61, 16));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_18->setAlignment(Qt::AlignCenter);
        label_19 = new QLabel(page);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(680, 170, 61, 16));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_19->setAlignment(Qt::AlignCenter);
        label_20 = new QLabel(page);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(380, 170, 61, 16));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(page);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(80, 170, 61, 16));
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_21->setAlignment(Qt::AlignCenter);
        brandstack->addWidget(page);
        BtnBrand8->raise();
        BtnBrand2->raise();
        BtnBrand1->raise();
        label_12->raise();
        label_13->raise();
        BtnBrand3->raise();
        label_14->raise();
        BtnBrand4->raise();
        label_15->raise();
        BtnBrand5->raise();
        label_16->raise();
        BtnBrand9->raise();
        BtnBrand7->raise();
        label_17->raise();
        BtnBrand11->raise();
        BtnBrand6->raise();
        label_18->raise();
        label_19->raise();
        label_20->raise();
        label_21->raise();
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        pushButton_16 = new QPushButton(page_2);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(220, 10, 80, 71));
        pushButton_16->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/toyota.jpg);"));
        BtnBrand10 = new QPushButton(page_2);
        BtnBrand10->setObjectName("BtnBrand10");
        BtnBrand10->setGeometry(QRect(70, 10, 80, 71));
        BtnBrand10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/porsche.jpg);"));
        label_22 = new QLabel(page_2);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(230, 80, 61, 20));
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_22->setAlignment(Qt::AlignCenter);
        label_23 = new QLabel(page_2);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(80, 80, 61, 20));
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_23->setAlignment(Qt::AlignCenter);
        brandstack->addWidget(page_2);
        Bleft = new QPushButton(page_5);
        Bleft->setObjectName("Bleft");
        Bleft->setGeometry(QRect(360, 230, 31, 31));
        QFont font3;
        font3.setPointSize(18);
        Bleft->setFont(font3);
        Bleft->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:0px;"));
        Bright = new QPushButton(page_5);
        Bright->setObjectName("Bright");
        Bright->setGeometry(QRect(410, 230, 31, 31));
        Bright->setFont(font3);
        Bright->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:0px;"));
        menustack->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        Cright = new QPushButton(page_6);
        Cright->setObjectName("Cright");
        Cright->setGeometry(QRect(410, 230, 31, 31));
        Cright->setFont(font3);
        Cright->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:0px;"));
        carstack = new QStackedWidget(page_6);
        carstack->setObjectName("carstack");
        carstack->setGeometry(QRect(0, 20, 811, 201));
        carstack->setStyleSheet(QString::fromUtf8("color: rgb(4, 4, 4);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        label_25 = new QLabel(page_9);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(70, 80, 61, 20));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);\n"
"border:0px;"));
        label_25->setAlignment(Qt::AlignCenter);
        BtnCar1 = new QPushButton(page_9);
        BtnCar1->setObjectName("BtnCar1");
        BtnCar1->setGeometry(QRect(60, 10, 80, 71));
        BtnCar1->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/A.png);\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("resources/\352\262\275\354\260\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar1->setIcon(icon1);
        BtnCar1->setIconSize(QSize(70, 70));
        BtnCar1->setCheckable(false);
        label_26 = new QLabel(page_9);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(220, 80, 61, 20));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_26->setAlignment(Qt::AlignCenter);
        BtnCar2 = new QPushButton(page_9);
        BtnCar2->setObjectName("BtnCar2");
        BtnCar2->setGeometry(QRect(210, 10, 80, 71));
        BtnCar2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/B.png);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("resources/\354\206\214\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar2->setIcon(icon2);
        BtnCar2->setIconSize(QSize(70, 70));
        BtnCar2->setCheckable(false);
        BtnCar3 = new QPushButton(page_9);
        BtnCar3->setObjectName("BtnCar3");
        BtnCar3->setGeometry(QRect(360, 10, 80, 71));
        BtnCar3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/C.png);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("resources/\354\244\200\354\244\221\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar3->setIcon(icon3);
        BtnCar3->setIconSize(QSize(70, 70));
        BtnCar3->setCheckable(false);
        label_27 = new QLabel(page_9);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(370, 80, 61, 20));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_27->setAlignment(Qt::AlignCenter);
        BtnCar4 = new QPushButton(page_9);
        BtnCar4->setObjectName("BtnCar4");
        BtnCar4->setGeometry(QRect(510, 10, 80, 71));
        BtnCar4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/D.png);\n"
""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("resources/\354\244\221\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar4->setIcon(icon4);
        BtnCar4->setIconSize(QSize(70, 70));
        BtnCar4->setCheckable(false);
        label_28 = new QLabel(page_9);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(520, 80, 61, 20));
        label_28->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_28->setAlignment(Qt::AlignCenter);
        BtnCar5 = new QPushButton(page_9);
        BtnCar5->setObjectName("BtnCar5");
        BtnCar5->setGeometry(QRect(660, 10, 80, 71));
        BtnCar5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/E.png);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("resources/\354\244\200\353\214\200\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar5->setIcon(icon5);
        BtnCar5->setIconSize(QSize(70, 70));
        BtnCar5->setCheckable(false);
        label_29 = new QLabel(page_9);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(670, 80, 61, 20));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_29->setAlignment(Qt::AlignCenter);
        BtnCar10 = new QPushButton(page_9);
        BtnCar10->setObjectName("BtnCar10");
        BtnCar10->setGeometry(QRect(660, 100, 80, 71));
        BtnCar10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/J.png);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("resources/\353\214\200\355\230\225SUV.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar10->setIcon(icon6);
        BtnCar10->setIconSize(QSize(70, 70));
        BtnCar10->setCheckable(false);
        BtnCar8 = new QPushButton(page_9);
        BtnCar8->setObjectName("BtnCar8");
        BtnCar8->setGeometry(QRect(360, 100, 80, 71));
        BtnCar8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/H.png);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("resources/\354\206\214\355\230\225SUV.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar8->setIcon(icon7);
        BtnCar8->setIconSize(QSize(70, 70));
        BtnCar8->setCheckable(false);
        label_30 = new QLabel(page_9);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(520, 170, 61, 16));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_30->setAlignment(Qt::AlignCenter);
        BtnCar9 = new QPushButton(page_9);
        BtnCar9->setObjectName("BtnCar9");
        BtnCar9->setGeometry(QRect(510, 100, 80, 71));
        BtnCar9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/I.png);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("resources/\354\244\221\355\230\225SUV.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar9->setIcon(icon8);
        BtnCar9->setIconSize(QSize(70, 70));
        BtnCar9->setCheckable(false);
        BtnCar7 = new QPushButton(page_9);
        BtnCar7->setObjectName("BtnCar7");
        BtnCar7->setGeometry(QRect(210, 100, 80, 71));
        BtnCar7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/G.png);"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("resources/\354\212\244\355\217\254\354\270\240\354\271\264.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar7->setIcon(icon9);
        BtnCar7->setIconSize(QSize(70, 70));
        BtnCar7->setCheckable(false);
        BtnCar6 = new QPushButton(page_9);
        BtnCar6->setObjectName("BtnCar6");
        BtnCar6->setGeometry(QRect(60, 100, 80, 71));
        BtnCar6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/F.png);"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8("resources/\353\214\200\355\230\225.png"), QSize(), QIcon::Normal, QIcon::Off);
        BtnCar6->setIcon(icon10);
        BtnCar6->setIconSize(QSize(70, 70));
        BtnCar6->setCheckable(false);
        label_31 = new QLabel(page_9);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(220, 170, 61, 16));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_31->setAlignment(Qt::AlignCenter);
        label_32 = new QLabel(page_9);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(670, 170, 61, 16));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_32->setAlignment(Qt::AlignCenter);
        label_33 = new QLabel(page_9);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(370, 170, 61, 16));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_33->setAlignment(Qt::AlignCenter);
        label_34 = new QLabel(page_9);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(70, 170, 61, 16));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_34->setAlignment(Qt::AlignCenter);
        carstack->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        BtnCar12 = new QPushButton(page_10);
        BtnCar12->setObjectName("BtnCar12");
        BtnCar12->setGeometry(QRect(220, 10, 80, 71));
        BtnCar12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/L.png);"));
        BtnCar12->setCheckable(false);
        BtnCar11 = new QPushButton(page_10);
        BtnCar11->setObjectName("BtnCar11");
        BtnCar11->setGeometry(QRect(70, 10, 80, 71));
        BtnCar11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-image: url(:/resources/K.png);"));
        BtnCar11->setCheckable(false);
        label_35 = new QLabel(page_10);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(230, 80, 61, 20));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_35->setAlignment(Qt::AlignCenter);
        label_36 = new QLabel(page_10);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(80, 80, 61, 20));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(12, 12, 12);border:0px;"));
        label_36->setAlignment(Qt::AlignCenter);
        carstack->addWidget(page_10);
        Cleft = new QPushButton(page_6);
        Cleft->setObjectName("Cleft");
        Cleft->setGeometry(QRect(360, 230, 31, 31));
        Cleft->setFont(font3);
        Cleft->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border:0px;"));
        menustack->addWidget(page_6);
        label_8 = new QLabel(showsales);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 40, 61, 41));
        QFont font4;
        font4.setPointSize(11);
        font4.setUnderline(true);
        label_8->setFont(font4);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 4, 255);"));
        label_8->setAlignment(Qt::AlignCenter);
        btnStackBrand = new QPushButton(showsales);
        btnStackBrand->setObjectName("btnStackBrand");
        btnStackBrand->setGeometry(QRect(70, 240, 271, 31));
        QFont font5;
        font5.setPointSize(11);
        font5.setBold(true);
        btnStackBrand->setFont(font5);
        btnStackBrand->setCursor(QCursor(Qt::PointingHandCursor));
        btnStackBrand->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        label_7 = new QLabel(showsales);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(70, 40, 61, 41));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(4, 4, 4);"));
        label_7->setAlignment(Qt::AlignCenter);
        label_10 = new QLabel(showsales);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(320, 40, 81, 41));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(4, 4, 4);"));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(showsales);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(400, 40, 81, 41));
        label_11->setFont(font);
        label_11->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(4, 4, 4);"));
        label_11->setAlignment(Qt::AlignCenter);
        btnStackCar = new QPushButton(showsales);
        btnStackCar->setObjectName("btnStackCar");
        btnStackCar->setGeometry(QRect(480, 240, 271, 31));
        btnStackCar->setFont(font5);
        btnStackCar->setCursor(QCursor(Qt::PointingHandCursor));
        btnStackCar->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        btnModel = new QPushButton(showsales);
        btnModel->setObjectName("btnModel");
        btnModel->setGeometry(QRect(550, 90, 261, 24));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setUnderline(false);
        btnModel->setFont(font6);
        btnModel->setCursor(QCursor(Qt::PointingHandCursor));
        btnModel->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;border-color: rgb(143, 143, 143);"));
        btnWhole = new QPushButton(showsales);
        btnWhole->setObjectName("btnWhole");
        btnWhole->setGeometry(QRect(0, 90, 261, 24));
        btnWhole->setFont(font1);
        btnWhole->setCursor(QCursor(Qt::PointingHandCursor));
        btnWhole->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        pushButton = new QPushButton(showsales);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 123, 811, 111));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        pushButton->setAutoDefault(true);
        pushButton->setFlat(true);
        mainstack->addWidget(showsales);
        login = new QWidget();
        login->setObjectName("login");
        mainstack->addWidget(login);

        verticalLayout->addWidget(mainstack);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 810, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(btnStackBrand, SIGNAL(clicked()), MainWindow, SLOT(btnStackBrandClicked()));
        QObject::connect(btnStackCar, SIGNAL(clicked()), MainWindow, SLOT(btnStackCarClicked()));
        QObject::connect(Bleft, SIGNAL(clicked()), MainWindow, SLOT(ChangeBStackPage()));
        QObject::connect(Bright, SIGNAL(clicked()), MainWindow, SLOT(ChangeBStackPage()));
        QObject::connect(Cleft, SIGNAL(clicked()), MainWindow, SLOT(ChangeCStackPage()));
        QObject::connect(Cright, SIGNAL(clicked()), MainWindow, SLOT(ChangeCStackPage()));
        QObject::connect(BtnCar1, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar2, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar3, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar4, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar5, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar6, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar7, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar8, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar9, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar10, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar11, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnCar12, &QPushButton::clicked, btnModel, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand10, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(pushButton_16, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand1, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand2, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand3, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand4, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand5, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand6, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand11, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand7, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand8, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));
        QObject::connect(BtnBrand9, &QPushButton::clicked, btnBrand, qOverload<>(&QPushButton::click));

        mainstack->setCurrentIndex(0);
        menustack->setCurrentIndex(0);
        brandstack->setCurrentIndex(0);
        carstack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(tooltip)
        label_6->setToolTip(QCoreApplication::translate("MainWindow", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("MainWindow", "\354\213\240\354\260\250\352\262\200\354\203\211", nullptr));
        btnBrand->setText(QCoreApplication::translate("MainWindow", "\353\270\214\353\236\234\353\223\234\353\263\204", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\354\213\240\354\260\250", nullptr));
        label_5->setText(QString());
#if QT_CONFIG(tooltip)
        label_9->setToolTip(QCoreApplication::translate("MainWindow", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QCoreApplication::translate("MainWindow", "\352\262\254\354\240\201\354\232\224\354\262\255 \355\230\204\355\231\251", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\355\230\204\353\214\200", nullptr));
        BtnBrand1->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\352\270\260\354\225\204", nullptr));
        BtnBrand2->setText(QString());
        BtnBrand3->setText(QString());
        label_14->setText(QCoreApplication::translate("MainWindow", "\354\240\234\353\204\244\354\213\234\354\212\244", nullptr));
        BtnBrand4->setText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "\354\211\220\353\263\264\353\240\210", nullptr));
        BtnBrand5->setText(QString());
        label_16->setText(QCoreApplication::translate("MainWindow", "KG\353\252\250\353\271\214\353\246\254\355\213\260", nullptr));
        BtnBrand9->setText(QString());
        BtnBrand7->setText(QString());
        label_17->setText(QCoreApplication::translate("MainWindow", "\354\225\204\354\232\260\353\224\224", nullptr));
        BtnBrand8->setText(QString());
        BtnBrand11->setText(QString());
        BtnBrand6->setText(QString());
        label_18->setText(QCoreApplication::translate("MainWindow", "BMW", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\353\240\211\354\204\234\354\212\244", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\353\262\244\354\270\240", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\353\245\264\353\205\270\354\275\224\353\246\254\354\225\204", nullptr));
        pushButton_16->setText(QString());
        BtnBrand10->setText(QString());
        label_22->setText(QCoreApplication::translate("MainWindow", "\353\217\204\354\232\224\355\203\200", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\355\217\254\353\245\264\354\211\220", nullptr));
        Bleft->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        Bright->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        Cright->setText(QCoreApplication::translate("MainWindow", "\342\226\266", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\352\262\275\354\260\250", nullptr));
        BtnCar1->setText(QString());
        label_26->setText(QCoreApplication::translate("MainWindow", "\354\206\214\355\230\225", nullptr));
        BtnCar2->setText(QString());
        BtnCar3->setText(QString());
        label_27->setText(QCoreApplication::translate("MainWindow", "\354\244\200\354\244\221\355\230\225", nullptr));
        BtnCar4->setText(QString());
        label_28->setText(QCoreApplication::translate("MainWindow", "\354\244\221\355\230\225", nullptr));
        BtnCar5->setText(QString());
        label_29->setText(QCoreApplication::translate("MainWindow", "\354\244\200\353\214\200\355\230\225", nullptr));
        BtnCar10->setText(QString());
        BtnCar8->setText(QString());
        label_30->setText(QCoreApplication::translate("MainWindow", "\354\244\221\355\230\225SUV", nullptr));
        BtnCar9->setText(QString());
        BtnCar7->setText(QString());
        BtnCar6->setText(QString());
        label_31->setText(QCoreApplication::translate("MainWindow", "\354\212\244\355\217\254\354\270\240\354\271\264", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "\353\214\200\355\230\225SUV", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "\354\206\214\355\230\225SUV", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "\353\214\200\355\230\225", nullptr));
        BtnCar12->setText(QString());
        BtnCar11->setText(QString());
        label_35->setText(QCoreApplication::translate("MainWindow", "\354\203\201\354\232\251", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "RV/MPV", nullptr));
        Cleft->setText(QCoreApplication::translate("MainWindow", "\342\227\200", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\355\214\220\353\247\244\354\213\244\354\240\201", nullptr));
        btnStackBrand->setText(QCoreApplication::translate("MainWindow", "\353\270\214\353\236\234\353\223\234\353\263\204", nullptr));
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QCoreApplication::translate("MainWindow", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("MainWindow", "\355\214\220\353\247\244\354\241\260\352\261\264", nullptr));
#if QT_CONFIG(tooltip)
        label_10->setToolTip(QCoreApplication::translate("MainWindow", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_10->setText(QCoreApplication::translate("MainWindow", "\354\235\274\354\213\234\353\266\210 \354\240\225\353\263\264", nullptr));
#if QT_CONFIG(tooltip)
        label_11->setToolTip(QCoreApplication::translate("MainWindow", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QCoreApplication::translate("MainWindow", "\355\225\240\353\266\200 \354\240\225\353\263\264", nullptr));
        btnStackCar->setText(QCoreApplication::translate("MainWindow", "\354\260\250\354\242\205\353\263\204", nullptr));
        btnModel->setText(QCoreApplication::translate("MainWindow", "\353\252\250\353\215\270\353\263\204", nullptr));
        btnWhole->setText(QCoreApplication::translate("MainWindow", "\354\240\204\354\262\264", nullptr));
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
