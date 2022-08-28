#include <iostream>
#include <list>

bool validate_balance(int balance)
{
    return balance > 0;
}

int main()
{
    std::list<std::string> bank_acc_name;
    std::list<int> bank_balance;
    int choice;

    do
    {
        std::cout << "Welcome to Mosh Bank" << std::endl;
        std::cout << " Press 1 to open a bank account\n Press 2 to close a bank account\n Press 3 to list all bank accounts with their balances\n Press 4 to deposit money in a bank account\n Press 5 to withdraw money from a bank account" << std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            std::cout << "Hello, please enter your name" << std::endl;
            std::string name;
            std::cin >> name;
            bank_acc_name.push_back(name);
            std::cout << "Enter initial deposit" << std::endl;
            int balance;
            std::cin >> balance;
            while (!validate_balance(balance))
            {
                std::cout << "Balance cannot be negative. Re-enter initial deposit" << std::endl;
                std::cin >> balance;
            }
            bank_balance.push_back(balance);
            std::cout << "Congratulations! Your account has been created\nYour account number is " << bank_acc_name.size() << std::endl;
            break;
        }
        case 3:
            for (int i = 0; i < bank_acc_name.size(); i++)
            {
                auto it_name = bank_acc_name.begin();
                auto it_balance = bank_balance.begin();
                std::advance(it_name, i);
                std::advance(it_balance, i);
                std::cout << *it_name << " " << *it_balance << std::endl;
            }
            break;
        default:
            std::cout << "Non-valid input" << std::endl;
            break;
        }
        std::cout << "Do you want to continue? Enter 1 for yes or 0 for no" << std::endl;
        std::cin >> choice;
    } while (choice);
}