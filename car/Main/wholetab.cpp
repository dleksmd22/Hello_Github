#include "wholetab.h"
#include "ui_wholetab.h"
// 테스트 깃 테스트
WholeTab::WholeTab(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WholeTab)
{
    ui->setupUi(this);
    //월/기간 탭 크기 조절
    ui->Session_Tab->setStyleSheet("QTabBar::tab {width:405px;}");
    //테이블위젯 크기 조절
    ui->Brand_Car_Korea->setColumnWidth(0,610);
    ui->Brand_Car_Korea->setColumnWidth(1,70);
    ui->Brand_Car_Korea->setColumnWidth(2,70);
    ui->Brand_Car_Foreign->setColumnWidth(0,610);
    ui->Brand_Car_Foreign->setColumnWidth(1,70);
    ui->Brand_Car_Foreign->setColumnWidth(2,70);
    ui->Model_Car_Korea->setColumnWidth(0,610);
    ui->Model_Car_Korea->setColumnWidth(1,70);
    ui->Model_Car_Korea->setColumnWidth(2,70);
    ui->Model_Car_Foreign->setColumnWidth(0,610);
    ui->Model_Car_Foreign->setColumnWidth(1,70);
    ui->Model_Car_Foreign->setColumnWidth(2,70);
    //버튼연결
    connect(ui->Brand_PushButton,SIGNAL(clicked()),this->parent(),SLOT(on_btnBrand_clicked()));
    connect(ui->Model_PushButton,SIGNAL(clicked()),this->parent(),SLOT(on_btnModel_clicked()));
}

WholeTab::~WholeTab()
{
    delete ui;
}

/*수정사항
1. 기간 수입 top10 부분 추가
2. 기간 국내 top10 처음 콤보박스 경로 변경
3. 월조회 국내/수입 전월대비판매량 추가
4. 기간조회 top10의 전월대비판매량 데이터값 0으로 수정

-----------------------------

5. index 사용하여 코드줄이기, 가독성 높이기
6. 브랜드이름 변환
*/


////////////////////////////////////////////// 월선택 조회 버튼 ///////////////////////////////////////////////////


QString WholeTab::ConvertBrandName(int bnum) //브랜드이름 변환 , 헤더파일에 선언을 해줘야함.
{
    switch(bnum)
    {
    case 1:
        return "현대";
    case 2:
        return "기아";
    case 3:
        return "제네시스";
    case 4:
        return "쉐보레";
    case 5:
        return "KG 모빌리티";
    case 6:
        return "르노코리아";
    case 7:
        return "BMW";
    case 8:
        return "벤츠";
    case 9:
        return "아우디";
    case 10:
        return "렉서스";
    case 11:
        return "포르쉐";
    }
}

////////////////// 월선택 국산 top 5 //////////////////




