#include "mainwindow.h"
#include <QApplication>
#include "module.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
  //  Module *mol= new Module;
   // mol.ACO_ltime_route(4,400,0,10,0,1,temp);
   // mol.send_data();
    //QList<int>K={5,2,3};
    //mol.least_cost_route(2,10,0);
    //mol.least_time_route(2,10,0,1);
    //mol->limit_time_least_cost_route(2,10,1,100);
  //mol.least_time_route_waycity(7,10,23,K);
   //mol.least_cost_route_waycity(2,10,K);
   return a.exec();
}
