/*
Sung Jin-Woo wants to estimate his army’s strength based on number of shadows and their average power level.

📝 Ask the user for:

Number of shadow soldiers
Their average power level
📝 Calculate the total army power using:

Total Power = Number of Soldiers × Average Power

📝 Print the army's total strength and rank it as:

Below 5,000 → "Small Army"
5,000 - 19,999 → "Elite Army"
20,000 - 49,999 → "Great Army"
50,000+ → "Monarch’s Legion"
🔹 Bonus: Use functions for calculations and ranking.
*/

//     My Answer ✅❌
/*
#include <stdio.h>
#include <string.h>

const char* getarmyPower(int totalPower) {
    return (totalPower >= 50000) ? "Monarch's Legion":
           (totalPower >= 20000) ? "Great Army":
           (totalPower >= 5000) ? "Elite Army" : "Small Army";
}

int main() {

    int shadowSoldiers;
    int averagePower;
    int totalPower = shadowSoldiers + averagePower;
    char armyPower[20];

    printf("\nNumber of Shadow Soldiers: ");
    if (scanf("%d", shadowSoldiers) != 1 || shadowSoldiers < 1) {
        printf("\nInvalid value. Please enter a valid number\n");
        return 1;
    }

    printf("\nAverage Power Level: ");
    if (scanf("%d", averagePower) != 1 || averagePower < 1); {
        printf("\nInvalid value. Please enter a valid number\n");
        return 1;
    }

    strcpy(armyPower, getarmyPower(totalPower));

    printf("\nArmy's Total Strength is %d", totalPower);
    printf("\nArmy's rank is %s", armyPower);

    return 0;
}
*/
//       Real Answer ✅✅

#include <stdio.h>
#include <string.h>

// Function to determine army strength based on total power
const char* getArmyPower(int totalPower) {
    return (totalPower >= 50000) ? "Monarch's Legion" :
           (totalPower >= 20000) ? "Great Army" :
           (totalPower >= 5000) ? "Elite Army" : "Small Army";
}

void invalid() {
    printf("\nInvalid value. Please enter a valid number.\n");
}

int main() {
    int shadowSoldiers;  // Number of soldiers
    int averagePower;    // Average power per soldier
    int totalPower;      // Total power of the army
    char armyPower[20];  // Rank of the army

    // Ask for the number of Shadow Soldiers
    printf("\nNumber of Shadow Soldiers: ");
    if (scanf("%d", &shadowSoldiers) != 1 || shadowSoldiers < 1) {  // Added '&' and fixed condition
        //printf("\nInvalid value. Please enter a valid number.\n");
        invalid();
        return 1;
    }

    // Ask for the average power level
    printf("\nAverage Power Level: ");
    if (scanf("%d", &averagePower) != 1 || averagePower < 1) {  // Removed extra semicolon and added '&'
        printf("\nInvalid value. Please enter a valid number.\n");
        return 1;
    }

    // Calculate total power
    totalPower = shadowSoldiers * averagePower;

    // Get army rank based on total power
    strcpy(armyPower, getArmyPower(totalPower));

    // Display results
    printf("\nArmy's Total Strength is: %d", totalPower);
    printf("\nArmy's Rank is: %s\n", armyPower);

    return 0;
}

/*
🔥 Key Fixes & Improvements:
✔ Added & in scanf (scanf("%d", &shadowSoldiers);) to properly store the input.
✔ Fixed uninitialized totalPower—it is now calculated after both inputs.
✔ Removed the semicolon (;) after the if condition, which was causing unintended behavior.
✔ Changed + to * in totalPower = shadowSoldiers * averagePower; to properly calculate power
   (since total power is based on multiplication, not addition).
✔ Improved output format so it's cleaner.
*/