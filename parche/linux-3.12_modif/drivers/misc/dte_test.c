#define __KERNEL__
#define MODULE
#include <linux/module.h>
#include <linux/kernel.h>


int init_module(void){
	printk("bos días mundo \n");
	return 0;
}

void cleanup_module(void){
	printk("adeus mundo \n");
}
