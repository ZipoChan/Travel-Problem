#include "myscence.h"
#include <qdebug.h>
#include <qlist.h>
#include <QFile>

myScence::myScence(QObject *parent,int c_time) : QGraphicsScene(parent)
{
    //背景图片
    this->back_pic = new background_pic;
    this->addItem(this->back_pic);
    relax=true;
    curruenttime=0;
    line_number=0;
    pos_number=0;
    staytime=8888888;
    for(int i=0;i<100;i++)
    {
        line[i]=new Line();
        addItem(line[i]);
        pos[i] = new Position();
        addItem(pos[i]);
    }
    traveller=new Position();
    addItem(traveller);
}

void myScence::updatetime_hour()
{
    curruenttime++;
    curruenttime%=24;
   // qDebug()<<curruenttime;
    if(!relax)
    resttime--;
    if(relax)
    {
        staytime--;
        if(staytime==0)
        {
            basetime=QTime::currentTime();
            relax=0;
        }
    }
    if(resttime==0)
    arrive();
    //qDebug() <<"resttime:"<<resttime<<" staytime: "<<staytime<<"\n";
}

void myScence::updatetime_mini()
{
    current = QTime::currentTime();
    if(!relax)
    {
    spendtime = basetime.msecsTo(current);
    currentposX=position_x[currentcity]+((double)spendtime/(double)(traveltime[currentcnt]*2000))*(position_x[target]-position_x[currentcity]);
    currentposY=position_y[currentcity]+((double)spendtime/(double)(traveltime[currentcnt]*2000))*(position_y[target]-position_y[currentcity]);
    traveller->setRect(currentposX, currentposY, diameter, diameter);
    line[currentcnt]->setLine(currentposX+3, currentposY + 3, position_x[target] + 3, position_y[target] + 3);
    QString tempq=QString::number(currentposX)+" "+QString::number(currentposY);
    emit tomain(tempq);
    }

}

void myScence::arrive()
{
    QFile file(username+"_dialog.txt");
    if(!file.open(QIODevice::Append)|QIODevice::Text){
        qDebug()<<"wrong!";
    }
    QTextStream in(&file);
    in<<"Arrive at city "<<currentcity<<" at "<<curruenttime<<"\r\n";
    file.close();
    relax=true;
    line[currentcnt]->setVisible(false);
    pos[currentcnt+1]->setVisible(false);
    currentcnt++;
    resttime=traveltime[currentcnt];
    currentcity=target;
    target=citypath[currentcnt];
    currentposX=position_x[currentcity];
    currentposY=position_y[currentcity];
    if(curruenttime<gopath[currentcnt])
    {
        staytime=gopath[currentcnt]-curruenttime;
    }
    else if(curruenttime>gopath[currentcnt])
    {
        staytime=gopath[currentcnt]+24-curruenttime;
    }
    else
    {
        staytime=0;
        basetime=QTime::currentTime();
        relax=false;
        pos[currentcity]->setVisible(false);
    }

}

void myScence::updatemap(QString data_string)
{
    relax=true;
    //分析传入字符串并解析出内容
     pos[0]->setVisible(false);
     for(int i=0;i<line_number;i++)
     {
         line[i]->setVisible(false);
         pos[i+1]->setVisible(false);
     }

    QList<QString> travel_string_list = data_string.split(" ",QString::SkipEmptyParts);
    line_number = (travel_string_list.length() - 1) / 5;
    pos_number = line_number + 1;



    firstcity=travel_string_list.at(0).toInt();
    lastcity=travel_string_list.at(line_number*5).toInt();
    currentposX=position_x[firstcity];
    currentposY=position_y[firstcity];
    currentcity=firstcity;
    currentcnt=0;
    target=travel_string_list.at(5).toInt();
    spendtime=0;
    staytime=24+travel_string_list.at(1).toInt()-curruenttime;

    for(int i=0;i<line_number;i++)
    {

        int starttime;
        int arrivetime;
        starttime=travel_string_list.at(i*5+1).toInt();
        arrivetime=travel_string_list.at(i*5+4).toInt();
        if(starttime<arrivetime)
            traveltime[i]=arrivetime-starttime;
        else
            traveltime[i]=24+arrivetime-starttime;
        citypath[i]=travel_string_list.at(i*5+5).toInt();
        waypath[i]=travel_string_list.at(i*5+2);
        costpath[i]=travel_string_list.at(i*3).toInt();
        gopath[i]=starttime;
    }

    resttime=traveltime[0];


    int first_city = firstcity;

    //pos[0] = new Position();
    //traveller = new Position();
    pos[0]->setRect(position_x[first_city], position_y[first_city], diameter, diameter);
    pos[0]->setVisible(true);
    traveller->setRect(position_x[first_city], position_y[first_city], diameter, diameter);
    traveller->setVisible(true);
   // addItem(traveller);
    //addItem(pos[0]);

    for (int i = 1; i < pos_number; i ++)
    {
        int city_number = travel_string_list.at(5 * i).toInt();
        //pos[i] = new Position();
        pos[i]->setRect(position_x[city_number], position_y[city_number], diameter, diameter);
        pos[i]->setVisible(true);
        //addItem(pos[i]);
    }

    for(int i =0;i<line_number;i++)
    {
        //line[i] = new Line();
        line[i]->setLine(position_x[first_city] + 3, position_y[first_city] + 3, position_x[citypath[i]] + 3, position_y[citypath[i]] + 3);
        line[i]->setVisible(true);
        qDebug()<<"draw line "<<i<<"from "<<first_city<<" to "<<citypath[i]<<endl;
        first_city=citypath[i];
        //addItem(line[i]);
    }
}
