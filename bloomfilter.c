#include <stdio.h>
#include <string.h>

#define BUCKET_SIZE 1000

// bucket of defined size:
int bucket[BUCKET_SIZE] = {0};

// implementing hash function:
int hashFunction(char username[]) {
    int sum = 0;
    for (int i = 0; username[i] != '\0'; i++) {
        sum += (int)username[i];
    }
    // Modulus to keep hash value within bucket range
    return sum % BUCKET_SIZE;
}

// Function to check and insert username
void checkAndInsert(char username[]) {
    int index = hashFunction(username);

    if (bucket[index] == 0) {
        bucket[index] = 1;  // mark as used
        printf("\nUsername '%s' is available. You may proceed!\n", username);
    } else {
        printf("\nSorry! Username '%s' already in use.\n", username);
        printf("Suggestion: Try adding numbers or symbols like '%s123' or '%s_01'\n",
               username, username);
    }
}

int main() {
    char username[100];
    int choice;

    printf("=====================================\n");
    printf("   SIMPLE BLOOM FILTER DEMO PROGRAM  \n");
    printf("=====================================\n");
    printf("Bucket size: %d\n", BUCKET_SIZE);

    do {
        printf("\nEnter a username to register: ");
        scanf("%s", username);

        checkAndInsert(username);

        printf("\nDo you want to check another username? (1 = Yes / 0 = No): ");
        scanf("%d", &choice);

    } while (choice == 1);

    printf("\nThank you for using the system!\n");
    printf("Developed by: Yuvraj Pandey (B.Tech CSE-AI)\n");

    return 0;
}
