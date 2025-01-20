#ifndef BANK_H
#define BANK_H
#include "BankAccount.h"
#include "Client.h"
#include <map>
#include <mutex>
#include <vector>

class BankAccount;
class Client;

class Bank
{
private:
    std::vector<Client> clients;
    std::map<int, BankAccount> BankAccounts;
    std::mutex bank_mtx;
    int nextAccountID = 0;

public:
    Bank();
    ~Bank();

    void makeTransaction(int amount, int map_index);
    void displayBankAccounts(int account);
    void addClient();
    void addBankAccount();
};

#endif