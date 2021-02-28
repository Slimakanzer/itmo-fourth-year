obj-m :=var5.o
all :
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean :
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
ins:
	sudo insmod var5.ko
rm:
	sudo rmmod var5
