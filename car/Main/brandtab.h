#ifndef BRANDTAB_H
#define BRANDTAB_H

#include <QWidget>
#include <QTableWidget>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QHash>
#include <QMessageBox>
#include <QAbstractButton>



QT_BEGIN_NAMESPACE
namespace Ui {
class BrandTab;
}
QT_END_NAMESPACE

class BrandTab: public QWidget
{
    Q_OBJECT

public:
    BrandTab(QWidget *parent = nullptr);
    ~BrandTab();

private:
    Ui::BrandTab *ui;
    QString brand;
    int searchType;


private slots:
    /*상호 slots함수 추가 */
    void insertComparedSalesData(QString month);


    void brandTapClicked();
    void monthIndexChanged();
    void monthPickButtonClicked();
    void durationPickButtonClicked();
    void searchButtonClicked();

    void hyundaiButttonClicked();
    void kiaButtonClicked();
    void genesisButtonClicked();
    void chevroletButtonClicked();
    void kgMobilityButtonClicked();
    void renaultButtonClicked();
    void bmwButtonClicked();
    void benzButtonClicked();
    void audiButtonClicked();
    void lexusButtonClicked();
    void porscheButtonClicked();

    QString monthlyTotalSalesFind(QString month, int type);
    void BrandTotalSalesByPeriodFind(QString extract1, QString extract2);
    void monthlyBrandTotalSalesFind(QString month);

    QString monthlySpecificBrandTotalSalesFind(QString month, QString brand);
    void monthlyModelTotalSalesFind(QString month, QString totalSalesData);
    void ModelTotalSalesByPeriodFind(QString extract1, QString extract2);




};
#endif // BRANDTAB_H
