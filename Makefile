.SECONDARY:

all: exe/test07.elf

%.elf: src/test07.o src/cmplx.o
	gcc src/test07.o src/cmplx.o -o $@ -lm

%.o: %.c
	gcc -c $< -I inc/ -o $@

clean:
	rm -f src/*.o exe/app.elf
