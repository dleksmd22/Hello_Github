#ifndef MODELTAB_H
#define MODELTAB_H

#include <QWidget>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QTableWidgetItem>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui {
class ModelTab;
}
QT_END_NAMESPACE

class ModelTab : public QWidget
{
    Q_OBJECT

public:
    ModelTab(QWidget *parent = nullptr);
    ~ModelTab();

private slots:
    void btnMonthClicked(); //월선택 클릭
    void btnDurationClicked(); //기간선택 클릭
    void mMonthCurrentIndexChanged(int index); //월선택 - 월 변경시
    void btnShowClicked(); //기간선택  - 기간 조회시

    //메인윈도우에서 차종 선택시 호출될 슬롯함수
    void ShowDefault(); //테이블 초기상태(23.12) 출력
    //차종번호 저장
    void setCarType1();
    void setCarType2();
    void setCarType3();
    void setCarType4();
    void setCarType5();
    void setCarType6();
    void setCarType7();
    void setCarType8();
    void setCarType9();
    void setCarType10();
    void setCarType11();
    void setCarType12();

    void delCarType(); //차종번호 해제

private:
    Ui::ModelTab *ui;
    QSqlDatabase db; //DB_Car
    unsigned int typeNum; //차종번호


    void UpdateTable(QSqlQuery&);

};
#endif // MODELTAB_H
