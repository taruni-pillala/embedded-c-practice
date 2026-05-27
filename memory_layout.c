#include <stdio.h>

// 1. GLOBAL VARIABLE (Initialized)
// This lives in the "Data Section" (SRAM).
// Its initial value (100) is stored in Flash and copied to SRAM when the MCU boots.
int globally_tracked_heartbeats = 100;

// 2. GLOBAL VARIABLE (Uninitialized)
// This lives in the "BSS Section" (SRAM).
// The microcontroller automatically resets this to 0 at startup.
int patient_alert_counter;

// 3. CONSTANT VARIABLE
// This lives permanently in the "Read-Only / Flash Memory".
// It can never be changed by the code while running.
const int DEVICE_ID = 5542;

void my_medical_function(void)
{
    // 4. LOCAL VARIABLE
    // This lives in the "Stack Section" (SRAM).
    // It is created dynamically when this function starts, and destroyed the moment the function ends.
    int temporary_sensor_reading = 45;

    printf("Temporary Reading inside function: %d\n", temporary_sensor_reading);
}

int main(void)
{
    // Calling our function to look at local variables
    my_medical_function();

    // Printing values just to verify they exist
    printf("Device ID (Flash): %d\n", DEVICE_ID);
    printf("Heartbeats (Data Segment): %d\n", globally_tracked_heartbeats);
    printf("Alert Counter (BSS Segment): %d\n", patient_alert_counter);

    return 0;
}