project : run.o list.o fun.o
	cc run.o fun.o list.o -o project
run.o : run.c list.h
	cc -c run.c 
fun.o : fun.c  list.h
	cc -c fun.c 
list.o : list.c list.h
	cc -c list.c
