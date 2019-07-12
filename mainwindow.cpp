#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timerRefresh = new QTimer(this);

    m_timerRefresh->connect(m_timerRefresh, SIGNAL(timeout()), this, SLOT(timer_refresh()));
    m_timerRefresh->setInterval(10);
    ui->lcdNumber->setDecMode();
    ui->lcdNumber->setDigitCount(12);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    setWindowTitle("StopWatch");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnStart_clicked()
{
    m_stopWatch.start();
    m_timerRefresh->start();
}

void MainWindow::on_btnStop_clicked()
{
    m_timerRefresh->stop();
}

void MainWindow::on_btnReset_clicked()
{
    ui->lcdNumber->display("0");
}

void MainWindow::timer_refresh()
{
    QString text;
    auto t = m_stopWatch.elapsed<fdrtsp::milliseconds>();
    uint64_t hour = 0, minute = 0, sec = 0, msec=0;
    if (t >= 3600000) hour = t/3600000;
    if (t >= 60000) minute = (t%3600000) / 60000;
    if (t >= 1000) sec = (t % 60000) / 1000;
    msec = t % 1000;

    text = QString("%1:%2:%3:%4").arg(hour).arg(minute, 2, 10, QChar('0')).
            arg(sec, 2, 10, QChar('0')).arg(msec, 3, 10, QChar('0'));

    ui->lcdNumber->display(text);
}
