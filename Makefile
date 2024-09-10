MCU = atmega328p
F_CPU = 16000000UL
CC = avr-gcc
CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Wall -Os
OBJ = main.o traffic_light.o

AVRDUDE_PORT = /dev/cu.usbserial-1110   # Update this for your system

all: main.hex

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o main.o

traffic_light.o: src/traffic_light/traffic_light.c
	$(CC) $(CFLAGS) -c src/traffic_light/traffic_light.c -o traffic_light.o

main.elf: $(OBJ)
	$(CC) $(CFLAGS) -o main.elf $(OBJ)

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom main.elf main.hex

upload: main.hex
	avrdude -c arduino -p $(MCU) -P $(AVRDUDE_PORT) -b 115200 -U flash:w:main.hex

clean:
	rm -f *.o main.elf main.hex
