/********************************************************************************
** Form generated from reading UI file 'brandtab.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRANDTAB_H
#define UI_BRANDTAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BrandTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *monthPick;
    QPushButton *durationPick;
    QStackedWidget *dateStack;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *yearIndex;
    QComboBox *monthIndex;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *yearIndex1;
    QComboBox *monthIndex1;
    QLabel *label_24;
    QComboBox *yearIndex2;
    QComboBox *monthIndex2;
    QPushButton *searchButtion;
    QStackedWidget *brandInfoStack;
    QWidget *page;
    QWidget *page_8;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *ds_2;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *hyundaiSales;
    QLabel *hyundaiOnMonth;
    QWidget *page_9;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QVBoxLayout *verticalLayout_8;
    QLabel *ds_3;
    QLabel *label_9;
    QVBoxLayout *verticalLayout_9;
    QLabel *kiaSales;
    QLabel *kiaOnMonth;
    QWidget *page_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_12;
    QVBoxLayout *verticalLayout_18;
    QLabel *ds_4;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_19;
    QLabel *genesisSales;
    QLabel *genesisOnMonth;
    QWidget *page_13;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_14;
    QVBoxLayout *verticalLayout_20;
    QLabel *ds_5;
    QLabel *label_13;
    QVBoxLayout *verticalLayout_21;
    QLabel *chevorletSales;
    QLabel *chevorletOnMonth;
    QWidget *page_14;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_22;
    QLabel *ds_6;
    QLabel *label_15;
    QVBoxLayout *verticalLayout_23;
    QLabel *kgSales;
    QLabel *kgOnMonth;
    QWidget *page_19;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_24;
    QLabel *ds_7;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_25;
    QLabel *renaultSales;
    QLabel *renaultOnMonth;
    QWidget *page_20;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_20;
    QVBoxLayout *verticalLayout_26;
    QLabel *ds_8;
    QLabel *label_19;
    QVBoxLayout *verticalLayout_27;
    QLabel *bmwSales;
    QLabel *bmwOnMonth;
    QWidget *page_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_22;
    QVBoxLayout *verticalLayout_10;
    QLabel *ds_9;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_11;
    QLabel *benzSales;
    QLabel *benzOnMonth;
    QWidget *page_21;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_25;
    QVBoxLayout *verticalLayout_16;
    QLabel *ds_10;
    QLabel *label_23;
    QVBoxLayout *verticalLayout_17;
    QLabel *audiSales;
    QLabel *audiOnMonth;
    QWidget *page_22;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_27;
    QVBoxLayout *verticalLayout_13;
    QLabel *ds_11;
    QLabel *label_26;
    QVBoxLayout *verticalLayout_12;
    QLabel *lexusSales;
    QLabel *lexusOnMonth;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label;
    QVBoxLayout *verticalLayout_14;
    QLabel *ds;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_15;
    QLabel *porscheSales;
    QLabel *porscheOnMonth;
    QWidget *page_23;
    QStackedWidget *contentStack;
    QWidget *page_17;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *specificBrandTable;
    QWidget *page_18;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *domesticTable;
    QTableWidget *overseasTable;

    void setupUi(QWidget *BrandTab)
    {
        if (BrandTab->objectName().isEmpty())
            BrandTab->setObjectName("BrandTab");
        BrandTab->resize(810, 764);
        BrandTab->setMinimumSize(QSize(810, 0));
        BrandTab->setMaximumSize(QSize(810, 16777215));
        BrandTab->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(BrandTab);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        monthPick = new QPushButton(BrandTab);
        monthPick->setObjectName("monthPick");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        monthPick->setFont(font);
        monthPick->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));

        horizontalLayout->addWidget(monthPick);

        durationPick = new QPushButton(BrandTab);
        durationPick->setObjectName("durationPick");
        durationPick->setFont(font);
        durationPick->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));

        horizontalLayout->addWidget(durationPick);


        verticalLayout->addLayout(horizontalLayout);

        dateStack = new QStackedWidget(BrandTab);
        dateStack->setObjectName("dateStack");
        dateStack->setStyleSheet(QString::fromUtf8("color: rgb(4, 4, 4);\n"
"/*border: 1px solid;\n"
"border-color: rgb(143, 143, 143);*/"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(300, -1, 300, -1);
        yearIndex = new QComboBox(page_3);
        yearIndex->addItem(QString());
        yearIndex->setObjectName("yearIndex");
        yearIndex->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_2->addWidget(yearIndex);

        monthIndex = new QComboBox(page_3);
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->addItem(QString());
        monthIndex->setObjectName("monthIndex");
        monthIndex->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_2->addWidget(monthIndex);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        dateStack->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_3 = new QVBoxLayout(page_4);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(200, -1, 200, -1);
        yearIndex1 = new QComboBox(page_4);
        yearIndex1->addItem(QString());
        yearIndex1->setObjectName("yearIndex1");
        yearIndex1->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(139, 139, 139);"));

        horizontalLayout_3->addWidget(yearIndex1);

        monthIndex1 = new QComboBox(page_4);
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->addItem(QString());
        monthIndex1->setObjectName("monthIndex1");
        monthIndex1->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(139, 139, 139);"));

        horizontalLayout_3->addWidget(monthIndex1);

        label_24 = new QLabel(page_4);
        label_24->setObjectName("label_24");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_24->setFont(font1);
        label_24->setStyleSheet(QString::fromUtf8("border:0px;"));

        horizontalLayout_3->addWidget(label_24);

        yearIndex2 = new QComboBox(page_4);
        yearIndex2->addItem(QString());
        yearIndex2->setObjectName("yearIndex2");
        yearIndex2->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(139, 139, 139);"));

        horizontalLayout_3->addWidget(yearIndex2);

        monthIndex2 = new QComboBox(page_4);
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->addItem(QString());
        monthIndex2->setObjectName("monthIndex2");
        monthIndex2->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(139, 139, 139);"));

        horizontalLayout_3->addWidget(monthIndex2);

        searchButtion = new QPushButton(page_4);
        searchButtion->setObjectName("searchButtion");
        QFont font2;
        font2.setPointSize(11);
        searchButtion->setFont(font2);
        searchButtion->setStyleSheet(QString::fromUtf8("border:2px solid;\n"
"border-color: rgb(143, 143, 143);\n"
""));

        horizontalLayout_3->addWidget(searchButtion);

        horizontalLayout_3->setStretch(0, 5);
        horizontalLayout_3->setStretch(1, 3);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 5);
        horizontalLayout_3->setStretch(4, 3);
        horizontalLayout_3->setStretch(5, 3);

        verticalLayout_3->addLayout(horizontalLayout_3);

        dateStack->addWidget(page_4);

        verticalLayout->addWidget(dateStack);

        brandInfoStack = new QStackedWidget(BrandTab);
        brandInfoStack->setObjectName("brandInfoStack");
        brandInfoStack->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));
        page = new QWidget();
        page->setObjectName("page");
        brandInfoStack->addWidget(page);
        page_8 = new QWidget();
        page_8->setObjectName("page_8");
        horizontalLayout_4 = new QHBoxLayout(page_8);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(9, 9, 9, 9);
        label_2 = new QLabel(page_8);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/hyndai.gif);"));

        horizontalLayout_4->addWidget(label_2);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(-1, 0, -1, 0);
        ds_2 = new QLabel(page_8);
        ds_2->setObjectName("ds_2");
        ds_2->setFont(font2);
        ds_2->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));

        verticalLayout_7->addWidget(ds_2);

        label_4 = new QLabel(page_8);
        label_4->setObjectName("label_4");
        label_4->setFont(font2);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));

        verticalLayout_7->addWidget(label_4);


        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(-1, 0, -1, 0);
        hyundaiSales = new QLabel(page_8);
        hyundaiSales->setObjectName("hyundaiSales");
        hyundaiSales->setFont(font2);
        hyundaiSales->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));

        verticalLayout_6->addWidget(hyundaiSales);

        hyundaiOnMonth = new QLabel(page_8);
        hyundaiOnMonth->setObjectName("hyundaiOnMonth");
        hyundaiOnMonth->setFont(font2);

        verticalLayout_6->addWidget(hyundaiOnMonth);


        horizontalLayout_4->addLayout(verticalLayout_6);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 5);
        brandInfoStack->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName("page_9");
        horizontalLayout_5 = new QHBoxLayout(page_9);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(9, 9, 9, 9);
        label_10 = new QLabel(page_9);
        label_10->setObjectName("label_10");
        label_10->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/kia.png);"));

        horizontalLayout_5->addWidget(label_10);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(-1, 0, -1, 0);
        ds_3 = new QLabel(page_9);
        ds_3->setObjectName("ds_3");
        ds_3->setFont(font2);

        verticalLayout_8->addWidget(ds_3);

        label_9 = new QLabel(page_9);
        label_9->setObjectName("label_9");
        label_9->setFont(font2);

        verticalLayout_8->addWidget(label_9);


        horizontalLayout_5->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(-1, 0, -1, 0);
        kiaSales = new QLabel(page_9);
        kiaSales->setObjectName("kiaSales");
        kiaSales->setFont(font2);

        verticalLayout_9->addWidget(kiaSales);

        kiaOnMonth = new QLabel(page_9);
        kiaOnMonth->setObjectName("kiaOnMonth");
        kiaOnMonth->setFont(font2);

        verticalLayout_9->addWidget(kiaOnMonth);


        horizontalLayout_5->addLayout(verticalLayout_9);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 5);
        brandInfoStack->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName("page_10");
        horizontalLayout_10 = new QHBoxLayout(page_10);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        label_12 = new QLabel(page_10);
        label_12->setObjectName("label_12");
        label_12->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/genesis.png);"));

        horizontalLayout_10->addWidget(label_12);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName("verticalLayout_18");
        ds_4 = new QLabel(page_10);
        ds_4->setObjectName("ds_4");
        ds_4->setFont(font2);

        verticalLayout_18->addWidget(ds_4);

        label_11 = new QLabel(page_10);
        label_11->setObjectName("label_11");
        label_11->setFont(font2);

        verticalLayout_18->addWidget(label_11);


        horizontalLayout_10->addLayout(verticalLayout_18);

        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName("verticalLayout_19");
        genesisSales = new QLabel(page_10);
        genesisSales->setObjectName("genesisSales");
        genesisSales->setFont(font2);

        verticalLayout_19->addWidget(genesisSales);

        genesisOnMonth = new QLabel(page_10);
        genesisOnMonth->setObjectName("genesisOnMonth");
        genesisOnMonth->setFont(font2);

        verticalLayout_19->addWidget(genesisOnMonth);


        horizontalLayout_10->addLayout(verticalLayout_19);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 5);
        brandInfoStack->addWidget(page_10);
        page_13 = new QWidget();
        page_13->setObjectName("page_13");
        horizontalLayout_11 = new QHBoxLayout(page_13);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_14 = new QLabel(page_13);
        label_14->setObjectName("label_14");
        label_14->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/chevolet.png);"));

        horizontalLayout_11->addWidget(label_14);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName("verticalLayout_20");
        ds_5 = new QLabel(page_13);
        ds_5->setObjectName("ds_5");
        ds_5->setFont(font2);

        verticalLayout_20->addWidget(ds_5);

        label_13 = new QLabel(page_13);
        label_13->setObjectName("label_13");
        label_13->setFont(font2);

        verticalLayout_20->addWidget(label_13);


        horizontalLayout_11->addLayout(verticalLayout_20);

        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName("verticalLayout_21");
        chevorletSales = new QLabel(page_13);
        chevorletSales->setObjectName("chevorletSales");
        chevorletSales->setFont(font2);

        verticalLayout_21->addWidget(chevorletSales);

        chevorletOnMonth = new QLabel(page_13);
        chevorletOnMonth->setObjectName("chevorletOnMonth");
        chevorletOnMonth->setFont(font2);

        verticalLayout_21->addWidget(chevorletOnMonth);


        horizontalLayout_11->addLayout(verticalLayout_21);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 1);
        horizontalLayout_11->setStretch(2, 5);
        brandInfoStack->addWidget(page_13);
        page_14 = new QWidget();
        page_14->setObjectName("page_14");
        horizontalLayout_12 = new QHBoxLayout(page_14);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_16 = new QLabel(page_14);
        label_16->setObjectName("label_16");
        label_16->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/kg.png);"));

        horizontalLayout_12->addWidget(label_16);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName("verticalLayout_22");
        ds_6 = new QLabel(page_14);
        ds_6->setObjectName("ds_6");
        ds_6->setFont(font2);

        verticalLayout_22->addWidget(ds_6);

        label_15 = new QLabel(page_14);
        label_15->setObjectName("label_15");
        label_15->setFont(font2);

        verticalLayout_22->addWidget(label_15);


        horizontalLayout_12->addLayout(verticalLayout_22);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName("verticalLayout_23");
        kgSales = new QLabel(page_14);
        kgSales->setObjectName("kgSales");
        kgSales->setFont(font2);

        verticalLayout_23->addWidget(kgSales);

        kgOnMonth = new QLabel(page_14);
        kgOnMonth->setObjectName("kgOnMonth");
        kgOnMonth->setFont(font2);

        verticalLayout_23->addWidget(kgOnMonth);


        horizontalLayout_12->addLayout(verticalLayout_23);

        horizontalLayout_12->setStretch(0, 1);
        horizontalLayout_12->setStretch(1, 1);
        horizontalLayout_12->setStretch(2, 5);
        brandInfoStack->addWidget(page_14);
        page_19 = new QWidget();
        page_19->setObjectName("page_19");
        horizontalLayout_13 = new QHBoxLayout(page_19);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_18 = new QLabel(page_19);
        label_18->setObjectName("label_18");
        label_18->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/renault.png);"));

        horizontalLayout_13->addWidget(label_18);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName("verticalLayout_24");
        ds_7 = new QLabel(page_19);
        ds_7->setObjectName("ds_7");
        ds_7->setFont(font2);

        verticalLayout_24->addWidget(ds_7);

        label_17 = new QLabel(page_19);
        label_17->setObjectName("label_17");
        label_17->setFont(font2);

        verticalLayout_24->addWidget(label_17);


        horizontalLayout_13->addLayout(verticalLayout_24);

        verticalLayout_25 = new QVBoxLayout();
        verticalLayout_25->setObjectName("verticalLayout_25");
        renaultSales = new QLabel(page_19);
        renaultSales->setObjectName("renaultSales");
        renaultSales->setFont(font2);

        verticalLayout_25->addWidget(renaultSales);

        renaultOnMonth = new QLabel(page_19);
        renaultOnMonth->setObjectName("renaultOnMonth");
        renaultOnMonth->setFont(font2);

        verticalLayout_25->addWidget(renaultOnMonth);


        horizontalLayout_13->addLayout(verticalLayout_25);

        horizontalLayout_13->setStretch(0, 1);
        horizontalLayout_13->setStretch(1, 1);
        horizontalLayout_13->setStretch(2, 5);
        brandInfoStack->addWidget(page_19);
        page_20 = new QWidget();
        page_20->setObjectName("page_20");
        horizontalLayout_14 = new QHBoxLayout(page_20);
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_20 = new QLabel(page_20);
        label_20->setObjectName("label_20");
        label_20->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/bmw.png);"));

        horizontalLayout_14->addWidget(label_20);

        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName("verticalLayout_26");
        ds_8 = new QLabel(page_20);
        ds_8->setObjectName("ds_8");
        ds_8->setFont(font2);

        verticalLayout_26->addWidget(ds_8);

        label_19 = new QLabel(page_20);
        label_19->setObjectName("label_19");
        label_19->setFont(font2);

        verticalLayout_26->addWidget(label_19);


        horizontalLayout_14->addLayout(verticalLayout_26);

        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setObjectName("verticalLayout_27");
        bmwSales = new QLabel(page_20);
        bmwSales->setObjectName("bmwSales");
        bmwSales->setFont(font2);

        verticalLayout_27->addWidget(bmwSales);

        bmwOnMonth = new QLabel(page_20);
        bmwOnMonth->setObjectName("bmwOnMonth");
        bmwOnMonth->setFont(font2);

        verticalLayout_27->addWidget(bmwOnMonth);


        horizontalLayout_14->addLayout(verticalLayout_27);

        horizontalLayout_14->setStretch(0, 1);
        horizontalLayout_14->setStretch(1, 1);
        horizontalLayout_14->setStretch(2, 5);
        brandInfoStack->addWidget(page_20);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        horizontalLayout_6 = new QHBoxLayout(page_7);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(9, -1, -1, -1);
        label_22 = new QLabel(page_7);
        label_22->setObjectName("label_22");
        label_22->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/benz.png);"));

        horizontalLayout_6->addWidget(label_22);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        ds_9 = new QLabel(page_7);
        ds_9->setObjectName("ds_9");
        ds_9->setFont(font2);

        verticalLayout_10->addWidget(ds_9);

        label_21 = new QLabel(page_7);
        label_21->setObjectName("label_21");
        label_21->setFont(font2);

        verticalLayout_10->addWidget(label_21);


        horizontalLayout_6->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        benzSales = new QLabel(page_7);
        benzSales->setObjectName("benzSales");
        benzSales->setFont(font2);

        verticalLayout_11->addWidget(benzSales);

        benzOnMonth = new QLabel(page_7);
        benzOnMonth->setObjectName("benzOnMonth");
        benzOnMonth->setFont(font2);

        verticalLayout_11->addWidget(benzOnMonth);


        horizontalLayout_6->addLayout(verticalLayout_11);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 5);
        brandInfoStack->addWidget(page_7);
        page_21 = new QWidget();
        page_21->setObjectName("page_21");
        horizontalLayout_9 = new QHBoxLayout(page_21);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_25 = new QLabel(page_21);
        label_25->setObjectName("label_25");
        label_25->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/audi.png);"));

        horizontalLayout_9->addWidget(label_25);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        ds_10 = new QLabel(page_21);
        ds_10->setObjectName("ds_10");
        ds_10->setFont(font2);

        verticalLayout_16->addWidget(ds_10);

        label_23 = new QLabel(page_21);
        label_23->setObjectName("label_23");
        label_23->setFont(font2);

        verticalLayout_16->addWidget(label_23);


        horizontalLayout_9->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName("verticalLayout_17");
        audiSales = new QLabel(page_21);
        audiSales->setObjectName("audiSales");
        audiSales->setFont(font2);

        verticalLayout_17->addWidget(audiSales);

        audiOnMonth = new QLabel(page_21);
        audiOnMonth->setObjectName("audiOnMonth");
        audiOnMonth->setFont(font2);

        verticalLayout_17->addWidget(audiOnMonth);


        horizontalLayout_9->addLayout(verticalLayout_17);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 5);
        brandInfoStack->addWidget(page_21);
        page_22 = new QWidget();
        page_22->setObjectName("page_22");
        horizontalLayout_7 = new QHBoxLayout(page_22);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_27 = new QLabel(page_22);
        label_27->setObjectName("label_27");
        label_27->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/lexus.png);"));

        horizontalLayout_7->addWidget(label_27);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        ds_11 = new QLabel(page_22);
        ds_11->setObjectName("ds_11");
        ds_11->setFont(font2);

        verticalLayout_13->addWidget(ds_11);

        label_26 = new QLabel(page_22);
        label_26->setObjectName("label_26");
        label_26->setFont(font2);

        verticalLayout_13->addWidget(label_26);


        horizontalLayout_7->addLayout(verticalLayout_13);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        lexusSales = new QLabel(page_22);
        lexusSales->setObjectName("lexusSales");
        lexusSales->setFont(font2);

        verticalLayout_12->addWidget(lexusSales);

        lexusOnMonth = new QLabel(page_22);
        lexusOnMonth->setObjectName("lexusOnMonth");
        lexusOnMonth->setFont(font2);

        verticalLayout_12->addWidget(lexusOnMonth);


        horizontalLayout_7->addLayout(verticalLayout_12);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 5);
        brandInfoStack->addWidget(page_22);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayout_8 = new QHBoxLayout(page_2);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/resources/porsche.png);"));

        horizontalLayout_8->addWidget(label);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        ds = new QLabel(page_2);
        ds->setObjectName("ds");
        ds->setFont(font2);

        verticalLayout_14->addWidget(ds);

        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font2);

        verticalLayout_14->addWidget(label_3);


        horizontalLayout_8->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName("verticalLayout_15");
        porscheSales = new QLabel(page_2);
        porscheSales->setObjectName("porscheSales");
        porscheSales->setFont(font2);

        verticalLayout_15->addWidget(porscheSales);

        porscheOnMonth = new QLabel(page_2);
        porscheOnMonth->setObjectName("porscheOnMonth");
        porscheOnMonth->setFont(font2);

        verticalLayout_15->addWidget(porscheOnMonth);


        horizontalLayout_8->addLayout(verticalLayout_15);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 5);
        brandInfoStack->addWidget(page_2);
        page_23 = new QWidget();
        page_23->setObjectName("page_23");
        brandInfoStack->addWidget(page_23);

        verticalLayout->addWidget(brandInfoStack);

        contentStack = new QStackedWidget(BrandTab);
        contentStack->setObjectName("contentStack");
        page_17 = new QWidget();
        page_17->setObjectName("page_17");
        verticalLayout_4 = new QVBoxLayout(page_17);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        specificBrandTable = new QTableWidget(page_17);
        if (specificBrandTable->columnCount() < 3)
            specificBrandTable->setColumnCount(3);
        QFont font3;
        font3.setHintingPreference(QFont::PreferVerticalHinting);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font3);
        specificBrandTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        specificBrandTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        specificBrandTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        specificBrandTable->setObjectName("specificBrandTable");
        specificBrandTable->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);"));
        specificBrandTable->setShowGrid(true);
        specificBrandTable->horizontalHeader()->setCascadingSectionResizes(false);
        specificBrandTable->horizontalHeader()->setDefaultSectionSize(190);
        specificBrandTable->horizontalHeader()->setHighlightSections(true);
        specificBrandTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        specificBrandTable->horizontalHeader()->setStretchLastSection(true);
        specificBrandTable->verticalHeader()->setCascadingSectionResizes(false);
        specificBrandTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        specificBrandTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout_4->addWidget(specificBrandTable);

        contentStack->addWidget(page_17);
        page_18 = new QWidget();
        page_18->setObjectName("page_18");
        verticalLayout_5 = new QVBoxLayout(page_18);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        domesticTable = new QTableWidget(page_18);
        if (domesticTable->columnCount() < 3)
            domesticTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem3->setFont(font);
        domesticTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QFont font4;
        font4.setPointSize(10);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem4->setFont(font4);
        domesticTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem5->setFont(font4);
        domesticTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        domesticTable->setObjectName("domesticTable");
        domesticTable->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);"));
        domesticTable->setShowGrid(true);
        domesticTable->horizontalHeader()->setCascadingSectionResizes(false);
        domesticTable->horizontalHeader()->setDefaultSectionSize(190);
        domesticTable->horizontalHeader()->setHighlightSections(true);
        domesticTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        domesticTable->horizontalHeader()->setStretchLastSection(true);
        domesticTable->verticalHeader()->setCascadingSectionResizes(false);
        domesticTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        domesticTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout_5->addWidget(domesticTable);

        overseasTable = new QTableWidget(page_18);
        if (overseasTable->columnCount() < 3)
            overseasTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem6->setFont(font);
        overseasTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem7->setFont(font4);
        overseasTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QFont font5;
        font5.setPointSize(10);
        font5.setHintingPreference(QFont::PreferVerticalHinting);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setTextAlignment(Qt::AlignTrailing|Qt::AlignVCenter);
        __qtablewidgetitem8->setFont(font5);
        overseasTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        overseasTable->setObjectName("overseasTable");
        overseasTable->setStyleSheet(QString::fromUtf8("color: rgb(3, 3, 3);"));
        overseasTable->setShowGrid(true);
        overseasTable->horizontalHeader()->setCascadingSectionResizes(false);
        overseasTable->horizontalHeader()->setDefaultSectionSize(190);
        overseasTable->horizontalHeader()->setHighlightSections(true);
        overseasTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        overseasTable->horizontalHeader()->setStretchLastSection(true);
        overseasTable->verticalHeader()->setCascadingSectionResizes(false);
        overseasTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        overseasTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout_5->addWidget(overseasTable);

        contentStack->addWidget(page_18);

        verticalLayout->addWidget(contentStack);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        verticalLayout->setStretch(2, 4);
        verticalLayout->setStretch(3, 20);

        retranslateUi(BrandTab);
        QObject::connect(monthIndex, SIGNAL(currentIndexChanged(int)), BrandTab, SLOT(monthIndexChanged()));
        QObject::connect(searchButtion, SIGNAL(clicked()), BrandTab, SLOT(searchButtonClicked()));
        QObject::connect(durationPick, SIGNAL(clicked()), BrandTab, SLOT(durationPickButtonClicked()));
        QObject::connect(monthPick, SIGNAL(clicked()), BrandTab, SLOT(hyundaiButttonClicked()));

        dateStack->setCurrentIndex(0);
        monthIndex->setCurrentIndex(11);
        monthIndex1->setCurrentIndex(10);
        monthIndex2->setCurrentIndex(11);
        brandInfoStack->setCurrentIndex(6);
        contentStack->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BrandTab);
    } // setupUi

    void retranslateUi(QWidget *BrandTab)
    {
        BrandTab->setWindowTitle(QCoreApplication::translate("BrandTab", "Widget", nullptr));
        monthPick->setText(QCoreApplication::translate("BrandTab", "\354\233\224 \354\204\240\355\203\235", nullptr));
        durationPick->setText(QCoreApplication::translate("BrandTab", "\352\270\260\352\260\204 \354\204\240\355\203\235", nullptr));
        yearIndex->setItemText(0, QCoreApplication::translate("BrandTab", "2023\353\205\204", nullptr));

        monthIndex->setItemText(0, QCoreApplication::translate("BrandTab", "1\354\233\224", nullptr));
        monthIndex->setItemText(1, QCoreApplication::translate("BrandTab", "2\354\233\224", nullptr));
        monthIndex->setItemText(2, QCoreApplication::translate("BrandTab", "3\354\233\224", nullptr));
        monthIndex->setItemText(3, QCoreApplication::translate("BrandTab", "4\354\233\224", nullptr));
        monthIndex->setItemText(4, QCoreApplication::translate("BrandTab", "5\354\233\224", nullptr));
        monthIndex->setItemText(5, QCoreApplication::translate("BrandTab", "6\354\233\224", nullptr));
        monthIndex->setItemText(6, QCoreApplication::translate("BrandTab", "7\354\233\224", nullptr));
        monthIndex->setItemText(7, QCoreApplication::translate("BrandTab", "8\354\233\224", nullptr));
        monthIndex->setItemText(8, QCoreApplication::translate("BrandTab", "9\354\233\224", nullptr));
        monthIndex->setItemText(9, QCoreApplication::translate("BrandTab", "10\354\233\224", nullptr));
        monthIndex->setItemText(10, QCoreApplication::translate("BrandTab", "11\354\233\224", nullptr));
        monthIndex->setItemText(11, QCoreApplication::translate("BrandTab", "12\354\233\224", nullptr));

        yearIndex1->setItemText(0, QCoreApplication::translate("BrandTab", "2023\353\205\204", nullptr));

        monthIndex1->setItemText(0, QCoreApplication::translate("BrandTab", "1\354\233\224", nullptr));
        monthIndex1->setItemText(1, QCoreApplication::translate("BrandTab", "2\354\233\224", nullptr));
        monthIndex1->setItemText(2, QCoreApplication::translate("BrandTab", "3\354\233\224", nullptr));
        monthIndex1->setItemText(3, QCoreApplication::translate("BrandTab", "4\354\233\224", nullptr));
        monthIndex1->setItemText(4, QCoreApplication::translate("BrandTab", "5\354\233\224", nullptr));
        monthIndex1->setItemText(5, QCoreApplication::translate("BrandTab", "6\354\233\224", nullptr));
        monthIndex1->setItemText(6, QCoreApplication::translate("BrandTab", "7\354\233\224", nullptr));
        monthIndex1->setItemText(7, QCoreApplication::translate("BrandTab", "8\354\233\224", nullptr));
        monthIndex1->setItemText(8, QCoreApplication::translate("BrandTab", "9\354\233\224", nullptr));
        monthIndex1->setItemText(9, QCoreApplication::translate("BrandTab", "10\354\233\224", nullptr));
        monthIndex1->setItemText(10, QCoreApplication::translate("BrandTab", "11\354\233\224", nullptr));
        monthIndex1->setItemText(11, QCoreApplication::translate("BrandTab", "12\354\233\224", nullptr));

        label_24->setText(QCoreApplication::translate("BrandTab", "~", nullptr));
        yearIndex2->setItemText(0, QCoreApplication::translate("BrandTab", "2023\353\205\204", nullptr));

        monthIndex2->setItemText(0, QCoreApplication::translate("BrandTab", "1\354\233\224", nullptr));
        monthIndex2->setItemText(1, QCoreApplication::translate("BrandTab", "2\354\233\224", nullptr));
        monthIndex2->setItemText(2, QCoreApplication::translate("BrandTab", "3\354\233\224", nullptr));
        monthIndex2->setItemText(3, QCoreApplication::translate("BrandTab", "4\354\233\224", nullptr));
        monthIndex2->setItemText(4, QCoreApplication::translate("BrandTab", "5\354\233\224", nullptr));
        monthIndex2->setItemText(5, QCoreApplication::translate("BrandTab", "6\354\233\224", nullptr));
        monthIndex2->setItemText(6, QCoreApplication::translate("BrandTab", "7\354\233\224", nullptr));
        monthIndex2->setItemText(7, QCoreApplication::translate("BrandTab", "8\354\233\224", nullptr));
        monthIndex2->setItemText(8, QCoreApplication::translate("BrandTab", "9\354\233\224", nullptr));
        monthIndex2->setItemText(9, QCoreApplication::translate("BrandTab", "10\354\233\224", nullptr));
        monthIndex2->setItemText(10, QCoreApplication::translate("BrandTab", "11\354\233\224", nullptr));
        monthIndex2->setItemText(11, QCoreApplication::translate("BrandTab", "12\354\233\224", nullptr));

        searchButtion->setText(QCoreApplication::translate("BrandTab", "\354\241\260\355\232\214", nullptr));
        label_2->setText(QString());
        ds_2->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_4->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        hyundaiSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        hyundaiOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_10->setText(QString());
        ds_3->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_9->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        kiaSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        kiaOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_12->setText(QString());
        ds_4->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_11->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        genesisSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        genesisOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_14->setText(QString());
        ds_5->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_13->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        chevorletSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        chevorletOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_16->setText(QString());
        ds_6->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_15->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        kgSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        kgOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_18->setText(QString());
        ds_7->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_17->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        renaultSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        renaultOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_20->setText(QString());
        ds_8->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_19->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        bmwSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        bmwOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_22->setText(QString());
        ds_9->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_21->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        benzSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        benzOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_25->setText(QString());
        ds_10->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_23->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        audiSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        audiOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label_27->setText(QString());
        ds_11->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_26->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        lexusSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        lexusOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        label->setText(QString());
        ds->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        label_3->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        porscheSales->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        porscheOnMonth->setText(QCoreApplication::translate("BrandTab", "\354\240\204\354\233\224 (\353\214\200\353\271\204)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = specificBrandTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("BrandTab", "\353\252\250\353\215\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = specificBrandTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("BrandTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = specificBrandTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("BrandTab", "\354\240\220\354\234\240\354\234\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = domesticTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("BrandTab", "\352\265\255\354\202\260\354\260\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = domesticTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("BrandTab", "\354\264\235\355\225\251 : ", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = domesticTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("BrandTab", "\353\214\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = overseasTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("BrandTab", "\354\210\230\354\236\205\354\260\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = overseasTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("BrandTab", "\354\264\235\355\225\251 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = overseasTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("BrandTab", "\353\214\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BrandTab: public Ui_BrandTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRANDTAB_H
