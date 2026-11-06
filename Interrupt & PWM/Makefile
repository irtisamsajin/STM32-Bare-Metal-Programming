CC=arm-none-eabi-gcc
MACH=cortex-m4
TARGET = main
BUILD_DIR = build

SRCS= $(TARGET).c drivers/gpio.c drivers/timer.c drivers/interrupt.c
OBJS= $(BUILD_DIR)/$(TARGET).o $(BUILD_DIR)/gpio.o $(BUILD_DIR)/timer.o $(BUILD_DIR)/interrupt.o $(BUILD_DIR)/startup.o

CFLAGS= -c -mcpu=$(MACH) -mthumb -std=gnu11 -Wall -O0 -g3
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=$(BUILD_DIR)/$(TARGET).map

OPENOCD_INTERFACE = interface/stlink.cfg
OPENOCD_TARGET = target/stm32f4x.cfg


all: $(BUILD_DIR)/$(TARGET).elf

$(BUILD_DIR)/$(TARGET).o: $(TARGET).c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/gpio.o: drivers/gpio.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/timer.o: drivers/timer.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/interrupt.o: drivers/interrupt.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/startup.o: startup.s | $(BUILD_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/$(TARGET).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

flash: $(BUILD_DIR)/$(TARGET).elf
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET) -c "program $(BUILD_DIR)/$(TARGET).elf verify reset exit"

clean:
	rm -rf *.o *.elf *.map $(BUILD_DIR)

openocd:
	openocd -f $(OPENOCD_INTERFACE) -f $(OPENOCD_TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

