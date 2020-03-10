#include "aco.h"
#include <common.h>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <ctime>

#define MAXCITY 20
#define MAXANT 5
#define MAXWAY 5
#define INFCOST 8888888
#define INFTIME 88888
#define COST 0
#define START 1
#define END 2
#define TIME 3
#define NORMAL 1
#define ELITE 0.7
#define FACTORA 0.8
#define FACTORB 0.4
#define FACTORP 0.2
#define FACTORQ 100
#define FACTORCOST 100
#define MT 0
#define MC 1
#define MCLT 2
#define STRAIGHT 0
#define PASSTHROUGH 1
#define MAXTC 3
#define MINTC 0.4


using namespace std;

static ifstream in;
static bool flag[MAXCITY][MAXCITY][MAXWAY];
static int schedule[MAXCITY][MAXCITY][MAXWAY][4];
static int Tway[MAXCITY][MAXCITY][MAXWAY][24];
static int MCway[MAXCITY][MAXCITY][24];
static int MTway[MAXCITY][MAXCITY][24];
static int min_t[24];
static int MIN_COST[24];
static string schedulenum[MAXCITY][MAXCITY][MAXWAY];
static double T[MAXCITY][MAXCITY];
static double C[MAXCITY][MAXCITY];
static int bestcost;
static int besttime;
static int bestcitypath[MAXCITY];
static int bestwaypath[MAXCITY];
static int bestgopath[MAXCITY];
static int bestarrivepath[MAXCITY];
static int localbesttime;
static int localbestcost;
static int localbestid;
static int limittime;
static int bestcnt;
static bool testtarget[MAXCITY];
static double timefactor;
static bool setchange;
static string ans;

class Ant
{
public:
    int id;
    int passthrough;
    int passthroughnum;
    int t;
    int day;
    int totalt;
    int totalcost;
    int pos;
    bool* taboo;
    bool* target;
    bool alive;
    bool targetdone;
    int* citypath;
    int* waypath;
    int* gopath;
    int* arrivepath;
    int pathcnt;
    int chanceforcheap;
    Ant(int ID,int mode,int externt,int start,int);
    ~Ant();
    int nextcity();
    void move(int,int,int,int);
    void chooseway(int,int);
    void search(int,int);
    void throughsearch(int,int);
    void update(int,int,int,int);
    void show();
    void isbest(int);
    void islocalbest();
    void settarget(bool*);
};


static Ant* ants[MAXANT];
static double A,B,P,Q;

void Init();
void InitSchedule();
void InitWay();
void InitTway();
void InitMCway();
void InitMTway();
void InitPara();
void ReadTest();
void ShowSchedule();
void ShowWay();
void ShowTC();
string ThroughACO(int antmount,int generations,int start,int end,int t,int mode,int throughnum,bool* throughtarget,int LIMIT);
string ACO0(int antmount,int generations,int start,int end,int t,int mode,int LIMIT);
string getans(int start,int t);
int getnum(char&temp);
int chooseway(int t);

ACO::ACO()
{
    Init();
}
string ACO::gettheans(int antmount,int generations,int start,int end,int t,int mode,int throughnum,bool* throughtarget,int LIMIT)
{
    return ThroughACO(antmount, generations, start, end, t, mode,throughnum, throughtarget, LIMIT);
}

string ACO::gettheNOPATHans(int antmount, int generations, int start, int end, int t,int mode,int LIMIT)
{
    return ACO0(antmount,generations,start,end,t,mode,LIMIT);
}


void Init()
{
    //ReadTest();
    InitPara();
    InitSchedule();
   // qDebug()<<"hibitch";
    InitWay();
    //ShowSchedule();
    //ShowWay();
    //ACO(5, 10, 3, 7, 0, MC);

}



void InitPara()
{
    A=FACTORA;
    B=FACTORB;
    P=FACTORP;
    Q=FACTORQ;
    srand((unsigned int)time(0));
}

