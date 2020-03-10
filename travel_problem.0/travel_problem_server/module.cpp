#include "module.h"
#include "common.h"

Module::Module(){
    //curruent_time=c_time;
   total_charge=0;
    QFile file("timetable.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"file open wrong!";
    }
    int i, j, k;
    for (i = 0; i < max_citynumber;i++)
        for (j = 0; j < max_citynumber;j++)
            for (k = 0; k < max_vehicle_numer;k++)
            {
                mat[i][j][k].price=INF;
                mat[i][j][k].arrive_time=-1;
                mat[i][j][k].start_time=-1;
            }
    QTextStream in(&file);
    while(!in.atEnd()){
        QString line=in.readLine();
        //qDebug()<<line;
        QList<QString> sline=line.split(' ',QString::SkipEmptyParts);
        // qDebug()<<sline.at(0)<<sline.at(1)<<sline.at(2)<<sline.at(3)<<sline.at(4)<<sline.at(5)<<sline.at(6);
        mat[sline.at(0).toInt()][sline.at(1).toInt()][sline.at(2).toInt()].train_number=sline.at(3);
        mat[sline.at(0).toInt()][sline.at(1).toInt()][sline.at(2).toInt()].price=sline.at(4).toInt();
        mat[sline.at(0).toInt()][sline.at(1).toInt()][sline.at(2).toInt()].start_time=sline.at(5).toInt();
        mat[sline.at(0).toInt()][sline.at(1).toInt()][sline.at(2).toInt()].arrive_time=sline.at(6).toInt();
    }


    qDebug()<<"module load the map";
}

Module::~Module(){}

int Module::least_cost_route(int source,int destination,int outputflag){
    PATH Path[max_citynumber];
    for (int i = 0; i < max_citynumber;++i){
        if(i!=source){
            Path[i].precity = -1;
            Path[i].vehicle_type = -1;
            Path[i].charge = INF;
        }}
    Path[source].precity = source;
    Path[source].vehicle_type = -1;
    Path[source].shortest_time = 0;
    Path[source].charge = 0;
    int Queue[max_citynumber] = {0};
    int nextsource=source;
    for (int i = 0; i < max_citynumber;++i)
        if (i != source)
            Queue[i] = 1;
    while(Queue[destination]){
        nextsource = relax_lcost(nextsource, Path[nextsource].charge, Queue,Path);
       // qDebug()<<nextsource;
        Queue[nextsource] = 0;
    }
    if(outputflag==0){
        total_charge=Path[destination].charge;
        output_path(source, destination,Path,0);
       // send_data();
    }else if(outputflag==2){
        total_charge+=Path[destination].charge;
        output_path(source,destination,Path,2);
    }
    return Path[destination].charge;
}

int Module::relax_lcost(int source, int temp_charge, int *Queue, struct PATH *Path){
    int nextsource=-1;
    int temp_cheapest = INF;
    for (int i = 0; i < max_citynumber;++i){
        for (int k = 0; k < max_vehicle_numer;++k)
            if(mat[source][i][k].price<INF){
                int temp = mat[source][i][k].price+temp_charge;
                if (temp < Path[i].charge&&Queue[i])
                {
                    Path[i].charge = temp;
                    Path[i].vehicle_type = k;
                    Path[i].precity = source;
                    Path[i].shortest_time = mat[source][i][k].arrive_time;
                }
            }
        if(Path[i].charge<temp_cheapest&&Queue[i]){
            temp_cheapest = Path[i].charge;
            nextsource = i;
        }
    }
    return nextsource;
}

