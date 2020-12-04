#include<iostream>
#include<stdio.h>
#include<sstream>
using namespace std;


int months[2][12] = {{
    31,28,31,30,31,30,31,31,30,31,30,32
    },{
    31,29,31,30,31,30,31,31,30,31,30,32
}};
bool isRYear(int year){
    if(year % 4 == 0 && !(year%100 == 0&&!(year%400 == 0))){
        return true;
    }else {
        return false;
    }
}
int main(){
//    string a;

//    scanf("%s",&a);

    int year;
    int month;
    int day;
    int p;
    while((scanf("%d%c%d%c%d",&year,&p,&month,&p,&day))!=EOF){
        cout<<year<<endl;
        cout<<month<<endl;
        cout<<day<<endl;
        int type = 0;
        if(isRYear(year))
            type = 1;
        int dayofyear = 0;
        for(int i = 0; i < month-1; i++){
            dayofyear += months[type][i];
        }
        dayofyear+=day;
        cout<<dayofyear<<endl;

    }
//    string dateInfo = "2006/3/12";
//    string dateArray[3];
//    int index = 0;//0 means year; 1 means month; 2 means dayofyear
//    int l = 0;
//    int r = 0;
//    while(r < dateInfo.length()){
//        if(dateInfo[r] != '/'){
//            r++;
//        } else {
//           dateArray[index++] =  string(dateInfo.begin()+l,dateInfo.begin()+r);
//           l = r+1;
//           r++;
//        }
//
//        if(index == 2)
//            dateArray[2] = string(dateInfo.begin()+l,dateInfo.end());
//    }
//
//    for(string elem: dateArray){
//        cout<<elem<<endl;
//    }
//

    return 0;
}