void InitSchedule()
{
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            for(int k=0;k<MAXWAY;k++)
            {
                flag[i][j][k]=false;
                schedule[i][j][k][COST]=INFCOST;
            }
    in.open("timetable.txt",ios::in);
    char temp;
    int startcity;
    int endcity;
    int way;
    int starttime;
    int endtime;
    temp=1;
    while(!in.eof())
    {
        in>>startcity;
        in>>endcity;
        in>>way;
        flag[startcity][endcity][way]=true;
        in>>schedulenum[startcity][endcity][way];
        in>>schedule[startcity][endcity][way][COST];
        in>>starttime;
        in>>endtime;
        schedule[startcity][endcity][way][START]=starttime;
        schedule[startcity][endcity][way][END]=endtime;
        if(endtime>starttime)
            schedule[startcity][endcity][way][TIME]=endtime-starttime;
        else
            schedule[startcity][endcity][way][TIME]=24+endtime-starttime;
        in.get(temp);
    }
    /*for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            for(int k=0;k<MAXWAY;k++)
            {
                flag[i][j][k]=false;
                schedule[i][j][k][COST]=INFCOST;
            }
    char temp;
    int startcity;
    int endcity;
    int way;
    int starttime;
    int endtime;
    temp=1;
    QFile file("timetable2.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"file open wrong!2";
    }
    QTextStream in(&file);
    while(!in.atEnd()){

        QString line=in.readLine();
        //qDebug()<<line;
        QList<QString> sline=line.split(' ',QString::SkipEmptyParts);
        startcity=sline.at(0).toInt();
        endcity=sline.at(1).toInt();
        way=sline.at(2).toInt();
        schedulenum[startcity][endcity][way]=sline.at(3).toStdString();
        schedule[startcity][endcity][way][COST]=sline.at(3).toInt();
        starttime=sline.at(4).toInt();
        endtime=sline.at(5).toInt();
        flag[startcity][endcity][way]=1;
        if(endtime>starttime)
            schedule[startcity][endcity][way][TIME]=endtime-starttime;
        else
            schedule[startcity][endcity][way][TIME]=24+endtime-starttime;
    }*/
}


void InitWay()
{
    InitTway();
    InitMCway();
    InitMTway();
   // ShowSchedule();
}

void InitTway()
{
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            for(int k=0;k<MAXWAY;k++)
                if(flag[i][j][k])
                {
                    for(int t=0;t<=schedule[i][j][k][START];t++)
                        Tway[i][j][k][t]=schedule[i][j][k][START]-t+schedule[i][j][k][TIME];
                    for(int t=schedule[i][j][k][START]+1;t<24;t++)
                        Tway[i][j][k][t]=schedule[i][j][k][START]+24-t+schedule[i][j][k][TIME];
                }
                else
                {
                    for(int t=0;t<24;t++)
                        Tway[i][j][k][t]=schedule[i][j][k][START]+24-t+schedule[i][j][k][TIME];
                }
}

void InitMCway()
{
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
        {
            int min_cost=INFCOST;
            for(int p=0;p<24;p++)
                min_t[p]=INFTIME;
            for(int k=0;k<MAXWAY;k++)
            {
                if(flag[i][j][k]&&(schedule[i][j][k][COST]<=min_cost))
                {
                    if(schedule[i][j][k][COST]<min_cost)
                    {
                        min_cost=schedule[i][j][k][COST];
                        for(int t=0;t<24;t++)
                        {
                            MCway[i][j][t]=k;
                            min_t[t]=Tway[i][j][k][t];
                        }
                    }
                    else
                    {
                        for(int t=0;t<24;t++)
                        {
                            if(Tway[i][j][k][t]<min_t[t])
                            {
                                min_t[t]=Tway[i][j][k][t];
                                MCway[i][j][t]=k;
                            }
                        }
                    }
                }
            }
        }
}

void InitMTway()
{
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
        {
            for(int p=0;p<24;p++)
            {
                min_t[p]=INFTIME;
                MIN_COST[p]=INFCOST;
            }
            for(int k=0;k<MAXWAY;k++)
                if(flag[i][j][k])
                {
                    for(int t=0;t<24;t++)
                    {
                        if(Tway[i][j][k][t]<=min_t[t])
                        {
                            if(Tway[i][j][k][t]<min_t[t])
                            {
                                min_t[t]=Tway[i][j][k][t];
                                MIN_COST[t]=schedule[i][j][k][COST];
                                MTway[i][j][t]=k;
                            }
                            else
                            {
                                if(schedule[i][j][k][COST]<MIN_COST[t])
                                {
                                    min_t[t]=Tway[i][j][k][t];
                                    MIN_COST[t]=schedule[i][j][k][COST];
                                    MTway[i][j][t]=k;
                                }
                            }
                        }
                    }
                }
        }
}

