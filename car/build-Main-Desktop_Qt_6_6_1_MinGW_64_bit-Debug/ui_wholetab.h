/********************************************************************************
** Form generated from reading UI file 'wholetab.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WHOLETAB_H
#define UI_WHOLETAB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WholeTab
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *Session_Tab;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *Select_Years_ComboBox;
    QComboBox *Select_Month_ComboBox;
    QPushButton *Select_Ask_PushButton;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QComboBox *Session_Year_First_ComboBox;
    QComboBox *Session_Month_First_ComboBox;
    QLabel *label;
    QComboBox *Session_Year_Last_ComboBox;
    QComboBox *Session_Month_Last_ComboBox;
    QPushButton *Session_Ask_PushButton;
    QPushButton *Brand_PushButton;
    QTabWidget *Brand_Car_Tab;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *Brand_Car_Korea;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *Brand_Car_Foreign;
    QPushButton *Model_PushButton;
    QTabWidget *Model_Car_Tab;
    QWidget *tab_5;
    QTableWidget *Model_Car_Korea;
    QWidget *tab_6;
    QTableWidget *Model_Car_Foreign;
    QWidget *page_2;

    void setupUi(QWidget *WholeTab)
    {
        if (WholeTab->objectName().isEmpty())
            WholeTab->setObjectName("WholeTab");
        WholeTab->resize(816, 886);
        verticalLayout = new QVBoxLayout(WholeTab);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(WholeTab);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Session_Tab = new QTabWidget(page);
        Session_Tab->setObjectName("Session_Tab");
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(300, 0, 300, 0);
        Select_Years_ComboBox = new QComboBox(tab);
        Select_Years_ComboBox->addItem(QString());
        Select_Years_ComboBox->setObjectName("Select_Years_ComboBox");

        horizontalLayout_2->addWidget(Select_Years_ComboBox);

        Select_Month_ComboBox = new QComboBox(tab);
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->addItem(QString());
        Select_Month_ComboBox->setObjectName("Select_Month_ComboBox");

        horizontalLayout_2->addWidget(Select_Month_ComboBox);

        Select_Ask_PushButton = new QPushButton(tab);
        Select_Ask_PushButton->setObjectName("Select_Ask_PushButton");

        horizontalLayout_2->addWidget(Select_Ask_PushButton);

        Session_Tab->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        verticalLayout_3 = new QVBoxLayout(tab_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(200, -1, 200, -1);
        Session_Year_First_ComboBox = new QComboBox(tab_2);
        Session_Year_First_ComboBox->addItem(QString());
        Session_Year_First_ComboBox->setObjectName("Session_Year_First_ComboBox");

        horizontalLayout->addWidget(Session_Year_First_ComboBox);

        Session_Month_First_ComboBox = new QComboBox(tab_2);
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->addItem(QString());
        Session_Month_First_ComboBox->setObjectName("Session_Month_First_ComboBox");

        horizontalLayout->addWidget(Session_Month_First_ComboBox);

        label = new QLabel(tab_2);
        label->setObjectName("label");
        QFont font;
        font.setBold(true);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        Session_Year_Last_ComboBox = new QComboBox(tab_2);
        Session_Year_Last_ComboBox->addItem(QString());
        Session_Year_Last_ComboBox->setObjectName("Session_Year_Last_ComboBox");

        horizontalLayout->addWidget(Session_Year_Last_ComboBox);

        Session_Month_Last_ComboBox = new QComboBox(tab_2);
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->addItem(QString());
        Session_Month_Last_ComboBox->setObjectName("Session_Month_Last_ComboBox");

        horizontalLayout->addWidget(Session_Month_Last_ComboBox);

        Session_Ask_PushButton = new QPushButton(tab_2);
        Session_Ask_PushButton->setObjectName("Session_Ask_PushButton");

        horizontalLayout->addWidget(Session_Ask_PushButton);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 3);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 5);
        horizontalLayout->setStretch(4, 3);
        horizontalLayout->setStretch(5, 3);

        verticalLayout_3->addLayout(horizontalLayout);

        Session_Tab->addTab(tab_2, QString());

        verticalLayout_2->addWidget(Session_Tab);

        Brand_PushButton = new QPushButton(page);
        Brand_PushButton->setObjectName("Brand_PushButton");
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        Brand_PushButton->setFont(font1);
        Brand_PushButton->setAutoDefault(true);
        Brand_PushButton->setFlat(true);

        verticalLayout_2->addWidget(Brand_PushButton);

        Brand_Car_Tab = new QTabWidget(page);
        Brand_Car_Tab->setObjectName("Brand_Car_Tab");
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        verticalLayout_5 = new QVBoxLayout(tab_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        Brand_Car_Korea = new QTableWidget(tab_3);
        if (Brand_Car_Korea->columnCount() < 3)
            Brand_Car_Korea->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        Brand_Car_Korea->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        Brand_Car_Korea->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        Brand_Car_Korea->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        Brand_Car_Korea->setObjectName("Brand_Car_Korea");
        Brand_Car_Korea->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Brand_Car_Korea->horizontalHeader()->setDefaultSectionSize(30);
        Brand_Car_Korea->horizontalHeader()->setHighlightSections(false);
        Brand_Car_Korea->horizontalHeader()->setStretchLastSection(true);
        Brand_Car_Korea->verticalHeader()->setHighlightSections(false);

        verticalLayout_5->addWidget(Brand_Car_Korea);

        Brand_Car_Tab->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        verticalLayout_4 = new QVBoxLayout(tab_4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        Brand_Car_Foreign = new QTableWidget(tab_4);
        if (Brand_Car_Foreign->columnCount() < 3)
            Brand_Car_Foreign->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        Brand_Car_Foreign->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        Brand_Car_Foreign->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        Brand_Car_Foreign->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        Brand_Car_Foreign->setObjectName("Brand_Car_Foreign");
        Brand_Car_Foreign->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Brand_Car_Foreign->horizontalHeader()->setDefaultSectionSize(30);
        Brand_Car_Foreign->horizontalHeader()->setHighlightSections(false);
        Brand_Car_Foreign->horizontalHeader()->setStretchLastSection(true);
        Brand_Car_Foreign->verticalHeader()->setHighlightSections(false);

        verticalLayout_4->addWidget(Brand_Car_Foreign);

        Brand_Car_Tab->addTab(tab_4, QString());

        verticalLayout_2->addWidget(Brand_Car_Tab);

        Model_PushButton = new QPushButton(page);
        Model_PushButton->setObjectName("Model_PushButton");
        Model_PushButton->setFont(font1);
        Model_PushButton->setAutoDefault(true);
        Model_PushButton->setFlat(true);

        verticalLayout_2->addWidget(Model_PushButton);

        Model_Car_Tab = new QTabWidget(page);
        Model_Car_Tab->setObjectName("Model_Car_Tab");
        Model_Car_Tab->setMouseTracking(false);
        Model_Car_Tab->setTabletTracking(false);
        Model_Car_Tab->setFocusPolicy(Qt::TabFocus);
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        Model_Car_Korea = new QTableWidget(tab_5);
        if (Model_Car_Korea->columnCount() < 3)
            Model_Car_Korea->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        Model_Car_Korea->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        Model_Car_Korea->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        Model_Car_Korea->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        Model_Car_Korea->setObjectName("Model_Car_Korea");
        Model_Car_Korea->setGeometry(QRect(0, 0, 811, 191));
        Model_Car_Korea->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Model_Car_Korea->horizontalHeader()->setDefaultSectionSize(30);
        Model_Car_Korea->horizontalHeader()->setHighlightSections(false);
        Model_Car_Korea->horizontalHeader()->setStretchLastSection(true);
        Model_Car_Korea->verticalHeader()->setHighlightSections(false);
        Model_Car_Tab->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        Model_Car_Foreign = new QTableWidget(tab_6);
        if (Model_Car_Foreign->columnCount() < 3)
            Model_Car_Foreign->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        Model_Car_Foreign->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        Model_Car_Foreign->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        Model_Car_Foreign->setHorizontalHeaderItem(2, __qtablewidgetitem11);
        Model_Car_Foreign->setObjectName("Model_Car_Foreign");
        Model_Car_Foreign->setGeometry(QRect(0, 0, 811, 401));
        Model_Car_Foreign->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Model_Car_Foreign->horizontalHeader()->setDefaultSectionSize(30);
        Model_Car_Foreign->horizontalHeader()->setHighlightSections(false);
        Model_Car_Foreign->horizontalHeader()->setStretchLastSection(true);
        Model_Car_Foreign->verticalHeader()->setHighlightSections(false);
        Model_Car_Tab->addTab(tab_6, QString());

        verticalLayout_2->addWidget(Model_Car_Tab);

        verticalLayout_2->setStretch(0, 2);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 4);
        verticalLayout_2->setStretch(3, 1);
        verticalLayout_2->setStretch(4, 8);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(WholeTab);

        stackedWidget->setCurrentIndex(0);
        Session_Tab->setCurrentIndex(0);
        Brand_Car_Tab->setCurrentIndex(1);
        Model_Car_Tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WholeTab);
    } // setupUi

    void retranslateUi(QWidget *WholeTab)
    {
        WholeTab->setWindowTitle(QCoreApplication::translate("WholeTab", "Widget", nullptr));
        Select_Years_ComboBox->setItemText(0, QCoreApplication::translate("WholeTab", "2023\353\205\204", nullptr));

        Select_Month_ComboBox->setItemText(0, QCoreApplication::translate("WholeTab", "1\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(1, QCoreApplication::translate("WholeTab", "2\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(2, QCoreApplication::translate("WholeTab", "3\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(3, QCoreApplication::translate("WholeTab", "4\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(4, QCoreApplication::translate("WholeTab", "5\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(5, QCoreApplication::translate("WholeTab", "6\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(6, QCoreApplication::translate("WholeTab", "7\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(7, QCoreApplication::translate("WholeTab", "8\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(8, QCoreApplication::translate("WholeTab", "9\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(9, QCoreApplication::translate("WholeTab", "10\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(10, QCoreApplication::translate("WholeTab", "11\354\233\224", nullptr));
        Select_Month_ComboBox->setItemText(11, QCoreApplication::translate("WholeTab", "12\354\233\224", nullptr));

        Select_Ask_PushButton->setText(QCoreApplication::translate("WholeTab", "\354\241\260\355\232\214", nullptr));
        Session_Tab->setTabText(Session_Tab->indexOf(tab), QCoreApplication::translate("WholeTab", "\354\233\224 \354\204\240\355\203\235", nullptr));
        Session_Year_First_ComboBox->setItemText(0, QCoreApplication::translate("WholeTab", "2023\353\205\204", nullptr));

        Session_Month_First_ComboBox->setItemText(0, QCoreApplication::translate("WholeTab", "1\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(1, QCoreApplication::translate("WholeTab", "2\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(2, QCoreApplication::translate("WholeTab", "3\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(3, QCoreApplication::translate("WholeTab", "4\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(4, QCoreApplication::translate("WholeTab", "5\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(5, QCoreApplication::translate("WholeTab", "6\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(6, QCoreApplication::translate("WholeTab", "7\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(7, QCoreApplication::translate("WholeTab", "8\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(8, QCoreApplication::translate("WholeTab", "9\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(9, QCoreApplication::translate("WholeTab", "10\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(10, QCoreApplication::translate("WholeTab", "11\354\233\224", nullptr));
        Session_Month_First_ComboBox->setItemText(11, QCoreApplication::translate("WholeTab", "12\354\233\224", nullptr));

        label->setText(QCoreApplication::translate("WholeTab", "~", nullptr));
        Session_Year_Last_ComboBox->setItemText(0, QCoreApplication::translate("WholeTab", "2023\353\205\204", nullptr));

        Session_Month_Last_ComboBox->setItemText(0, QCoreApplication::translate("WholeTab", "1\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(1, QCoreApplication::translate("WholeTab", "2\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(2, QCoreApplication::translate("WholeTab", "3\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(3, QCoreApplication::translate("WholeTab", "4\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(4, QCoreApplication::translate("WholeTab", "5\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(5, QCoreApplication::translate("WholeTab", "6\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(6, QCoreApplication::translate("WholeTab", "7\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(7, QCoreApplication::translate("WholeTab", "8\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(8, QCoreApplication::translate("WholeTab", "9\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(9, QCoreApplication::translate("WholeTab", "10\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(10, QCoreApplication::translate("WholeTab", "11\354\233\224", nullptr));
        Session_Month_Last_ComboBox->setItemText(11, QCoreApplication::translate("WholeTab", "12\354\233\224", nullptr));

        Session_Ask_PushButton->setText(QCoreApplication::translate("WholeTab", "\354\241\260\355\232\214", nullptr));
        Session_Tab->setTabText(Session_Tab->indexOf(tab_2), QCoreApplication::translate("WholeTab", "\352\270\260\352\260\204 \354\204\240\355\203\235", nullptr));
        Brand_PushButton->setText(QCoreApplication::translate("WholeTab", "\353\270\214\353\236\234\353\223\234\353\263\204 Top 5", nullptr));
        QTableWidgetItem *___qtablewidgetitem = Brand_Car_Korea->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("WholeTab", "\355\232\214\354\202\254\353\252\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = Brand_Car_Korea->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("WholeTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = Brand_Car_Korea->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("WholeTab", "\354\240\220\354\234\240\354\234\250", nullptr));
        Brand_Car_Tab->setTabText(Brand_Car_Tab->indexOf(tab_3), QCoreApplication::translate("WholeTab", "\352\265\255\354\202\260\354\260\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = Brand_Car_Foreign->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("WholeTab", "\355\232\214\354\202\254\353\252\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = Brand_Car_Foreign->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("WholeTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = Brand_Car_Foreign->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("WholeTab", "\354\240\220\354\234\240\354\234\250", nullptr));
        Brand_Car_Tab->setTabText(Brand_Car_Tab->indexOf(tab_4), QCoreApplication::translate("WholeTab", "\354\210\230\354\236\205\354\260\250", nullptr));
        Model_PushButton->setText(QCoreApplication::translate("WholeTab", "\353\252\250\353\215\270\353\263\204 Top 10", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = Model_Car_Korea->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("WholeTab", "\354\260\250\353\237\211\353\252\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = Model_Car_Korea->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("WholeTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = Model_Car_Korea->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("WholeTab", "\354\240\204\354\233\224\353\214\200\353\271\204\355\214\220\353\247\244\353\237\211", nullptr));
        Model_Car_Tab->setTabText(Model_Car_Tab->indexOf(tab_5), QCoreApplication::translate("WholeTab", "\352\265\255\354\202\260\354\260\250", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = Model_Car_Foreign->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("WholeTab", "\354\260\250\353\237\211\353\252\205", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = Model_Car_Foreign->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("WholeTab", "\355\214\220\353\247\244\353\237\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = Model_Car_Foreign->horizontalHeaderItem(2);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("WholeTab", "\354\240\204\354\233\224\353\214\200\353\271\204\355\214\220\353\247\244\353\237\211", nullptr));
        Model_Car_Tab->setTabText(Model_Car_Tab->indexOf(tab_6), QCoreApplication::translate("WholeTab", "\354\210\230\354\236\205\354\260\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WholeTab: public Ui_WholeTab {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WHOLETAB_H
