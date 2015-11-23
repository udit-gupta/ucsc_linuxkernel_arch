#include <linux/init.h>
#include <linux/string.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/in.h>
#include <linux/errqueue.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("STUDENT");
MODULE_DESCRIPTION("Printing Process Info");

int pass_params;

module_param(pass_params, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(pass_params, "Params to pass");

int sysint_init(void) {
	printk("\n\n Hellow World. Module Pass Params Loaded ! Parameter passed is %d \n\n\n",pass_params);
	return 0;
}

void sysint_exit(void) {
	printk("\n\n Bye, Bye, Module Unloaded \n\n");
}

module_init(sysint_init);
module_exit(sysint_exit);