void ShowSchedule()
{
    cout<<"ShowSchedule:"<<endl;
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            for(int k=0;k<MAXWAY;k++)
                if(flag[i][j][k])
                {
                    qDebug()<<i<<j<<k;
                    qDebug()<<schedule[i][j][k][COST]<<'\t'<<schedule[i][j][k][START]<<'\t';
                    qDebug()<<schedule[i][j][k][END]<<'\t'<<schedule[i][j][k][TIME]<<endl;
                }
}

void ShowWay()
{
    cout<<"ShowTWay:"<<endl;
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            for(int k=0;k<MAXWAY;k++)
                if(flag[i][j][k])
                {
                    cout<<"TWayFor"<<" "<<i<<" "<<j<<" "<<k<<endl;
                    for(int t=0;t<24;t++)
                    {
                        cout<<"t:"<<t<<'\t'<<Tway[i][j][k][t]<<endl;
                    }
                }
    cout<<"ShowMCWay:"<<endl;
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            if(flag[i][j][0])
            {
                cout<<"MCWayFor"<<" "<<i<<" "<<j<<endl;
                for(int t=0;t<24;t++)
                {
                    cout<<"t:"<<t<<'\t'<<MCway[i][j][t]<<endl;
                }
            }
    cout<<"ShowMTWay:"<<endl;
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
            if(flag[i][j][0])
            {
                cout<<"MTWayFor"<<" "<<i<<" "<<j<<endl;
                for(int t=0;t<24;t++)
                {
                    cout<<"t:"<<t<<'\t'<<MTway[i][j][t]<<endl;
                }
            }
}

void ReadTest()
{
    cout<<"TEST"<<endl;
    in.open("/Users/chenzibo/Desktop/ACO/AOC/AOC/travel.txt",ios::in);
    char temp;
    while(in.get(temp))
    {
        cout<<temp;
    }
    cout<<"EOF"<<endl;
    in.close();
}

string ThroughACO(int antmount,int generations,int start,int end,int t,int mode,int throughnum,bool* throughtarget,int LIMIT)
{
    setchange=false;
    timefactor=1.0;
    bestcnt=0;
    bestcost=INFCOST;
    besttime=INFTIME;
    limittime=LIMIT;
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
        {
            T[i][j]=0.5;
            C[i][j]=0.5;
        }
    for(int g=0;g<generations;g++)
    {
        localbestid=0;
        localbestcost=INFCOST;
        localbesttime=INFTIME;
        for(int i=0;i<antmount;i++)
            ants[i]=new Ant (i,mode,t,start,PASSTHROUGH);
        if(setchange)
        {
            for(int i=0;i<antmount;i++)
                ants[i]->chanceforcheap=limittime-besttime;
        }
        for(int i=0;i<antmount;i++)
            ants[i]->passthroughnum=throughnum;
        for(int i=0;i<antmount;i++)
            ants[i]->settarget(throughtarget);
        for(int i=0;i<antmount;i++)
            ants[i]->throughsearch(mode,end);
        for(int i=0;i<MAXCITY;i++)
            for(int j=0;j<MAXCITY;j++)
            {
                T[i][j]=(1-P)*T[i][j];
                C[i][j]=(1-P)*C[i][j];
            }
        for(int i=0;i<antmount;i++)
            ants[i]->update(mode,start,NORMAL,PASSTHROUGH);
        for(int i=0;i<MAXCITY;i++)
            for(int j=0;j<MAXCITY;j++)
            {
                if(T[i][j]<MINTC)
                    T[i][j]=MINTC;
                else if(T[i][j]>MAXTC)
                    T[i][j]=MAXTC;
                if(C[i][j]<MINTC)
                    C[i][j]=MINTC;
                else if(C[i][j]>MAXTC)
                    C[i][j]=MAXTC;
            }
        //ShowTC();
        ants[localbestid]->update(mode,start,1,PASSTHROUGH);
        for(int i=0;i<antmount;i++)
            ants[i]->~Ant();
    }
    ans=getans(start, t);
    return ans;
}

