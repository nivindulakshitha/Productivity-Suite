#include <stdio.h>
#include <stdbool.h>
#define accountHolderSystem "Mr. Bandara N.M.N.L.N"

//System Variables
float accountBalanceSystem = 100000.00;
bool accountVerified = false;
//System Constants
const int accountNumberSystem = 12345678;
const int accountPinSystem = 1234;

//User Inputs
int atmServiceCode;
int accountNumberInput_01;
int accountNumberInput_02;
int accountPinInput_01;
int accountPinInput_02;
float depositAmount;
float withdrawAmount;

//Function Declarations
bool accountAuthentication (bool withAcc, bool withPin);
void depositFunction ();
void withdrawFunction ();
void accountSummery ();

void depositFunction () {
    bool auth = accountAuthentication (true, false);
    if (!auth) {
        return;
    }

    printf("\nAmount to deposit: Rs.");
    scanf("%f", &depositAmount);

    if (depositAmount < 100 || depositAmount > 1000000) {
        printf("Unsupported amount. Amount should be between Rs.100 - Rs.1,000,000\n");
    } else {
        accountBalanceSystem += depositAmount;
        printf("Transaction successfull.\n");
    }
}

void withdrawFunction () {
    bool auth = accountAuthentication (true, true);
    if (!auth) {
        return;
    }

    printf("\nAmount to withdraw: Rs.");
    scanf("%f", &withdrawAmount);

    if (withdrawAmount < 1 || withdrawAmount > accountBalanceSystem) {
        printf("Unsupported amount.\n");
    } else {
        accountBalanceSystem -= withdrawAmount;
        printf("Transaction successfull.\n");
    }
}

void accountSummery () {
    bool auth = accountAuthentication (true, true);
    if (!auth) {
        return;
    }
    printf("\n\n------------- Account Summery -------------\n");
    printf("Account Number\t-\t%d\n", accountNumberSystem);
    printf("Account Name\t-\t%s\n", accountHolderSystem);
    printf("Account Balance\t-\tRs.%.2f\n", accountBalanceSystem);
    printf("------------- End of Summery -------------\n\n");
}

bool accountAuthentication (bool withAcc, bool withPIN) {
    if (!withPIN && withAcc) {
        if (accountVerified) {
            return true;
        }
    }

    if (withAcc && !accountVerified) {
        printf("\n\tAccount number:\t");
        scanf("%d", &accountNumberInput_01);

        printf("\tAccount number:\t");
        scanf("%d", &accountNumberInput_02);

        if (accountNumberInput_01 == accountNumberInput_02 && accountNumberInput_01 == accountNumberSystem) {
            int userConfirm;
            printf("\tConfirm account holder as %s (0-Yes 1-No)? ", accountHolderSystem);
            scanf("%d", &userConfirm);
            if (!userConfirm) {
                accountVerified = true;
                if (!withPIN) {
                    return true;
                }
            } else {
                printf("\n\tAccount authentication failed!\n");
                return false;
            }
        } else {
            printf("\n\tAccount authentication failed!\n");
            return false;
        }
    }
    
    if (withPIN) {
        printf("\n\tAccount PIN:\t");
        scanf("%d", &accountPinInput_01);

        printf("\tAccount PIN:\t");
        scanf("%d", &accountPinInput_02);

        if (accountPinInput_01 == accountPinInput_02 && accountPinInput_01 == accountPinSystem) {
            return true;
        } else {
            printf("\n\tAccount authentication failed!\n");
            return false;
        }
    }
}

void main() {
    printf("\n\nWelcome to UniBank ATM service!\n");
    printf("-------------------------------\n");
 
    do {
        printf("\n0. Exit\t\t1. Deposit\t2. Withdraw\t3. Summery\n");
        printf("Function code: ");
        scanf("%d", &atmServiceCode);

        if (atmServiceCode == 1) {
            depositFunction();
        } else if (atmServiceCode == 2) {
            withdrawFunction();
        } else if (atmServiceCode == 3) {
            accountSummery();
        }
    } while (atmServiceCode);

    printf("\n\n------------------------------------\n");
    printf("Thank you for using UniBank ATM service.\n\n");
}