void WholeTab::on_Select_Ask_PushButton_clicked() // pushbutton click시 이벤트발생
{
    DB_Connection.open(); // DB연결, 열기
    QSqlDatabase::database().transaction(); // 데이터베이스에 접근하여 작업하기 위한 함수x

    QSqlQuery QueryLoadData(DB_Connection); // DB와 연결하여 sqlite로 데이터 가져오기
    QString month=QString::number(ui->Select_Month_ComboBox->currentIndex()+1); //달


    QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_"+month+"\") AS sale ,ROUND((total(\"2023_"+month+"\")/(SELECT SUM(\"2023_"+month+"\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_"+month+"\") DESC LIMIT 5;");


    // int NumberOFRowsToDisplay = 5; // 행의개수


    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 5; // 행의개수

        ui->Brand_Car_Korea->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수
        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            // ui->Brand_Car_Korea->insertRow(RowNumber); // Row 행번호 표시

            ui->Brand_Car_Korea->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Brand_Car_Korea->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Brand_Car_Korea->setItem(RowNumber, 2, new QTableWidgetItem(QString::number(QueryLoadData.value("percent").toDouble(),'f',2)));
            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }



    QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_"+month+"\") AS sale ,ROUND((total(\"2023_"+month+"\")/(SELECT SUM(\"2023_"+month+"\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_"+month+"\") DESC LIMIT 5;");




    /////////////////////////// 월선택 수입 top 5  ///////////////////



    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 5; // 행의개수

        ui->Brand_Car_Foreign->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수
        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            // ui->Brand_Car_Korea->insertRow(RowNumber); // Row 행번호 표시

            ui->Brand_Car_Foreign->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Brand_Car_Foreign->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Brand_Car_Foreign->setItem(RowNumber, 2, new QTableWidgetItem(QString::number(QueryLoadData.value("percent").toDouble(),'f',2)));
            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }

    //////////////////////////// 월선택 국산 TOP10  //////////////////////



    QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_"+month+"\") AS sale FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY MODEL ORDER BY (\"2023_"+month+"\") DESC LIMIT 10;");



    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 10; // 행의개수

        ui->Model_Car_Korea->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수

        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            ui->Model_Car_Korea->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Model_Car_Korea->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Model_Car_Korea->setItem(RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("gap").toString())));

            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }

    ///////////////////////////// 월선택 수입산 TOP10////////////////


    QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_"+month+"\") AS sale,0 AS gap FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY MODEL ORDER BY (\"2023_"+month+"\") DESC LIMIT 10;");


    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 10; // 행의개수

        ui->Model_Car_Foreign->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수

        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            ui->Model_Car_Foreign->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Model_Car_Foreign->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Model_Car_Foreign->setItem(RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("gap").toString())));

            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }



    QSqlDatabase::database().commit(); // 해당 작업의 사항을 보여주는 함수
    DB_Connection.close(); // DB 열었으니 닫음
}





////////////////////////////////////////////// 월선택 조회 버튼 끝///////////////////////////////////////////////////





////////////////////////////////////////////// 기간 조회 버튼 ///////////////////////////////////////////////////





