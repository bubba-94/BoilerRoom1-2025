#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"
#include "random.h"
#include "User.h"
#include "ThreadPool.h"

int main()
{
    Bank bank;
    ThreadPool threadPool(4);

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
    bank.viewAccount(1);        // displays how much account has in balance

    std::vector<std::pair<int, int>> depositTransactions =
        {
            {1, 100},
            {2, 200},
            {1, 50},
            {2, 300},
        };
    std::vector<std::pair<int, int>> withdrawTransactions =
        {
            {1, 30},
            {2, 100},
            {1, 10},
            {2, 50},
        };
    // put deposit into the pool
    for (const auto &transaction : depositTransactions)
    {
        threadPool.submit([&bank, transaction]()
                          {
            bank.depositToAccount(transaction.first, transaction.second);
            std::cout << "Deposited " << transaction.second << " to account " << transaction.first << "\n"; });
    }
    // put withdraws into the pool
    for (const auto &transaction : withdrawTransactions)
    {
        threadPool.submit([&bank, transaction]()
                          {
            bank.withdrawFromAccount(transaction.first, transaction.second);
            std::cout << "Withdrew " << transaction.second << " from account " << transaction.first << "\n"; });
    }
    // waits for the threads to finish (may want to delete this later)
    std::this_thread::sleep_for(std::chrono::seconds(2));

    bank.viewAccount(1); // displays how much account has in balance

    return 0;
}