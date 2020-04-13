#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void hello(char* text)
{
	for(size_t i=0; i<=9; ++i){
		printf("hello from %s \n",text);
		usleep(1000000);
}
		
}

int main()
{

pid_t id=fork();
/* assume there is now parent->child process*/
if(id==0)/*means child process*/
{
	pid_t id1=fork();
	if(id1==0)
{
char* args[2]={"./grand_child",NULL};
execvp(args[0],args);
}
else printf("hello from child process\n");
}
else hello("parent");
return 0;
}
