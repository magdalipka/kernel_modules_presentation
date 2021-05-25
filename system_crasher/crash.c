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

  address = 0x00000001;
  memsize = 1024:

  while (true) {

    p = ioremap(address, memsize);
    writeb('0', p);
    address++;

  }
  return 0;
}
static void goodbye(void) {
  printk(KERN_INFO "Goodbye world.\n");
}

module_init(hello);
module_exit(goodbye);