string ACO0(int antmount,int generations,int start,int end,int t,int mode,int LIMIT)
{
    limittime=LIMIT;
    setchange=false;
    timefactor=1.0;
    bestcost=INFCOST;
    besttime=INFTIME;
    for(int i=0;i<MAXCITY;i++)
        for(int j=0;j<MAXCITY;j++)
        {
            T[i][j]=0.5;
            C[i][j]=0.5;
        }
    for(int g=0;g<generations;g++)
    {
        localbestid=0;
        localbestcost=INFCOST;
        localbesttime=INFTIME;
        for(int i=0;i<antmount;i++)
            ants[i]=new Ant (i,mode,t,start,STRAIGHT);
        if(setchange)
        {
        for(int i=0;i<antmount;i++)
            ants[i]->chanceforcheap=limittime-besttime;
        }
        for(int i=0;i<antmount;i++)
            ants[i]->search(mode,end);
        for(int i=0;i<antmount;i++)
            ants[i]->update(mode,start,NORMAL,STRAIGHT);
        ants[localbestid]->update(mode,start,1,STRAIGHT);
        for(int i=0;i<antmount;i++)
            ants[i]->~Ant();
        for(int i=0;i<MAXCITY;i++)
            for(int j=0;j<MAXCITY;j++)
            {
                T[i][j]=(1-FACTORP)*T[i][j];
                C[i][j]=(1-FACTORP)*C[i][j];
            }
        for(int i=0;i<MAXCITY;i++)
            for(int j=0;j<MAXCITY;j++)
            {
                if(T[i][j]<0.4)
                    T[i][j]=04;
                else if(T[i][j]>3)
                    T[i][j]=3;
                if(C[i][j]<0.4)
                    C[i][j]=0.4;
                else if(C[i][j]>3)
                    C[i][j]=3;
            }
        //ShowTC();
    }
    ans=getans(start, t);
    return ans;
}




Ant::Ant(int ID,int mode,int externt,int start,int through)
{
    chanceforcheap=0;
    targetdone=false;
    passthrough=through;
    id=ID;
    citypath=new int[MAXCITY];
    waypath =new int[MAXCITY];
    gopath=new int[MAXCITY];
    arrivepath=new int[MAXCITY];
    taboo=new bool[MAXCITY];
    target=new bool[MAXCITY];
    t=externt;
    totalt=0;
    day=0;
    totalcost=0;
    pos=start;
    pathcnt=0;
    alive=true;
    for(int j=0;j<MAXCITY;j++)
        taboo[j]=false;
    taboo[start]=true;
}

Ant::~Ant()
{
    delete target;
    delete citypath;
    delete waypath;
    delete gopath;
    delete arrivepath;
    delete taboo;
}

void Ant::search(int mode,int end)
{
    while (alive)
    {
        chooseway(mode,STRAIGHT);
        if(pos==end)
        {
            //cout<<"ant arrive< cost:"<<totalcost<<" time:"<<totalt<<endl;
            if(mode==MC)
            {
                if(totalcost<=bestcost)
                {
                    if(totalcost<bestcost)
                        isbest(mode);
                    else if(totalt<besttime)
                        isbest(mode);
                }
                if(totalcost<=localbestcost)
                {
                    if(totalcost<localbestcost)
                        islocalbest();
                    else if(totalt<localbesttime)
                        islocalbest();
                }
            }
            else if (mode==MT)
            {
                if(totalt<=besttime)
                {
                    if(totalt<besttime)
                        isbest(mode);
                    else if(totalcost<bestcost)
                        isbest(mode);
                }
                if(totalt<=localbesttime)
                {
                    if(totalt<localbesttime)
                        islocalbest();
                    else if(totalcost<localbestcost)
                        islocalbest();
                }
            }
            else if (mode==MCLT)
            {
                if(alive)
                {
                    if(totalcost<=bestcost)
                    {
                        if(totalcost<bestcost)
                            isbest(mode);
                        else if(totalt<besttime)
                            isbest(mode);
                    }
                    if(totalcost<=localbestcost)
                    {
                        if(totalcost<localbestcost)
                            islocalbest();
                        else if(totalt<localbesttime)
                            islocalbest();
                    }
                }
            }
            break;
        }
    }
}

void Ant::throughsearch(int mode,int end)
{
    while (alive)
    {
        chooseway(mode,PASSTHROUGH);
        if(targetdone)
        {
            search(mode, end);
            break;
        }
    }
}

