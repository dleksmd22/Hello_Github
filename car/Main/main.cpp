#include "mainwindow.h"

#include <QApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //한번만 오픈하면됨!
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("DB_Car.db");
    if(!db.open())
    {
        qDebug()<<db.lastError()<<"데이터베이스 연결 실패!";
    }
    else
    {
        qDebug("데이터베이스 연결 완료");
    }

    MainWindow m;
    // m.setFixedSize(810,1000);
    // m.setWindowTitle("Danawa Car");
    // m.setWindowIcon(QIcon(":/resources/danawaImg.png"));
    m.show();
    return a.exec();
}
