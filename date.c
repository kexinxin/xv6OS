#include"types.h"
#include"user.h"
#include"date.h"
int
main(int argc,char *argv[]){
    struct rtcdate r;
    if(date(&r)){
        printf(2,"data failed\n");
        exit();
    }
    printf(2,"year:%d,month:%d,day:%d,hour:%d,minute:%d,minute:%d,second:%d\n",r.year,r.month,r.day,r.hour,r.minute,r.second); 
    exit();
}
int
test(){
    int a=4+6;
    return a; 
}
