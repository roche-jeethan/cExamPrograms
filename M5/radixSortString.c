#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100  // Maximum length of any name

// Function to get the maximum length of strings in the array
int getMaxLen(char array[][MAX_LEN], int n) {
    int maxLen = strlen(array[0]);
    for (int i = 1; i < n; i++) {
        if (strlen(array[i]) > maxLen) {
            maxLen = strlen(array[i]);
        }
    }
    return maxLen;
}

// Counting sort for a specific position
void countingSort(char array[][MAX_LEN], int size, int pos) {
    char output[size][MAX_LEN];
    int count[257] = {0};  // Extended ASCII (256 characters) + 1 for '\0'

    // Calculate count of characters at the given position
    for (int i = 0; i < size; i++) {
        int charIndex = pos < strlen(array[i]) ? (unsigned char)array[i][pos] : 0;
        count[charIndex + 1]++;
    }

    // Cumulative count
    for (int i = 1; i < 257; i++) {
        count[i] += count[i - 1];
    }

    // Place elements in sorted order
    for (int i = size - 1; i >= 0; i--) {
        int charIndex = pos < strlen(array[i]) ? (unsigned char)array[i][pos] : 0;
        strcpy(output[count[charIndex]], array[i]);
        count[charIndex]++;
    }

    // Copy sorted data back to original array
    for (int i = 0; i < size; i++) {
        strcpy(array[i], output[i]);
    }
}

// Radix sort for strings
void radixSort(char array[][MAX_LEN], int size) {
    int maxLen = getMaxLen(array, size);

    // Perform counting sort for each position from right to left
    for (int pos = maxLen - 1; pos >= 0; pos--) {
        countingSort(array, size, pos);
    }
}

// Print an array of strings
void printArray(char array[][MAX_LEN], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\t", array[i]);
    } printf("\n");
}

int main() {
    char array[20][MAX_LEN]; int i,n;
    printf("Enter the number of names: ");
    scanf("%d", &n);
    printf("Enter the names: ");
    for(i=0;i<n;i++){
        scanf("%s", array[i]);
    }
    printf("Original array:\n");
    printArray(array, n);

    radixSort(array, n);

    printf("\nSorted array:\n");
    printArray(array, n);

    return 0;
}
