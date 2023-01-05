#include<linux/sched.h>
#include<linux/kernel.h>

asmlinkage void sys_start_count_number(void) {
    unsigned int bf = current->process_switch_counter;
    current->process_switch_counter = 0;
    printk("[start count] %u to 0\n", bf);
}

asmlinkage unsigned int sys_end_count_number(void) {
    unsigned int ret = current->process_switch_counter;
    printk("[end count] %u\n", ret);
    return ret;
}
