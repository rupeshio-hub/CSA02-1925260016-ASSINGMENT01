#include <stdio.h>

int main(void)
{
    long long energy_wh;
    long long normal_rate;
    long long fixed_charge;
    long long energy_charge;
    long long total;
    int hour;
    int is_peak;

    printf("Enter energy consumed in Wh: ");

    if (scanf("%lld", &energy_wh) != 1 ||
        energy_wh < 0) {
        printf("Invalid energy reading.\n");
        return 1;
    }

    printf("Enter hour of day (0-23): ");

    if (scanf("%d", &hour) != 1 ||
        hour < 0 || hour > 23) {
        printf("Invalid hour.\n");
        return 1;
    }

    printf("Enter normal rate in paise per kWh: ");

    if (scanf("%lld", &normal_rate) != 1 ||
        normal_rate < 0) {
        printf("Invalid tariff rate.\n");
        return 1;
    }

    printf("Enter fixed charge in paise: ");

    if (scanf("%lld", &fixed_charge) != 1 ||
        fixed_charge < 0) {
        printf("Invalid fixed charge.\n");
        return 1;
    }

    /*
       Peak hours: 18:00 to 21:59.
       Energy is entered in Wh.
       Rate is in paise per kWh.
    */

    is_peak = (hour >= 18 && hour < 22);

    if (is_peak) {
        energy_charge =
            (energy_wh * normal_rate * 120LL + 50000LL)
            / 100000LL;
    } else {
        energy_charge =
            (energy_wh * normal_rate + 500LL) / 1000LL;
    }

    total = energy_charge + fixed_charge;

    printf("\nSMART METER BILL\n");
    printf("Energy consumed: %lld Wh\n", energy_wh);
    printf("Time: %02d:00\n", hour);

    if (is_peak)
        printf("Tariff: Peak rate (20%% higher)\n");
    else
        printf("Tariff: Normal rate\n");

    printf("Energy charge: Rs %lld.%02lld\n",
           energy_charge / 100, energy_charge % 100);

    printf("Fixed charge: Rs %lld.%02lld\n",
           fixed_charge / 100, fixed_charge % 100);

    printf("Total bill: Rs %lld.%02lld\n",
           total / 100, total % 100);

    return 0;
}
