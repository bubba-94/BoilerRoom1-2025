# BoilerRoom1-2025: Multithreaded Banking System

# Project Overview
BoilerRoom1-2025 is a multithreaded banking system designed to simulate multiple customers performing various banking transactions (deposits, withdrawals, and balance checks) concurrently. Using multithreading and synchronization techniques.

# Table of Contents

    1.Features
    2. System Requirements
    3. Installation
    4. Usage
    5. Project Structure
    6. Code Example
    7. Future Enhancements
    8. License

# Features

* Multithreading: Simulate concurrent customers performing transactions such as (deposit, withdrwals) within bank accounts
* Account Management: Support banking operations such as deposit, whtdrwaing and balance checking functions
* Synchronization: Ensure that the system is in a threas safe enviroment maintaing account integrity
* Balance Tracking: Display account balances after transaction are completed

# System Requirements
C++ c17 compiler support (g++)
Operating system such as Windows, Linux, macOS

# Installation
Git clone https://github.com/bubba-94/BoilerRoom1-2025.git

Navigate to the directory it was installed and open main.cpp

Run the program through main.cpp using the non test version.

# Usage
Once the program has started it will print out different instructions that the program has been doing where this can be adjusted within int main. 
Right now its currently running 5 accounts with 10 users.

# Project Structure
├── main.cpp              # Main entry point of the program
├── BankAccount.h         # Definition of BankAccount class (deposit, withdraw, getBalance)
├── Bank.h                # Definition of Bank class (manage accounts and bankaccount)
├── User.h                # User ID and Name
├── ThreadPool.h          # Handles thread logic ensuring concurrency
├── README.md             # Documentation for the project


# code example


# future Enchantments
* Allows users to authorize with a username and password
* Expand the logging systems
* refactor Main.cpp
* Remove the concept of User Objects
* Incorporate rollback mechanicsms in case of error during transactions.
* User interface for users to interact with the system

# License
Under the MIT license
