#include <stdio.h>
#include <stdlib.h>
#include <wiringSerial.h>

// https://pinout.xyz/pinout/uart (Raspberry Pi Pinout, 3V3 <-> VCC, TX <-> RX, RX <-> TX, GND <-> GND)
// https://www.u-blox.com/sites/default/files/PAM-7Q_DataSheet_(UBX-13002455).pdf (GPS Pinout p.11)
// $ sudo raspi-config # Interfacing options > Serial > Disable console > Enable UART
// $ gcc -o gps gps.c -lwiringPi

//#define SERIAL_DEVICE "/dev/ttyAMA0"
//#define SERIAL_DEVICE "/dev/ttyS0"
#define SERIAL_DEVICE "/dev/serial0"

//#define BAUD_RATE 115200
#define BAUD_RATE 9600

int main(void) {
    int fd = serialOpen(SERIAL_DEVICE, BAUD_RATE);
    if (fd == -1) {
        perror("serialOpen");
        exit(-1);
    }
    int ch = serialGetchar(fd);
    while(ch != -1) {
        putchar(ch);
        ch = serialGetchar(fd);
    }
    perror("serialGetchar");
    exit(-1);
}
