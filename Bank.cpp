#include <iostream>
#include <iomanip>
#include <iterator>
#include <chrono>
#include <thread>
#include "Bank.h"
#include "Random.h"
#include "Client.h"

Bank::Bank(){
    // Constructor creating 5 accounts with random account numbers
    for (int i = 0; i < 5; i++){
        addBankAccount();
    }
    for (int i = 0; i < 10; i ++){
        addClient();
    }
}

// Destructor
Bank::~Bank(){}

//Bank::Bank(std::map<int, BankAccount> BankAccounts) : BankAccounts(BankAccounts) {}

void Bank::addClient(){
    Client newClient;
    //newClient.setPTR();
    newClient.setClientID();
    clients.push_back(newClient);
    std::cout << "\nClient: " <<  newClient.getClientID() << " created.";
}

void Bank::addBankAccount()
{
    // Random amount of money deposited into the account at the start. 
    int amount = randomAmount();
    int id{};
    // Exists so that a new key/id value is always generated for the map whenever inserting a user.
    for (std::map<int, BankAccount>::iterator it = BankAccounts.begin(); it != BankAccounts.end(); ++it)
    {
        // Checks previous IDs and increments last one.
        auto last = std::prev(BankAccounts.end());
        int lastKey = last->first;
        id = lastKey + 1;
    }
    BankAccounts.insert(std::make_pair(id, BankAccount(amount, randomAccountNumber())));
}

void Bank::displayBankAccount(int account)
{
    std::lock_guard<std::mutex> lock(bank_mtx);
    std::cout << "\n----------------------CURRENT BALANCE----------------------";
    for (auto& pair : BankAccounts){
    
        std::cout << "\nAccount " << pair.second.getAccountID() << std::setw(18) << "|" <<
        std::setw(23) <<  "Balance: " << pair.second.getBalance() << "kr."; 
    }
    std::cout << "\n-----------------------------------------------------------";

    /*
        // Lock for displaying the accountnumber and balance.
        std::lock_guard<std::mutex> lock(bank_mtx);

        // Compares ID with existing accounts (key of map) and prints if found.
        auto it = BankAccounts.find(account);
        if (it != BankAccounts.end()){
            std::cout << "Account: " << it->second.getAccountID() << " Balance: " << it->second.getBalance() <<" kr" <<  std::endl; 
        }
        else if (it == BankAccounts.end()){
            std::cout << "Account: " << account << " does not exist.\n";
        } 
    */
}

void Bank::makeTransaction(int amount, int map_index){
    int client_index = randomClientIndexInVector();
    int decision = withdrawOrDeposit();

    std::map<int, BankAccount>::iterator it = BankAccounts.find(map_index);
    if (it != BankAccounts.end()){
        {
            // Withdraw
            if (decision == 1); {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                {
                    std::lock_guard<std::mutex> lock(bank_mtx);
                    std::cout << "\nClient " << clients[client_index].getClientID() << ": withdrew "<< amount << "kr from account: " << it->second.getAccountID(); 
                    //std::cout << "|\tPrevious balance: " << it -> second.getBalance() << "kr.";
                    it->second.withdraw(amount);
                }
                //std::cout << "|\tNew balance: " << it->second.getBalance() << "kr.";
            }
            // Deposit
            if (decision == 0){
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                {
                    std::lock_guard<std::mutex> lock(bank_mtx);
                    std::cout << "\nClient " << clients[client_index].getClientID() << ": deposited "<< amount << "kr to account: " << it->second.getAccountID();
                    it->second.deposit(amount);
                }
                //std::cout << "|\tPrevious balance: " << it -> second.getBalance() << "kr.";
                //std::cout << "|\tNew balance: " << it->second.getBalance() << "kr.";
            }
        }
    } 
}
/*
    for (std::map<int, BankAccount>::iterator it = BankAccounts.begin(); it != BankAccounts.end(); ++it)
    {
        int key = it->first;
        if (key == id)
        {
            std::cout << BankAccounts[key].getBalance();
        }
    }
*/
