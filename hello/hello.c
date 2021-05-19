#include <linux/module.h>
#include <linux/kernel.h>

static int hello(void) {
    printk(KERN_INFO "Hello world.\n");
    return 0;
}
static goodbye(void) {
    printk(KERN_INFO "Goodbye world.\n");
}

module_init(hello);
module_exit(goodbye);
