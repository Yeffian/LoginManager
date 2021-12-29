#include <iostream>
#include <string>
#include <fstream>

#define ENDL '\n'

void AddNewUser() {
    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::ofstream file;
    file.open("./users.txt", std::ios_base::app);

    int32_t size = username.size() + password.size() + 2;
    const char* buffer = (username + "|" + password + ENDL).c_str();

    file.write(buffer, size);

    file.close();
}

void ViewAllUsers() {
    std::ifstream file;
    file.open("./users.txt");

    std::string line;
    
    while (std::getline(file, line)) {
        std::cout << line << ENDL;
    }

    file.close();
}

void DeleteUserDatabase() {
    std::ofstream file;
    file.open("./users.txt");

    file << '\0';

    file.close();
}

void LoginToUser() {
    std::string username;
    std::string password;

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    std::ifstream file;
    file.open("./users.txt");

    std::string line;
    while (std::getline(file, line)) {
        if (line.find(username + "|" + password) != std::string::npos) {
            std::cout << "Welcome, " << username << ENDL;
            return;
        }
    }

    std::cout << "Login Failed!" << ENDL;
}

int main() {
    std::string master;

    std::cout << "Please enter your master password: ";
    std::cin >> master;

    if (master != "password") {
        return 1; 
    } else {
        while (true) {
            int32_t choice;

            std::cout << "Please select an option: " << ENDL;
            std::cout << "0) Quit" << ENDL;
            std::cout << "1) Add new user " << ENDL;
            std::cout << "2) View all users " << ENDL;
            std::cout << "3) Login to user " << ENDL;
            std::cout << "4) Purge user database " << ENDL;   
            std::cout << "> ";
            std::cin >> choice;

            switch (choice) {
                case 0:
                    std::cout << "Exiting.." << ENDL;
                    return 0;
                case 1:
                    AddNewUser();
                    continue;
                case 2:
                    ViewAllUsers();
                    continue;
                case 3:
                    LoginToUser();
                    continue;
                case 4:
                    DeleteUserDatabase();
                    continue;
            }
        } 
    }
}