void Module::output_path(int source, int destination, struct PATH *Path,int flag){//0output_lcost 1output_ltime 2 output_way_lost 4_output_way_ltime
    if(flag==0){
    if(destination==source){
            output_lcost=QString::number(source)+" ";}

    else if (Path[destination].precity == -1)
        output_lcost=" no path ";
    else{
        output_path(source, Path[destination].precity,Path,flag);
        output_lcost=output_lcost+QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].start_time)+" "
                +mat[Path[destination].precity][destination][Path[destination].vehicle_type ].train_number+" "+
                QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].price)+" "
                +QString::number(Path[destination].shortest_time)+" "+QString::number(destination)+" ";
    }}
    if(flag==1){
        if(destination==source){
                output_ltime=QString::number(source)+" ";}

        else if (Path[destination].precity == -1)
            output_ltime=" no path ";
        else{
            output_path(source, Path[destination].precity,Path,flag);
            output_ltime=output_ltime+QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].start_time)+" "
                    +mat[Path[destination].precity][destination][Path[destination].vehicle_type ].train_number+" "+
                    QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].price)+" "
                    +QString::number(Path[destination].shortest_time)+" "+QString::number(destination)+" ";
        }}
    if(flag==2){
    if(destination==source){
            output_way_lcost+=QString::number(source)+" ";}

    else if (Path[destination].precity == -1)
        output_way_lcost=" no path ";
    else{
        output_path(source, Path[destination].precity,Path,flag);
        output_way_lcost=output_way_lcost+QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].start_time)+" "
                +mat[Path[destination].precity][destination][Path[destination].vehicle_type ].train_number+" "+
                QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].price)+" "
                +QString::number(Path[destination].shortest_time)+" "+QString::number(destination)+" ";
    }}
    if(flag==3){
    if(destination==source){
            output_way_ltime+=QString::number(source)+" ";}

    else if (Path[destination].precity == -1)
        output_way_ltime=" no path ";
    else{
        output_path(source, Path[destination].precity,Path,flag);
        output_way_ltime=output_way_ltime+QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].start_time)+" "
                +mat[Path[destination].precity][destination][Path[destination].vehicle_type ].train_number+" "+
                QString::number(mat[Path[destination].precity][destination][Path[destination].vehicle_type ].price)+" "
                +QString::number(Path[destination].shortest_time)+" "+QString::number(destination)+" ";
    }}
}
void Module::send_data(QString Q){
    qDebug()<<Q;
}

void Module::least_cost_route_waycity(int source,int destination,QList<int>way_city){
    int dest=way_city.at(0);
    way_city.append(destination);
    int i=0;
    int sour=source;
    while(dest!=destination){
        least_cost_route(sour,dest,2);
        sour=dest;
        i++;
        dest=way_city.at(i);
    }
    least_cost_route(sour,dest,2);
 //   send_data();
}

