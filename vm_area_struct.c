/*
 * =====================================================================================
 *
 *       Filename:  vm_area_struct.c
 *
 *    Description:  测试虚拟内存的结构体
 *
 *        Version:  1.0
 *        Created:  2014年10月07日 16时16分03秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/sched.h>
MODULE_LICENSE("GPL");


static int __init module(void)
{
    struct mm_struct  *mymm = (&init_task)->mm ;
    struct vm_area_struct *pos = NULL;
    printk("current process:%s %d\n", current->comm, current->pid);
    for(pos = mymm->mmap; pos; pos = pos->vm_next) {
            printk("0x%lx-0x%lx\t", pos->vm_start, pos->vm_end);
            if(pos->vm_flags & VM_READ) {
	                printk("r");
	            } else {
		                printk("-");
		            }
            if(pos->vm_flags & VM_WRITE) {
	                printk("w");
	            } else {
		                printk("-");
		            }
            if(pos->vm_flags & VM_EXEC) {
	                printk("x");
	            } else {
		                printk("-");
		            }
    
            printk("\n");
        }
    return 0;
}

static void __exit rmodule(void)
{
    printk(KERN_ALERT"Goodbye,world\n");
}
module_init(module);
module_exit(rmodule);
