.SECONDARY:

all: exe/test06.elf

%.elf: src/test06.o src/cmplx.o
	gcc src/test06.o src/cmplx.o -o $@ -lm

%.o: %.c
	gcc -c $< -I inc/ -o $@

clean:
	rm -f src/*.o exe/app.elf

run: ./exe/*.elf
