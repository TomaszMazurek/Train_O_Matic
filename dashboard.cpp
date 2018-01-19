
#include "dashboard.h"
#include "ui_dashboard.h"
#include "dbmanager.h"
#include "ticket.h"
#include <QMouseEvent>

Dashboard::Dashboard(QWidget *parent) :
    QMainWindow(parent, Qt::FramelessWindowHint), ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    dbManager = new DbManager();
    ui->tableView->setModel(setTableModel());
    ui->tableView->sortByColumn(4, Qt::AscendingOrder);
    ui->stackedWidget->setCurrentIndex(0);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();
}
Dashboard::~Dashboard()
{
    delete ui;
}
void Dashboard::showTime()
{
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh:mm:ss");
    ui->lblTimer->setText(timeText);
    QDate date = QDate::currentDate();
    QString dateText = date.toString("dd-MM-yy");
    ui->lblDateTime->setText(dateText);
}
void Dashboard::on_btnHome_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
void Dashboard::on_btnSchedule_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    dbManager->getCurrentConnections();
    QSqlTableModel* mode=setTableModel();
    ui->tableView->setModel(mode);

}
void Dashboard::on_btnRoute_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
void Dashboard::on_btnTicket_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ticket = Ticket::createTicket();
    ticket->cost="11.0";

    ui->textBrowser->setText(setTicketText(ticket));

}
QSqlTableModel* Dashboard::setTableModel()
{
    QSqlTableModel *model = new QSqlTableModel(this);
    model->setTable("Connections");
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Z"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("DO"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PERON"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("TOR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("ODJAZD"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("PRZYJAZD"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("CENA BILETU"));
    model->removeColumn(0);

    return model;
}
QString Dashboard::setTicketText(TicketType *ticket)
{
    cost=ticket->cost.toDouble()*clasCost*typCost;
    QString ticketText = QString("OTrain\t\t\t\t\t       bilet: %1\n"
                     "sp. z o.o.\t\t\t\t\t      Klasa: %2\n"
                     "\n"
                     "%5 | %7 |      %8 -> %9      | %5 | %10\n"
                     "\n"
                     "\t\tPeron: %11"
                                 "1\t\t Tor: %12\n"
                     "\n"
                     "Pociąg nr. \tWagon:\tPrzedział:\tMiejsce: \n"
                     "     %13\t\t4\t5\t\t%3\n"
                     "\n"
                     "Numer biletu:\t\t%4       Cena:\t\t%6").arg(ticket->ticketType).arg(ticket->classType).arg(ticket->seatType).
            arg(ticket->ticketNum).arg(QDate::currentDate().toString("dd-MM-yy")).arg(cost).arg(ticket->departure).arg(ticket->origin)
            .arg(ticket->destination).arg(ticket->arrival).arg(ticket->platform).arg(ticket->track).arg(ticket->trainNum);

    return ticketText;
}
void Dashboard::on_btnBack_clicked()
{
    this->close();
}


/*
void Dashboard::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) //lets map scrolling to left button
        m_ScrollStart = event.pos(); //QPoint member, indicates the start of the scroll
    else
        QListView::mousePressEvent(event);
}
*/

void Dashboard::on_btnFirstClass_clicked()
{
    clasCost=2.1;
    ticket->classType = "I";
    ui->textBrowser->setText(setTicketText(ticket));

}
void Dashboard::on_btnSecondClass_clicked()
{
    clasCost=1;
    ticket->classType = "II";
    ui->textBrowser->setText(setTicketText(ticket));

}
void Dashboard::on_btnNormal_clicked()
{
    typCost=1;
    ticket->ticketType = "Normalny";
    ui->textBrowser->setText(setTicketText(ticket));

}
void Dashboard::on_btnReduced_clicked()
{
    typCost=0.51;
    ticket->ticketType = "Ulgowy";
    ui->textBrowser->setText(setTicketText(ticket));

}
void Dashboard::on_btnEconClass_clicked()
{
    ticket->classType = "E";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnWindowBack_clicked()
{
    ticket->seatType = "Okno tył";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnWindowFront_clicked()
{
    ticket->seatType = "Okno przód";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnMiddleBack_clicked()
{
    ticket->seatType = "Środek tył";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnMiddleFront_clicked()
{
    ticket->seatType = "Środek przód";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnDoorBack_clicked()
{
    ticket->seatType = "Drzwi tył";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnDoorFront_clicked()
{
    ticket->seatType = "Drzwi przód";
    ui->textBrowser->setText(setTicketText(ticket));
}
void Dashboard::on_btnSeatReservation_toggled(bool checked)
{
    ui->btnWindowBack->setEnabled(checked);
    ui->btnWindowFront->setEnabled(checked);
    ui->btnMiddleBack->setEnabled(checked);
    ui->btnMiddleFront->setEnabled(checked);
    ui->btnDoorBack->setEnabled(checked);
    ui->btnDoorFront->setEnabled(checked);
    if(checked == false){
        ticket->seatType = "";
        ui->textBrowser->setText(setTicketText(ticket));
    }
}
void Dashboard::on_btnClear_clicked()
{
    ui->btnSeatReservation->setChecked(false);
    ticket->classType = "";
    ticket->ticketType = "";
    ui->textBrowser->setText(setTicketText(ticket));
}

void Dashboard::on_btnBuy_clicked()
{
    ticket->cost=QString::number(cost);
  dbManager->saveTicket(ticket);

   on_btnClear_clicked();
   on_btnHome_clicked();
}

void Dashboard::on_tableView_activated(const QModelIndex &index)
{

}
