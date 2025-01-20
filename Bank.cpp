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
    // Next account id starts at 0
    BankAccounts.insert(std::make_pair(nextAccountID++, BankAccount(amount, randomAccountNumber())));
}

void Bank::displayBankAccounts(int account)
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

    std::lock_guard<std::mutex>lock(bank_mtx);
    std::map<int, BankAccount>::iterator it = BankAccounts.find(map_index);

    if (it != BankAccounts.end()){
        {
            std::cout << "\nThread (" << std::this_thread::get_id() << ") | ";
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            // Withdraw
            if (decision == 1) { 

                    std::cout << "Client " << clients[client_index].getClientID() << ": withdrew " << 
                    amount << "kr | From account: " << it->second.getAccountID(); 

                    it->second.withdraw(amount);        
            }
            // Deposit
            else if (decision == 0) {

                    std::cout << "Client " << clients[client_index].getClientID() << ": deposited " << 
                    amount << "kr | To account: " << it->second.getAccountID();

                    it->second.deposit(amount);            
            }
        }
    } 
}