#include <iostream>
#include <string>
#include <map>

class PasswordManager {
private:
    std::map<std::string, std::string> passwords;

public:
    void addPassword(const std::string& account, const std::string& password) {
        passwords[account] = password;
        std::cout << "Password added for account: " << account << std::endl;
    }

    void getPassword(const std::string& account) {
        if (passwords.find(account) != passwords.end()) {
            std::cout << "Password for account " << account << ": " << passwords[account] << std::endl;
        } else {
            std::cout << "Account not found." << std::endl;
        }
    }
};

int main() {
    PasswordManager passwordManager;

    while (true) {
        std::cout << "1. Add Password" << std::endl;
        std::cout << "2. Get Password" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "Select an option: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from the input buffer
        
        switch (choice) {
            case 1: {
                std::string account, password;
                std::cout << "Enter account name: ";
                std::getline(std::cin, account);
                std::cout << "Enter password: ";
                std::getline(std::cin, password);
                passwordManager.addPassword(account, password);
                break;
            }
            case 2: {
                std::string account;
                std::cout << "Enter account name: ";
                std::getline(std::cin, account);
                passwordManager.getPassword(account);
                break;
            }
            case 3:
                std::cout << "Exiting." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    }

    return 0;
}

