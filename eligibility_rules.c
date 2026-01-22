#include <stdio.h>
#include <string.h>
#include "eligibility_rules.h"

/* -------- USER INPUT -------- */
struct UserProfile getUserData() {
    struct UserProfile user;

    printf("\nEnter your name: ");
    scanf(" %[^\n]", user.name);

    printf("Enter age: ");
    scanf("%d", &user.age);

    printf("Enter category (GEN/OBC/SC/ST): ");
    scanf("%s", user.category);

    printf("Passed Class 10? (1=Yes, 0=No): ");
    scanf("%d", &user.passedClass10);

    printf("Passed Class 12? (1=Yes, 0=No): ");
    scanf("%d", &user.passedClass12);

    if (user.passedClass12) {
        printf("Subjects in Class 12 (PCM/PCB/PCMB/ARTS/COMMERCE): ");
        scanf("%s", user.subjects12);

        printf("Year of passing Class 12: ");
        scanf("%d", &user.yearOfPassing12);
    }

    printf("Graduation completed? (1=Yes, 0=No): ");
    scanf("%d", &user.graduationCompleted);

    if (user.graduationCompleted) {
        printf("Graduation stream (Engineering/Science/Arts/Medical): ");
        scanf("%s", user.graduationStream);

        printf("Graduation year: ");
        scanf("%d", &user.graduationYear);
    }

    printf("UPSC attempts already used: ");
    scanf("%d", &user.upscAttempts);

    return user;
}

/* -------- CLASS 10 -------- */
void checkClass10(struct UserProfile user) {
    if (user.age >= 14) {
        printf("\n✅ Eligible for Class 10.\n");
    } else {
        printf("\n❌ Not eligible for Class 10.\nReason: Minimum age is 14.\n");
    }
}

/* -------- CLASS 12 -------- */
void checkClass12(struct UserProfile user) {
    if (user.passedClass10) {
        printf("\n✅ Eligible for Class 12.\n");
    } else {
        printf("\n❌ Not eligible for Class 12.\nReason: Class 10 not passed.\n");
    }
}

/* -------- GRADUATION -------- */
void checkGraduation(struct UserProfile user) {
    if (user.passedClass12) {
        printf("\n✅ Eligible for Graduation.\n");
    } else {
        printf("\n❌ Not eligible for Graduation.\nReason: Class 12 not passed.\n");
    }
}

/* -------- JEE MAIN -------- */
void checkJEE(struct UserProfile user) {
    if (!user.passedClass12) {
        printf("\n❌ Not eligible for JEE Main.\nReason: Class 12 not passed.\n");
        return;
    }

    if (strcmp(user.subjects12, "PCM") != 0 &&
        strcmp(user.subjects12, "PCMB") != 0) {
        printf("\n❌ Not eligible for JEE Main.\nReason: PCM subjects required.\n");
        return;
    }

    if (CURRENT_YEAR - user.yearOfPassing12 > 2) {
        printf("\n❌ Not eligible for JEE Main.\nReason: Class 12 passed too early.\n");
        return;
    }

    printf("\n✅ Eligible for JEE Main.\n");
}

/* -------- UPSC -------- */
void checkUPSC(struct UserProfile user) {
    int maxAge = 32, maxAttempts = 6;

    if (strcmp(user.category, "OBC") == 0) {
        maxAge = 35;
        maxAttempts = 9;
    } else if (strcmp(user.category, "SC") == 0 ||
               strcmp(user.category, "ST") == 0) {
        maxAge = 37;
        maxAttempts = 999;
    }

    if (user.age < 21 || user.age > maxAge) {
        printf("\n❌ Not eligible for UPSC.\nReason: Age not in allowed range.\n");
        return;
    }

    if (!user.graduationCompleted) {
        printf("\n❌ Not eligible for UPSC.\nReason: Graduation not completed.\n");
        return;
    }

    if (user.upscAttempts >= maxAttempts) {
        printf("\n❌ Not eligible for UPSC.\nReason: Attempt limit exceeded.\n");
        return;
    }

    printf("\n✅ Eligible for UPSC.\n");
    printf("Remaining attempts: %d\n", maxAttempts - user.upscAttempts);
}

/* -------- GATE -------- */
void checkGATE(struct UserProfile user) {
    if (!user.graduationCompleted) {
        printf("\n❌ Not eligible for GATE.\nReason: Graduation required.\n");
        return;
    }

    if (strcmp(user.graduationStream, "Engineering") != 0 &&
        strcmp(user.graduationStream, "Science") != 0) {
        printf("\n❌ Not eligible for GATE.\nReason: Engineering/Science degree required.\n");
        return;
    }

    printf("\n✅ Eligible for GATE.\n");
}

/* -------- NEET -------- */
void checkNEET(struct UserProfile user) {
    int maxAge = 25;

    if (strcmp(user.category, "OBC") == 0 ||
        strcmp(user.category, "SC") == 0 ||
        strcmp(user.category, "ST") == 0) {
        maxAge = 30;
    }

    if (user.age < 17 || user.age > maxAge) {
        printf("\n❌ Not eligible for NEET.\nReason: Age criteria not met.\n");
        return;
    }

    if (!user.passedClass12) {
        printf("\n❌ Not eligible for NEET.\nReason: Class 12 not passed.\n");
        return;
    }

    if (strcmp(user.subjects12, "PCB") != 0 &&
        strcmp(user.subjects12, "PCMB") != 0) {
        printf("\n❌ Not eligible for NEET.\nReason: PCB subjects required.\n");
        return;
    }

    printf("\n✅ Eligible for NEET.\n");
}
