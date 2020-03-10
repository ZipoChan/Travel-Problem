#ifndef ACO_H
#define ACO_H

#include <string>
using namespace std;

#include <stdio.h>

class ACO
{
public:
    ACO();
    string gettheans(int antmount,int generations,int start,int end,int t,int mode,int throughnum,bool* throughtarget,int LIMIT);
    string gettheNOPATHans(int antmount,int generations,int start,int end,int t,int mode,int LIMIT);
};

#endif /* ACO_hpp */


