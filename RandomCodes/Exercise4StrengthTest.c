/*
Sung Jin-Woo takes a strength test before ranking up. Based on his physical strength, determine his hunter category.

Rules:

Below 50 kg → "Weak"
50 - 99 kg → "Average"
100 - 149 kg → "Strong"
150+ kg → "Superhuman"
📝 Ask the user for their lifting weight and print their hunter category.
🔹 Bonus: Instead of if-else, try using arrays or switch-case.
*/

//     My Answer (WRONG ❌❌)

#include <stdio.h>
#include <string.h>

char getCategory(int weight)[11] {
    if(weight >= 150) return "Superhuman";
    else  if(weight >= 100) return "Strong";
    else if(weight >= 50) return "Average";
    return "Weak";
}

int main() {

    int weight;
    char category[11];

    printf("\nLifting Weight: ");
    fgets("%s", sizeof(weight), stdin);
    weight[strlen(weight) - 1] = '\0';

    if(weight < 0);
     printf("\nInvalid Weight");
     return 0;

     category[11] = getCategory(int weight)[11];

     printf("\nYour Hunter Category is %s", category);
     
     return 0;
}

/*
Key Issues:
1. Return Type in getCategory: The function getCategory should return a string (char[] or char*), not a char.

2. Incorrect Input Handling with fgets: You used fgets("%s", ...), but this is incorrect for reading an integer.
You should use scanf or modify your input handling.

3. Array Size for category: The line category[11] = getCategory(int weight)[11]; is incorrect.
You're trying to assign a string to a character array, but you're using a wrong syntax and also accessing it incorrectly.

4. Invalid if statement syntax: The statement if(weight < 0); has a stray semicolon and won't execute properly.
*/

//        Real Answer ✅✅

#include <stdio.h>
#include <string.h>

// Function to determine Hunter Category based on weight
const char* getCategory(int weight) {
    if (weight >= 150) return "Superhuman";  // For weights 150+ kg
    else if (weight >= 100) return "Strong"; // For weights 100-149 kg
    else if (weight >= 50) return "Average"; // For weights 50-99 kg
    return "Weak"; // For weights below 50 kg
}

int main() {
    int weight;                // Variable to store weight
    char category[20];         // Array to store the hunter category as a string

    // Prompt the user to input weight
    printf("\nLifting Weight: ");
    scanf("%d", &weight);      // Read an integer value for weight

    // Check for negative input (invalid weight)
    if (weight < 0) {
        printf("\nInvalid Weight\n");
        return 1;  // Exit with error code
    }

    // Get the category for the given weight
    strcpy(category, getCategory(weight)); // Copy the returned category into category array

    // Output the determined hunter category
    printf("\nYour Hunter Category is: %s\n", category);
    
    return 0;  // Successful execution
}

/*
Explanation of Changes:

Function getCategory:
I changed the function to return a pointer to a constant string (const char*) instead of a char.
This allows you to return the string directly.

Input with scanf:
I replaced fgets with scanf("%d", &weight); to read an integer (%d) for weight. fgets is used for reading strings,
but here you need an integer.

String Copy:
Instead of category[11] = getCategory(int weight)[11];, I used strcpy(category, getCategory(weight));
to copy the returned string into the category array.

Negative Weight Check:
Fixed the if (weight < 0) check (removed the unnecessary semicolon) and added a return value of 1 for error handling.

Improved Output:
The program prints the category in a readable format using %s to print the string from the category array.
*/