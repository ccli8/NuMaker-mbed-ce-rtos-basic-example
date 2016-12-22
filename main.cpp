#include "mbed.h"
#include "rtos.h"
#if defined(TARGET_NUMAKER_PFM_NUC472)
DigitalOut led1(LED1);
DigitalOut led2(LED2);
#elif defined(TARGET_NUMAKER_PFM_M453)
DigitalOut led1(LED1);
DigitalOut led2(LED2);
#endif

void led2_thread(void const *args) {
    while (true) {
        led2 = !led2;
        Thread::wait(1000);
    }
}
 
int main() {
    Thread thread(led2_thread);
    
    while (true) {
        led1 = !led1;
        Thread::wait(500);
    }
}
