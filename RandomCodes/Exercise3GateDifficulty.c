/*
A hunter enters a dungeon and needs to know its difficulty level based on its danger score.

Rules:

0 - 19 → F-Rank Gate
20 - 39 → E-Rank Gate
40 - 59 → D-Rank Gate
60 - 79 → C-Rank Gate
80 - 99 → B-Rank Gate
100+ → A-Rank Gate
📝 Write a program where the user enters the danger score, and you print the gate's rank.
*/

//   My Answer

#include <stdio.h>

char getRank(int dangerScore) {
    if(dangerScore >=100) return 'A';
    if(dangerScore >=80) return 'B';
    if(dangerScore >=60) return 'C';
    if(dangerScore >=40) return 'D';
    if(dangerScore >=20) return 'E';
    else return 'F';
}

    int main() {

        int dangerScore;
        char rank;

        printf("Gate's Danger Score: ");
        scanf("%d", &dangerScore);

        rank = getRank(dangerScore);

        printf("This is a %c-Rank Dungeon", rank);

        return 0;
    }

    //    Real Answer

#include <stdio.h>

// Function to determine the gate's rank based on danger score
char getRank(int dangerScore) {
    if (dangerScore >= 100) return 'A'; // 100+ → A-Rank Gate
    if (dangerScore >= 80) return 'B';  // 80-99 → B-Rank Gate
    if (dangerScore >= 60) return 'C';  // 60-79 → C-Rank Gate
    if (dangerScore >= 40) return 'D';  // 40-59 → D-Rank Gate
    if (dangerScore >= 20) return 'E';  // 20-39 → E-Rank Gate
    return 'F'; // 0-19 → F-Rank Gate (No need for "else" since this is the last case)
}

int main() {
    int dangerScore; // Variable to store the user's input
    char rank;       // Variable to store the assigned rank

    // Ask the user to input the gate's danger score
    printf("Gate's Danger Score: ");
    scanf("%d", &dangerScore); // Read the input value

    // Check if the user entered a negative number (which doesn't make sense)
    if (dangerScore < 0) {
        printf("Invalid danger score. Please enter a non-negative value.\n");
        return 1; // Exit with an error code
    }

    // Call the getRank function to determine the rank
    rank = getRank(dangerScore);

    // Print the result to the user
    printf("This is a %c-Rank Dungeon.\n", rank);

    return 0; // Program executed successfully
}