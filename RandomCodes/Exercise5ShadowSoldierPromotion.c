/*
Jin-Woo is promoting his shadow soldiers. Each soldier has a kill count, and based on their experience, they get a new rank.

Rules:

0 - 4 kills → "Fodder"
5 - 9 kills → "Elite"
10 - 19 kills → "Knight"
20 - 49 kills → "General"
50+ kills → "Commander"
📝 Ask the user for the kill count and determine the soldier’s rank.
🔹 Bonus: Make it a function like char* getSoldierRank(int kills)
*/

//        My Answer ✅

#include <stdio.h>
#include<string.h>

const char* getSoldierRank(int kills) {
if(kills >= 50) return "Commander";
else if(kills >= 20) return "General";
else if(kills >= 10) return "Knight";
else if(kills >= 5) return "Elite";
return "Fodder";
}

int main() {

    int kills;
    char SoldierRank[15];

    printf("\nKill Count: ");
    if(scanf("%d", &kills) != 1) {
        printf("\nInvalid number\n");
        return 1;
    }
    
    if (kills < 0) {
        printf("\nInvalid number\n");
        return 1;
    }

    strcpy(SoldierRank, getSoldierRank(kills));

    printf("\nSoldier's rank is %s\n", SoldierRank);

    return 0;
}

//        Real Answer ✅✅

#include <stdio.h>
#include <string.h>

// Function to determine the soldier's rank based on kills
const char* getSoldierRank(int kills) {
    if (kills >= 50) return "Commander";
    if (kills >= 20) return "General";
    if (kills >= 10) return "Knight";
    if (kills >= 5) return "Elite";
    return "Fodder";
}

int main() {
    int kills;
    char SoldierRank[15]; // Array to store the rank

    // Ask for kill count
    printf("\nKill Count: ");
    if (scanf("%d", &kills) != 1 || kills < 0) {  // Check for invalid or negative input
        printf("\nInvalid number. Please enter a non-negative integer.\n");
        return 1;
    }

    // Get and store the soldier's rank
    strcpy(SoldierRank, getSoldierRank(kills));

    // Print the soldier's rank
    printf("\nSoldier's rank is %s\n", SoldierRank);

    return 0;
}

/*
✅ What’s Better in This Version?
✔️ Merges both invalid input checks into one condition (scanf("%d", &kills) != 1 || kills < 0).
✔️ Uses a single error message instead of repeating printf("\nInvalid number\n");.
✔️ More compact and readable.
*/