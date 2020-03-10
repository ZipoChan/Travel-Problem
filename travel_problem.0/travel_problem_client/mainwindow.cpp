#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdebug.h>
#include <QList>
#include <QAbstractButton>
#include "QHostAddress"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    curruent_time=0;

    //qtr=new QTimer();
    //connect(qtr,SIGNAL(timeout()),this,SLOT(updatetime()));
    //qtr->start(1000);

    this->sc = new myScence(nullptr,curruent_time);
    //sc->updatemap(string_test);

    //updatetime_hour&updatetime_mini
    socket =new QTcpSocket();
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::socket_read_data);
    socket_connect();
    connect(sc,SIGNAL(tomain(QString)),this,SLOT(rev_mys(QString)));
   // connect(qtr,SIGNAL(timeout()),sc,SLOT(updatetime()));
    this->ui->graphicsView->setScene(sc);

    //this->ana_result(string_test);
}
void MainWindow::rev_mys(QString Q){
    ui->xy->setText(Q);
}
void MainWindow::socket_read_data(){
    buffer=socket->readAll();
    qDebug()<<buffer;
    QString temp =buffer;
    QList<QString> sline=temp.split(" ",QString::SkipEmptyParts);
    if(sline.at(0)=="link"){
        QTime t;
        t.start();
        while(t.elapsed()<400-sline.at(2).toInt())
            QCoreApplication::processEvents();
        curruent_time=sline.at(1).toInt()+1;
        username=sline.at(3);
        sc->getusername(username);
        ui->le_name->setText(username);
        raw_timer = new QTimer();
        sc->timechange(sline.at(1).toInt()+1);
        connect(raw_timer,SIGNAL(timeout()),this,SLOT(updatetime()));
        connect(raw_timer,SIGNAL(timeout()),sc,SLOT(updatetime_hour()));
        raw_timer->start(2000);
        smooth_timer = new QTimer();
        connect(smooth_timer,SIGNAL(timeout()),sc,SLOT(updatetime_mini()));
        smooth_timer->start(100);
        QFile *file =new QFile;
        file->setFileName(username+"_dialog.txt");
        if(!file->open(QIODevice::Append)|QIODevice::Text){
            qDebug()<<"wrong!";
        }
        QTextStream in(file);
        in<<"login"<<"\r\n";
        file->close();
    }
    else if(sline.size()<4){
        ana_result(buffer);
    }
    else{
        ana_result(buffer);
        sc->updatemap(buffer);
    }
}
void MainWindow::socket_connect(){
    socket->abort();
    socket->connectToHost(QHostAddress("10.122.208.244"),8172);

    if(!socket->waitForConnected(30000)){
        qDebug()<<tr("failed to connect");
    }
    else{
        qDebug()<<tr("success");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatetime(){
    curruent_time++;
    curruent_time%=24;
    this->ui->lcdTimer->display(curruent_time);
}

void revdata(){
//    this->sc->draw()
}

void MainWindow::ana_result(QString data_string){
    ui->textBrowser->clear();
    QString city_name[20] = {"北京", "上海", "广州", "哈尔滨", "沈阳", "天津", "兰州", "成都", "贵阳", "武汉", "济南", "西宁", "昆明", "合肥", "西安", "石家庄", "呼和浩特", "厦门", "长沙", "南宁"};
    QList<QString> travel_string_list = data_string.split(" ",QString::SkipEmptyParts);
    if(travel_string_list.size()<2){
        this->ui->textBrowser->setText("没有找到合适的路线！");
    }else{
    for (int i = 0; i < travel_string_list.length() - 1; i+=5) {
        int start_city = travel_string_list.at(i).toInt();
        int arrive_city = travel_string_list.at(i+5).toInt();
        QString start_time = travel_string_list.at(i+1);
        QString arrive_time = travel_string_list.at(i+4);
        QString travel_measure = travel_string_list.at(i+2);
        QString price = travel_string_list.at(i+3);
        QString print_string = "";
        print_string += start_time+":00从"+city_name[start_city]+"出发，乘坐"+travel_measure+
                "于"+arrive_time+":00到达"+city_name[arrive_city]+"，票价"+price+"元";
        this->ui->textBrowser->append(print_string);
    }}
}

void MainWindow::on_ptn_ok_clicked()
{
   QFile file(username+"_dialog.txt");
   if(!file.open(QIODevice::Append)|QIODevice::Text){
       qDebug()<<"wrong!";
   }
   QTextStream in(&file);


   in<<"inqure"<<"\r\n";
   file.close();
    QString way_city;
    QString buffer;
    if(ui->bj->isChecked()==true){
        way_city+="0";
        way_city+=" ";
    }
    if(ui->sh->isChecked()==true){
        way_city+="1";
        way_city+=" ";
    }
    if(ui->gz->isChecked()==true){
        way_city+="2";
        way_city+=" ";
    }
    if(ui->heb->isChecked()==true){
        way_city+="3";
        way_city+=" ";
    }
    if(ui->sy->isChecked()==true){
        way_city+="4";
        way_city+=" ";
    }
    if(ui->tj->isChecked()==true){
        way_city+="5";
        way_city+=" ";
    }
    if(ui->lz->isChecked()==true){
        way_city+="6";
        way_city+=" ";
    }
    if(ui->cd->isChecked()==true){
        way_city+="7";
        way_city+=" ";
    }
    if(ui->gy->isChecked()==true){
        way_city+="8";
        way_city+=" ";
    }
    if(ui->wh->isChecked()==true){
        way_city+="9";
        way_city+=" ";
    }

    if(ui->jn->isChecked()==true){
        way_city+="10";
        way_city+=" ";
    }
    if(ui->xn->isChecked()==true){
        way_city+="11";
        way_city+=" ";
    }
    if(ui->km->isChecked()==true){
        way_city+="12";
        way_city+=" ";
    }
    if(ui->hf->isChecked()==true){
        way_city+="13";
        way_city+=" ";
    }
    if(ui->xa->isChecked()==true){
        way_city+="14";
        way_city+=" ";
    }
    if(ui->sjz->isChecked()==true){
        way_city+="15";
        way_city+=" ";
    }
    if(ui->hhht->isChecked()==true){
        way_city+="16";
        way_city+=" ";
    }
    if(ui->xm->isChecked()==true){
        way_city+="17";
        way_city+=" ";
    }
    if(ui->cs->isChecked()==true){
        way_city+="18";
        way_city+=" ";
    }
    if(ui->nn->isChecked()==true){
        way_city+="19";
        way_city+=" ";
    }
    if(ui->co_p->currentIndex()==0){
        if(way_city.size())
            buffer="4 "+QString::number(ui->co_s->currentIndex())+" "+QString::number(ui->co_e->currentIndex())+" "+QString::number(curruent_time)+" "+way_city+"E";
        else{
            buffer="1 "+QString::number(ui->co_s->currentIndex())+" "+QString::number(ui->co_e->currentIndex())+" "+QString::number(curruent_time)+" ";
        }
    }
    else if(ui->co_p->currentIndex()==1){
        if(way_city.size())
            buffer="5 "+QString::number(ui->co_s->currentIndex())+" "+QString::number(ui->co_e->currentIndex())+" "+QString::number(curruent_time)+" "+way_city+"E";
        else{
            buffer="2 "+QString::number(ui->co_s->currentIndex())+" "+QString::number(ui->co_e->currentIndex())+" "+QString::number(curruent_time);
        }
    }
    else if(ui->co_p->currentIndex()==2){
        if(way_city.size())
            buffer="6 "+QString::number(ui->co_s->currentIndex())+" "+QString::number(ui->co_e->currentIndex())+" "+QString::number(curruent_time)+" "+ui->lineEdit->text()+" "+way_city+"E";
        else{
            buffer="3 "+QString::number(ui->co_s->currentIndex())+" "+QString::number(ui->co_e->currentIndex())+" "+QString::number(curruent_time)+" "+ui->lineEdit->text();
        }
    }
    socket->write(buffer.toLatin1());
}
