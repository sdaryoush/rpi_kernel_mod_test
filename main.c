#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>

int main(void) {
    if(open("/dev/led_control", O_RDONLY) == -1) {
        printf("ERROR: Could not open led_control!\n");
    }
    printf("led_control opened!\n");
    return 0;
}
