#define _GNU_SOURCE
#include <linux/sched.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
char child_stack[10000+1];

void print (const char *text)
{
int i;
for(i=0; i<1000; i++){
printf("hello from %s\n",text);
usleep(1000000);
}
}
int grand(void* params)
{

print("child2 process");
}

int child(void* params)
{
int result= clone(grand,child_stack+10000,0,0);
print("child process");
}
int main()
{


int result= clone(child,child_stack+10000,0,0);
printf("clone result = %d\n",result);
print("parent");


return 0;
}
