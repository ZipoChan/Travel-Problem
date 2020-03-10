#ifndef MYSCENCE_H
#define MYSCENCE_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <QGraphicsScene>
#include <background_pic.h>
#include <position.h>
#include <line.h>

class myScence : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScence(QObject *parent = nullptr,int c_time=0);
    ~myScence(){}
    void updatemap(QString data_string);
    void draw(QString q);
    void arrive();
    void timechange(int t){
        curruenttime=t;
    }
    void getusername(QString t){
        username=t;
    }
signals:
    void tomain(QString Q);
public slots:
   // void updatetime();
    void updatetime_hour();
    void updatetime_mini();
private:
    background_pic * back_pic;
    Position * pos[100];
    Position * traveller;
    Line * line[100];
    QString username;
    int traveltime[100];
    int citypath[100];
    QString waypath[100];
    int costpath[100];
    int gopath[100];

    int firstcity;
    int lastcity;

    int currentcity;
    int target;

    QTime basetime;
    QTime current;
    int spendtime;
    int staytime;

    double currentposX;
    double currentposY;

    int citynum;
    int currentcnt;

    int curruenttime;
    int resttime;

    bool relax;

    int line_number;
    int pos_number;

    //参数预设
    int position_x[20] = {618, 691, 580, 790, 715, 635, 440, 430, 485, 585, 630, 410, 425, 630, 515, 605, 550, 646, 565, 510};   //城市地点x坐标
    int position_y[20] = {296, 449, 580, 150, 270, 310, 370, 460, 525, 460, 355, 355, 550, 440, 405, 320, 260, 550, 500, 580};   //城市地点y坐标
    QString city_name[20] = {"北京", "上海", "广州", "哈尔滨", "沈阳", "天津", "兰州", "成都", "贵阳", "武汉", "济南", "西宁", "昆明", "合肥", "西安", "石家庄", "呼和浩特", "厦门", "长沙", "南宁"};
    int diameter = 6;   //城市圆圈直径
};


#endif // MYSCENCE_H
