void send_command(int address, int command);
void calculate_crc(int data[]);
void reset_scanner();
void save_settings()

                                    // addresses for setting the following parameters
#define MODEADDR            0x00    // continous/induction mode
#define INTERVALADDR        0x05    // read interval
#define S_INTERVALADDR      0x13    // interval between reading the same barcode
#define READTIMEADDR        0x06    // time for single read
#define OUTPUTTIMEADDR      0x14    // time for data output
#define UARTSETUPADDR1      0x2B    // UART settings
#define UARTSETUPADDR2      0x2A    // UART settings
#define BARCODETYPESADDR    0x2C    // allowed barcode types all/default/none
#define CODE128ADDR         0x33    // allow Code128
#define CODE39ADDR          0x36    // allow Code39
#define EAN13ADDR           0x2E    // allow EAN13
#define QRADDR              0x3F    // allow QR-codes
#define OUTPUTFORMATADDR    0x60    // output formatting
