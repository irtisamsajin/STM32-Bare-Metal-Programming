CC=arm-none-eabi-gcc
MACH=cortex-m4
TARGET = main

CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 -g3
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=$(TARGET).map

OPENOCD_INTERFACE = interface/stlink.cfg
OPENOCD_TARGET = target/stm32f4x.cfg

all: $(TARGET).o startup.o $(TARGET).elf

$(TARGET).o: $(TARGET).c
	$(CC) $(CFLAGS) -o $@ $^ 

startup.o: startup.s
	$(CC) $(CFLAGS) -o $@ $^ 

$(TARGET).elf: $(TARGET).o startup.o
	$(CC) $(LDFLAGS) -o $@ $^

flash: $(TARGET).elf
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) -c "program $(TARGET).elf verify reset exit"

clean:
	rm -rf *.o *.elf *.map

openocd:
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET)

