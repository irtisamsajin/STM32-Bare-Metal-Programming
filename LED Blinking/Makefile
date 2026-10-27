CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 -g3
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=main.map

OPENOCD_INTERFACE = interface/stlink.cfg
OPENOCD_TARGET = target/stm32f4x.cfg

all: main.o startup.o main.elf

main.o: main.c
	$(CC) $(CFLAGS) -o $@ $^ 

startup.o: startup.s
	$(CC) $(CFLAGS) -o $@ $^ 

main.elf: main.o startup.o
	$(CC) $(LDFLAGS) -o $@ $^

flash: main.elf
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) -c "program main.elf verify reset exit"

clean:
	rm -rf *.o *.elf *.map

openocd:
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET)

