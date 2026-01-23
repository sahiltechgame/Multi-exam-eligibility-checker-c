#include <stdio.h>

/* -------- Class 10 -------- */
void checkClass10() {
    int age;

    printf("\n--- Class 10 Eligibility ---\n");
    printf("Enter age: ");
    scanf("%d", &age);

    if (age >= 14)
        printf("✅ Eligible for Class 10\n");
    else
        printf("❌ Not eligible (Minimum age 14)\n");
}

/* -------- Class 12 -------- */
void checkClass12() {
    int passed10;

    printf("\n--- Class 12 Eligibility ---\n");
    printf("Passed Class 10? (1=Yes, 0=No): ");
    scanf("%d", &passed10);

    if (passed10)
        printf("✅ Eligible for Class 12\n");
    else
        printf("❌ Not eligible (Class 10 required)\n");
}

/* -------- Graduation -------- */
void checkGraduation() {
    int passed12;

    printf("\n--- Graduation Eligibility ---\n");
    printf("Passed Class 12? (1=Yes, 0=No): ");
    scanf("%d", &passed12);

    if (passed12)
        printf("✅ Eligible for Graduation\n");
    else
        printf("❌ Not eligible (Class 12 required)\n");
}

/* -------- JEE Main -------- */
void checkJEE() {
    int passed12, pcm;

    printf("\n--- JEE Main Eligibility ---\n");
    printf("Passed Class 12? (1=Yes, 0=No): ");
    scanf("%d", &passed12);

    printf("Studied PCM? (1=Yes, 0=No): ");
    scanf("%d", &pcm);

    if (passed12 && pcm)
        printf("✅ Eligible for JEE Main\n");
    else
        printf("❌ Not eligible (Class 12 with PCM required)\n");
}

/* -------- UPSC -------- */
void checkUPSC() {
    int age, graduate;

    printf("\n--- UPSC Eligibility ---\n");
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Graduation completed? (1=Yes, 0=No): ");
    scanf("%d", &graduate);

    if (age >= 21 && age <= 32 && graduate)
        printf("✅ Eligible for UPSC\n");
    else
        printf("❌ Not eligible (Age 21–32 + Graduation required)\n");
}

/* -------- GATE -------- */
void checkGATE() {
    int graduate;

    printf("\n--- GATE Eligibility ---\n");
    printf("Graduation completed or final year? (1=Yes, 0=No): ");
    scanf("%d", &graduate);

    if (graduate)
        printf("✅ Eligible for GATE\n");
    else
        printf("❌ Not eligible (Graduation required)\n");
}

/* -------- NEET -------- */
void checkNEET() {
    int age, passed12, pcb;

    printf("\n--- NEET Eligibility ---\n");
    printf("Enter age: ");
    scanf("%d", &age);

    printf("Passed Class 12? (1=Yes, 0=No): ");
    scanf("%d", &passed12);

    printf("Studied PCB? (1=Yes, 0=No): ");
    scanf("%d", &pcb);

    if (age >= 17 && passed12 && pcb)
        printf("✅ Eligible for NEET\n");
    else
        printf("❌ Not eligible (Age ≥17 + PCB required)\n");
}
