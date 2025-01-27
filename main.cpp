// im abit confused what do i actually need for a unit test? Do i need to write anything more then the catch_config_main do test files need a header file?
#include <iostream>
#include <map>
#include "BankAccount.h"
#include "Bank.h"
#include "random.h"
#include "User.h"
#include "ThreadPool.h"
#include "coutMutex.h"

int main()
{
    ThreadPool threadPool(2);
    Bank bank;
    // please refactor the code later so we dont have to make any objects here.
    User user1(1);
    User user2(2);
    User user3(3);
    User user4(4);
    User user5(5);
    User user6(6);
    User user7(7);
    User user8(8);
    User user9(9);
    User user10(10);
    bank.addUser(1, user1);
    bank.addUser(2, user2);
    bank.addUser(3, user3);
    bank.addUser(4, user4);
    bank.addUser(5, user5);
    bank.addUser(6, user6);
    bank.addUser(7, user7);
    bank.addUser(8, user8);
    bank.addUser(9, user9);
    bank.addUser(10, user10);

    // should create 10 bank accounts
    /*for (int i = 0; i < 10; i++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bank.addUser(i, "");
    } */
    // couple 2 users to every bank account
    bank.addBankAccount({1, 2});
    bank.addBankAccount({3, 4});
    bank.addBankAccount({5, 6});
    bank.addBankAccount({7, 8});
    bank.addBankAccount({9, 10});
    /*
    for (int j = 5; j < 5; j++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bank.addBankAccount(j);
    } */
    /*for (int j = 5; j < 5; j++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bank.displayUserID(j);
    } */
    bank.displayUserID(1);
    bank.displayUserID(2);
    bank.displayUserID(3);
    bank.displayUserID(4);
    bank.displayUserID(5);
    for (int j = 5; j < 5; j++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bank.displayBankAccount(j);
    }
    bank.displayBankAccount(1);
    bank.displayBankAccount(2);
    bank.displayBankAccount(3);
    bank.displayBankAccount(4);
    bank.displayBankAccount(5);
    for (int j = 5; j < 5; j++)
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        bank.viewAccountBalance(j);
    }
    bank.viewAccountBalance(1);
    bank.viewAccountBalance(2);
    bank.viewAccountBalance(3);
    bank.viewAccountBalance(4);
    bank.viewAccountBalance(5);
    std::vector<std::pair<int, int>> depositTransactions =
        {
            {1, 300},
            {2, 200},
            {1, 50},
            {2, 300},
            {3, 300},
            {4, 300},
            {5, 300},
        };
    std::vector<std::pair<int, int>> withdrawTransactions =
        {
            {1, 200},
            {2, 100},
            {1, 10},
            {2, 50},
            {3, 50},
            {4, 50},
            {5, 50},
        };
    // bank.transferAmountToBankAccount(2, 1, 300); // may want to add a comment to this
    std::vector<std::tuple<int, int, int>> transferFromAccountToAccount =
        {
            // accountID1, accountID2, amount
            // {2, 1, 300},
        };
    // put deposit into the pool
    for (const auto &transaction : depositTransactions)
    {
        threadPool.submit([&bank, transaction]()
                          {
                              bank.depositToAccount(transaction.first, transaction.second);
                              //  std::cout << "Deposited " << transaction.second << " to account " << transaction.first << "\n";
                          });
    }
    // put withdraws into the pool
    for (const auto &transaction : withdrawTransactions)
    {
        threadPool.submit([&bank, transaction]()
                          {
                              bank.withdrawFromAccount(transaction.first, transaction.second);
                              // std::cout << "Withdrew " << transaction.second << " from account " << transaction.first << "\n";
                          });
    }
    for (const auto &transaction : transferFromAccountToAccount)
    {
        threadPool.submit([&bank, transaction]()
                          {
                              // bank.transferAmountToBankAccount(transaction.first, transaction.second, transaction.third);
                              // bank.transferAmountToBankAccount(std::get<0>(transaction), std::get<1>(transaction), std::get<2>(transaction));
                              // std::cout << "Withdrew " << transaction.second << " from account " << transaction.first << "\n";
                          });
    }
    threadPool.waitForCompletion(); // syncs threadPool with Main by waiting for threads to finish before proceeding

    bank.viewAccountBalance(1);
    bank.viewAccountBalance(2);
    bank.viewAccountBalance(3);
    bank.viewAccountBalance(4);
    bank.viewAccountBalance(5);

    // the threads clearly mess up the std::cout probably due to having a race condition to std::cout, could potentially somehow mutex lock it? Mabye override the original std::cout function?

    return 0;
}