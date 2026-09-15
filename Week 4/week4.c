#include <stdio.h>

int main() {
    char studentName[50];
    int test1Mark;
    int test2Mark;
    int AssignmentMark;

    printf("\nEnter Student Name: ");
    scanf("%49s", studentName);

    printf("\nEnter Test 1 mark: ");
    scanf("%d", &test1Mark);

    printf("\nEnter Test 2 mark: ");
    scanf("%d", &test2Mark);

    printf("\nEnter Assignment mark: ");
    scanf("%d", &AssignmentMark);
    
    double total = test1Mark + test2Mark + AssignmentMark;

    printf("\nStudent: %s\n", studentName);
    printf("\nTotal Marks: %.2lf\n\n", total);

    if(total >= 75) {
        printf("Distinction\n");
    }
    else if(total >= 60) {
        printf("Credit\n");
    }
    else if(total > 50) {
        printf("Pass\n");
    } 
    else {
        printf("Fail\n");
    }


return 0;
}