#include <stdio.h>

#define FIXED_CHARGE 5000L

int main(void)
{
    int units = 150;
    long energy_charge = 50L * 225L;
    long total = FIXED_CHARGE + energy_charge;

#ifdef DEBUG
    printf("DEBUG: Units = %d\n", units);
    printf("DEBUG: Energy charge = %ld paise\n",
           energy_charge);
    printf("DEBUG: Total = %ld paise\n", total);
#endif

    printf("Units consumed: %d\n", units);
    printf("Energy charge: Rs %ld.%02ld\n",
           energy_charge / 100, energy_charge % 100);
    printf("Total bill: Rs %ld.%02ld\n",
           total / 100, total % 100);

    return 0;
}


