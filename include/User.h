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
    // default constructor
    User() : userID(0), name("") {}
    // requires a ID (int) and a name (string)
    User(int userID) : userID(userID) {}

    int getID();
    std::string getName();

    void addAccount(BankAccount *bankAccount);
    const std::vector<BankAccount *> &getBankAccounts();
};

#endif