#include "mbed.h"
#include "rtos.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);

void led2_thread(DigitalOut *led) {
    while (true) {
        *led = !*led;
#if MBED_MAJOR_VERSION >= 6
        ThisThread::sleep_for(1000);
#else
        Thread::wait(1000);
#endif
    }
}
 
int main() {
    Thread thread;

#ifdef MBED_MAJOR_VERSION
    printf("Mbed OS version %d.%d.%d\r\n\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);
#endif
 
    thread.start(callback(led2_thread, &led2));
   
    while (true) {
        led1 = !led1;
#if MBED_MAJOR_VERSION >= 6
        ThisThread::sleep_for(500);
#else
        Thread::wait(500);
#endif
    }
}
