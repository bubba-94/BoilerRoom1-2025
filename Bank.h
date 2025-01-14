#ifndef BANK_H
#define BANK_H

class BankAccount;

class Bank
{
private:
    // key, BankAccount
    std::map<int, BankAccount> BankAccounts;

public:
    // Bank(std::map<int, BankAccount> BankAccounts) : BankAccounts(BankAccounts) {}

    void addBankAccount();
    void displayBankAccount(int id);
};

#endif