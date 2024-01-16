#include <linux/module.h>
#include <linux/init.h>

#define DRIVER_NAME ("led_control")

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sdaryoush");
MODULE_DESCRIPTION("A simple LED controller driver via GPIO");

static int __init led_control_init(void) {
	printk("%s initialized\n", DRIVER_NAME);
	return 0;
}

static void __exit led_control_exit(void) {
	printk("%s exiting\n", DRIVER_NAME);
}

module_init(led_control_init);
module_exit(led_control_exit);
