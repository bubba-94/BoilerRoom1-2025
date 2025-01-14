#ifndef USER_H
#define USER_H

// sorry :(
#include <string>
#include <vector>

class BankAccount;

class User
{
private:
    int userID;
    std::string name;
    std::vector<BankAccount *> ownedBankAccounts; // if we want to give one user multiple bank accounts (May need to be reworked) // could use a vector instead?

public:
    User(int userID, std::string name) : userID(userID), name(name) {}

    int getID();
    std::string getName();

    void addAccount(BankAccount *bankAccount);
    std::vector<BankAccount *> &getBankAccounts();
};

#endif