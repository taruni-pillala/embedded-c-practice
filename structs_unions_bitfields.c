#include <stdio.h>

// ── STRUCT ── modelling a sensor
struct Sensor
{
    int id;
    float temperature;
    int is_active;
};

// ── BITFIELD ── modelling a hardware status register
struct StatusRegister
{
    unsigned int data_ready : 1; // bit 0 - data is ready to read
    unsigned int overflow : 1;   // bit 1 - buffer overflow occurred
    unsigned int parity_err : 1; // bit 2 - communication error
    unsigned int reserved : 29;  // bits 3-31 - unused
};

// ── UNION ── same memory, two views
union DataPacket
{
    unsigned int full_word; // view as full 32-bit value
    unsigned char bytes[4]; // view as 4 separate bytes
};

int main()
{

    // using struct
    struct Sensor temp_sensor;
    temp_sensor.id = 1;
    temp_sensor.temperature = 36.5;
    temp_sensor.is_active = 1;

    printf("=== STRUCT - Sensor Data ===\n");
    printf("Sensor ID: %d\n", temp_sensor.id);
    printf("Temperature: %.1f degrees\n", temp_sensor.temperature);
    printf("Active: %d\n\n", temp_sensor.is_active);

    // using bitfield
    struct StatusRegister status;
    status.data_ready = 1; // data is ready
    status.overflow = 0;   // no overflow
    status.parity_err = 0; // no error

    printf("=== BITFIELD - Status Register ===\n");
    printf("Data Ready: %d\n", status.data_ready);
    printf("Overflow: %d\n", status.overflow);
    printf("Parity Error: %d\n\n", status.parity_err);

    // using union
    union DataPacket packet;
    packet.full_word = 0x12345678;

    printf("=== UNION - Same memory, two views ===\n");
    printf("Full 32-bit word: 0x%08X\n", packet.full_word);
    printf("Byte 0: 0x%02X\n", packet.bytes[0]);
    printf("Byte 1: 0x%02X\n", packet.bytes[1]);
    printf("Byte 2: 0x%02X\n", packet.bytes[2]);
    printf("Byte 3: 0x%02X\n", packet.bytes[3]);

    // connecting everything - like real STM32 register access
    printf("\n=== REAL EMBEDDED USE - GPIO modelled as struct ===\n");

    struct GPIO
    {
        volatile unsigned int MODER; // mode register
        volatile unsigned int ODR;   // output data register
        volatile unsigned int IDR;   // input data register
    };

    struct GPIO gpio_sim;
    gpio_sim.ODR = 0x00;

    // turn ON LED at pin 13 using struct + bit manipulation
    gpio_sim.ODR |= (1 << 13);
    printf("GPIO ODR after LED ON: 0x%08X\n", gpio_sim.ODR);

    // turn OFF LED at pin 13
    gpio_sim.ODR &= ~(1 << 13);
    printf("GPIO ODR after LED OFF: 0x%08X\n", gpio_sim.ODR);

    return 0;
}