# BoilerRoom1-2025
First school group assignment of 2025, a multithreaded bankingsystem.

The goal of the project is to simulate a basic banking system that handles multiple customers performing transactions (deposits, withdrawals, balance checks) simultaneously. The system must use multithreading to simulate concurrent customers and synchronization techniques to ensure the integrity of shared resources (e.g., account balances).

Session 1: Bygga grunden (Vecka 1)
Mål:
Implementera ett grundläggande banksystem med kontohantering med hjälp av trådar för att hantera flera kunder som utför transaktioner
samtidigt.
Instruktioner för Session 1:
Uppgift: Skapa ett banksystem med flertådiga kunder
1. Skapa en BankAccount-klass
Attribut: balance (int), accountNumber (int)
Metoder:
deposit(int amount)
withdraw(int amount)
getBalance()
2. Skapa en Bank-klass
Hantera flera konton i en std::map<int, BankAccount> .
Implementera metoder för att lägga till konton och hämta kontouppgifter.
3. Simulera kunder med hjälp av trådar
Skapa en funktion Client som simulerar en kund som utför transaktioner på ett slumpmässigt konto.
Använd std::thread för att skapa flera kunder som körs samtidigt.
4. Krav:
Implementera minst 5 konton och 10 kunder som körs parallellt.
Varje kund ska utföra slumpmässiga transaktioner (insättningar eller uttag).
Skriv ut kontosaldon efter att alla kunder har slutfört sina transaktioner.
