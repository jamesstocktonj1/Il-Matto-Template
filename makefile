# AVR Makefile
# James Stockton


# make file commands
#	all 	- compiles whole program
#	disasm 	- disassembles elf file
#	size 	- shows size of elf file
#	test	- test programmer connection
#	flash	- upload hex to target
#	fuse	- set fuses of target
#	clean	- deletes compiled files
#	help	- displays usage message

# avr constants
MCU = atmega644p
CLK = 12000000

# compiler constants
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
OBJSIZE = avr-size

# compiler flags
CFLAGS = -Wall -Os
TARGET = main

# build and source folders
BUILD = build
SOURCE = src
INCLUDES = $(wildcard $(SOURCE)/*.c)
#LIB = lib
#LIBRARY = $(wildcard $(LIB)/*.c)

#programmer constant
AVRDUDE = avrdude 
PROGRAMMER = usbasp

#fuses
LF = 0xff
HF = 0x9c
EF = 0xff


all: $(BUILD)/$(TARGET).hex

disasm: $(BUILD)/$(TARGET).elf
	$(OBJDUMP) -d $(BUILD)/$(TARGET).elf

size: $(BUILD)/$(TARGET).elf
	$(OBJSIZE) -C $(BUILD)/$(TARGET).elf

test:
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU)

flash: all
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -U flash:w:$(BUILD)/$(TARGET).hex

fuse:
	$(AVRDUDE) -c $(PROGRAMMER) -p $(MCU) -U lfuse:w:$(LF):m -U hfuse:w:$(HF):m -U efuse:w:$(EF):m

clean:
	rm -f $(BUILD)/$(TARGET).elf
	rm -f $(BUILD)/$(TARGET).
	
help:
	@echo Il Matto Makefile Usage
	@echo \tall \t-\t compiles whole program
	@echo \tdisasm \t-\t disassembles elf file
	@echo \tsize \t-\t shows size of elf file
	@echo \ttest \t-\t test programmer connection
	@echo \tflash \t-\t upload hex to target
	@echo \tfuse \t-\t set fuses of target
	@echo \tclean \t-\t deletes compiled files


$(BUILD)/$(TARGET).elf: $(TARGET).c $(INCLUDES)
	$(CC) -DF_CPU=$(CLK) -mmcu=$(MCU) $(CFLAGS) $(TARGET).c $(INCLUDES) -o $(BUILD)/$(TARGET).elf

$(BUILD)/$(TARGET).hex: $(BUILD)/$(TARGET).elf
	$(OBJCOPY) $(BUILD)/$(TARGET).elf $(BUILD)/$(TARGET).hex -O ihex