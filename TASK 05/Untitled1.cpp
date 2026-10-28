#include <stdio.h>


#define FIXED_CHARGE_PAISE 500  

long compute_fixed_bill(void)
{
    return FIXED_CHARGE_PAISE;
}

int main(void)
{
    long bill = compute_fixed_bill();

#ifdef DEBUG
    printf("DEBUG: Fixed charge = %ld paise\n", bill);
#endif

    printf("Fixed charge = Rs %ld.%02ld\n", 
           bill / 100, bill % 100);

    return 0; 
}
