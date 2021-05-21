#include <linux/module.h>
#include <linux/kernel.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static int hello(void) {
    printk(KERN_INFO "Hello world.\n");
    while (true) {
      int address;
      get_random_bytes(&address, sizeof(address)); 
      if (address < 0) address = -address;
      memset(i, 0, 8);
    }
    return 0;
}
static void goodbye(void) {
    printk(KERN_INFO "Goodbye world.\n");
}

module_init(hello);
module_exit(goodbye);
