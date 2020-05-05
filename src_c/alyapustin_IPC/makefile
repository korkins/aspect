OFILES = humlicek.o  cmplx.o

CC = g++

COMPILEFLAGS = -Wall -W -O3

install: $(OFILES)
	mv humlicek.o ..
	mv cmplx.o ..

humlicek.o: humlicek.cpp cmplx.h
	$(CC) -c $(COMPILEFLAGS) humlicek.cpp

cmplx.o: cmplx.cpp cmplx.h
	$(CC) -c $(COMPILEFLAGS) cmplx.cpp