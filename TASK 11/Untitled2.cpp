
#include <stdio.h>

int main(void)
{
    int energy_Wh;
    int hour;
    int rate_paise;
    long fixed_charge_paise = 5000;
    long energy_charge_paise;
    long total_bill_paise;

    printf("Enter energy consumed in Wh: ");
    scanf("%d", &energy_Wh);

    printf("Enter hour (0-23): ");
    scanf("%d", &hour);

    printf("Enter normal rate in paise per kWh: ");
    scanf("%d", &rate_paise);

    if (energy_Wh < 0 || hour < 0 || hour > 23 || rate_paise < 0)
    {
        printf("Invalid input!\n");
        return 1;
    }

    /* Calculate energy charge */
    energy_charge_paise =
        (long)energy_Wh * rate_paise / 1000;

    /* Apply 20%% extra charge during peak hours (6 PM to 9:59 PM) */
    if (hour >= 18 && hour < 22)
    {
        energy_charge_paise =
            energy_charge_paise * 120 / 100;

        printf("Peak hours: 20%% extra charge applied.\n");
    }
    else
    {
        printf("Normal hours: No extra charge.\n");
    }

    total_bill_paise =
        energy_charge_paise + fixed_charge_paise;

    printf("\nEnergy consumed: %d Wh\n", energy_Wh);

    printf("Energy charge: Rs %ld.%02ld\n",
           energy_charge_paise / 100,
           energy_charge_paise % 100);

    printf("Fixed charge: Rs %ld.%02ld\n",
           fixed_charge_paise / 100,
           fixed_charge_paise % 100);

    printf("Total bill: Rs %ld.%02ld\n",
           total_bill_paise / 100,
           total_bill_paise % 100);

    return 0;
}


