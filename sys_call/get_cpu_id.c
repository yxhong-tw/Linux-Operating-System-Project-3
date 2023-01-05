#include<linux/thread_info.h>

asmlinkage unsigned int sys_get_cpu_id(void) {
    struct thread_info *ti;
    ti = current_thread_info();
    unsigned int cpu_id;
    cpu_id = ti->cpu;
    return cpu_id;
}