int Module::least_time_route(int source, int destination, int current_time,int outputflag){
    PATH Path[max_citynumber];
    for (int i = 0; i < max_citynumber;++i){
        if(i!=source){
            Path[i].precity = -1;
            Path[i].vehicle_type = -1;
            Path[i].shortest_time = INF;
            Path[i].charge = 0;
        }}
    Path[source].charge = 0;
    Path[source].precity = source;
    Path[source].vehicle_type = -1;
    Path[source].shortest_time = 0;

    int Queue[max_citynumber] = {0};
    for (int i = 0; i < max_citynumber;++i)
        if (i != source)
            Queue[i] = 1;
    int nextsource=source;
    int temp_shortest = INF;
    for (int i = 0; i < max_citynumber;++i){
        for (int k = 0; k < max_vehicle_numer;++k){
            if(mat[source][i][k].price<INF){
                int temp = (mat[source][i][k].arrive_time - mat[source][i][k].start_time + 24) % 24 +
                           (mat[source][i][k].start_time - current_time + 24) % 24;
                if (temp < Path[i].shortest_time)
                {
                    Path[i].shortest_time = temp;
                    Path[i].vehicle_type = k;
                    Path[i].precity = source;
                }
            }
        }
        if(Path[i].shortest_time<temp_shortest&&i!=source){
            temp_shortest = Path[i].shortest_time;
            nextsource = i;
        }
    }
    Queue[nextsource] = 0;
    int temp_time = current_time;
    while(Queue[destination]){
        nextsource = relax_ltime(nextsource, (temp_time + Path[nextsource].shortest_time)%24, Queue,Path);
        Queue[nextsource] = 0;
    }
    if(outputflag==1){
        total_time= Path[destination].shortest_time;
       // total_charge+=Path[destination].charge;
        //qDebug() << "Total cost:" << Path[destination].shortest_time;
        output_path(source, destination,Path,1);
        //send_data();
    }else if(outputflag==3){
        total_time+=Path[destination].shortest_time;
        output_path(source,destination,Path,3);
    }
    return Path[destination].shortest_time;
}
int Module::relax_ltime(int temp_source, int temp_current_time, int *Queue, struct PATH *Path){
    int next_source;
    int temp_shortest = INF;
    for (int i = 0; i < max_citynumber;++i){
        for (int k = 0; k < max_vehicle_numer;++k){
            if(mat
        [temp_source][i][k].price<INF){
                int temp = (mat[temp_source][i][k].arrive_time - mat[temp_source][i][k].start_time + 24) % 24 +
                           (mat[temp_source][i][k].start_time - temp_current_time + 24) % 24;
                if (temp+Path[temp_source].shortest_time < Path[i].shortest_time&&Queue[i])
                {
                    Path[i].shortest_time = temp+Path[temp_source].shortest_time;
                    Path[i].vehicle_type = k;
                    Path[i].precity = temp_source;
                }
            }
        }
        if(Path[i].shortest_time<temp_shortest&&Queue[i]){
            next_source = i;
            temp_shortest = Path[i].shortest_time;
        }
    }
    return next_source;
}
/*void Module::limit_time_waycity(int source, int destination, int curruent_time, int limit_time, QList<int> way_city){
    QList<int>way_city_copy=way_city;
        way_city_copy.append(destination);
    total_time=0;
    total_charge=0;
    int dest=way_city_copy.at(0);
    int i=0;
    int sour=source;
    while(dest!=destination){
        least_time_route(sour,dest,curruent_time+total_time,0);
        sour=dest;
        i++;
        dest=way_city_copy.at(i);
    }
   least_time_route(sour,dest,(curruent_time+total_time)%24,0);
    if(total_time>limit_time){
        output="no path";
    }
    else if(total_time<limit_time){
        struct PATH2 *p= new struct PATH2;
        dynamic_limit_time_least_cost_route_waycity(source,destination,curruent_time,limit_time,way_city,p);
        output=QString::number(source);
        int tempsource=source;
        while(p->next_city){
            output+=" "+QString::number(mat[tempsource][p->next_city_number][p->next_vehicle_number].start_time)+" "
                    +QString::number(mat[tempsource][p->next_city_number][p->next_vehicle_number].arrive_time)+" "+QString::number(p->next_city_number);
            tempsource=p->next_city_number;
            struct PATH2 *temp_p = p;
            p = p->next_city;
            delete temp_p;
        }
        delete p;
       send_data();
    }
}*/
/*int Module::dynamic_limit_time_least_cost_route_waycity(int source, int destination, int curruent_time, int limit_time, QList<int> way_city, struct PATH2 *p){
   // qDebug()<<"dl";
   // qDebug()<<way_city;
    if(way_city.size()==0) {
         int shortest_time=least_time_route(source,destination,curruent_time,4);
         if(shortest_time<limit_time){
      int tempcharge=dynamic_find_limit_least_cost(source,destination,limit_time,curruent_time,p);
      //  qDebug()<<tempcharge;
        return tempcharge;}
         else {
             return INF;
         }
    }else {
         int temp_least_charge=INF;
         for (int i = 0; i < max_citynumber;i++)
         {
             for (int k = 0; k < max_vehicle_numer;k++){
                 if(mat[source][i][k].price<INF)
                     {
                         QList<int> way_city_copy=way_city;
                        if(i==way_city.at(0)){
                           way_city_copy.removeFirst();
                        }
                         struct PATH2 *tempp = new struct PATH2;
                         tempp->next_city=NULL;
                         int temp_time=(mat[source][i][k].arrive_time - mat[source][i][k].start_time + 24) % 24 +
                             (mat[source][i][k].start_time - curruent_time + 24) % 24;//source到i所需时间
                         int temp = least_time_route_waycity(i, destination, (curruent_time+temp_time)%24,way_city)+temp_time;
                         if(temp<=limit_time){
                             int nextcharge = mat[source][i][k].price
                                     +dynamic_limit_time_least_cost_route_waycity(i, destination, mat[source][i][k].arrive_time, limit_time - temp_time,way_city_copy,tempp);
                             if(nextcharge<temp_least_charge)
                             {

                                 p->next_city = tempp;
                                 p->next_city_number = i;
                                 p->next_vehicle_number = k;
                                 p->next_arrive_time = mat[source][i][k].arrive_time;
                                 temp_least_charge = nextcharge;
                             }else{
                                 delete tempp;
                             }
                         }
                     }
                 else
                     break;
             }
         }
         return temp_least_charge;
}
}*/
int Module::least_time_route_waycity(int source,int destination,int curruent_time,QList<int>way_city){
    //qDebug()<<source<<destination<<curruent_time<<way_city;
    total_time=0;
    total_charge=0;
    int dest=way_city.at(0);
     QList<int>way_city_copy=way_city;
    way_city_copy.append(destination);
    int i=0;
    int sour=source;
    while(dest!=destination){
        least_time_route(sour,dest,(curruent_time+total_time)%24,3);
        sour=dest;
        i++;
        dest=way_city_copy.at(i);
    }
    least_time_route(sour,dest,(curruent_time+total_time)%24,3);
   // send_data();
    return total_time;
}

