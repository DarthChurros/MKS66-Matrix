ifdef MEM
	DATA = -g
	VG = valgrind --leak-check=full
endif

all: main.o display.o draw.o matrix.o
	gcc $(DATA) -o program main.o display.o draw.o matrix.o

main.o: main.c
	gcc $(DATA) -c main.c

display.o: display.c display.h ml6.h
	gcc $(DATA) -c display.c

draw.o: draw.c draw.h ml6.h
	gcc $(DATA) -c draw.c

matrix.o: matrix.c matrix.h
	gcc $(DATA) -c matrix.c

run:
	$(VG) ./program $(ARGS)

clean:
	rm *.o
	rm program
