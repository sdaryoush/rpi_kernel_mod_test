obj-m += led_control.o

CC=gcc

KERNEL_REL=$(shell uname -r)

all:
	make -C /lib/modules/$(KERNEL_REL)/build M=$(PWD) modules
	$(CC) main.c -o main

clean:
	make -C /lib/modules/$(KERNEL_REL)/build M=$(PWD) clean
	rm -f main
