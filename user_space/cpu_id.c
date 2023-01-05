#include<unistd.h>
#include<stdio.h>

#define __NR_GET_CPU 351

unsigned int call_cpu_id() {
    return syscall(__NR_GET_CPU);
}


int main() {
    unsigned int id = syscall(351);
    printf("[cpu] %u\n", id);
    return 0;
}
