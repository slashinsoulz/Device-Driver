/* Global definition for the example character device driver */

int init_module(void);
void cleanup_module(void);
static int device_open(struct inode *, struct file *);
static int device_release(struct inode *, struct file *);
static ssize_t device_read(struct file *, char *, size_t, loff_t *);
static ssize_t device_write(struct file *, const char *, size_t, loff_t *);
static long device_ioctl(struct file *file, unsigned int ioctl_num, unsigned long);

#define DEVICE_NAME "opsysmem"	/* Dev name as it appears in /proc/devices   */

/* 
 * Global variables are declared as static, so are global within the file. 
 */
struct cdev *my_cdev;
       dev_t dev_num;

static int Major;		/* Major number assigned to our device driver */
static size_t maxSize = 2097152;
static const int maxMsgSize = 4096;



static struct file_operations fops = {
	.read = device_read,
	.write = device_write,
	.open = device_open,
	.unlocked_ioctl = device_ioctl,
	.release = device_release
};