void WholeTab::on_Session_Ask_PushButton_clicked()
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();
    QSqlQuery QueryLoadData(DB_Connection);

    QString startmonth=QString::number(ui->Session_Month_First_ComboBox->currentIndex()+1); //달
    QString lastmonth=QString::number(ui->Session_Month_Last_ComboBox->currentIndex()+1); //달

    QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_"+startmonth+"\") AS sale,ROUND((total(\"2023_"+startmonth+"\")/(SELECT SUM(\"2023_"+startmonth+"\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_"+startmonth+"\") DESC LIMIT 5;");

    if(startmonth <= lastmonth)
    {
        for(char startmonth = 1; startmonth < 13; startmonth++)
        {
            QString::append(ui->Session_Month_First_ComboBox->currentIndex()+1);
            continue;
        }
    }


    //////////// 기간 국산 top5 1월 //////////////// 국산 TOP 5


    if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "1") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "2") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\" + \"2023_2\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "3") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "4") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "5") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "6") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "7") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "8") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "9") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "10") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "11") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "12") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }


    ///////////// 기간 국산 top5 2월 //////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "2") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "3") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "4") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "5") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "6") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "7") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "8") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "9") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "10") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "11") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "12") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }


    /////////////// 기간 국산 top5 3월/////////////////



    if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }

    ///////////////// 기간 국산 top5 4월 //////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }



    ///////////////// 기간 국산 top5 5월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }


    ///////////////// 기간 국산 top5 6월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }



    ///////////////// 기간 국산 top5 7월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }


    ///////////////// 기간 국산 top5 8월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }



    ///////////////// 기간 국산 top5 9월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }



    ///////////////// 기간 국산 top5 10월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_10\") AS sale ,ROUND((total(\"2023_10\")/(SELECT SUM(\"2023_10\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_10\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_10\")/(SELECT SUM(\"2023_10\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_10\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_10\")/(SELECT SUM(\"2023_10\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_10\") DESC LIMIT 5;");
    }




    ///////////////// 기간 국산 top5 11월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_11\") AS sale ,ROUND((total(\"2023_11\")/(SELECT SUM(\"2023_11\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_11\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_11\")/(SELECT SUM(\"2023_11\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_11\") DESC LIMIT 5;");
    }




    ///////////////// 기간 국산 top5 12월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "12" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_12\") AS sale ,ROUND((total(\"2023_12\")/(SELECT SUM(\"2023_12\") FROM CAR_TB WHERE BRAND < 7))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY BRAND ORDER BY SUM(\"2023_12\") DESC LIMIT 5;");
    }





    if (QueryLoadData.exec())
    {
        int NumberOFRowsToDisplay = 5;
        ui->Brand_Car_Korea->setRowCount(NumberOFRowsToDisplay);
        int RowNumber = 0;

        while (QueryLoadData.next())
        {
            ui->Brand_Car_Korea->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Brand_Car_Korea->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Brand_Car_Korea->setItem(RowNumber, 2, new QTableWidgetItem(QString::number(QueryLoadData.value("percent").toDouble(), 'f', 2)));
            RowNumber++;
        }
    }




    //////////// 기간 수입 top5 1월 ////////////////수입




    if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "1") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\") AS sale , ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "2") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\" + \"2023_2\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "3") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "4") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "5") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "6") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "7") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "8") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "9") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "10") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "11") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "12") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_1\"+ \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_1\")/(SELECT SUM(\"2023_1\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_1\") DESC LIMIT 5;");
    }




    ///////////// 기간 수입 top5 2월 //////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "2") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "3") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "4") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "5") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "6") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "7") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "8") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "9") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "10") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "11") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "12") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_2\")/(SELECT SUM(\"2023_2\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_2\") DESC LIMIT 5;");
    }




    /////////////// 기간 수입 top5 3월/////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_3\")/(SELECT SUM(\"2023_3\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_3\") DESC LIMIT 5;");
    }




    ///////////////// 기간 수입 top5 4월 //////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_4\")/(SELECT SUM(\"2023_4\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_4\") DESC LIMIT 5;");
    }




    ///////////////// 기간 수입 top5 5월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_5\")/(SELECT SUM(\"2023_5\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_5\") DESC LIMIT 5;");
    }





    ///////////////// 기간 수입 top5 6월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_6\")/(SELECT SUM(\"2023_6\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_6\") DESC LIMIT 5;");
    }




    /////////////////기간 수입 top5 7월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_7\")/(SELECT SUM(\"2023_7\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_7\") DESC LIMIT 5;");
    }




    /////////////////기간 수입 top5 8월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_8\")/(SELECT SUM(\"2023_8\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_8\") DESC LIMIT 5;");
    }




    /////////////////기간 수입 top5 9월///////////////////////////




    if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\" + \"2023_10\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_9\")/(SELECT SUM(\"2023_9\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_9\") DESC LIMIT 5;");
    }





    /////////////////기간 수입 top5 10월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_10\") AS sale ,ROUND((total(\"2023_10\")/(SELECT SUM(\"2023_10\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_10\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_10\" + \"2023_11\") AS sale ,ROUND((total(\"2023_10\")/(SELECT SUM(\"2023_10\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_10\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_10\" + \"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_10\")/(SELECT SUM(\"2023_10\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_10\") DESC LIMIT 5;");
    }




    /////////////////기간 수입 top5 11월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_11\") AS sale ,ROUND((total(\"2023_11\")/(SELECT SUM(\"2023_11\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_11\") DESC LIMIT 5;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_11\" + \"2023_12\") AS sale ,ROUND((total(\"2023_11\")/(SELECT SUM(\"2023_11\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_11\") DESC LIMIT 5;");
    }





    /////////////////기간 수입 top5 12월///////////////////////////





    if(ui->Session_Month_First_ComboBox->currentText() == "12" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT BRAND AS company, sum(\"2023_12\") AS sale ,ROUND((total(\"2023_12\")/(SELECT SUM(\"2023_12\") FROM CAR_TB WHERE BRAND > 6))*100, 0) as percent FROM CAR_TB WHERE BRAND BETWEEN 7 AND 11 GROUP BY BRAND ORDER BY SUM(\"2023_12\") DESC LIMIT 5;");
    }

    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 5; // 행의개수

        ui->Brand_Car_Foreign->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수
        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            // ui->Brand_Car_Korea->insertRow(RowNumber); // Row 행번호 표시

            ui->Brand_Car_Foreign->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Brand_Car_Foreign->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Brand_Car_Foreign->setItem(RowNumber, 2, new QTableWidgetItem(QString::number(QueryLoadData.value("percent").toDouble(),'f',2)));
            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }



    //////////////////////기간 국산 top10



    ///////////////      기간 국산차 top10 1월



    if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "1") // Select_Month_ComboBox가 해당월을 출력함 1월
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 AND 6 GROUP BY MODEL ORDER BY SUM(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "2")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_1\") DESC LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 2월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "2")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_2\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 3월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_3\") desc LIMIT 10;");
    }


    ////////////////////////////      기간 국산차top10 4월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_4\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 5월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_5\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 6월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_6\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_6\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_6\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_6\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_6\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_6\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 7월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_7\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_7\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_7\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_7\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_7\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 8월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_8\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_8\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_8\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_8\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_8\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 9월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_9\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_9\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_9\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_9\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 10월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_10\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_10\") desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_10\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 11월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_11\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by sum(\"2023_11\") desc LIMIT 10;");
    }

    ////////////////////////////      기간 국산차top10 12월
    ///
    ///
    ///


    if(ui->Session_Month_First_ComboBox->currentText() == "12" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 1 and 6 GROUP BY MODEL order by \"2023_12\" desc LIMIT 10;");
    }






    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 10; // 행의개수

        ui->Model_Car_Korea->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수
        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            // ui->Brand_Car_Korea->insertRow(RowNumber); // Row 행번호 표시

            ui->Model_Car_Korea->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Model_Car_Korea->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Model_Car_Korea->setItem(RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("gap").toString())));
            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }

    ///////////////////// 기간 수입 TOP10
    ///
    ///
    ///
    ///     기간 수입차 1월
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "1")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "2")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "1" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_1\" + \"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_1\" desc LIMIT 10;");
    }


    ////////////     기간 수입차top10 2월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "2")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "2" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_2\" + \"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_2\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 3월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "3")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "3" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_3\" + \"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_3\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 4월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "4")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "4" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_4\" + \"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_4\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 5월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "5")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "5" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_5\" + \"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_5\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 6월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "6")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "6" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_6\" + \"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_6\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 7월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "7")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "7" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_7\" + \"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_7\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 8월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "8")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_8\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_8\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_8\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_8\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "8" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_8\" + \"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_8\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 9월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "9")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_9\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\" + \"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_9\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_9\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "9" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_9\" + \"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_9\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 10월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "10")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_10\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_10\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_10\" + \"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_10\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "10" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_10\" + \"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_10\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 11월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "11")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_11\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_11\" desc LIMIT 10;");
    }
    else if(ui->Session_Month_First_ComboBox->currentText() == "11" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_11\" + \"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_11\" desc LIMIT 10;");
    }

    ////////////     기간 수입차top10 12월 /////
    ///
    ///
    ///
    ///
    if(ui->Session_Month_First_ComboBox->currentText() == "12" && ui->Session_Month_Last_ComboBox->currentText() == "12")
    {
        QueryLoadData.prepare("SELECT MODEL AS company, sum(\"2023_12\") AS sale, 0 as gap  FROM CAR_TB WHERE BRAND BETWEEN 7 and 11 GROUP BY MODEL order by \"2023_12\" desc LIMIT 10;");
    }







    if (QueryLoadData.exec()) // 실행
    {
        int NumberOFRowsToDisplay = 10; // 행의개수

        ui->Model_Car_Foreign->setRowCount(NumberOFRowsToDisplay); // Brand_Car_Korea의 행의 개수
        int RowNumber = 0; // 데이터 행넘버초기화, 0부터시작


        while (QueryLoadData.next()) // 데이터반복
        {
            // ui->Brand_Car_Korea->insertRow(RowNumber); // Row 행번호 표시

            ui->Model_Car_Foreign->setItem(RowNumber, 0, new QTableWidgetItem(QString(QueryLoadData.value("company").toString())));
            ui->Model_Car_Foreign->setItem(RowNumber, 1, new QTableWidgetItem(QString(QueryLoadData.value("sale").toString())));
            ui->Model_Car_Foreign->setItem(RowNumber, 2, new QTableWidgetItem(QString(QueryLoadData.value("gap").toString())));
            RowNumber = RowNumber + 1; // 넘버 1씩 증가
        }
    }




    QSqlDatabase::database().commit();
    DB_Connection.close();
}
