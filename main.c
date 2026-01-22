#include <stdio.h>
#include "eligibility_rules.h"

int main() {
    int choice;
    struct UserProfile user;

    printf("===== Multi-Exam Eligibility Evaluation System =====\n");

    user = getUserData();

    do {
        printf("\n----- MENU -----\n");
        printf("1. Class 10\n");
        printf("2. Class 12\n");
        printf("3. Graduation\n");
        printf("4. JEE Main\n");
        printf("5. UPSC\n");
        printf("6. GATE\n");
        printf("7. NEET\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkClass10(user); break;
            case 2: checkClass12(user); break;
            case 3: checkGraduation(user); break;
            case 4: checkJEE(user); break;
            case 5: checkUPSC(user); break;
            case 6: checkGATE(user); break;
            case 7: checkNEET(user); break;
            case 8: printf("\nExiting program.\n"); break;
            default: printf("\nInvalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}
