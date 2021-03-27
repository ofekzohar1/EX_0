#include <stdio.h>
#include <assert.h>
/* Define Constants */
#define MAX_BASE 16
#define MIN_BASE 2

int a, b; /* Store the input base and desired base */
int buildDecimalNum(); /* Convert number (user input) in a given base to decimal base */
int invalidBase(int base); /* Function checks whether the base is in range */
int digitCalc(char digit); /* Calculates the numeric value of the char digit */
void decToOtherBase(int decNum, int base); /* Calculates and print a given number in a desired base using recursion */

int main() {
    int decNum;

    printf("Please enter the numbers base:");
    scanf("%d", &a);
    if (invalidBase(a)) {
        printf("Invalid input base");
        return 0;
    }

    printf("Please enter the desired base:");
    scanf("%d", &b);
    if (invalidBase(b)) {
        printf("Invalid desired base");
        return 0;
    }

    printf("Please enter a number in base %d:", a);
    decNum = buildDecimalNum();
    printf("The result is: ");
    decToOtherBase(decNum, b);

    return 0;
}

int buildDecimalNum() {
    int sum;
    char digit;

    getchar(); /* Clear the Input Buffer */
    digit = getchar();
    while (digit != '\n') {
        sum = (sum * a) + digitCalc(digit);
        digit = getchar();
    }
    return sum;
}

void decToOtherBase(int decNum, int base) {
    char digit;

    if (decNum != 0) {
        decToOtherBase(decNum / base, base);

        /* Calculate the digit value in char type */
        if(decNum % base >= 10)
            digit = (decNum % base) - 10 +'a';
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
        printf("Invalid number!");
        exit(0); /* Terminate the program */
    }
    return decDigit;
}