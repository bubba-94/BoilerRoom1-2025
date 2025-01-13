#include "Random.h"

int randomBankNumber(){
std::random_device rd;
std::mt19937 gen(rd());

// Comparing random value with key value of BankAccounts map.
std::uniform_int_distribution<> distrib(1, 5);

// Return value
int generatedNumber = distrib(gen);

return generatedNumber;
}

int randomAmount(){
// Another int generator ranged from 50 - 500
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> distrib(50, 500);

int generatedNumber = distrib(gen);

return generatedNumber;
}