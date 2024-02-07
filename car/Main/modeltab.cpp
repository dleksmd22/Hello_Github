#include "modeltab.h"
#include "ui_modeltab.h"


ModelTab::ModelTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModelTab)
{
    typeNum=0;
    ui->setupUi(this);
    // ui->stackedWidget->setCurrentIndex(0);

    // db=QSqlDatabase::addDatabase("QSQLITE");
    // db.setDatabaseName("DB_Car.db");
    // if(!db.open())
    // {
    //     qDebug()<<db.lastError()<<"데이터베이스 파일 오픈 실패!";
    // }
    // else
    // {
    //     qDebug("데이터베이스 파일 오픈");
    // }
    ShowDefault();

    //테이블 열 크기 조절
    // ui->tableWidget->setColumnWidth(0,50); //나중에 이미지
    ui->tableWidget->setColumnWidth(0,610);
    ui->tableWidget->setColumnWidth(1,70);
    ui->tableWidget->setColumnWidth(2,70);

    //테이블 내용 정렬

}

ModelTab::~ModelTab()
{
    delete ui;
}
//테이블 초기상태(23.12) 출력
void ModelTab::ShowDefault()
{
    //디폴트 화면 --23년 12월 전체 모델별 순위
    QSqlQuery qry;
    if(typeNum==0)
    {
        qry.prepare("SELECT MODEL,\"2023_12\",\"2023_12\"/TOTAL(\"2023_12\") OVER() FROM CAR_TB ORDER BY \"2023_12\" DESC");
    }
    else
    {
        qry.prepare("SELECT MODEL,\"2023_12\",\"2023_12\"/TOTAL(\"2023_12\") OVER() FROM CAR_TB WHERE CARTYPE="+QString::number(typeNum)+" ORDER BY \"2023_12\" DESC");
    }

    qry.exec();

    UpdateTable(qry);
    //ui초기화면 설정
    // ui->stackedWidget->setCurrentIndex(0);
    // ui->mMonth->setCurrentIndex(11);
    ui->btnMonth->click();
}
//월선택 클릭
void ModelTab::btnMonthClicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->mMonth->setCurrentIndex(11);
    ui->btnMonth->setStyleSheet("QPushButton {color:blue;border: 1px solid;border-color:blue;}");
    ui->btnDuration->setStyleSheet("QPushButton {color: rgb(11, 11, 11);border: 1px solid;border-color: rgb(143, 143, 143);}");
}

//기간선택 클릭
void ModelTab::btnDurationClicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->dMonthS->setCurrentIndex(10);
    ui->dMonthF->setCurrentIndex(11);
    ui->btnDuration->setStyleSheet("QPushButton {color:blue;border: 1px solid;border-color:blue;}");
    ui->btnMonth->setStyleSheet("QPushButton {color: rgb(11, 11, 11);border: 1px solid;border-color: rgb(143, 143, 143);}");
}

