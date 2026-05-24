#include <stdio.h>
int main()
{
    unsigned int reg = 00x0;
    // set bit 3
    reg |= (1 << 3);
    printf("After SET bit 3: 0x%2X\n", reg);
    // clear bit 3
    reg &= ~(1 << 3);
    printf("After Clear bit 3:0x%2X\n", reg);
    // toggle bit 5
    reg ^= (1 << 5);
    printf("after toggle bit 5:0x%2X\n", reg)
        // check bit 5
        if (reg &= (1 << 5))
            printf("Bit 5 is set\n");
    else printf("Bit 5 is not set\n");
    return 0;
}