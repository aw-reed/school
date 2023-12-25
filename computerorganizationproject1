#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
    }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
for(int i = 0; i < bSize; i++){ // prints puzzle, loops through rows of array
        for(int j = 0; j < bSize; j++){ // loops through columns of the array
                printf("%c ", *(*(arr + i) + j)); // prints each element of the array
        }
        printf("\n"); // prints a new line after each row of the array
    }
    printf("\n"); // final new line after the puzzle is fully printed out
}

bool range (int row, int col){ // this checks if the given row and cloumn is in the bounds of the puzzle
        return (row >= 0) && (row < bSize) && (col >= 0) && (col <bSize);
}

int search(char** arr, char* word, int row, int col, int in, int length, int **pathNum){
        int rownum[] = { -1, -1, -1, 0, 0, 1, 1, 1}; // 2 integer arrays which represent row / column
        int colnum[] = { -1, 0, 1, -1, 1, -1, 0, 1}; // 8 possible directions the word can be found
        int j = 0;
        if (in > (length) || *(*(arr + row) + col) != *(word + in)){ // checks if current index is greater than the length of the word, or if character does not match current char
                return 0; // if either is true, then 0 is returned to indicate unsuccessful search
        }
        if (in == length){ // index is equal to length, function updates element in pathNum to 1 to show search was successful
        *(* (pathNum + row) + col) = * (* (pathNum + row) + col) * 10 + in + 1;
                return 1;
        }
        int direction;
        for(direction = 0; direction < 8; direction ++) { // for loop that checks all 8 directions, recursively calls itself with new row/column indices 
                if(in == length){
                return 1; // returns 1 to indiciate successful search
                break;
                }
                if (range(row + *(rownum + direction), col + *(colnum+direction))){ // if statement that iterates over the 8 directions
                        if(search(arr, word, row + *(rownum + direction), col + *(colnum + direction), in + 1, length, pathNum)){
                                * (* (pathNum + row) + col) = * (* (pathNum + row) + col) * 10 + in + 1; 
                                return 1; // 1 is returned to indicate a successful search
                        }
                } 
 
        }
        return 0;
}

void convert(char *word){ // converts all lowercase letters to uppercase letters
        char* lowcase = word;
        while(*lowcase) { // loop continues until end of the string is reached
        if('a' <= *lowcase || *lowcase >= 'z') *lowcase -= 32; // checks each character using ASCII charcter codes, if lowercase subtracts 32 from ASCII value.
        lowcase++; // moves to next char in string
        } 
}


void searchPuzzle(char** arr, char* word) {
        int **array = (int **) malloc(bSize * sizeof(int *)); // creates 2d array using dynamic memory allocation
        for(int i = 0; i<bSize; i++){
                *(array + i) = (int *) malloc(bSize * sizeof(int));
                for(int j = 0; j < bSize; j++){
                        *(*(array +i) + j) = 0;
                }
        }
        int x[] = { -1, -1, -1, 0, 0, 1, 1, 1}; // 2 1d integer arrays which represents each of the 8 directions
        int y[] = { -1, 0, 1, -1, 1, -1, 0, 1};
 
        int length = (strlen(word) - 1); // length of word
        int valid = 0;
        for(int c = 0; c < length; c++){
                convert(word); // entire word is made uppercase
        }
        for(int row = 0; row < bSize; row++){ // function iterates through each rw and column of the puzzle grid using two nested for loops
                for(int col = 0; col < bSize; col++){
                        if (*(*(arr + row) + col) == *(word)) {
                                valid = search(arr,word, row, col, 0, length, array); // searchs for next character in any of the 8 directions
                                if(valid == 1) { // if it was found, then search made valid equal to 1
                                        printf("Word found! \n");
                                        printf("Printing the search path:\n");
                                                for (int p = 0; p < bSize; p++){
                                                        for(int q = 0; q <bSize; q++){
                                                                printf("%d\t", *(*(array+p)+q));
                                                        }
                                                        printf("\n");
                                                }
                                                return;
                                        }
                                }
                        }
                } 
                printf("Word not found! \n"); // if word is not found, value was made 0.
        }
