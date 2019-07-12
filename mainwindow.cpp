#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_timerRefresh = new QTimer(this);
    m_timerRefresh->connect(m_timerRefresh, SIGNAL(timeout()), this, SLOT(on_timer_refresh()));
    m_timerRefresh->setInterval(10);
    ui->lcdNumber->setDecMode();
    ui->lcdNumber->setDigitCount(12);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);

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
    ui->lcdNumber->display("0:0:000");
}

void MainWindow::on_timer_refresh()
{
    QString text;
    auto t = m_stopWatch.elapsed<fdrtsp::milliseconds>();
    uint64_t hour = 0, minute = 0, sec = 0, msec=0;
    if (t >= 3600000) hour = t/3600000;
    if (t >= 60000) minute = (t%3600000) / 60000;
    if (t >= 1000) sec = (t % 60000) / 1000;
    msec = t % 1000;

    char fmtstr[256];
    sprintf(fmtstr, "%u:%.2u:%.2u:%.3u", hour, minute, sec, msec);
    //text = QString("%1:%2:%3:%4").arg(hour,2).arg(minute,2).arg(sec).arg(msec,3);
    printf("time:%s\n", fmtstr);
    text = fmtstr;

    ui->lcdNumber->display(text);
    //std::cout << m_stopWatch.elapsed() << std::endl;
}
