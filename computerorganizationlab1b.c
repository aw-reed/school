#include <stdio.h>
#include <stdlib.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num != 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    int integer;
    int x = 0;
    int arr[100];  // Assuming a maximum of 100 inputs
    int even = 0;
    int odd = 0;
    double evenSum = 0;
    double oddSum = 0;
    double evenAvg;
    double oddAvg;

    do {
        printf("Enter the %d", x + 1);

        if (x + 1 == 1) {
            printf("st number: ");
        } else if (x + 1 == 2) {
            printf("nd number: ");
        } else if (x + 1 == 3) {
            printf("rd number: ");
        } else {
            printf("th number: ");
        }

        scanf("%d", &integer);
        arr[x] = integer;
        x++;

        if (arr[0] == 0) {
            printf("There is no average to compute.\n");
            exit(0);
        }
    } while (integer != 0);

    for (int i = 0; i < x - 1; i++) {
        int digitSum = sumOfDigits(arr[i]);
        if (digitSum % 2 != 0) {
            oddSum += arr[i];
            odd++;
        }
    }

    if (odd > 0) {
        oddAvg = oddSum / odd;
        printf("Average of inputs whose digits sum up to an odd number: %.2f\n", oddAvg);
    } else {
        printf("No inputs with digits summing up to an odd number.\n");
    }

    return 0;
}
