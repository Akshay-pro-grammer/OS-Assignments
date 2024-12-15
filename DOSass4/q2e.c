#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
int main(){
pid_t pid;
int i=5;
pid=fork();
if(pid==0){
i=i+1;
printf("child %d",i);
}
else{
wait(NULL);
printf("parent %d",i);
}
return 0;
}
