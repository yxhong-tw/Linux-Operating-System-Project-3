#include<unistd.h>
#include<stdio.h>
#include<sys/time.h>

#define ON 1
#define OFF 0
#define WAIT_TIME 120 //sec
#define SEC_TO_USEC 1000000

void start_to_count_number_of_process_switches() {
    syscall(352);
}

unsigned int stop_to_count_number_of_process_switches() {
    unsigned int ret;
    ret = syscall(353);
    return ret;
}

int main() {
    // struct timeval tv;
    // gettimeofday(&tv, NULL);

    // printf("tv_sec: %d\n", tv.tv_sec);
    // printf("tv_usec: %d\n", tv.tv_usec);
    
    unsigned int a;
    int loop_switch = ON;
    int b = 0;
    struct timeval start_tv;
    struct timeval now_tv;

    start_to_count_number_of_process_switches();
    gettimeofday(&start_tv, NULL);
    while(loop_switch) {
        
        b = b+1;

        gettimeofday(&now_tv, NULL);
        int diff;
        diff = (now_tv.tv_sec - start_tv.tv_sec) * SEC_TO_USEC + (now_tv.tv_usec - start_tv.tv_usec);
        if(diff >= WAIT_TIME * SEC_TO_USEC) loop_switch = OFF;
    }
    a = stop_to_count_number_of_process_switches();
    printf("\nDuring the pass time the process makes %u times process switches.\n", a);

    return 0;
}