void Ant::update(int mode,int start,int elitefactor,int passthrough)
{
    if(alive)
    {
        double deltaT=(elitefactor*Q)/totalt;
        double deltaC=(elitefactor*FACTORCOST*Q)/totalcost;
        int first=start;
        int last;
        for(int i=0;i<pathcnt;i++)
        {
            last=citypath[i];
            T[first][last]+=deltaT;
            C[first][last]+=deltaC;
            first=last;
        }
    }
}

void Ant::chooseway(int mode,int passthrough)
{
    int * p=new int[MAXCITY];
    int * pcity=new int[MAXCITY];
    int * p2=new int[MAXCITY];
    int * pcity2=new int[MAXCITY];
    int cnt=0;
    int cnt2=0;
   // qDebug()<<"CHOOSEWAY:"<<endl;
    bool cheapcity=false;
    if(mode==MCLT&&(int)timefactor!=1)
    {
        double pcheap=0.6*((double)chanceforcheap/(double)limittime)+0.08;
        int PCHEAP=pcheap*1000;
        int choosecheap=rand()%1000;
        if(choosecheap<PCHEAP)
            cheapcity=true;
    }
    for(int i=0;i<MAXCITY;i++)
    {
        if(taboo[i]||!flag[pos][i][0])
        {

        }
        else
        {
            if(mode==MC)
            {
                int way=MCway[pos][i][t];
                double cost=schedule[pos][i][way][COST];
               // qDebug()<<"cost:"<<cost<<" "<<"p="<<pow(C[pos][i],A)<<" * "<<pow(double(FACTORCOST)/cost, B)<<endl;
                p[cnt]=5+1000*(pow(C[pos][i],A)*pow(double(FACTORCOST)/cost, B));
               // qDebug()<<"cnt:"<<cnt<<" P for "<<pos<<" "<<i<<" is"<<p[cnt]<<endl;
                pcity[cnt]=i;
                cnt++;
            }
            else if(mode==MT)
            {
                int way=MTway[pos][i][t];
                int timecost=Tway[pos][i][way][t];
                p[cnt]=5+1000*(pow(T[pos][i],A)*pow(1.0/double(timecost), B));
               // qDebug()<<"time:"<<timecost<<" "<<"p="<<pow(T[pos][i],A)<<" * "<<pow(1.0/double(timecost), B)<<endl;
                pcity[cnt]=i;
              //  qDebug()<<"cnt:"<<cnt<<" P for "<<pos<<" "<<i<<" is"<<p[cnt]<<endl;
                cnt++;
            }
            else if(mode==MCLT)
            {
                int way=MTway[pos][i][t];
                int timecost=Tway[pos][i][way][t];
                p[cnt]=5+1000*(pow(T[pos][i],A)*pow(1.0/double(timecost), B));
                pcity[cnt]=i;
                cnt++;

                way=MCway[pos][i][t];
                double cost=schedule[pos][i][way][COST];
                //cout<<"cost:"<<cost<<" "<<"p="<<pow(C[pos][i],A)<<" * "<<pow(double(FACTORCOST)/cost, B)<<endl;
                p2[cnt2]=5+1000*(pow(C[pos][i],A)*pow(double(FACTORCOST)/cost, B));
                //cout<<"cnt:"<<cnt<<" P for "<<pos<<" "<<i<<" is"<<p[cnt]<<endl;
                pcity2[cnt2]=i;
                cnt2++;
            }
        }
    }
    if(cnt==0)
    {
        alive=false;
        //cout<<"ant die!!!"<<endl;
        //cout<<"Resurrection！"<<endl;;
        for(int i=0;i<MAXCITY;i++)
        {
            if(flag[pos][i][0])
                taboo[i]=false;
        }
        delete [] p;
        delete [] p2;
        delete [] pcity;
        delete [] pcity2;
    }
    else
    {
        int total=0;
        for(int index=0;index<cnt;index++)
            total+=p[index];
        int choose=((int)rand())%total;
        int index=0;
        while(choose>=p[index])
        {
            choose-=p[index];
            index++;
        }
        int index2=0;
        total=0;
        if(MCLT&&cheapcity)
        {
            for(int index=0;index<cnt2;index++)
                total+=p2[index];
            int choose=((int)rand())%total;
            index2=0;
            while(choose>=p2[index2])
            {
                choose-=p2[index2];
                index2++;
            }
        }
        int nxtcity=pcity[index];
        int nxtcity2=0;
        int way=MTway[pos][nxtcity][t];
        if(mode==MC)
            way=MCway[pos][nxtcity][t];
        int way2=0;
        if(MCLT&&cheapcity)
        {
            nxtcity2=pcity2[index2];
            way2=MCway[pos][nxtcity2][t];
            int deltatime=Tway[pos][nxtcity2][way2][t]-Tway[pos][nxtcity][way][t];
            chanceforcheap-=deltatime;
            if(chanceforcheap<0)
                chanceforcheap=limittime*0.05;
            nxtcity=nxtcity2;
            way=way2;
        }
        delete [] p;
        delete [] pcity;
        delete [] p2;
        delete [] pcity2;
        move(nxtcity, way,passthrough,mode);
    }
}

