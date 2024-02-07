/********************************************************************************
** Form generated from reading UI file 'modeltab.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELTAB_H
#define UI_MODELTAB_H

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

class Ui_ModelTab
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnMonth;
    QPushButton *btnDuration;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *mYear;
    QComboBox *mMonth;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *dYearS;
    QComboBox *dMonthS;
    QLabel *label;
    QComboBox *dYearF;
    QComboBox *dMonthF;
    QPushButton *btnShow;
    QTableWidget *tableWidget;

    void setupUi(QWidget *ModelTab)
    {
        if (ModelTab->objectName().isEmpty())
            ModelTab->setObjectName("ModelTab");
        ModelTab->resize(810, 670);
        ModelTab->setMinimumSize(QSize(810, 0));
        ModelTab->setMaximumSize(QSize(810, 16777215));
        verticalLayout = new QVBoxLayout(ModelTab);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(10);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, -1, 0, -1);
        btnMonth = new QPushButton(ModelTab);
        btnMonth->setObjectName("btnMonth");
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        btnMonth->setFont(font);
        btnMonth->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        btnMonth->setAutoRepeatDelay(300);
        btnMonth->setAutoRepeatInterval(100);
        btnMonth->setAutoDefault(false);
        btnMonth->setFlat(false);

        horizontalLayout->addWidget(btnMonth);

        btnDuration = new QPushButton(ModelTab);
        btnDuration->setObjectName("btnDuration");
        btnDuration->setFont(font);
        btnDuration->setStyleSheet(QString::fromUtf8("color: rgb(11, 11, 11);\n"
"border: 1px solid;\n"
"border-color: rgb(143, 143, 143);"));
        btnDuration->setAutoDefault(false);
        btnDuration->setFlat(false);

        horizontalLayout->addWidget(btnDuration);


        verticalLayout->addLayout(horizontalLayout);

        stackedWidget = new QStackedWidget(ModelTab);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setMinimumSize(QSize(810, 0));
        stackedWidget->setMaximumSize(QSize(810, 16777215));
        page = new QWidget();
        page->setObjectName("page");
        horizontalLayout_5 = new QHBoxLayout(page);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(300, -1, 300, -1);
        mYear = new QComboBox(page);
        mYear->addItem(QString());
        mYear->setObjectName("mYear");
        mYear->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_4->addWidget(mYear);

        mMonth = new QComboBox(page);
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->addItem(QString());
        mMonth->setObjectName("mMonth");
        mMonth->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_4->addWidget(mMonth);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 3);

        horizontalLayout_5->addLayout(horizontalLayout_4);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        horizontalLayout_3 = new QHBoxLayout(page_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(200, -1, 200, 0);
        dYearS = new QComboBox(page_2);
        dYearS->addItem(QString());
        dYearS->setObjectName("dYearS");
        dYearS->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_2->addWidget(dYearS);

        dMonthS = new QComboBox(page_2);
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->addItem(QString());
        dMonthS->setObjectName("dMonthS");
        dMonthS->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_2->addWidget(dMonthS);

        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label);

        dYearF = new QComboBox(page_2);
        dYearF->addItem(QString());
        dYearF->setObjectName("dYearF");
        dYearF->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_2->addWidget(dYearF);

        dMonthF = new QComboBox(page_2);
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->addItem(QString());
        dMonthF->setObjectName("dMonthF");
        dMonthF->setStyleSheet(QString::fromUtf8("border: 1.2px solid;\n"
"border-color: rgb(150, 150, 150);"));

        horizontalLayout_2->addWidget(dMonthF);

        btnShow = new QPushButton(page_2);
        btnShow->setObjectName("btnShow");

        horizontalLayout_2->addWidget(btnShow);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 3);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 5);
        horizontalLayout_2->setStretch(4, 3);
        horizontalLayout_2->setStretch(5, 3);

        horizontalLayout_3->addLayout(horizontalLayout_2);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);

        tableWidget = new QTableWidget(ModelTab);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setTabKeyNavigation(false);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setWordWrap(true);
        tableWidget->setCornerButtonEnabled(true);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tableWidget->horizontalHeader()->setDefaultSectionSize(34);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(true);
        tableWidget->verticalHeader()->setHighlightSections(false);

        verticalLayout->addWidget(tableWidget);

        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 8);

        retranslateUi(ModelTab);
        QObject::connect(btnMonth, SIGNAL(clicked()), ModelTab, SLOT(btnMonthClicked()));
        QObject::connect(btnDuration, SIGNAL(clicked()), ModelTab, SLOT(btnDurationClicked()));
        QObject::connect(mMonth, SIGNAL(currentIndexChanged(int)), ModelTab, SLOT(mMonthCurrentIndexChanged(int)));
        QObject::connect(btnShow, SIGNAL(clicked()), ModelTab, SLOT(btnShowClicked()));

        stackedWidget->setCurrentIndex(0);
        mMonth->setCurrentIndex(0);
        dMonthS->setCurrentIndex(0);
        dMonthF->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ModelTab);
    } // setupUi

    void retranslateUi(QWidget *ModelTab)
    {
        ModelTab->setWindowTitle(QCoreApplication::translate("ModelTab", "ModelTab", nullptr));
        btnMonth->setText(QCoreApplication::translate("ModelTab", "\354\233\224 \354\204\240\355\203\235", nullptr));
        btnDuration->setText(QCoreApplication::translate("ModelTab", "\352\270\260\352\260\204 \354\204\240\355\203\235", nullptr));
        mYear->setItemText(0, QCoreApplication::translate("ModelTab", "2023\353\205\204", nullptr));

        mMonth->setItemText(0, QCoreApplication::translate("ModelTab", "1\354\233\224", nullptr));
        mMonth->setItemText(1, QCoreApplication::translate("ModelTab", "2\354\233\224", nullptr));
        mMonth->setItemText(2, QCoreApplication::translate("ModelTab", "3\354\233\224", nullptr));
        mMonth->setItemText(3, QCoreApplication::translate("ModelTab", "4\354\233\224", nullptr));
        mMonth->setItemText(4, QCoreApplication::translate("ModelTab", "5\354\233\224", nullptr));
        mMonth->setItemText(5, QCoreApplication::translate("ModelTab", "6\354\233\224", nullptr));
        mMonth->setItemText(6, QCoreApplication::translate("ModelTab", "7\354\233\224", nullptr));
        mMonth->setItemText(7, QCoreApplication::translate("ModelTab", "8\354\233\224", nullptr));
        mMonth->setItemText(8, QCoreApplication::translate("ModelTab", "9\354\233\224", nullptr));
        mMonth->setItemText(9, QCoreApplication::translate("ModelTab", "10\354\233\224", nullptr));
        mMonth->setItemText(10, QCoreApplication::translate("ModelTab", "11\354\233\224", nullptr));
        mMonth->setItemText(11, QCoreApplication::translate("ModelTab", "12\354\233\224", nullptr));

        dYearS->setItemText(0, QCoreApplication::translate("ModelTab", "2023\353\205\204", nullptr));

        dMonthS->setItemText(0, QCoreApplication::translate("ModelTab", "1\354\233\224", nullptr));
        dMonthS->setItemText(1, QCoreApplication::translate("ModelTab", "2\354\233\224", nullptr));
        dMonthS->setItemText(2, QCoreApplication::translate("ModelTab", "3\354\233\224", nullptr));
        dMonthS->setItemText(3, QCoreApplication::translate("ModelTab", "4\354\233\224", nullptr));
        dMonthS->setItemText(4, QCoreApplication::translate("ModelTab", "5\354\233\224", nullptr));
        dMonthS->setItemText(5, QCoreApplication::translate("ModelTab", "6\354\233\224", nullptr));
        dMonthS->setItemText(6, QCoreApplication::translate("ModelTab", "7\354\233\224", nullptr));
        dMonthS->setItemText(7, QCoreApplication::translate("ModelTab", "8\354\233\224", nullptr));
        dMonthS->setItemText(8, QCoreApplication::translate("ModelTab", "9\354\233\224", nullptr));
        dMonthS->setItemText(9, QCoreApplication::translate("ModelTab", "10\354\233\224", nullptr));
        dMonthS->setItemText(10, QCoreApplication::translate("ModelTab", "11\354\233\224", nullptr));
        dMonthS->setItemText(11, QCoreApplication::translate("ModelTab", "12\354\233\224", nullptr));

        label->setText(QCoreApplication::translate("ModelTab", "~", nullptr));
        dYearF->setItemText(0, QCoreApplication::translate("ModelTab", "2023\353\205\204", nullptr));

        dMonthF->setItemText(0, QCoreApplication::translate("ModelTab", "1\354\233\224", nullptr));
        dMonthF->setItemText(1, QCoreApplication::translate("ModelTab", "2\354\233\224", nullptr));
        dMonthF->setItemText(2, QCoreApplication::translate("ModelTab", "3\354\233\224", nullptr));
        dMonthF->setItemText(3, QCoreApplication::translate("ModelTab", "4\354\233\224", nullptr));
        dMonthF->setItemText(4, QCoreApplication::translate("ModelTab", "5\354\233\224", nullptr));
        dMonthF->setItemText(5, QCoreApplication::translate("ModelTab", "6\354\233\224", nullptr));
        dMonthF->setItemText(6, QCoreApplication::translate("ModelTab", "7\354\233\224", nullptr));
        dMonthF->setItemText(7, QCoreApplication::translate("ModelTab", "8\354\233\224", nullptr));
        dMonthF->setItemText(8, QCoreApplication::translate("ModelTab", "9\354\233\224", nullptr));
        dMonthF->setItemText(9, QCoreApplication::translate("ModelTab", "10\354\233\224", nullptr));
        dMonthF->setItemText(10, QCoreApplication::translate("ModelTab", "11\354\233\224", nullptr));
        dMonthF->setItemText(11, QCoreApplication::translate("ModelTab", "12\354\233\224", nullptr));

        btnShow->setText(QCoreApplication::translate("ModelTab", "\354\241\260\355\232\214", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ModelTab", "\353\252\250\353\215\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ModelTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ModelTab", "\354\240\220\354\234\240\354\234\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelTab: public Ui_ModelTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELTAB_H
