#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>
#include "stop_watch_impl.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    fdrtsp::Stopwatch m_stopWatch;
    QTimer *m_timerRefresh;
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnStart_clicked();

    void on_btnStop_clicked();

    void on_btnReset_clicked();

    void timer_refresh();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
