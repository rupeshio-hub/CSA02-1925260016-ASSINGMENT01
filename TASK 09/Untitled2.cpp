#include <stdio.h>

#define METER_MAX 65535U
#define FIXED_CHARGE 5000LL
#define RATE2 225LL
#define RATE3 450LL

long long calculate_bill(unsigned int units)
{
    long long energy = 0;

    if (units > 200)
        energy = 100LL * RATE2
               + (long long)(units - 200) * RATE3;
    else if (units > 100)
        energy = (long long)(units - 100) * RATE2;

    return FIXED_CHARGE + energy;
}

int get_units(long long previous, long long current,
              unsigned int *units)
{
    if (previous < 0 || previous > METER_MAX ||
        current < 0 || current > METER_MAX)
        return 0;

    if (current >= previous) {
        *units = (unsigned int)(current - previous);
    } else if (previous >= 60000 && current <= 1000) {
        *units = (unsigned int)(METER_MAX - previous + 1 + current);
    } else {
        return 0;
    }

    return 1;
}

void print_bill(unsigned int units)
{
    long long bill = calculate_bill(units);

    printf("%3u units -> Rs %lld.%02lld\n",
           units, bill / 100, bill % 100);
}

int main(void)
{
    unsigned int units;
    int i;

    printf("TASK 09: BILLING PROGRAM TESTS\n\n");

    printf("1. Normal and boundary tests:\n");
    print_bill(0);
    print_bill(100);
    print_bill(150);
    print_bill(200);
    print_bill(350);

    printf("\n2. Meter rollover test:\n");

    if (get_units(65400, 120, &units)) {
        printf("Previous reading: 65400\n");
        printf("Current reading : 120\n");
        printf("Units consumed  : %u\n", units);
        print_bill(units);
    }

    printf("\n3. Invalid reading test:\n");

    if (!get_units(5000, 4500, &units))
        printf("Invalid reading: decrease without rollover.\n");

    if (!get_units(-1, 100, &units))
        printf("Invalid reading: negative value.\n");

    printf("\n4. Five-bill total:\n");

    {
        unsigned int bills[] = {0, 100, 150, 200, 350};
        long long total = 0;

        for (i = 0; i < 5; i++) {
            total += calculate_bill(bills[i]);
        }

        printf("Total for five bills = Rs %lld.%02lld\n",
               total / 100, total % 100);
    }

    return 0;
}
