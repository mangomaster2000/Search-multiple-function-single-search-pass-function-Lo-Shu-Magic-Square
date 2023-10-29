#include <stdio.h>

// Global variables
const int bCol = 3;
const int bRow = 3;

// Function prototypes
void input(int arr[bRow][bCol]);
void display(int arr[bRow][bCol]);
int loShuSquare(int arr[bRow][bCol]);

int main() {
    // Local variables
    int box[bRow][bCol];
    int isLoShu;

    // Display output
    printf("****************************************************************");
    printf("\nWelcome to the Lo Shu Magic Square Program");
    printf("\nThe Lo Shu Magic Square has the following properties: ");
    printf("\n-The grid contains the numbers 1 through 9");
    printf("\n-The sum of each row, column, and each diagonal adds up to the same number!");
    printf("\n****************************************************************");
    printf("\n");
    printf("\n");

    // Prompt user input
    input(box);

    // Display user input
    display(box);

    // Is the box Lo Shu or not
    isLoShu = loShuSquare(box);

    return 0;
}

// Display and increment box
void display(int arr[bRow][bCol]) {
    for (int row = 0; row < bRow; row++) {
        printf("\n");
        for (int col = 0; col < bCol; col++) {
            printf("%d|", arr[row][col]);
        }
    }
    printf("\n");
}

//input num to box
void input(int arr[bRow][bCol]) {
    int digit;
    int i = 1;
    int error[10] = {0};

    // Loop through and record input
    for (int row = 0; row < bRow; row++) {
        for (int col = 0; col < bCol;) {
            digit = 0; // Initialize digit to zero before using it

            while (digit < 1 || digit > 9) {
                printf("\nEnter digit %d: ", i);
                scanf("%d", &digit);

                // Error case
                if (digit < 1 || digit > 9) {
                    printf("Invalid number. Range is from 1-9\n");
                } else if (error[digit]) {
                    printf("Invalid number. You can only input a number once\n");
                } else {
                    error[digit] = 1;
                    arr[row][col] = digit;
                    col++;
                    i++;
                }
            }
        }
    }
}

//check if it meets req 
int loShuSquare(int arr[bRow][bCol]) {
    int rSum, cSum, dSum, d2Sum;
    int rows[bRow];
    int col[bCol];
    int isLoShu;

    printf("\n");

//calculate sum of each row and display
    for (int row = 0; row < bRow; row++) {
        rSum = 0;
        for (int col = 0; col < bCol; col++) {
            rSum += arr[row][col];
            rows[row] = rSum;
        }
        printf("The sum of row %d: %d\n", row + 1, rSum);
    }
    printf("\n");

//calculate the sum of each col and display
    for (int column = 0; column < bCol; column++) {
        cSum = 0;
        for (int row = 0; row < bRow; row++) {
            cSum += arr[row][column];
            col[column] = cSum;
        }
        printf("The sum of column %d: %d\n", column + 1, cSum);
    }
    printf("\n");

    dSum = d2Sum = 0;

//calculate the sum of diagonals
    for (int i = 0; i < bRow; i++) {
        for (int j = 0; j < bCol; j++) {
            if (i == j) {
                dSum += arr[i][j];
            }
            if (j == i) {
                d2Sum += arr[j][i];
            }
        }
    }
    printf("Sum of Diagonal 1: %d\n", dSum);
    printf("Sum of Diagonal 2: %d\n", d2Sum);

//check if all paths are 15
    if (rows[0] == rows[1] && rows[1] == rows[2] && col[0] == col[1] && col[1] == col[2] &&
        rSum && cSum && dSum && d2Sum == 15) {
        printf("\nYou have created a Lo Shu Square!\n");
        isLoShu = 1;
    } else {
        printf("\nFailed . . . Try again!\n");
        isLoShu = 0;
    }

    return isLoShu;
}