//테이블 갱신
void ModelTab::UpdateTable(QSqlQuery& qry)
{
    ui->tableWidget->setRowCount(0);
    //테이블에 데이터 넣을때 사용
    QString mname;
    QString sale;
    QString rate;
    QTableWidgetItem* item;
    unsigned int row=0;
    while(qry.next())
    {
        if(qry.value(1)!="0")
        {
            ui->tableWidget->insertRow(row);
            mname=qry.value(0).toString();
            item=new QTableWidgetItem(mname);
            ui->tableWidget->setItem(row,0,item);
            if(qry.value(1).toInt()>1000)
            {
                sale=QString::number(qry.value(1).toInt()/1000);
                sale.append(",");
                // sale.append(QString::number(qry.value(1).toInt()%1000));
                if(qry.value(1).toInt()%1000==0)
                {
                    sale.append("000");
                }
                else if(qry.value(1).toInt()%1000<10)
                {
                    sale.append("00");
                }
                else if(qry.value(1).toInt()%1000<100)
                {
                    sale.append("0");
                }
                sale.append(QString::number(qry.value(1).toInt()%1000));
            }
            else
            {
                sale=qry.value(1).toString();
            }
            item=new QTableWidgetItem(sale);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row,1,item);

            rate=QString::number(qry.value(2).toDouble()*100,'f',2);
            rate.append("%");
            item=new QTableWidgetItem(rate);
            item->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->setItem(row,2,item);
            row++;
        }
    }
}
//월선택 - 월 변경시
void ModelTab::mMonthCurrentIndexChanged(int index)
{
    //선택한 월의 모델별 순위 출력해야함

    QString colname="\"2023_"+QString::number(index+1)+"\"";

    QSqlQuery qry;
    if(typeNum==0)
    {
        qry.prepare("SELECT MODEL,"+colname+","+colname+"/TOTAL("+colname+") OVER() FROM CAR_TB ORDER BY "+colname+" DESC");
        // qry.prepare("SELECT MODEL,"+colname+",TOTAL("+colname+") OVER() FROM CAR_TB ORDER BY "+colname+" DESC");
    }
    else
    {
        qry.prepare("SELECT MODEL,"+colname+","+colname+"/TOTAL("+colname+") OVER() FROM CAR_TB WHERE CARTYPE="+QString::number(typeNum)+" ORDER BY "+colname+" DESC");
        // qry.prepare("SELECT MODEL,"+colname+",TOTAL("+colname+") OVER() FROM CAR_TB WHERE CARTYPE="+QString::number(typeNum)+" ORDER BY "+colname+" DESC");
    }
    qry.exec();
    UpdateTable(qry);
}

//기간선택 - 기간 조회시
void ModelTab::btnShowClicked()
{
    unsigned int smonth = ui->dMonthS->currentIndex()+1;
    unsigned int fmonth = ui->dMonthF->currentIndex()+1;
    if(smonth>fmonth) //잘못된 기간 선택시
    {
        QMessageBox::critical(this,"경고 메시지","조회 기간이 잘못되었습니다.",QMessageBox::Ok);
        return;
    }
    else if(smonth==fmonth)
    {
        ui->mMonth->setCurrentIndex(smonth-1);
        // btnMonthClicked(); //굳이 돌아가게 해야할까?ㅋㅋㅋ
        return;
    }

    //기간내 모델별 순위 출력해야함
    QString colcal="";
    for(unsigned int i=smonth;i<fmonth;++i)
    {
        colcal.append("\"2023_"+QString::number(i)+"\"");
        colcal.append("+");
    }
    colcal.append("\"2023_"+QString::number(fmonth)+"\"");

    QSqlQuery qry;

    qry.prepare("SELECT MODEL,"+colcal+",("+colcal+")/TOTAL("+colcal+") OVER() FROM CAR_TB ORDER BY "+colcal+" DESC");
    qry.exec();
    UpdateTable(qry);
}
//차종번호 저장
void ModelTab::setCarType1()
{
    typeNum=1;
    ShowDefault();
}
void ModelTab::setCarType2()
{
    typeNum=2;
    ShowDefault();
}
void ModelTab::setCarType3()
{
    typeNum=3;
    ShowDefault();
}
void ModelTab::setCarType4()
{
    typeNum=4;
    ShowDefault();
}
void ModelTab::setCarType5()
{
    typeNum=5;
    ShowDefault();
}
void ModelTab::setCarType6()
{
    typeNum=6;
    ShowDefault();
}
void ModelTab::setCarType7()
{
    typeNum=7;
    ShowDefault();
}
void ModelTab::setCarType8()
{
    typeNum=8;
    ShowDefault();
}
void ModelTab::setCarType9()
{
    typeNum=9;
    ShowDefault();
}
void ModelTab::setCarType10()
{
    typeNum=10;
    ShowDefault();
}
void ModelTab::setCarType11()
{
    typeNum=11;
    ShowDefault();
}
void ModelTab::setCarType12()
{
    typeNum=12;
    ShowDefault();
}

//차종번호 해제
void ModelTab::delCarType()
{
    typeNum=0;
}
