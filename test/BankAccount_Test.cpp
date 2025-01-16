#define CATCH_CONFIG_MAIN // how does it connect to bankaccount_test.cpp???? I dont get it, where would it even establish the link itself?, how do i get the main to compile and the test together? how can i exclude tests and only run them when i want them to run
#include "catch.hpp"
#include "BankAccount.h"

class BankAccountTest
{
protected:
    BankAccount account;
    BankAccountTest() : account(1000, 1, 1) {}
};

// makes sure that deposit becomes 1500 with the inputs 1000, 500
TEST_CASE("Deposit increases balance", "[BankAccount]")
{
    BankAccount account(1000, 1, 1);
    account.deposit(500);
    REQUIRE(account.getBalance() == 1500);
}

// test that withdraw becomes 700 with inputs 1000-300
TEST_CASE("Withdraw Decreases balance", "[BankAccount]")
{
    BankAccount account(1000, 1, 1);
    account.withdraw(300);
    REQUIRE(account.getBalance() == 700);
}
// test what happens if withdraw is higher then balanace
// TEST FAILED
TEST_CASE("withdraw more than Balance", "[BankAccount]")
{
    BankAccount account(1000, 1, 1);
    account.withdraw(1500);
    REQUIRE(account.getBalance() == 1000);
}

// check that user ID is correct for the account
TEST_CASE("User ID is correct", "[BankAccount]")
{
    BankAccount account(1000, 1, 1);
    REQUIRE(account.getUserID() == 1);
}