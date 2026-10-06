#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS  10
#define NUM_REGS     20
#define REG_LEN      20

void captureSalaries(float salaries[], int n) {
    for (int i = 0; i < n; i++) {
        float value;
        do {
            printf("Enter salary for employee %d: ", i + 1);
            if (scanf("%f", &value) != 1) {
                while (getchar() != '\n');
                value = -1;
            }
            if (value <= 0) {
                printf("Invalid salary. Enter a positive number.\n");
            }
        } while (value <= 0);
        salaries[i] = value;
    }
}

void displaySalaries(float salaries[], int n) {
    printf("\n--- Employee Salaries ---\n");
    for (int i = 0; i < n; i++) {
        printf("Employee %2d: %.2f\n", i + 1, salaries[i]);
    }
}

void salaryReport(float salaries[], int n) {
    float total = 0;
    float highest = salaries[0];
    float lowest = salaries[0];

    for (int i = 0; i < n; i++) {
        total += salaries[i];
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest)  lowest = salaries[i];
    }

    printf("\n--- Salary Report ---\n");
    printf("Total salary expenditure: %.2f\n", total);
    printf("Average salary:           %.2f\n", total / n);
    printf("Highest salary:           %.2f\n", highest);
    printf("Lowest salary:            %.2f\n", lowest);
}

void searchSalary(float salaries[], int n) {
    float target;
    int found = 0;

    printf("Enter salary to search for: ");
    scanf("%f", &target);

    for (int i = 0; i < n; i++) {
        if (salaries[i] == target) {
            printf("Salary found at position %d (employee %d).\n", i, i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Salary not found.\n");
    }
}

void sortFloats(float arr[], int n) {
    float temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void captureBudgets(float budgets[], int n) {
    for (int i = 0; i < n; i++) {
        float value;
        do {
            printf("Enter budget for department %d: ", i + 1);
            if (scanf("%f", &value) != 1) {
                while (getchar() != '\n');
                value = -1;
            }
            if (value <= 0) {
                printf("Invalid budget. Enter a positive number.\n");
            }
        } while (value <= 0);
        budgets[i] = value;
    }
}

void displayBudgets(float budgets[], int n) {
    printf("\n--- Department Budgets ---\n");
    for (int i = 0; i < n; i++) {
        printf("Department %2d: %.2f\n", i + 1, budgets[i]);
    }
}

void budgetReport(float budgets[], int n) {
    float total = 0;
    for (int i = 0; i < n; i++) {
        total += budgets[i];
    }
    printf("\nTotal budget:   %.2f\n", total);
    printf("Average budget: %.2f\n", total / n);
}

void captureRegistrations(char regs[][REG_LEN], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", regs[i]);
    }
}

void displayRegistrations(char regs[][REG_LEN], int n) {
    printf("\n--- Vehicle Registrations ---\n");
    for (int i = 0; i < n; i++) {
        printf("%2d. %s\n", i + 1, regs[i]);
    }
}

void searchRegistration(char regs[][REG_LEN], int n) {
    char target[REG_LEN];
    int found = 0;

    printf("Enter registration number to search for: ");
    scanf("%19s", target);

    for (int i = 0; i < n; i++) {
        if (strcmp(regs[i], target) == 0) {
            printf("Registration found at position %d.\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Registration not found.\n");
    }
}

int main() {
    float salaries[NUM_SALARIES];
    float budgets[NUM_BUDGETS];
    char registrations[NUM_REGS][REG_LEN];

    int salariesCaptured = 0;
    int budgetsCaptured = 0;
    int regsCaptured = 0;
    int choice;

    do {
        printf("\n===== MUNICIPAL INFORMATION MANAGEMENT SYSTEM =====\n");
        printf(" EMPLOYEE SALARIES\n");
        printf("  1. Capture salaries\n");
        printf("  2. Display salaries\n");
        printf("  3. Salary report (total, average, highest, lowest)\n");
        printf("  4. Search for a salary\n");
        printf("  5. Sort salaries (lowest to highest) and display\n");
        printf(" DEPARTMENT BUDGETS\n");
        printf("  6. Capture budgets\n");
        printf("  7. Display budgets\n");
        printf("  8. Budget report (total, average)\n");
        printf("  9. Sort budgets (lowest to highest) and display\n");
        printf(" VEHICLE REGISTRATIONS\n");
        printf(" 10. Capture registrations\n");
        printf(" 11. Display registrations\n");
        printf(" 12. Search for a registration\n");
        printf("  0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            choice = -1;
        }

        switch (choice) {
            case 1:
                captureSalaries(salaries, NUM_SALARIES);
                salariesCaptured = 1;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
                if (!salariesCaptured) {
                    printf("Capture salaries first (option 1).\n");
                } else if (choice == 2) {
                    displaySalaries(salaries, NUM_SALARIES);
                } else if (choice == 3) {
                    salaryReport(salaries, NUM_SALARIES);
                } else if (choice == 4) {
                    searchSalary(salaries, NUM_SALARIES);
                } else {
                    sortFloats(salaries, NUM_SALARIES);
                    printf("Salaries sorted.\n");
                    displaySalaries(salaries, NUM_SALARIES);
                }
                break;
            case 6:
                captureBudgets(budgets, NUM_BUDGETS);
                budgetsCaptured = 1;
                break;
            case 7:
            case 8:
            case 9:
                if (!budgetsCaptured) {
                    printf("Capture budgets first (option 6).\n");
                } else if (choice == 7) {
                    displayBudgets(budgets, NUM_BUDGETS);
                } else if (choice == 8) {
                    budgetReport(budgets, NUM_BUDGETS);
                } else {
                    sortFloats(budgets, NUM_BUDGETS);
                    printf("Budgets sorted.\n");
                    displayBudgets(budgets, NUM_BUDGETS);
                }
                break;
            case 10:
                captureRegistrations(registrations, NUM_REGS);
                regsCaptured = 1;
                break;
            case 11:
            case 12:
                if (!regsCaptured) {
                    printf("Capture registrations first (option 10).\n");
                } else if (choice == 11) {
                    displayRegistrations(registrations, NUM_REGS);
                } else {
                    searchRegistration(registrations, NUM_REGS);
                }
                break;
            case 0:
                printf("Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
