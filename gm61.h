void send_command(int address, int command);
void calculate_crc(int data[]);
void reset_scanner();

int INIT_SCANNER[][2] = {
    {0x00, 0x82}, // continous reading on and light normally off
    {0x05, 0x05}, // 0.5 second read interval
    {0x13, 0x94}, // 2 second same barcode read interval
    {0x2C, 0x02}, // read all types of barcodes
    {0x2E, 0x01}, // enable reading EAN13, because the above doesn't do it
    {0x60, 0x00}, // remove all formatting from the returned data
};  