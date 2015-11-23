#include <linux/kernel.h>
#include <linux/string.h>
#include <linux/vmalloc.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("STUDENT");
MODULE_DESCRIPTION("Printing Proc Info");

#define MAX_LEN       4096

static struct proc_dir_entry *mydir;
static struct proc_dir_entry *pfile;

static int read_index;
static int write_index;

static char *info;

static int myproc_read(char *page,char **start,off_t off,int count,int *eof,void *data) {
	int len;
    	if (off > 0) {
        	*eof = 1;
        	return 0;
    	}

    	if (read_index >= write_index)
    		read_index = 0;

    	len = sprintf(page, "%s\n", &info[read_index]);
    	read_index += len;
    	return len;
}

static int myproc_write(struct file *flip, const char __user *buff, unsigned long len, void *data) {
	int capacity = (MAX_LEN-write_index)+1;
    	
	if (len > capacity) {
        	printk(KERN_INFO "No space to write in procEntry123!\n");
        	return -1;
    	}	
    
	if (copy_from_user( &info[write_index], buff, len )) {
        	return -2;
    	}

    	write_index += len;
    	info[write_index-1] = 0;
    	
	return len;	
}

static int __init myproc_init(void) {
	int ret=0;	
	
	info=(char *)vmalloc(MAX_LEN);
	memset(info,0,MAX_LEN);
	
	mydir=proc_mkdir("mydir",NULL);
	if(!mydir) {
		ret=-1;
		vfree(info);
		printk(KERN_ERR"Can't create /proc/mydir \n");
		return ret;
	}

	pfile=create_proc_entry("pool",0666,mydir);
	if(!pfile) {
		ret=-1;
		vfree(info);
		printk(KERN_ERR"Can't create /proc/mydir/pool \n");
		return ret;
	}

	read_index=0;	
	write_index=0;	
	pfile->read_proc=myproc_read;
	pfile->write_proc=myproc_write;

	printk(KERN_INFO"\n Proc Entry Created .. \n");
	
	return ret;
}

static void __exit myproc_exit(void) {
	remove_proc_entry("pool",mydir);
	remove_proc_entry("mydir",NULL);
}

module_init(myproc_init);
module_exit(myproc_exit);

