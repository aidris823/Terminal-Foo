all: AnM_Burger_Shop.o
	gcc AnM_Burger_Shop.o
AnM_Burger_Shop.o: AnM_Burger_Shop.c burgers.h
	gcc -c AnM_Burger_Shop.c
run: a.out
	./a.out
