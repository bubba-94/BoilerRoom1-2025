#ifndef RANDOM_H
#define RANDOM_H
#include <random>

//RANDOMSSSSSSS


// Randomize an integer for comparing the key value of BankAccounts map.
int randomMapIndex();

// Randomize an amount (kr) from 50-500
int randomAmount();

// Randomize a 3 digit account number between 100 - 999
int randomAccountNumber();

// Randomize a 5 digit accountID.
int randomClientID();

// Random client index from 0 - 9
int randomClientIndexInVector();

// Random 0 or 1
int withdrawOrDeposit();
#endif
