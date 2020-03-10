#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "module.h"
#include "common.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    myserver = new Server(this);

    if(!myserver->listen(QHostAddress::Any, 8172)){
        qDebug()<<"wrong!";
    }else{
        qDebug()<<"yes!";
    }
    curruenttime=0;
    ui->lcd_timer->display(curruenttime);
    connect(myserver,SIGNAL(update()),this,SLOT(updatetimedisplay()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::updatetimedisplay(){
    curruenttime++;
    curruenttime=(curruenttime+24)%24;
    ui->lcd_timer->display(curruenttime);
   // mol->add_time();
}



void MainWindow::on_le_returnPressed()
{
   // qDebug()<<"hibitch";
}
