#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/random.h>
#include <asm/io.h>

MODULE_LICENSE("GPL");

static int hello(void) {
  printk(KERN_INFO "Hello world.\n");

  unsigned char* p;
  unsigned int address;
  unsigned int memsize;

  memsize = 1024;

  while (true) {
    get_random_bytes(&address, sizeof(address));
    printk(KERN_INFO "%d\n", address);
    if (address < 0) address = -address;
    p = ioremap(address, memsize);
    writeb('0', p);
    iounmap(p);
  }
  return 0;
}
static void goodbye(void) {
  printk(KERN_INFO "Goodbye world.\n");
}

module_init(hello);
module_exit(goodbye);
