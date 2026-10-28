#include <stdio.h>

int main(void)
{
    unsigned int previous, current;
    unsigned int units;
    long energy_charge = 0;
    long fixed_charge = 5000L;
    long total;

    printf("Enter previous reading: ");

    if (scanf("%u", &previous) != 1 || previous > 65535U)
    {
        printf("Invalid previous reading.\n");
        return 1;
    }

    printf("Enter current reading: ");

    if (scanf("%u", &current) != 1 || current > 65535U)
    {
        printf("Invalid current reading.\n");
        return 1;
    }

    
    units = (current - previous) & 65535U;

    if (units > 200U)
    {
        energy_charge =
            100L * 225L + (long)(units - 200U) * 450L;
    }
    else if (units > 100U)
    {
        energy_charge = (long)(units - 100U) * 225L;
    }

    total = fixed_charge + energy_charge;

    printf("Units consumed: %u\n", units);
    printf("Energy charge: Rs %ld.%02ld\n",
           energy_charge / 100, energy_charge % 100);
    printf("Fixed charge: Rs %ld.%02ld\n",
           fixed_charge / 100, fixed_charge % 100);
    printf("Total bill: Rs %ld.%02ld\n",
           total / 100, total % 100);

    return 0;
}


