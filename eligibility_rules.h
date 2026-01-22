#ifndef ELIGIBILITY_RULES_H
#define ELIGIBILITY_RULES_H

#define CURRENT_YEAR 2026

struct UserProfile {
    char name[50];
    int age;
    char category[10];   // GEN / OBC / SC / ST

    int passedClass10;
    int passedClass12;

    char subjects12[20]; // PCM / PCB / PCMB / ARTS / COMMERCE
    int yearOfPassing12;

    int graduationCompleted;
    char graduationStream[20]; // Engineering / Science / Arts / Medical
    int graduationYear;

    int upscAttempts;
};

/* Function Declarations */
struct UserProfile getUserData();

void checkClass10(struct UserProfile user);
void checkClass12(struct UserProfile user);
void checkGraduation(struct UserProfile user);
void checkJEE(struct UserProfile user);
void checkUPSC(struct UserProfile user);
void checkGATE(struct UserProfile user);
void checkNEET(struct UserProfile user);

#endif
