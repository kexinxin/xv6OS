#include "types.h"
#include "stat.h"
#include "user.h"

void periodic();

int
main(int argc,char *argv[]){
    int i;
    printf(1,"alarmtest starting\n");
    alarm(10,periodic);
    write(2,"kexinxin",1);
    for (i=0;i<25*5000000;i++){
        if((i%2500000)==0)
            write(2,".",1);
    }
    exit();
}
void
periodic(){
    printf(1,"alarmTest!\n");
}
