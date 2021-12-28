import re
import hashlib

def add(name, password):
    with open('users.txt', 'a') as f:
       f.write(f'{name}:{password}\n')

def view():
    with open('users.txt', 'r') as f:
        print('-------------------- USERS --------------------')
        lines = f.readlines()

        for line in lines:
            user = re.split(':', line)

            print(f"Username: {user[0]}, Password: {user[1].rstrip()}")
        print('-----------------------------------------------')

def purge():
    with open('users.txt', 'w') as f:
        f.write('') # write an empty string instead of appending, to delete everything

def login():
    name = input("Username: ")
    password = input("Password: ")
    
    hashed_pass = hashlib.sha256(password.encode()).hexdigest()

    with open('users.txt', 'r') as f:
        lines = f.readlines()
        for line in lines:
            user = re.split(':', line)

            if user[0] == name and user[1].rstrip() == hashed_pass:
                print(f"\n\nWelcome {name}!\n\n")
                break
            else:
                print("\n\nInvalid username or password.\n\n")

def main():
    master_pass = input("Enter master password: ") 

    if master_pass != "password":
        print("Incorrect password")
        exit()

    while True:
        print("Please select an option: ")
        print("0) Quit")
        print("1) Add new user ")
        print("2) View all users ")
        print("3) Login to user ")
        print("4) Purge user database ")

        option = int(input("> "))

        if option > 3:
            print("\n\nInvalid option, try again. Use 0 to quit.\n\n")
            continue
        elif option == 0:
            print("Exiting...")
            exit()
        elif option == 1:
            name = input("Username: ")
            password = input("Password: ")

            hashed_pass = hashlib.sha256(password.encode()).hexdigest()

            print(f'Adding user {name}:{hashed_pass}')

            add(name, hashed_pass)
        elif option == 2:
            view()
        elif option == 3:
            login()
        elif option == 4:
            purge()

if __name__ == "__main__":
    main()
