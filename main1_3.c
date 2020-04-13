#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <dlfcn.h>

void (*printer)();

int init_library()
{
void *hdl= dlopen("./libHello.so",RTLD_LAZY);
if(hdl==NULL) return 0;
printer=(void(*)())dlsym(hdl,"print_hello");
if(printer== NULL) return 0;
return 1;

}


int main()
{

if(init_library()==1)
	printer();
else
	printf("Error linking Library at runtime !\n");

return 0;
}

