#auther  : bassam
# Date   :feb 4- 2022
CC=arm-none-eabi-
CFLAFS=-mcpu=arm926ej-s -g
INCS=-I .
LIBS=
SRC=$(wildcard *.c)
obj= $(SRC:.c=.o)
#As=$(wildcard *.s)
#objAs=$(As:.s=.o)
project_name=learn-in-depth

all: $(project_name).bin

startup.o: startup.s
	$(CC)as.exe $(CFLAFS) $< -o $@ 2> log
	
	
%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAFS) $< -o $@
	
$(project_name).elf: startup.o app.o uart.o
	$(CC)ld.exe -T linker_script.ld startup.o app.o uart.o -o $@ -Map=Map_file.map
	
$(project_name).bin: $(project_name).elf 
	$(CC)objcopy.exe $< $@
	@echo "Every thing is Done...."

clean_all:
	rm *.bin *.elf *.o
	
clean:
	rm *.bin *.elf