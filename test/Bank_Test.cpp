#include "catch.hpp"
#include "Bank.h"
#include "BankAccount.h"
#include "User.h"
#include "random.h"

class BankTest
{
protected:
    Bank bank;

    BankTest()
    {
        bank.addUser(1, "ilo");
        bank.addUser(2, "lio");

        bank.addBankAccount(1);
        bank.addBankAccount(2);
    }
};

TEST_CASE_METHOD(BankTest, "Test adding users", "[Bank]")
{
    REQUIRE_NOTHROW(bank.displayUserID(1));
    REQUIRE_NOTHROW(bank.displayUserID(2));
}

TEST_CASE_METHOD(BankTest, "Test bank account creation", "[Bank]")
{
    bank.displayBankAccount(1);
    bank.displayBankAccount(2);
}

TEST_CASE_METHOD(BankTest, "Test deposit functionality", "[Bank]")
{
    bank.depositToAccount(1, 1000);
    bank.viewAccountBalance(1);

    BankAccount account1 = bank.getBankAccount(1);
    REQUIRE(account1.getBalance() == 1000);
}

// make sure that the system refuses withdrawing more then exists within a bank account
TEST_CASE_METHOD(BankTest, "Test withdrawl larger than balance", "[Bank]")
{
    bank.depositToAccount(1, 500);
    bank.withdrawFromAccount(1, 1000);

    BankAccount account1 = bank.getBankAccount(1);
    REQUIRE(account1.getBalance() == 500);
}

TEST_CASE_METHOD(BankTest, "test view account balance", "[Bank]")
{
    bank.depositToAccount(1, 500);
    bank.viewAccountBalance(1);

    BankAccount account1 = bank.getBankAccount(1);
    REQUIRE(account1.getBalance() == 500);
}