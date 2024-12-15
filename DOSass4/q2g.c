#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
int i=5;
if(fork()==0){
printf("child %d",i);
}
else
printf("parent %d",i);
return 0;
}
