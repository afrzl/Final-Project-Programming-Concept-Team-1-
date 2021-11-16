#include <stdio.h>

int main()
{
    float collected, taxCounty, taxState, sales, total_sales;
    char month[255];
    for (;;)
    {
        printf("Enter total amount collected (-1 to quit): ");
        scanf("%f", &collected);
        if (collected == -1)
        {
            break;
        }
        else
        {
            printf("Enter name of month: ");
            scanf("%s", &month);

            taxCounty = 0.05 * sales;
            taxState = 0.04 * sales;
            total_sales = taxCounty + taxState;
            sales = collected - total_sales;

            printf("Total Collections: $ %.2f\n", sales);
            // printf("Sales: $ %.2f\n", collected - taxCounty - taxState);
            // printf("County Sales Tax: $ %.2f\n", taxCounty);
            // printf("State Sales Tax: $ %.2f\n", taxState);
            // printf("Total Sales Tax Collected: $ %.2f\n", taxCounty + taxState);
        }
    }
}