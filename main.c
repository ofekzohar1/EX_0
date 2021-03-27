#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/* Define Constants */
#define MAX_BASE 16
#define MIN_BASE 2

int a, b; /* Store the input base and desired base */
long buildDecimalNum(); /* Convert number (user input) in a given base to decimal base */
int invalidBase(int base); /* Function checks whether the base is in range */
int digitCalc(char digit); /* Calculates the numeric value of the char digit */
void decToOtherBase(long decNum, int base); /* Calculates and print a given number in a desired base using recursion */

int main() {
    long decNum;

    printf("Please enter the numbers base:\n");
    scanf("%d", &a);
    if (invalidBase(a)) {
        printf("Invalid input base\n");
        return 0;
    }

    printf("Please enter the desired base:\n");
    scanf("%d", &b);
    if (invalidBase(b)) {
        printf("Invalid desired base\n");
        return 0;
    }

    printf("Please enter a number in base %d:\n", a);
    decNum = buildDecimalNum();
    printf("The result is: ");
    if (decNum == 0 || b == 10)
        printf("%ld", decNum);
    else
        decToOtherBase(decNum, b);
    printf("\n");

    return 0;
}

long buildDecimalNum() {
    long sum = 0;
    char digit;

    /* Clear the Input Buffer */
    do {
        digit = getchar();
    } while (digit == '\n');

    do {
        sum = (sum * a) + digitCalc(tolower(digit));
        digit = getchar();
    } while (digit != '\n');
    return sum;
}

void decToOtherBase(long decNum, int base) {
    char digit;

    if (decNum != 0) {
        decToOtherBase(decNum / base, base);

        /* Calculate the digit value in char type */
        if (decNum % base >= 10)
            digit = (decNum % base) - 10 + 'a';
        else
            digit = decNum % base + '0';
        printf("%c", digit);
    }
}

int invalidBase(int base) {
    return (base < MIN_BASE || base > MAX_BASE);
}

int digitCalc(char digit) {
    int decDigit;

    if ('0' <= digit && digit <= '9')
        decDigit = digit - '0';
    else
        decDigit = digit - 'a' + 10;

    /* Out of base's digit range */
    if (decDigit < 0 || decDigit > (a - 1)) {
        printf("Invalid number!\n");
        exit(0); /* Terminate the program */
    }
    return decDigit;
}