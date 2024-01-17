#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

#define DRIVER_NAME         ("led_control")
#define DRIVER_MAJ_DEV_ID   (30)

#define FAIL_IF(stm)        \
    do { \
        if(stm) { \
            printk("Failed in %s at line %d", __func__, __LINE__); \
            return -1; \
        } \
    } while(0)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("sdaryoush");
MODULE_DESCRIPTION("A simple LED controller driver via GPIO");


static int led_control_open(struct inode *device_file, struct file *instance);
static int led_control_close(struct inode *device_file, struct file *instance);

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = led_control_open,
    .release = led_control_close
};

static int led_control_open(struct inode *device_file, struct file *instance) {
    printk("%s open\n", DRIVER_NAME);
	return 0;
}

static int led_control_close(struct inode *device_file, struct file *instance) {
    printk("%s close\n", DRIVER_NAME);
	return 0;
}

static int __init led_control_init(void) {
	printk("%s initialized\n", DRIVER_NAME);
    FAIL_IF(register_chrdev(DRIVER_MAJ_DEV_ID, DRIVER_NAME, &fops) < 0);
	return 0;
}

static void __exit led_control_exit(void) {
	printk("%s exiting\n", DRIVER_NAME);
}

module_init(led_control_init);
module_exit(led_control_exit);
