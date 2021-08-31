/**
 * Created by Linus Zhang on 2021/7/28.
 */

#include <stdio.h>

int main(void)
{
    int item, year, month, day;
    float price;

    printf("Enter item number: ");
    scanf("%d", &item);

    printf("Enter unit price: ");
    scanf("%f", &price);

    printf("Enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("Item\tUnit\tPurchase\n");
    printf("\t\tPrice\tDate\n");
    printf("%d\t\t$%8.2f,\t%.2d/%.2d/%.4d\n", item, price, month, day, year);

}