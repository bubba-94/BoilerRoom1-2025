
#include "BankAccount.h"

//BankAccount::BankAccount(){}

void BankAccount::deposit(int amount){
    this->balance += amount;
}

void BankAccount::withdraw(int amount){
    if (amount > balance){
        balance = balance;
        std::cerr << "\t error: failed because there were insufficient funds "; 
    }
    else if (amount < balance){
        this->balance -= amount;
    }
}

int BankAccount::getBalance(){
    return balance;
}

int BankAccount::getAccountID(){
    return accountId;
}
