/********************************************************************************
** Form generated from reading UI file 'loginpage.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINPAGE_H
#define UI_LOGINPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginPage
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QPushButton *btnStart;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *page_2;
    QLabel *label_4;
    QLineEdit *Llogin;
    QPushButton *btnLogin;
    QLineEdit *Lpw;
    QPushButton *btnSID;
    QPushButton *btnSPW;
    QPushButton *btnJoin;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label_5;
    QPushButton *pushButton_6;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *btnHome;
    QPushButton *pushButton;
    QWidget *page_3;
    QLabel *label_15;
    QLineEdit *Ename;
    QLineEdit *Ephone;
    QLineEdit *Eid;
    QLineEdit *Epw;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *btnCKphone;
    QPushButton *btnCKid;
    QLabel *label_20;
    QPushButton *btnEnroll;
    QPushButton *btnBack;
    QWidget *page_4;
    QLabel *label_21;
    QStackedWidget *SIDstackedWidget;
    QWidget *page_6;
    QPushButton *btnSearchID;
    QLabel *label_23;
    QLabel *label_22;
    QLineEdit *SIphone;
    QLineEdit *SIname;
    QPushButton *btnBack2;
    QWidget *page_7;
    QLabel *label_25;
    QLabel *lblShowID;
    QPushButton *btnGTlogin;
    QPushButton *btnSPW2;
    QWidget *page_8;
    QLabel *label_28;
    QPushButton *btngotoSID;
    QLabel *label_24;
    QWidget *page_5;
    QLabel *label_27;
    QLabel *label_29;
    QStackedWidget *SPWstackedWidget;
    QWidget *page_9;
    QPushButton *btnSearchPW;
    QLabel *label_30;
    QLabel *label_31;
    QLineEdit *SPid;
    QLineEdit *SPname;
    QLabel *label_32;
    QLineEdit *SPphone;
    QPushButton *btnBack3;
    QWidget *page_10;
    QLabel *label_35;
    QLabel *lblShowPW;
    QPushButton *btnGTlogin2;
    QWidget *page_11;
    QLabel *label_37;
    QPushButton *btngotoSPW;

    void setupUi(QWidget *LoginPage)
    {
        if (LoginPage->objectName().isEmpty())
            LoginPage->setObjectName("LoginPage");
        LoginPage->resize(851, 620);
        verticalLayout = new QVBoxLayout(LoginPage);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(LoginPage);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName("page");
        label = new QLabel(page);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 30, 771, 221));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        btnStart = new QPushButton(page);
        btnStart->setObjectName("btnStart");
        btnStart->setGeometry(QRect(330, 480, 121, 51));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        btnStart->setFont(font);
        btnStart->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;\n"
""));
        label_2 = new QLabel(page);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 270, 691, 51));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(true);
        label_2->setFont(font1);
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(180, 320, 441, 81));
        label_3->setFont(font1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 20, 221, 81));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        Llogin = new QLineEdit(page_2);
        Llogin->setObjectName("Llogin");
        Llogin->setGeometry(QRect(260, 80, 371, 41));
        QFont font2;
        font2.setPointSize(14);
        Llogin->setFont(font2);
        Llogin->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
""));
        btnLogin = new QPushButton(page_2);
        btnLogin->setObjectName("btnLogin");
        btnLogin->setGeometry(QRect(260, 180, 371, 41));
        btnLogin->setFont(font);
        btnLogin->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"color: rgb(252, 252, 252);\n"
"background-color: rgb(23, 0, 200);\n"
"\n"
"border-radius: 10px;"));
        Lpw = new QLineEdit(page_2);
        Lpw->setObjectName("Lpw");
        Lpw->setGeometry(QRect(260, 130, 371, 41));
        Lpw->setFont(font2);
        Lpw->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
""));
        Lpw->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        Lpw->setEchoMode(QLineEdit::Password);
        Lpw->setCursorMoveStyle(Qt::LogicalMoveStyle);
        btnSID = new QPushButton(page_2);
        btnSID->setObjectName("btnSID");
        btnSID->setGeometry(QRect(260, 230, 111, 41));
        btnSID->setFont(font);
        btnSID->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(23, 0, 200);\n"
"\n"
"border-radius: 10px;"));
        btnSPW = new QPushButton(page_2);
        btnSPW->setObjectName("btnSPW");
        btnSPW->setGeometry(QRect(380, 230, 131, 41));
        btnSPW->setFont(font);
        btnSPW->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(23, 0, 200);\n"
"\n"
"border-radius: 10px;"));
        btnJoin = new QPushButton(page_2);
        btnJoin->setObjectName("btnJoin");
        btnJoin->setGeometry(QRect(520, 230, 111, 41));
        btnJoin->setFont(font);
        btnJoin->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(23, 0, 200);\n"
"\n"
"border-radius: 10px;"));
        checkBox = new QCheckBox(page_2);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(260, 50, 111, 22));
        checkBox->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        checkBox_2 = new QCheckBox(page_2);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(450, 50, 71, 22));
        checkBox_2->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        checkBox_3 = new QCheckBox(page_2);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(530, 50, 101, 22));
        checkBox_3->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        checkBox_3->setCheckable(false);
        label_5 = new QLabel(page_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 390, 91, 16));
        QFont font3;
        font3.setPointSize(9);
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_5->setAlignment(Qt::AlignCenter);
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(520, 20, 111, 24));
        pushButton_6->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_6 = new QLabel(page_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(340, 390, 101, 16));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(page_2);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(450, 390, 91, 16));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(page_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(550, 390, 101, 16));
        label_8->setFont(font3);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(page_2);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(240, 300, 91, 81));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"/*border-image: url(:/resources/NaverImg.PNG);*/"));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/resources/NaverImg.PNG")));
        label_10 = new QLabel(page_2);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(350, 300, 91, 81));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"/*border-image: url(:/resources/KaKaoImg.PNG);*/"));
        label_10->setPixmap(QPixmap(QString::fromUtf8(":/resources/KaKaoImg.PNG")));
        label_11 = new QLabel(page_2);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(450, 300, 91, 81));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"/*border-image: url(:/resources/FacebookImg.PNG);*/"));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/resources/FacebookImg.PNG")));
        label_12 = new QLabel(page_2);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(550, 300, 91, 81));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"/*border-image: url(:/resources/enuriImg.PNG);*/"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/resources/enuriImg.PNG")));
        label_13 = new QLabel(page_2);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(240, 430, 421, 91));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"/*border-image: url(:/resources/adImg.PNG);*/"));
        label_13->setPixmap(QPixmap(QString::fromUtf8(":/resources/adImg.PNG")));
        label_13->setScaledContents(false);
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(page_2);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(240, 540, 411, 20));
        QFont font4;
        font4.setPointSize(10);
        label_14->setFont(font4);
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_14->setAlignment(Qt::AlignCenter);
        btnHome = new QPushButton(page_2);
        btnHome->setObjectName("btnHome");
        btnHome->setGeometry(QRect(380, 570, 101, 31));
        btnHome->setFont(font);
        btnHome->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 430, 421, 91));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255,0);"));
        pushButton->setCheckable(false);
        pushButton->setAutoDefault(true);
        pushButton->setFlat(true);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_15 = new QLabel(page_3);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(270, 20, 271, 41));
        QFont font5;
        font5.setPointSize(20);
        font5.setBold(true);
        label_15->setFont(font5);
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_15->setAlignment(Qt::AlignCenter);
        Ename = new QLineEdit(page_3);
        Ename->setObjectName("Ename");
        Ename->setGeometry(QRect(230, 210, 371, 41));
        Ename->setFont(font2);
        Ename->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        Ephone = new QLineEdit(page_3);
        Ephone->setObjectName("Ephone");
        Ephone->setGeometry(QRect(230, 270, 371, 41));
        Ephone->setFont(font2);
        Ephone->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        Eid = new QLineEdit(page_3);
        Eid->setObjectName("Eid");
        Eid->setGeometry(QRect(230, 330, 371, 41));
        Eid->setFont(font2);
        Eid->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        Epw = new QLineEdit(page_3);
        Epw->setObjectName("Epw");
        Epw->setGeometry(QRect(230, 390, 371, 41));
        Epw->setFont(font2);
        Epw->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        Epw->setEchoMode(QLineEdit::Password);
        label_16 = new QLabel(page_3);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(180, 210, 41, 41));
        label_16->setFont(font);
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_17 = new QLabel(page_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(140, 270, 81, 41));
        label_17->setFont(font);
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_18 = new QLabel(page_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(160, 330, 61, 41));
        label_18->setFont(font);
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        label_19 = new QLabel(page_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(140, 390, 81, 41));
        label_19->setFont(font);
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        btnCKphone = new QPushButton(page_3);
        btnCKphone->setObjectName("btnCKphone");
        btnCKphone->setGeometry(QRect(610, 270, 101, 41));
        btnCKphone->setFont(font);
        btnCKphone->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(199, 199, 199);\n"
