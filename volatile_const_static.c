#include <stdio.h>
// const=this pin number never changes
const unsigned int LED_pin = 13;

// function using static -remembers between calls
void count_presses()
{
    static int count = 0;
    count++;
    printf("Button pressed %d times\n", count);
}
int main()
{
    // showing constant
    printf("LED is on Pin:%d\n", LED_pin);
    // showing static, calling the function 5 times
    count_presses();
    count_presses();
    count_presses();
    count_presses();
    count_presses();

    // showing volatile concept
    // in real embedded code this would be:
    // volatile unsigned int *LED_REG = (volatile unsigned int *)0x40011010;
    // here we simulate it with a normal variable
    volatile unsigned int reg = 0x00;
    reg |= (1 << LED_pin); // turn on LED
    printf("LED register value after turning on pin %d,:0x%2X\n", LED_pin, reg);
    reg &= ~(1 << LED_pin); // turn off LED
    printf("LED register value after turning off pin %d,:0x%2X\n", LED_pin, reg);
    return 0;
}