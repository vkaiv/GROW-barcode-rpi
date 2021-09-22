#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>
#include "gm61.h"

int scanner;
char data;

int main() {
    if (wiringPiSetup() < 0) return -1;

    // the datasheet says that the default baud rate is 9600
    // but after reseting the device once it changed it to 57600
    scanner = serialOpen("/dev/ttyS0", 57600);
    if (scanner < 0) return -1;

    for (int i = 0; i < sizeof(INIT_SCANNER) / sizeof(int) / 2; i++) {
        send_command(INIT_SCANNER[i][0], INIT_SCANNER[i][1]);
    }
    
    while (1) {
        if (serialDataAvail(scanner) > 0) {
            data = serialGetchar(scanner);
            printf("%c", data);
            fflush(stdout);
        }
    }

    return 0;
}

void send_command(int address, int command) {
    // bytes 0-4 are standard for all setup commands
    // bytes 7 and 8 are for crc values
    int data[] = {0x7E, 0x00, 0x08, 0x01, 0x00, address, command, 0x00, 0x00};

    // only bytes 2-6 are used for the crc calculations
    calculate_crc(data+2);

    for (int i = 0; i < sizeof(data) / sizeof(int); i++) {
        serialPutchar(scanner, data[i]);
    }

}

void reset_scanner() {
    int reset[] = {0x7E, 0x00, 0x09, 0x01, 0x00, 0x00, 0xFF, 0x00, 0x00};
    calculate_crc(reset + 2);
    
    for (int i = 0; i < 9; i++) {
        serialPutchar(scanner, reset[i]);
    } 

}

// CRC16-CCITT/KERMIT
void calculate_crc(int data[]) {
    unsigned short crc = 0;
    
    for (int len = 0; len < 5; len++){
        crc ^= (data[len] << 8);
        for(int i = 0; i < 8; i++) {
            // check if the MSB is 1
            if ((crc & 0x8000) != 0) {
                // shift left and xor with 0x11021
                crc = (crc << 1) ^ 0x1021;
            } else {
                // if MSB is 0 shift left
                crc <<= 1;
            }
        }
    }

    data[5] = crc >> 8;       // upper 8 bits
    data[6] = crc & 0x00FF;   // lower 8 bits
}