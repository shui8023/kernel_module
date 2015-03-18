/*
 * =====================================================================================
 *
 *       Filename:  print_pid.c
 *
 *    Description:  打印进程的pid和进程名字
 *
 *        Version:  1.0
 *        Created:  2015年03月18日 15时00分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shui(dubingyang), dubingyangxiyou@gmail.com
 *        Company:  Class 1201 of software engineering
 *
 * =====================================================================================
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/list.h>


static void print_pid_t(void)
{
	struct task_struct *task, *p;
	struct list_head *pos;
	int count = 0;

	printk("hello world begin:\n");
	
	task = &init_task;

	list_for_each(pos, &task->tasks) {
		p = list_entry(pos, struct task_struct, tasks);
		count++;
		printk("%d-->%s\n", p->pid, p->comm);
	}

	printk("the number of process:%d\n", count);
}

void __init init_modules(void)
{
	print_pid_t();

}
void __exit exit_modules(void)
{
	printk("leave for the kernel\n");
}

module_init(init_modules);
module_exit(exit_modules);
