#include <stdio.h>

int main() {
    int level;

    printf("\nEnter Hunter's Level: ");
    
    if (scanf("%d", &level) != 1) {  // If input is NOT a number
        printf("Invalid input! Please enter a number.\n");
        return 1;  // Exit program with error
    }

    if (level >= 10) {
        printf("Access granted\n");
    } else if (level <= 0) {
        printf("Invalid level\n");
    } else {
        printf("Access denied\n");
    }

    return 0;
}