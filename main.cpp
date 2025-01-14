#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"
#include "random.h"
#include "User.h"

int main()
{
    Bank bank;
    std::cout << "hello" << std::endl;
    bank.addUser(1, "iko");  // create a user named IKO with UserID 1
    bank.addUser(2, "ikea"); // create a user named ikea with UserID 2

    bank.addBankAccount(1); // creates bankaccount 1 coupled with user 1
    bank.addBankAccount(1); // creates bankasccount 2 coupled with user 1
    bank.addBankAccount(2); // creates bankaccount 3 coupled with user 2

    bank.displayBankAccount(1); // display bank account 1
    bank.displayBankAccount(2); // display bank account 1
    bank.displayBankAccount(3); // display bank account 1
    bank.displayUserID(1);      // display who owns the bank account
    bank.displayUserID(2);      // display who owns the bank account
    bank.displayUserID(3);      // display who owns the bank account

    return 0;
}