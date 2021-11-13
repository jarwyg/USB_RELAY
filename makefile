CC=g++
CFLAGS=-I.
DEPS = rs232.h
OBJ = main.o rs232.c

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

usb_relay: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
	
.PHONY: clean

clean:
	rm -f *.o usb_relay 

install:
	cp usb_relay /usr/bin/usb_relay
