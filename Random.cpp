#include "Random.h"

int randomMapIndex(){
    std::random_device rd;
    std::mt19937 gen(rd());

    // Comparing random value with key value of BankAccounts map.
    std::uniform_int_distribution<> distrib(0, 4);

    // Return value
    int generatedMapIndex = distrib(gen);

    return generatedMapIndex;
}

int randomAmount(){
    // Another int generator ranged from 50 - 500
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(50, 500);

    int generatedAmount = distrib(gen);

    return generatedAmount;
}

int randomAccountNumber(){
    std::random_device rd;
    std::mt19937 gen(rd());

    // Generates a random account number within frame 100 - 999
    std::uniform_int_distribution<> distrib(100, 999);
    // Return value
    int generatedAccountNumber = distrib(gen);

    return generatedAccountNumber;
}

int randomClientID(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1000, 1337);

    int generatedClientID = distrib(gen);

    return generatedClientID;
}

int randomClientIndexInVector(){
    // Another int generator ranged from 0 - 9
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 9);

    int generatedAmount = distrib(gen);

    return generatedAmount;
}

int withdrawOrDeposit(){
    // Another int generator ranged from 0 - 9
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 1);

    int generatedAmount = distrib(gen);

    return generatedAmount;
}