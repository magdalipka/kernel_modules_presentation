#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>   
#include <linux/fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");

#define DEVICE_NAME "messenger_server"
#define MSG_BUFFER_LEN 10

static ssize_t server_read(struct file*, char*, size_t, loff_t*);
static ssize_t server_write(struct file*, const char*, size_t, loff_t*);

static int major_num;
static char* msg_buffer;

static struct file_operations file_ops = {
 .read = server_read,
 .write = server_write,
};

static ssize_t server_read(struct file* flip, char* buffer, size_t len, loff_t* offset) {
    if (copy_to_user(buffer, msg_buffer, MSG_BUFFER_LEN)) {
        printk(KERN_ALERT "Error reading data!\n");
    }
    return MSG_BUFFER_LEN;
}

static ssize_t server_write(struct file* flip, const char* buffer, size_t len, loff_t* offset) {
    if (copy_from_user(msg_buffer, buffer, len)) {
        printk(KERN_ALERT "Error writing data!\n");
    }
    return len;
}

static int server_init(void) {

    msg_buffer = kmalloc(MSG_BUFFER_LEN, GFP_KERNEL);

    major_num = register_chrdev(0, "messenger_server", &file_ops);
    if (major_num < 0) {
        printk(KERN_ALERT "Could not register messenger_server: %d\n", major_num);
        return major_num;
    } else {
        printk(KERN_INFO "messenger_server module loaded with device major number %d\n", major_num);
        return 0;
    }
}

static void server_exit(void) {
    unregister_chrdev(major_num, DEVICE_NAME);
    printk(KERN_INFO "Goodbye, messenger_server!\n");
}

/* Register module functions */
module_init(server_init);
module_exit(server_exit);