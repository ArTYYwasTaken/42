/*
In Solo Leveling, mana cores determine a hunter’s magic potential. Based on their mana power, assign a core grade.

Rules:

Below 100 MP → "Low-grade Core"
100 - 299 MP → "Mid-grade Core"
300 - 599 MP → "High-grade Core"
600+ MP → "Supreme Core"
📝 Ask the user for their MP and print their mana core grade.
🔹 Bonus: Instead of multiple if-else, use a ternary operator.
*/

//      My Answer ✅

#include <stdio.h>
#include <string.h>

const char* getCoreGrade (int manaPower) {
    // If Else
    if (manaPower >= 600) return "Supreme Core";
    else if (manaPower >= 300) return "High-grade Core";
    else if (manaPower >= 100) return "Mid-grade Core";
    return "Low-grade Core";
}
    // Ternary Operator
    return (manaPower >= 600) ? "Supreme Core":
           (manaPower >= 300) ? "High-grade Core":
           (manaPower >= 100) ? "Mid-grade Core" : "Low-grade Core";
}

int main() {
    int (manaPower);
    char coreGrade[20];

    printf("\nMana Core Count: ");
    if(scanf("%d", &manaPower) != 1 || manaPower < 0) {
        printf("Invalid value, please write a valid value");
        return 1;
    }

   strcpy (coreGrade, getCoreGrade (manaPower));

    printf("You are a %s", coreGrade);

    return 0;
}

//      Real Answer ✅✅

#include <stdio.h>
#include <string.h>

// Function to determine mana core grade
const char* getCoreGrade(int manaPower) {
    if (manaPower >= 600) return "Supreme Core";
    if (manaPower >= 300) return "High-grade Core";
    if (manaPower >= 100) return "Mid-grade Core";
    return "Low-grade Core";
}

int main() {
    int manaPower;   // Fixed variable declaration
    char coreGrade[20];

    // Ask for mana power input
    printf("\nMana Core Count: ");
    if (scanf("%d", &manaPower) != 1 || manaPower < 0) {  // Invalid input check
        printf("Invalid value, please enter a valid number.\n");
        return 1;
    }

    // Get the mana core grade and store it
    strcpy(coreGrade, getCoreGrade(manaPower));

    // Print the result
    printf("You are a %s\n", coreGrade);
    
    return 0;
}

/*
🔥 Key Fixes & Improvements:
✔ Removed unnecessary parentheses in int (manaPower);.
✔ Made error messages clearer so users know what went wrong.