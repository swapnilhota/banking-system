#include <iostream>

using namespace std;

class Account
{
private:
    long accountNumber;
    string firstName;
    string lastName;
    float balance;
    static long NextAccountNumber;

public:
    Account() {}
    Account(string fname, string lname, float balance);
    long getAccNo() { return accountNumber; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    float getBalance() { return balance; }

    void Deposit(float amount);
    void WithDraw(float amount);
    static void setLastAccountNumber(long accountNumber);
    static long getLastAccountNumber();
    friend ofstream &operator<<(ofstream &ofs, Account &acc);
    friend ifstream &operator>>(ifstream &ifs, Account &acc);
    friend ostream &operator<<(ostream &os, Account &acc);
};

class Bank
{
private:
    map<long, Account> accounts;

public:
    Bank();
    Account OpenAccount(string fname, string lname, float balance);
    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);
    void CloseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
};

int main()
{
    Bank b;
    Account acc;

    int choice;
    string fname, lname;
    long accountNumber;
    float balance;
    float amount;
    cout << "******Banking System******" << endl;

    do
    {
        cout << "\n\t Select one option";
        cout << "\n\t 1. Open an Account";
        cout << "\n\t 2. Balance Enquiry";
        cout << "\n\t 3. Deposit";
        cout << "\n\t 4. Withdrawal";
        cout << "\n\t 5. Close an Account";
        cout << "\n\t 6. Show All Accounts";
        cout << "\n\t 7. Quit";
        cout << "\n\n\t Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter First Name: ";
            cin >> fname;
            cout << "Enter Last Name: ";
            cin >> lname;
            cout << "Enter Initial Balance: ";
            cin >> balance;
            acc = b.OpenAccount(fname, lname, balance);
            cout << "\nCongratulations Account has been created\n";
            cout << acc;
            break;
        case 2:
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            acc = b.BalanceEnquiry(accountNumber);
            cout << "\nYour Account Details\n";
            cout << acc;
            break;
        case 3:
            cout << "Enter Account Number: ";
            cin >> accountNumber;
            cout << "Enter Balance: ";
            cin >> amount;
            acc = b.Deposit(accountNumber, amount);
            cout << "\nAmount is Deposited\n";
            cout << acc;
        }
    } while ();

    return 0;
}