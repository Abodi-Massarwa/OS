all: lib subtask23 subtask22 subtask21 subtask3 subtask2 subtask1

subtask1:hello_ariel.c hello_ariel.h main1_1.c
	gcc hello_ariel.c main1_1.c -o hello1

subtask2:hello_ariel.h main1_1.c libHello.so
	gcc  main1_1.c -L. -l Hello -o hello2

subtask3:hello_ariel.h main1_3.c
	gcc  main1_3.c -fPIC -ldl -o hello3

lib:hello_ariel.h hello_ariel.c
	gcc -fPIC -shared hello_ariel.c -o libHello.so

subtask21: grand_child
	gcc main2_1.c -o hello21

subtask22:
	gcc main2_2.c -o hello22

subtask23:
	gcc main2_3.c -o hello23

grand_child: grand_child.c
	gcc grand_child.c -o grand_child

.PHONY: clean 
clean:
	rm -f hello1 hello2 hello3 libHello.so grand_child hello21 hello22 hello23 hello24
