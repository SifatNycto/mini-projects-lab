#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

void showBalance(double balance);
double deposit();
double withdraw(double balance);
void clearScreen();
void pauseScreen();
void callRick();

int main()
{
    double balance = 0.0;
    int choice;
    
    std::cout << std::fixed << std::setprecision(2);

    do
    {
        clearScreen();

        std::cout << "+--------------------+" << std::endl;
        std::cout << "|   WELCOME TO BANK  |" << std::endl;
        std::cout << "+--------------------+" << std::endl;
        std::cout << std::endl;
        std::cout << "+--------------------+" << std::endl;
        std::cout << "|  1. Show Balance   |" << std::endl;
        std::cout << "|  2. Deposit Money  |" << std::endl;
        std::cout << "|  3. Withdraw Money |" << std::endl;
        std::cout << "|  4. Exit           |" << std::endl;
        std::cout << "|  5. Just For Fun   |" << std::endl;
        std::cout << "+--------------------+" << std::endl;

        std::cout << "Enter Your choice: ";
        std::cin >> choice;
        std::cin.clear();
        fflush(stdin);

        switch (choice)
        {
            case 1: showBalance(balance);
                    pauseScreen();
                    break;
            case 2: balance += deposit();
                    showBalance(balance);
                    pauseScreen();
                    break;
            case 3: balance -= withdraw(balance);
                    showBalance(balance);
                    pauseScreen();
                    break;
            case 4: std::cout << std::endl << "Thanks for using this BANK" << std::endl;
                    pauseScreen();
                    break;
            case 5: std::cout << std::endl << "Launching Rick Feature for 10 seconds...";
                    callRick();
                    std::cout << std::endl << "Rick Dancing Ended.\nReturning to main program...\n";
                    pauseScreen();
                    break;
            default: std::cout << std::endl << "Invalid Option Choice !!!";
        }

    } while (choice != 4);
    
}

void showBalance(double balance) {
    std::cout << std::endl << "Your current balance is: $" << balance << std::endl;
}

double deposit() {
    double amount;
    std::cout << std::endl << "How much you wanna deposit: $";
    std::cin >> amount;

    if (amount > 0) return amount;
    else {
        std::cout << std::endl << "Invalid amount.\nEnter valid amount.";
        return 0;
    }
}

double withdraw(double balance) {
    double amount;
    std::cout << std::endl << "How much you wanna withdraw: $";
    std::cin >> amount;

    if (amount > balance)
    {
        std::cout << std::endl << "Insufficient fund to withdraw.";
        return 0;
    }
    else if (amount < 0) {
        std::cout << std::endl << "Invalid withdraw amount !!!\nEnter valid withdraw amount.";
        return 0;
    }
    else return amount;
}

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");

    #else
        system("clear");
    #endif
}


//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void pauseScreen() {
    std::cout << std::endl << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

// void pauseScreen() {
//     #if defined(_WIN32) || defined(_WIN64)
//         system("pause");
//
//     #else
//         system("read -p 'Press Enter to continue...' var");
//     #endif
// }

void callRick() {
    #if defined(_WIN32) || defined(_WIN64)
        system("start cmd /c \"color a && curl ascii.live/rick\"");
        system("timeout /t 10 >nul");
        system("taskkill /IM curl.exe /F >num 2>&1");
        system("cls");

    #else
        system("curl ascii.live/rick & sleep 10; pkill curl; clear");
    #endif
}
