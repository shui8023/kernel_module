FILENAME = 1
KERNEL = $(addsuffix .ko, $(FILENAME))
obj-m :=$(addsuffix .o,$(FILENAME))

PWD = $(shell pwd)

MODULE_PWD := /lib/modules/$(shell uname -r)/build

all:
	make -C $(MODULE_PWD) M=$(PWD) modules
	sudo insmod $(KERNEL)
	sudo tail -n 10 /var/log/messages
clean:
	rm -rf *.ko *.o *mod.c
