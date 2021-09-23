void send_command(int address, int command);
void calculate_crc(int data[]);
void reset_scanner();
void save_settings()

                                    // addresses for setting the following parameters
#define MODE_ADDR            0x00    // continous/induction mode
#define INTERVAL_ADDR        0x05    // read interval
#define S_INTERVAL_ADDR      0x13    // interval between reading the same barcode
#define READTIME_ADDR        0x06    // time for single read
#define OUTPUTTIME_ADDR      0x14    // time for data output
#define UARTSETUP_ADDR1      0x2B    // UART settings
#define UARTSETUP_ADDR2      0x2A    // UART settings
#define BARCODETYPES_ADDR    0x2C    // allowed barcode types all/default/none
#define CODE128_ADDR         0x33    // allow Code128
#define CODE39_ADDR          0x36    // allow Code39
#define EAN13_ADDR           0x2E    // allow EAN13
#define QR_ADDR              0x3F    // allow QR-codes
#define OUTPUTFORMAT_ADDR    0x60    // output formatting
