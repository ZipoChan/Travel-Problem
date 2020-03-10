#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <myscence.h>
#include <QTime>
#include <QTimer>
#include <QTcpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void socket_connect();
public slots:
    void updatetime();
    void ana_result(QString data_string);
     void socket_read_data();
     void rev_mys(QString Q);
private slots:
     void on_ptn_ok_clicked();

private:
    Ui::MainWindow *ui;
    myScence * sc;
    int curruent_time;
    QTimer *qtr;
    QString username;
    QTimer *raw_timer;
    QTimer *smooth_timer;
    QString inqure;
     QTcpSocket *socket;
     QString buffer;
    //传入参数
    QString string_test = "2 7 CA544 1240 10 0 10 CA217 1210 13 9 14 CA573 870 17 1 17 T44 400 21 10";
    QString string_test2 = "2 7 CA544 1240 21 10";
    //参数预设
    QString city_name[20] = {"北京", "上海", "广州", "哈尔滨", "沈阳", "天津", "兰州", "成都", "贵阳", "武汉", "济南", "西宁", "昆明", "合肥", "西安", "石家庄", "呼和浩特", "厦门", "长沙", "南宁"};
};

#endif // MAINWINDOW_H
