#include <stdio.h>

int main(void)
{
    int bill_counts[] = {4000, 60000, 800000};
    int i;

    /* Example bill: Rs 162.50 = 16250 paise */
    long long bill_paise = 16250LL;

    printf("TASK 10: FLOAT VS INTEGER PAISE\n\n");

    for (i = 0; i < 3; i++) {
        int count = bill_counts[i];

        float float_total = 0.0f;
        long long paise_total = 0;

        for (int j = 0; j < count; j++) {
            float_total += 162.50f;
            paise_total += bill_paise;
        }

        printf("Number of bills: %d\n", count);
        printf("Float total: Rs %.2f\n", float_total);
        printf("Paise total: Rs %lld.%02lld\n",
               paise_total / 100, paise_total % 100);
        printf("\n");
    }

    printf("Size of int       = %zu bytes\n", sizeof(int));
    printf("Size of long      = %zu bytes\n", sizeof(long));
    printf("Size of long long = %zu bytes\n", sizeof(long long));

    return 0;
}
