#ifndef CLIENT_H
#define CLIENT_H
#include "Bank.h"
#include "Random.h"
#include <thread>
#include <vector>

class BankAccount;

class Client{
private:
    int clientID{};
    // std::unique_ptr<BankAccount> ptr;
public:
    Client();
    ~Client();
    void setClientID();
    int getClientID();
    void setPTR();
};
#endif