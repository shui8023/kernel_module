
obj-m := print_pid.o
#当前的目录
CURRENT_PATH := $(shell pwd)
#这个是kernel的模块目录
LINUX_KERNEL_PATH := /lib/modules/$(shell uname -r)/build
#也可以直接将内存模块直接插入到kernel中,?=的意思是如果没有定义LINUX_KERNEL_PATH,则使用这个，不过一般的电脑都没有
#kernel开发包，需要安装kernel-devel, sudo apt-get install kernel-devel
LINUX_KERNEL_PATH ?= /usr/src/kernels/$(shell uname -r)
all:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) modules

clean:
	make -C $(LINUX_KERNEL_PATH) M=$(CURRENT_PATH) clean

