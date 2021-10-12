hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Hisse.o -c ./src/Hisse.c
	gcc -I ./include/ -o ./lib/Emir.o -c ./src/Emir.c
	gcc -I ./include/ -o ./lib/Portfoy.o -c ./src/Portfoy.c
	gcc -I ./include/ -o ./lib/Dosya.o -c ./src/Dosya.c 
	gcc -I ./include/ -o ./lib/Banka.o -c ./src/Banka.c	
	gcc -I ./include/ -o ./bin/uygulama ./src/Program.c ./lib/Hisse.o ./lib/Dosya.o ./lib/Banka.o ./lib/Emir.o ./lib/Portfoy.o
calistir:
	./bin/uygulama