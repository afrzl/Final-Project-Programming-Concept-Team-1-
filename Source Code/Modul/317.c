#include <stdio.h>

int main()
{
    for (;;)
    {
        int acc_number, mort_amount, mort_term;
        float int_rate, total_pay;
        printf("Enter account number (-1 to end): ");
        scanf("%d", &acc_number);
        if (acc_number == -1)
        {
            break;
        }
        else
        {
            printf("Enter mortgage amount (in dollars): ");
            scanf("%d", &mort_amount);
            printf("Enter mortgage term (in years): ");
            scanf("%d", &mort_term);
            printf("Enter interest rate (as a decimal): ");
            scanf("%f", &int_rate);
            total_pay = ((mort_amount * int_rate * mort_term) + mort_amount) / (mort_term * 12);
            printf("The monthly payable interest $ %.0f\n\n", total_pay);
        }
    }
}