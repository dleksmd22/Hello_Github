#ifndef WHOLETAB_H
#define WHOLETAB_H

#include <QWidget>
#include <QtSql> // db추가작업

QT_BEGIN_NAMESPACE
namespace Ui {
class WholeTab;
}
QT_END_NAMESPACE

class WholeTab : public QWidget
{
    Q_OBJECT

public:
    WholeTab(QWidget *parent = nullptr);
    ~WholeTab();

private slots:
    void on_Select_Ask_PushButton_clicked();

    void on_Session_Ask_PushButton_clicked();

private:
    Ui::WholeTab *ui;
    QSqlDatabase DB_Connection; // db추가작업

    QString ConvertBrandName(int bnum);

};
#endif // WHOLETAB_H