void Ant::move(int nxtcity, int way,int passthrough,int mode)
{
    if(passthrough==PASSTHROUGH)
    {
        if(target[nxtcity])
        {
            target[nxtcity]=false;
            passthroughnum--;
        }
        if(passthroughnum==0)
            targetdone=true;
    }
    //cout<<"ant move from "<<pos<<" to "<<nxtcity<<" by "<<way<<" ";
    int firsttime=schedule[pos][nxtcity][way][TIME];
    int lasttime=Tway[pos][nxtcity][way][t];
    totalt+=lasttime;
    if(mode==MCLT&&totalt>limittime)
    {
        alive=false;
        //cout<<"ant die!!!"<<endl;
        return;
    }
    //cout<<"at "<<totalt<<endl;
    gopath[pathcnt]=totalt-firsttime;
    arrivepath[pathcnt]=totalt;
    totalcost+=schedule[pos][nxtcity][way][COST];
    taboo[nxtcity]=true;
    citypath[pathcnt]=nxtcity;
    waypath[pathcnt]=way;
    pathcnt++;
    t=t+lasttime;
    if(t>=24)
    {
        t-=24;
        day+=1;
    }
    pos=nxtcity;
}


void Ant::isbest(int mode)
{
    bestcost=totalcost;
    besttime=totalt;
    bestcnt=pathcnt;
    for(int i=0;i<pathcnt;i++)
    {
        bestcitypath[i]=citypath[i];
        bestwaypath[i]=waypath[i];
        bestgopath[i]=gopath[i];
        bestarrivepath[i]=arrivepath[i];
    }
    if(mode==MCLT)
    {
        timefactor=(double)besttime/(double)limittime;
        setchange=true;
    }
    //show();
}

void Ant::islocalbest()
{
    localbestcost=totalcost;
    localbesttime=totalt;
    localbestid=id;
}

void Ant::show()
{
    cout<<"Antshow: cost: "<<totalcost<<" time:"<<totalt<<endl;
    for(int i=0;i<pathcnt;i++)
    {
        cout<<"path:"<<citypath[i]<<" "<<waypath[i]<<" time:"<<gopath[i]<<" "<<arrivepath[i]<<endl;
    }
    cout<<endl;
}

void Ant::settarget(bool *throughtarget)
{
    for(int i=0;i<MAXCITY;i++)
        target[i]=throughtarget[i];
}

void ShowTC()
{
    cout<<"T:"<<endl;
    for(int i=0;i<MAXCITY;i++)
    {
        for(int j=0;j<MAXCITY;j++)
            cout<<T[i][j]<<'\t';
        cout<<endl;
    }
    cout<<"C:"<<endl;
    for(int i=0;i<MAXCITY;i++)
    {
        for(int j=0;j<MAXCITY;j++)
            cout<<T[i][j]<<'\t';
        cout<<endl;
    }
}

string getans(int start,int t)
{
    string s;
   // qDebug()<<bestcnt<<"hi";
    s+=to_string(start);
    for(int i=0;i<bestcnt;i++)
    {
      //  qDebug()<<"hi";
        s+=' ';
        s+=to_string((t+bestgopath[i])%24);
        s+=' ';
        s+=schedulenum[start][bestcitypath[i]][bestwaypath[i]];
        s+=' ';
        s+=to_string(schedule[start][bestcitypath[i]][bestwaypath[i]][COST]);
        s+=' ';
        s+=to_string((t+bestarrivepath[i])%24);
        s+=' ';
        s+=to_string(bestcitypath[i]);
        start=bestcitypath[i];
    }
    return s;
}
