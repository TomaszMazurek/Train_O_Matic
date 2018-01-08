#ifndef DASHBOARD_H
#define DASHBOARD_H
#include <QMainWindow>
#include <QtSql>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QtPrintSupport>
#include "dbmanager.h"
#include "ticket.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = 0);
//    void mousePressEvent(QMouseEvent *event);
    ~Dashboard();

private slots:
    void showTime();
    void on_btnHome_clicked();
    void on_btnSchedule_clicked();
    void on_btnBack_clicked();
    void on_btnRoute_clicked();
    void on_btnTicket_clicked();

    void on_btnFirstClass_clicked();
    void on_btnSecondClass_clicked();
    void on_btnNormal_clicked();
    void on_btnReduced_clicked();
    void on_btnEconClass_clicked();

    void on_btnSeatReservation_toggled(bool checked);
    void on_btnWindowBack_clicked();
    void on_btnWindowFront_clicked();
    void on_btnMiddleBack_clicked();
    void on_btnMiddleFront_clicked();
    void on_btnDoorBack_clicked();
    void on_btnDoorFront_clicked();

    void on_btnClear_clicked();

private:
    Ui::Dashboard *ui;
    DbManager *dbManager;
    QList<Connection> connections;
    QPoint *m_ScrollStart;
    TicketType *ticket;

    QSqlTableModel* setTableModel();
    QString setTicketText(TicketType *ticket);


};

#endif // DASHBOARD_H