"border-radius: 10px;"));
        btnCKid = new QPushButton(page_3);
        btnCKid->setObjectName("btnCKid");
        btnCKid->setGeometry(QRect(610, 330, 101, 41));
        btnCKid->setFont(font);
        btnCKid->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(199, 199, 199);\n"
"border-radius: 10px;"));
        label_20 = new QLabel(page_3);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(220, 80, 381, 101));
        label_20->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);"));
        btnEnroll = new QPushButton(page_3);
        btnEnroll->setObjectName("btnEnroll");
        btnEnroll->setGeometry(QRect(280, 470, 111, 41));
        btnEnroll->setFont(font);
        btnEnroll->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        btnBack = new QPushButton(page_3);
        btnBack->setObjectName("btnBack");
        btnBack->setGeometry(QRect(410, 470, 111, 41));
        btnBack->setFont(font);
        btnBack->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        label_21 = new QLabel(page_4);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(290, 10, 271, 41));
        label_21->setFont(font5);
        label_21->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_21->setAlignment(Qt::AlignCenter);
        SIDstackedWidget = new QStackedWidget(page_4);
        SIDstackedWidget->setObjectName("SIDstackedWidget");
        SIDstackedWidget->setGeometry(QRect(180, 200, 481, 241));
        SIDstackedWidget->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        btnSearchID = new QPushButton(page_6);
        btnSearchID->setObjectName("btnSearchID");
        btnSearchID->setGeometry(QRect(140, 170, 111, 41));
        btnSearchID->setFont(font);
        btnSearchID->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        label_23 = new QLabel(page_6);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(10, 80, 81, 41));
        label_23->setFont(font);
        label_23->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        label_22 = new QLabel(page_6);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(50, 20, 41, 41));
        label_22->setFont(font);
        label_22->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        SIphone = new QLineEdit(page_6);
        SIphone->setObjectName("SIphone");
        SIphone->setGeometry(QRect(100, 80, 371, 41));
        SIphone->setFont(font2);
        SIphone->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        SIname = new QLineEdit(page_6);
        SIname->setObjectName("SIname");
        SIname->setGeometry(QRect(100, 20, 371, 41));
        SIname->setFont(font2);
        SIname->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        btnBack2 = new QPushButton(page_6);
        btnBack2->setObjectName("btnBack2");
        btnBack2->setGeometry(QRect(270, 170, 111, 41));
        btnBack2->setFont(font);
        btnBack2->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        SIDstackedWidget->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        label_25 = new QLabel(page_7);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(130, 50, 251, 21));
        label_25->setFont(font);
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lblShowID = new QLabel(page_7);
        lblShowID->setObjectName("lblShowID");
        lblShowID->setGeometry(QRect(140, 110, 231, 21));
        QFont font6;
        font6.setPointSize(18);
        font6.setBold(true);
        font6.setUnderline(true);
        lblShowID->setFont(font6);
        lblShowID->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        lblShowID->setAlignment(Qt::AlignCenter);
        btnGTlogin = new QPushButton(page_7);
        btnGTlogin->setObjectName("btnGTlogin");
        btnGTlogin->setGeometry(QRect(90, 170, 161, 41));
        btnGTlogin->setFont(font);
        btnGTlogin->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        btnSPW2 = new QPushButton(page_7);
        btnSPW2->setObjectName("btnSPW2");
        btnSPW2->setGeometry(QRect(260, 170, 151, 41));
        btnSPW2->setFont(font);
        btnSPW2->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        SIDstackedWidget->addWidget(page_7);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        label_28 = new QLabel(page_8);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(10, 40, 461, 21));
        label_28->setFont(font);
        btngotoSID = new QPushButton(page_8);
        btngotoSID->setObjectName("btngotoSID");
        btngotoSID->setGeometry(QRect(190, 160, 131, 41));
        btngotoSID->setFont(font);
        btngotoSID->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        SIDstackedWidget->addWidget(page_8);
        label_24 = new QLabel(page_4);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(240, 90, 381, 101));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(8, 8, 8);"));
        stackedWidget->addWidget(page_4);
        SIDstackedWidget->raise();
        label_21->raise();
        label_24->raise();
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        label_27 = new QLabel(page_5);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(230, 100, 381, 101));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_29 = new QLabel(page_5);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(280, 20, 271, 41));
        label_29->setFont(font5);
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_29->setAlignment(Qt::AlignCenter);
        SPWstackedWidget = new QStackedWidget(page_5);
        SPWstackedWidget->setObjectName("SPWstackedWidget");
        SPWstackedWidget->setGeometry(QRect(180, 230, 481, 291));
        SPWstackedWidget->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        btnSearchPW = new QPushButton(page_9);
        btnSearchPW->setObjectName("btnSearchPW");
        btnSearchPW->setGeometry(QRect(130, 230, 111, 41));
        btnSearchPW->setFont(font);
        btnSearchPW->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        label_30 = new QLabel(page_9);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(0, 150, 81, 41));
        label_30->setFont(font);
        label_31 = new QLabel(page_9);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(40, 30, 41, 41));
        label_31->setFont(font);
        SPid = new QLineEdit(page_9);
        SPid->setObjectName("SPid");
        SPid->setGeometry(QRect(90, 90, 371, 41));
        SPid->setFont(font2);
        SPname = new QLineEdit(page_9);
        SPname->setObjectName("SPname");
        SPname->setGeometry(QRect(90, 30, 371, 41));
        SPname->setFont(font2);
        label_32 = new QLabel(page_9);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(0, 90, 81, 41));
        label_32->setFont(font);
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        SPphone = new QLineEdit(page_9);
        SPphone->setObjectName("SPphone");
        SPphone->setGeometry(QRect(90, 150, 371, 41));
        SPphone->setFont(font2);
        btnBack3 = new QPushButton(page_9);
        btnBack3->setObjectName("btnBack3");
        btnBack3->setGeometry(QRect(260, 230, 111, 41));
        btnBack3->setFont(font);
        btnBack3->setStyleSheet(QString::fromUtf8("color: rgb(6, 6, 6);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        SPWstackedWidget->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        label_35 = new QLabel(page_10);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(100, 40, 291, 31));
        label_35->setFont(font);
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        lblShowPW = new QLabel(page_10);
        lblShowPW->setObjectName("lblShowPW");
        lblShowPW->setGeometry(QRect(130, 110, 231, 21));
        lblShowPW->setFont(font6);
        lblShowPW->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 255);"));
        lblShowPW->setAlignment(Qt::AlignCenter);
        btnGTlogin2 = new QPushButton(page_10);
        btnGTlogin2->setObjectName("btnGTlogin2");
        btnGTlogin2->setGeometry(QRect(160, 180, 161, 41));
        btnGTlogin2->setFont(font);
        btnGTlogin2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        SPWstackedWidget->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName("page_11");
        label_37 = new QLabel(page_11);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(10, 40, 461, 31));
        label_37->setFont(font);
        btngotoSPW = new QPushButton(page_11);
        btngotoSPW->setObjectName("btngotoSPW");
        btngotoSPW->setGeometry(QRect(180, 160, 131, 41));
        btngotoSPW->setFont(font);
        btngotoSPW->setStyleSheet(QString::fromUtf8("border-radius: 10px;\n"
"background-color: rgb(254, 254, 254);\n"
"border:2px solid;"));
        SPWstackedWidget->addWidget(page_11);
        stackedWidget->addWidget(page_5);

        verticalLayout->addWidget(stackedWidget);

        QWidget::setTabOrder(Llogin, Lpw);
        QWidget::setTabOrder(Lpw, btnLogin);
        QWidget::setTabOrder(btnLogin, Ename);
        QWidget::setTabOrder(Ename, Ephone);
        QWidget::setTabOrder(Ephone, btnCKphone);
        QWidget::setTabOrder(btnCKphone, Eid);
        QWidget::setTabOrder(Eid, btnCKid);
        QWidget::setTabOrder(btnCKid, Epw);
        QWidget::setTabOrder(Epw, btnEnroll);
        QWidget::setTabOrder(btnEnroll, SIname);
        QWidget::setTabOrder(SIname, SIphone);
        QWidget::setTabOrder(SIphone, btnSearchID);
        QWidget::setTabOrder(btnSearchID, SPname);
        QWidget::setTabOrder(SPname, SPid);
        QWidget::setTabOrder(SPid, SPphone);
        QWidget::setTabOrder(SPphone, btnSearchPW);
        QWidget::setTabOrder(btnSearchPW, checkBox);
        QWidget::setTabOrder(checkBox, checkBox_2);
        QWidget::setTabOrder(checkBox_2, btnBack);
        QWidget::setTabOrder(btnBack, pushButton_6);
        QWidget::setTabOrder(pushButton_6, checkBox_3);
        QWidget::setTabOrder(checkBox_3, btnSID);
        QWidget::setTabOrder(btnSID, btnStart);
        QWidget::setTabOrder(btnStart, btnGTlogin);
        QWidget::setTabOrder(btnGTlogin, btnSPW2);
        QWidget::setTabOrder(btnSPW2, btngotoSID);
        QWidget::setTabOrder(btngotoSID, btnJoin);
        QWidget::setTabOrder(btnJoin, btnBack2);
        QWidget::setTabOrder(btnBack2, btnHome);
        QWidget::setTabOrder(btnHome, btnSPW);
        QWidget::setTabOrder(btnSPW, btnBack3);
        QWidget::setTabOrder(btnBack3, btnGTlogin2);
        QWidget::setTabOrder(btnGTlogin2, btngotoSPW);

        retranslateUi(LoginPage);
        QObject::connect(btnSID, SIGNAL(clicked()), LoginPage, SLOT(gotoSID()));
        QObject::connect(btnSPW, SIGNAL(clicked()), LoginPage, SLOT(gotoSPW()));
        QObject::connect(btnJoin, SIGNAL(clicked()), LoginPage, SLOT(gotoJoin()));
        QObject::connect(btnHome, SIGNAL(clicked()), LoginPage, SLOT(gotoHome()));
        QObject::connect(btnBack, SIGNAL(clicked()), LoginPage, SLOT(gotoLogin()));
        QObject::connect(btnBack2, SIGNAL(clicked()), LoginPage, SLOT(gotoLogin()));
        QObject::connect(btnGTlogin, SIGNAL(clicked()), LoginPage, SLOT(gotoLogin()));
        QObject::connect(btnSPW2, SIGNAL(clicked()), LoginPage, SLOT(gotoSPW()));
        QObject::connect(btnBack3, SIGNAL(clicked()), LoginPage, SLOT(gotoLogin()));
        QObject::connect(btnStart, SIGNAL(clicked()), LoginPage, SLOT(gotoLogin()));
        QObject::connect(btnGTlogin2, SIGNAL(clicked()), LoginPage, SLOT(gotoLogin()));
        QObject::connect(btngotoSPW, SIGNAL(clicked()), LoginPage, SLOT(gotoSPW()));
        QObject::connect(btngotoSID, SIGNAL(clicked()), LoginPage, SLOT(gotoSID()));
        QObject::connect(btnLogin, SIGNAL(clicked()), LoginPage, SLOT(ProgressLogin()));
        QObject::connect(Llogin, &QLineEdit::returnPressed, Lpw, qOverload<>(&QLineEdit::setFocus));
        QObject::connect(Lpw, &QLineEdit::returnPressed, btnLogin, qOverload<>(&QPushButton::click));
        QObject::connect(btnSearchID, SIGNAL(clicked()), LoginPage, SLOT(SearchID()));
        QObject::connect(SIname, &QLineEdit::returnPressed, SIphone, qOverload<>(&QLineEdit::setFocus));
        QObject::connect(SIphone, &QLineEdit::returnPressed, btnSearchID, qOverload<>(&QPushButton::click));
        QObject::connect(btnSearchPW, SIGNAL(clicked()), LoginPage, SLOT(SearchPW()));
        QObject::connect(SPname, &QLineEdit::returnPressed, SPid, qOverload<>(&QLineEdit::setFocus));
        QObject::connect(SPid, &QLineEdit::returnPressed, SPphone, qOverload<>(&QLineEdit::setFocus));
        QObject::connect(SPphone, &QLineEdit::returnPressed, btnSearchPW, qOverload<>(&QPushButton::click));
        QObject::connect(Ename, &QLineEdit::returnPressed, Ephone, qOverload<>(&QLineEdit::setFocus));
        QObject::connect(Ephone, &QLineEdit::returnPressed, btnCKphone, qOverload<>(&QPushButton::click));
        QObject::connect(Eid, &QLineEdit::returnPressed, btnCKid, qOverload<>(&QPushButton::click));
        QObject::connect(Epw, &QLineEdit::returnPressed, btnEnroll, qOverload<>(&QPushButton::click));
        QObject::connect(pushButton, SIGNAL(clicked()), LoginPage, SLOT(pushButtonClicked()));
        QObject::connect(btnEnroll, SIGNAL(clicked()), LoginPage, SLOT(ProgressJoin()));
        QObject::connect(btnCKphone, SIGNAL(clicked()), LoginPage, SLOT(CKPhoneNum()));
        QObject::connect(btnCKid, SIGNAL(clicked()), LoginPage, SLOT(CKID()));

        stackedWidget->setCurrentIndex(2);
        SIDstackedWidget->setCurrentIndex(0);
        SPWstackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LoginPage);
    } // setupUi

    void retranslateUi(QWidget *LoginPage)
    {
        LoginPage->setWindowTitle(QCoreApplication::translate("LoginPage", "Widget", nullptr));
        label->setText(QString());
        btnStart->setText(QCoreApplication::translate("LoginPage", "\354\213\234\354\236\221\355\225\230\352\270\260", nullptr));
        label_2->setStyleSheet(QCoreApplication::translate("LoginPage", "color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);", nullptr));
        label_2->setText(QCoreApplication::translate("LoginPage", "\353\270\214\353\236\234\353\223\234\353\263\204 / \354\260\250\354\242\205\353\263\204 \355\214\220\353\247\244\353\237\211 \353\260\217 \354\240\220\354\234\240\354\234\250 \355\231\225\354\235\270\354\235\200 \354\227\254\352\270\260", nullptr));
        label_3->setStyleSheet(QCoreApplication::translate("LoginPage", "color: rgb(0, 0, 0);\n"
"background-color: rgb(255, 255, 255);", nullptr));
        label_3->setText(QCoreApplication::translate("LoginPage", "\354\235\264\352\263\263 danawa \354\231\200 \355\225\250\352\273\230\355\225\230\354\204\270\354\232\224", nullptr));
        label_4->setText(QCoreApplication::translate("LoginPage", "TextLabel", nullptr));
        Llogin->setPlaceholderText(QCoreApplication::translate("LoginPage", "\354\225\204\354\235\264\353\224\224", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginPage", "\353\241\234\352\267\270\354\235\270", nullptr));
        Lpw->setPlaceholderText(QCoreApplication::translate("LoginPage", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        btnSID->setText(QCoreApplication::translate("LoginPage", "\354\225\204\354\235\264\353\224\224 \354\260\276\352\270\260", nullptr));
        btnSPW->setText(QCoreApplication::translate("LoginPage", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260", nullptr));
        btnJoin->setText(QCoreApplication::translate("LoginPage", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        checkBox->setText(QCoreApplication::translate("LoginPage", "\353\241\234\352\267\270\354\235\270 \354\203\201\355\203\234 \354\234\240\354\247\200", nullptr));
        checkBox_2->setText(QCoreApplication::translate("LoginPage", "\354\235\274\353\260\230\355\232\214\354\233\220", nullptr));
#if QT_CONFIG(tooltip)
        checkBox_3->setToolTip(QCoreApplication::translate("LoginPage", "\354\240\221\352\267\274\355\225\240 \354\210\230 \354\227\206\354\212\265\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        checkBox_3->setText(QCoreApplication::translate("LoginPage", "\355\230\221\353\240\245\354\202\254 \352\264\200\353\246\254\354\236\220", nullptr));
        label_5->setText(QCoreApplication::translate("LoginPage", "\353\204\244\354\235\264\353\262\204 \353\241\234\352\267\270\354\235\270", nullptr));
#if QT_CONFIG(tooltip)
        pushButton_6->setToolTip(QCoreApplication::translate("LoginPage", "(\354\236\204\354\213\234)\353\271\204\353\241\234\352\267\270\354\235\270 \355\214\220\353\247\244\354\213\244\354\240\201 \354\241\260\355\232\214", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton_6->setText(QCoreApplication::translate("LoginPage", "\353\271\204\353\241\234\352\267\270\354\235\270 \354\243\274\353\254\270\354\241\260\355\232\214", nullptr));
        label_6->setText(QCoreApplication::translate("LoginPage", "\354\271\264\354\271\264\354\230\244 \353\241\234\352\267\270\354\235\270", nullptr));
        label_7->setText(QCoreApplication::translate("LoginPage", "\355\216\230\354\235\264\354\212\244\353\266\201 \353\241\234\352\267\270\354\235\270", nullptr));
        label_8->setText(QCoreApplication::translate("LoginPage", "\354\227\220\353\210\204\353\246\254 \353\241\234\352\267\270\354\235\270", nullptr));
#if QT_CONFIG(tooltip)
        label_9->setToolTip(QCoreApplication::translate("LoginPage", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_9->setText(QString());
#if QT_CONFIG(tooltip)
        label_10->setToolTip(QCoreApplication::translate("LoginPage", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_10->setText(QString());
#if QT_CONFIG(tooltip)
        label_11->setToolTip(QCoreApplication::translate("LoginPage", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_11->setText(QString());
#if QT_CONFIG(tooltip)
        label_12->setToolTip(QCoreApplication::translate("LoginPage", "\354\225\204\354\247\201 \354\247\200\354\233\220\355\225\230\354\247\200 \354\225\212\353\212\224 \352\270\260\353\212\245\354\236\205\353\213\210\353\213\244.", nullptr));
#endif // QT_CONFIG(tooltip)
        label_12->setText(QString());
        label_14->setText(QCoreApplication::translate("LoginPage", "Copyright \302\251 connectwave Co., Ltd. All Rights Reserved.", nullptr));
        btnHome->setText(QCoreApplication::translate("LoginPage", "\354\235\264\354\240\204", nullptr));
        pushButton->setText(QString());
        label_15->setText(QCoreApplication::translate("LoginPage", "\355\232\214\354\233\220\352\260\200\354\236\205", nullptr));
        Ephone->setText(QString());
        Ephone->setPlaceholderText(QCoreApplication::translate("LoginPage", "'-' \354\240\234\354\231\270", nullptr));
        label_16->setText(QCoreApplication::translate("LoginPage", "\354\204\261\355\225\250", nullptr));
        label_17->setText(QCoreApplication::translate("LoginPage", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        label_18->setText(QCoreApplication::translate("LoginPage", "\354\225\204\354\235\264\353\224\224", nullptr));
        label_19->setText(QCoreApplication::translate("LoginPage", "\353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        btnCKphone->setText(QCoreApplication::translate("LoginPage", "\354\244\221\353\263\265 \352\262\200\354\202\254", nullptr));
        btnCKid->setText(QCoreApplication::translate("LoginPage", "\354\244\221\353\263\265 \352\262\200\354\202\254", nullptr));
        label_20->setText(QCoreApplication::translate("LoginPage", "TextLabel", nullptr));
        btnEnroll->setText(QCoreApplication::translate("LoginPage", "\354\203\235\354\204\261 \355\225\230\352\270\260", nullptr));
        btnBack->setText(QCoreApplication::translate("LoginPage", "\354\235\264\354\240\204", nullptr));
        label_21->setText(QCoreApplication::translate("LoginPage", "\354\225\204\354\235\264\353\224\224 \354\260\276\352\270\260", nullptr));
        btnSearchID->setText(QCoreApplication::translate("LoginPage", "\355\231\225\354\235\270", nullptr));
        label_23->setText(QCoreApplication::translate("LoginPage", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        label_22->setText(QCoreApplication::translate("LoginPage", "\354\204\261\355\225\250", nullptr));
        SIphone->setText(QString());
        SIphone->setPlaceholderText(QCoreApplication::translate("LoginPage", "'-' \354\240\234\354\231\270", nullptr));
        btnBack2->setText(QCoreApplication::translate("LoginPage", "\354\235\264\354\240\204", nullptr));
        label_25->setText(QCoreApplication::translate("LoginPage", "\355\232\214\354\233\220\353\213\230\354\235\230 \352\263\204\354\240\225\354\235\204 \354\260\276\354\225\230\354\212\265\353\213\210\353\213\244.", nullptr));
        lblShowID->setText(QString());
        btnGTlogin->setText(QCoreApplication::translate("LoginPage", "\353\241\234\352\267\270\354\235\270 \355\231\224\353\251\264 \354\235\264\353\217\231", nullptr));
        btnSPW2->setText(QCoreApplication::translate("LoginPage", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260", nullptr));
        label_28->setText(QCoreApplication::translate("LoginPage", "\354\236\205\353\240\245\355\225\230\354\213\240 \354\240\225\353\263\264\354\231\200 \354\235\274\354\271\230\355\225\230\353\212\224 \352\263\204\354\240\225\354\235\264 \354\241\264\354\236\254\355\225\230\354\247\200 \354\225\212\354\212\265\353\213\210\353\213\244.", nullptr));
        btngotoSID->setText(QCoreApplication::translate("LoginPage", "\353\217\214\354\225\204\352\260\200\352\270\260", nullptr));
        label_24->setText(QCoreApplication::translate("LoginPage", "TextLabel", nullptr));
        label_27->setText(QString());
        label_29->setText(QCoreApplication::translate("LoginPage", "\353\271\204\353\260\200\353\262\210\355\230\270 \354\260\276\352\270\260", nullptr));
        btnSearchPW->setText(QCoreApplication::translate("LoginPage", "\355\231\225\354\235\270", nullptr));
        label_30->setText(QCoreApplication::translate("LoginPage", "\354\240\204\355\231\224\353\262\210\355\230\270", nullptr));
        label_31->setText(QCoreApplication::translate("LoginPage", "\354\204\261\355\225\250", nullptr));
        SPid->setText(QString());
        label_32->setText(QCoreApplication::translate("LoginPage", "\354\225\204\354\235\264\353\224\224", nullptr));
        SPphone->setText(QString());
        SPphone->setPlaceholderText(QCoreApplication::translate("LoginPage", "'-' \354\240\234\354\231\270", nullptr));
        btnBack3->setText(QCoreApplication::translate("LoginPage", "\354\235\264\354\240\204", nullptr));
        label_35->setText(QCoreApplication::translate("LoginPage", "\355\232\214\354\233\220\353\213\230\354\235\230 \353\271\204\353\260\200\353\262\210\355\230\270\353\245\274 \354\260\276\354\225\230\354\212\265\353\213\210\353\213\244.", nullptr));
        lblShowPW->setText(QString());
        btnGTlogin2->setText(QCoreApplication::translate("LoginPage", "\353\241\234\352\267\270\354\235\270 \355\231\224\353\251\264 \354\235\264\353\217\231", nullptr));
        label_37->setText(QCoreApplication::translate("LoginPage", "\354\236\205\353\240\245\355\225\230\354\213\240 \354\240\225\353\263\264\354\231\200 \354\235\274\354\271\230\355\225\230\353\212\224 \352\263\204\354\240\225\354\235\264 \354\241\264\354\236\254\355\225\230\354\247\200 \354\225\212\354\212\265\353\213\210\353\213\244.", nullptr));
        btngotoSPW->setText(QCoreApplication::translate("LoginPage", "\353\217\214\354\225\204\352\260\200\352\270\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginPage: public Ui_LoginPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINPAGE_H
