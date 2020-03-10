
#ifndef MODULE_H
#define MODULE_H

const int max_citynumber=20;
const int max_vehicle_numer=5;
const int INF = 99999999;

#include "common.h"
#include "aco.h"

struct ticket_info{
    QString train_number;
    int start_time;
    int arrive_time;
    int price;
};

struct PATH2{
    int next_arrive_time;
    struct PATH2* next_city;
    int next_vehicle_number;
    int next_city_number;
};

struct PATH{
    int precity;
    int shortest_time;
    int vehicle_type;
    int charge;
};

class Module: public  QObject
{
    Q_OBJECT
public:
    ACO aco;
    Module();
    ~Module();
    void least_cost_route_waycity(int source,int destination,QList<int>way_city);
    int least_time_route_waycity(int source,int destination,int curruent_time,QList<int>way_city);
    //void limit_time_waycity(int source,int destination,int curruent_time,int limit_time,QList<int>way_city);
    //int dynamic_limit_time_least_cost_route_waycity(int source,int destination,int curruent_time,int limit_time,QList<int>way_city,struct PATH2* p);
    int relax_ltime(int temp_source, int temp_current_time, int Queue[max_citynumber],struct PATH Path[max_citynumber]);
    void output_path(int source, int destnation,struct PATH Path[max_citynumber],int flag);//0output_lcost 1output_ltime 2 output_way_lost 4_output_way_ltime
    int relax_lcost(int source, int temp_charge, int Queue[max_citynumber],struct PATH Path[max_citynumber]);
    int least_cost_route(int source,int destination,int outputflag);
    int least_time_route(int source, int destination, int current_time,int outputflag);
    void limit_time_least_cost_route(int source, int destination, int current_time, int limit_time);
    int dynamic_find_limit_least_cost(int source, int destination, int limit_time, int current_time, struct PATH2 *path);
    void send_data(QString Q);
    void ACO_lcost_route(int antmount,int generations,int start,int end,int t,int throughnum,bool* throughtarget);
    void ACO_ltime_route(int antmount,int generations,int start,int end,int t,int throughnum,bool* throughtarget);
    void ACO_limit_route(int antmount,int generations,int start,int end,int t,int throughnum,bool* throughtarget,int LIMIT);
    void NOPATH_limit_route(int antmount,int generations,int start,int end,int t,int LIMIT);
    void clear(){
        output_lcost.clear();
        output_ltime.clear();
        output_limit.clear();
        output_way_lcost.clear();
        output_way_ltime.clear();
        output_ACO_lcost.clear();
        output_ACO_ltime.clear();
        output_ACO_limit.clear();
        output_NOPATH_limit.clear();
    }
    void molstart(int des,const QByteArray & Q){
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        switch(sline.at(0).toInt()){
            case 1:
            mol1(des,Q);
            break;
        case 2:
        mol2(des,Q);
        break;
        case 3:
            mol3(des,Q);
            break;
        case 4:
        mol4(des,Q);
        break;
        case 5:
        mol5(des,Q);
        break;
        case 6:
        mol6(des,Q);
            break;
        }
    }
    void mol1(int desc,const QByteArray &Q){
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        least_cost_route(sline.at(1).toInt(),sline.at(2).toInt(),0);
        datasend(desc,output_lcost.toLatin1());
        clear();
    }
    void mol2(int desc,const QByteArray &Q){
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        least_time_route(sline.at(1).toInt(),sline.at(2).toInt(),sline.at(3).toInt(),1);
        datasend(desc,output_ltime.toLatin1());
        clear();
    }
    void mol3(int desc,const QByteArray &Q){
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        //bool temp[max_citynumber]={0};
      //  limit_time_least_cost_route(sline.at(1).toInt(),sline.at(2).toInt(),sline.at(3).toInt(),sline.at(4).toInt());
        NOPATH_limit_route(10,8000,sline.at(1).toInt(),sline.at(2).toInt(),sline.at(3).toInt(),sline.at(4).toInt());
        datasend(desc,output_NOPATH_limit.toLatin1());
        clear();
    }
    void mol4(int desc,const QByteArray &Q){
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        int i=4;
        bool temp[max_citynumber]={0};
        int cnt=0;
        while(sline.at(i)!="E"){
           temp[sline.at(i).toInt()]=1;
           cnt++;
           i++;
        }
        ACO_lcost_route(4,4000,sline.at(1).toInt(),sline.at(2).toInt(),sline.at(3).toInt(),cnt,temp);
        datasend(desc,output_ACO_lcost.toLatin1());
        clear();
    }
    void mol5(int desc,const QByteArray &Q){
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        int i=4;
        bool temp[max_citynumber]={0};
        int cnt=0;
        while(sline.at(i)!="E"){
           temp[sline.at(i).toInt()]=1;
           cnt++;
           i++;
        }
        ACO_ltime_route(4,4000,sline.at(1).toInt(),sline.at(2).toInt(),sline.at(3).toInt(),cnt,temp);
        datasend(desc,output_ACO_ltime.toLatin1());
        clear();
    }
    void mol6(int desc,const QByteArray &Q){
        qDebug()<<Q;
        QString tempQ=Q;
        QStringList sline=tempQ.split(" ",QString::SkipEmptyParts);
        int i=5;
        bool temp[max_citynumber]={0};
        int cnt=0;
        while(sline.at(i)!="E"){
           temp[sline.at(i).toInt()]=1;
           cnt++;
           i++;
        }
        ACO_limit_route(4,4000,sline.at(1).toInt(),sline.at(2).toInt(),sline.at(3).toInt(),cnt,temp,sline.at(4).toInt());
        datasend(desc,output_ACO_limit.toLatin1());
        clear();
    }

signals:
    void  datasend(int desc,const QByteArray & data);
private:
    QString output_lcost;
    QString output_ltime;
    QString output_limit;
    QString output_way_lcost;
    QString output_way_ltime;
    QString output_ACO_lcost;
    QString output_ACO_ltime;
    QString output_ACO_limit;
    QString output_NOPATH_limit;
    int total_time;
    int depature_time;
    int limit_time;
    int arrive_time;
    int total_charge;
    struct ticket_info  mat[max_citynumber][max_citynumber][max_vehicle_numer];
   // int curruent_time;
};

#endif // MODULE_H
