#include <stdio.h>

int main() {
    double revenue;
    double expenses;
    double balance;

    printf("\nMUNICIPAL BUDGET CALCULATOR\n");

    printf("Enter total revenue: ");
    scanf("%lf", &revenue);

    printf("Enter total expenses: ");
    scanf("%lf", &expenses);

    balance = revenue - expenses;

    printf("\nRevenue: %.2f\n", revenue);
    printf("Expenses: %.2ff\n", expenses);
    printf("Balance: %.2f\n", balance);

return 0;
}