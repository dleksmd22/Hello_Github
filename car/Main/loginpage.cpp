#include <QMessageBox>
#include <QDesktopServices>
#include <QUrl>

#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    QPixmap danawaLogo (":resources/danawaImg.jpg");

    ui->label->setPixmap(danawaLogo.scaled(780,450,Qt::IgnoreAspectRatio));
    ui->label_4->setPixmap(danawaLogo.scaled(230,280,Qt::IgnoreAspectRatio));
    ui->label_20->setPixmap(danawaLogo.scaled(380,400,Qt::IgnoreAspectRatio));
    ui->label_24->setPixmap(danawaLogo.scaled(380,400,Qt::IgnoreAspectRatio));
    ui->label_27->setPixmap(danawaLogo.scaled(380,400,Qt::IgnoreAspectRatio));

    ui->stackedWidget->setCurrentIndex(0);

    //판매실적화면으로 이동
    connect(ui->pushButton_6,SIGNAL(clicked()),this->parent(),SLOT(ShowSales()));
}

LoginPage::~LoginPage()
{
    delete ui;
}
//홈화면으로
void LoginPage::gotoHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
//로그인화면으로
void LoginPage::gotoLogin()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->Llogin->clear();
    ui->Lpw->clear();
}

//회원가입화면으로
void LoginPage::gotoJoin()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->Eid->clear();
    ui->Ename->clear();
    ui->Ephone->clear();
    ui->Epw->clear();

    ckPhone=false; ckId=false;
    ui->btnEnroll->setDisabled(true);
}

//아이디찾기화면으로
void LoginPage::gotoSID()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->SIDstackedWidget->setCurrentIndex(0);
    ui->SIphone->clear();
    ui->SIname->clear();
}

//비밀번호찾기화면으로
void LoginPage::gotoSPW()
{
    ui->stackedWidget->setCurrentIndex(4);
    ui->SPWstackedWidget->setCurrentIndex(0);
    ui->SPid->clear();
    ui->SPname->clear();
    ui->SPphone->clear();
}
//회원가입 진행
void LoginPage::ProgressJoin()
{
    if(ui->Ename->text().isEmpty()||ui->Epw->text().isEmpty())
    {
        QMessageBox::critical(this,"경고 메시지","모든 항목을 입력해주세요.",QMessageBox::Ok);
    }
    else
    {
        QSqlQuery qry;
        qry.prepare("INSERT INTO USER_TB(UID, UPW, UNAME, UPHONE) VALUES('"+ui->Eid->text()+"', '"+ui->Epw->text()+"', '"+ui->Ename->text()+"', '"+ui->Ephone->text().split('-').join("")+"')");
        qry.exec();
        QMessageBox::information(this,"알림 메시지","회원가입이 완료되었습니다. 로그인 창으로 이동합니다.",QMessageBox::Ok);
        gotoLogin();
        ckPhone=false; ckId=false;
        ui->btnEnroll->setDisabled(true);
    }
}
//휴대폰 번호 중복검사
void LoginPage::CKPhoneNum()
{
    if(!ui->Ephone->text().isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("SELECT * FROM USER_TB WHERE UPHONE='"+ui->Ephone->text().split('-').join("")+"'");
        qry.exec();
        if(qry.next()) //번호 중복
        {
            QMessageBox::critical(this,"경고 메시지","중복된 전화번호입니다.",QMessageBox::Ok);
            ui->Ephone->clear();
            ui->Ephone->setFocus();
        }
        else
        {
            QMessageBox::information(this,"알림 메시지","사용가능한 전화번호입니다.",QMessageBox::Ok);
            ckPhone=true;
            ui->Eid->setFocus();
        }
        if(ckPhone&&ckId) ui->btnEnroll->setDisabled(false);
    }
    else
    {
        QMessageBox::critical(this,"경고 메시지","전화번호를 입력하세요.",QMessageBox::Ok);
    }
}

//아이디 중복검사
void LoginPage::CKID()
{
    if(!ui->Eid->text().isEmpty())
    {
        QSqlQuery qry;
        qry.prepare("SELECT UPW FROM USER_TB WHERE UID='"+ui->Eid->text()+"'");
        qry.exec();
        if(qry.next()) //아이디 중복
        {
            QMessageBox::critical(this,"경고 메시지","중복된 아이디입니다.",QMessageBox::Ok);
            ui->Eid->clear();
            ui->Eid->setFocus();
        }
        else
        {
            QMessageBox::information(this,"알림 메시지","사용가능한 아이디입니다.",QMessageBox::Ok);
            ckId=true;
            ui->Epw->setFocus();
        }
        if(ckPhone&&ckId) ui->btnEnroll->setDisabled(false);
    }
    else
    {
        QMessageBox::critical(this,"경고 메시지","아이디를 입력하세요.",QMessageBox::Ok);
    }
}

//로그인 진행
void LoginPage::ProgressLogin()
{
    QString tmpID, tmpPW;
    tmpID=ui->Llogin->text();
    tmpPW=ui->Lpw->text();

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
    //디비연결은 파일중 하나에서만 하면됨

    QSqlQuery qry;
    qry.prepare("SELECT UPW FROM USER_TB WHERE UID='"+tmpID+"';");
    qry.exec();
    if(qry.next()&&qry.value(0).toString()==tmpPW)//아이디가 일치하는 계정 존재 //아 이거 왜 자꾸 잊지 ㅋㅋㅋ큐ㅠㅠ
    {
        ui->pushButton_6->click(); //임시 ->판매실적화면으로 넘기기
        //로그인정보 저장해야..겠지? 아직은 필요 없다
    }
    else
    {
        //존재하지 않는 아이디
        QMessageBox::critical(this,"경고 메시지","존재하지 않는 아이디이거나 틀린 비밀번호입니다.",QMessageBox::Ok);
        ui->Llogin->clear();
        ui->Lpw->clear();
    }
}
//아이디 찾기
void LoginPage::SearchID()
{
    QSqlQuery qry;
    qry.prepare("SELECT UID FROM USER_TB WHERE UNAME='"+ui->SIname->text()+"' AND UPHONE='"+ui->SIphone->text().split('-').join("")+"'");
    qry.exec();
    if(qry.next())
    {
        qDebug()<<qry.value(0).toString();
        ui->SIDstackedWidget->setCurrentIndex(1);
        ui->lblShowID->setText(qry.value(0).toString());
    }
    else
    {
        ui->SIDstackedWidget->setCurrentIndex(2);
    }
}
//비밀번호 찾기
void LoginPage::SearchPW()
{
    QSqlQuery qry;
    qry.prepare("SELECT UPW FROM USER_TB WHERE UNAME='"+ui->SPname->text()+"' AND UPHONE='"+ui->SPphone->text().split('-').join("")+"' AND UID='"+ui->SPid->text()+"'");
    qry.exec();
    if(qry.next())
    {
        ui->SPWstackedWidget->setCurrentIndex(1);
        ui->lblShowPW->setText(qry.value(0).toString());
    }
    else
    {
        ui->SPWstackedWidget->setCurrentIndex(2);
    }
}

void LoginPage::pushButtonClicked()
{
    QDesktopServices::openUrl(QUrl("https://event.danawa.com/"));
}

