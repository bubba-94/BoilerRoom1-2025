#include "BankAccount.h"
#include "Bank.h"
#include "Random.h"
#include "Client.h"
#include <thread>
#include <vector>
#include <mutex>

void display(Bank &bank, bool &running){
    while(running == true){
        std::this_thread::sleep_for(std::chrono::seconds(10));
        bank.displayBankAccount(randomMapIndex());
    }
}

void worker(Bank &bank, bool &running){
    while(running == true){
        bank.makeTransaction(randomAmount(), randomMapIndex());
    }
}

int main (){
    bool running{true};
    // Constructor initializes 5 accounts with random account numbers
    // and 10 clients with a random clientID
    Bank bank;

    std::thread displayAccounts(display, std::ref(bank), std::ref(running));

    // Vector of threads.
    std::vector <std::thread> user_threads;

    for(int i = 0; i < 5; i++){
        // pushes 10 threads to user_threads using func calling() with &bank parameter.
        user_threads.push_back(std::thread(worker, std::ref(bank), std::ref(running)));
    }

    std::this_thread::sleep_for(std::chrono::seconds(35));
    running = false;
    // join all existing threads inside user_threads
    for (auto &thread : user_threads){
        thread.join();
    }
    bank.displayBankAccount(randomMapIndex());
    displayAccounts.join();

    return 0;
}