void Module::limit_time_least_cost_route(int source, int destination, int current_time, int limit_time){
    int shortest_time=least_time_route(source,destination,current_time,1);
    qDebug()<<"hi";
    if(shortest_time>limit_time){
        output_limit="no path";
       // send_data();
    }
    else if(shortest_time==limit_time){
        output_limit=output_ltime;
        //send_data();
    }
    else {
        struct PATH2 *path=new struct PATH2;
        int temp=dynamic_find_limit_least_cost(source,destination,limit_time,current_time,path);
        output_limit=QString::number(source);
        int tempsource=source;
        while(path->next_city){
            output_limit+=" "+QString::number(mat[tempsource][path->next_city_number][path->next_vehicle_number].start_time)+" "
                    +mat[tempsource][path->next_city_number][path->next_vehicle_number].train_number+" "
                    +QString::number(mat[tempsource][path->next_city_number][path->next_vehicle_number].price)+" "
                    +QString::number(mat[tempsource][path->next_city_number][path->next_vehicle_number].arrive_time)+" "+QString::number(path->next_city_number);
            tempsource=path->next_city_number;
            struct PATH2 *temp_p = path;
            path = path->next_city;
            delete temp_p;

        }
        delete path;
    }
   // qDebug()<<output_limit;
   // send_data();
}

int  Module::dynamic_find_limit_least_cost(int source, int destination, int limit_time, int current_time, struct PATH2 *path){
    //qDebug()<<"df";
    //qDebug()<<"hibitch";
    if(source==destination){
        path->next_city= NULL;
        return 0;
    }
    else{
        int temp_least_charge=INF;
        int best_k = -1;
        int best_i = -1;

        for (int i = 0; i < max_citynumber;i++)
        {
            for (int k = 0; k < max_vehicle_numer;k++){
                if(mat[source][i][k].price<INF)
                    {
                        struct PATH2 *p = new struct PATH2;
                        p->next_city=NULL;
                        int temp_time=(mat[source][i][k].arrive_time - mat[source][i][k].start_time + 24) % 24 +
                            (mat[source][i][k].start_time - current_time + 24) % 24;//source到i所需时间
                        int temp = least_time_route(i, destination, (current_time+temp_time)%24,4);
                        if(temp<=limit_time-temp_time){
                            int nextcharge = mat[source][i][k].price+dynamic_find_limit_least_cost(i, destination, limit_time - temp_time, mat[source][i][k].arrive_time,p);
                            if(nextcharge<temp_least_charge)
                            {

                                path->next_city = p;
                                path->next_city_number = i;
                                path->next_vehicle_number = k;
                                path->next_arrive_time = mat[source][i][k].arrive_time;
                                temp_least_charge = nextcharge;
                                best_k = k;
                                best_i = i;
                            }else{
                                delete p;
                            }
                        }
                    }
                else
                    break;
            }
        }
        return temp_least_charge;
    }

}


void Module::ACO_lcost_route(int antmount,int generations,int start,int end,int t,int throughnum,bool* throughtarget)
{
    output_ACO_lcost=QString::fromStdString(aco.gettheans(antmount,generations,start,end,t,1,throughnum,throughtarget,88888));
}
void Module::ACO_ltime_route(int antmount,int generations,int start,int end,int t,int throughnum,bool* throughtarget)
{
    output_ACO_ltime=QString::fromStdString(aco.gettheans(antmount,generations,start,end,t,0,throughnum,throughtarget,88888));
}
void Module::ACO_limit_route(int antmount,int generations,int start,int end,int t,int throughnum,bool* throughtarget,int LIMIT)
{
    output_ACO_limit=QString::fromStdString(aco.gettheans(antmount,generations,start,end,t,2,throughnum,throughtarget,LIMIT));
}
void Module::NOPATH_limit_route(int antmount, int generations, int start, int end, int t,int LIMIT)
{
    output_NOPATH_limit=QString::fromStdString(aco.gettheNOPATHans(antmount,generations,start,end,t,2,LIMIT));
}
