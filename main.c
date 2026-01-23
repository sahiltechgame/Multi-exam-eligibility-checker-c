#include <stdio.h>
#include "eligibility_rules.h"

int main() {
    int choice;

    printf("\n===============================\n");
    printf(" Multi-Exam Eligibility System\n");
    printf("===============================\n\n");

    printf("Select exam to check eligibility:\n");
    printf("1. Class 10\n");
    printf("2. Class 12\n");
    printf("3. Graduation\n");
    printf("4. JEE Main\n");
    printf("5. UPSC\n");
    printf("6. GATE\n");
    printf("7. NEET\n");
    printf("8. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: checkClass10(); break;
        case 2: checkClass12(); break;
        case 3: checkGraduation(); break;
        case 4: checkJEE(); break;
        case 5: checkUPSC(); break;
        case 6: checkGATE(); break;
        case 7: checkNEET(); break;
        case 8:
            printf("Thank you for using the system.\n");
            break;
        default:
            printf("Invalid choice. Restart program.\n");
    }

    return 0;
}
