#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "wholetab.h"
#include "brandtab.h"
#include "modeltab.h"
#include "loginpage.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void ShowSales(void); //로그인화면->판매실적화면
    void btnStackBrandClicked();
    void btnStackCarClicked();
    void ChangeBStackPage();
    void ChangeCStackPage();


    void on_pushButton_clicked();

    void on_btnModel_clicked();

    void on_btnWhole_clicked();

    void on_btnBrand_clicked();

private:
    Ui::MainWindow *ui;
    LoginPage* l;
    WholeTab* w;
    BrandTab* b;
    ModelTab* m;
};
#endif // MAINWINDOW_H
