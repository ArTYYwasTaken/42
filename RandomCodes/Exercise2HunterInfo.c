#include <stdio.h>
#include <string.h>

char getRank(int level) {
    if (level >= 100) return 'S';
    if (level >= 80) return 'A';
    if (level >= 60) return 'B';
    if (level >= 40) return 'C';
    if (level >= 20) return 'D';
    return 'E';
}

int main() {
    char name[50];  // Larger buffer for full name
    char class[50]; // Larger buffer for full class
    int level;
    char rank;

    printf("\nWhat's your name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline from input

    printf("\nWhat class are you: ");
    fgets(class, sizeof(class), stdin);
    class[strcspn(class, "\n")] = '\0'; // Remove newline from input

    printf("\nWhat level are you: ");
    if (scanf("%d", &level) != 1) {
        printf("\nInvalid level");
        return 1;
    }

    rank = getRank(level); // Assign rank based on level

    printf("\n--- Hunter Info ---");
    printf("\nName: %s", name);
    printf("\nClass: %s", class);
    printf("\nLevel: %d", level);
    printf("\nRank: %c\n", rank);

    return 0;
}
