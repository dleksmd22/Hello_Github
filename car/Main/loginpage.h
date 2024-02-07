#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginPage;
}
QT_END_NAMESPACE

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

private slots:
    //홈화면으로
    void gotoHome();
    //로그인화면으로
    void gotoLogin();
    //회원가입화면으로
    void gotoJoin();
    //아이디찾기화면으로
    void gotoSID();
    //비밀번호찾기화면으로
    void gotoSPW();
    //회원가입 진행
    void ProgressJoin();
    //휴대폰 번호 중복검사
    void CKPhoneNum();
    //아이디 중복검사
    void CKID();
    //로그인 진행
    void ProgressLogin();
    //아이디 찾기
    void SearchID();
    //비밀번호 찾기
    void SearchPW();

    void pushButtonClicked();

private:
    Ui::LoginPage *ui;
    QSqlDatabase db;
    bool ckPhone; //
    bool ckId; //
};
#endif // LOGINPAGE_H
