#include <iostream>
#include <string>
using namespace std;

// Base class
class Account
{
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    Account(int accNo, string name, double bal)
    {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        }
        else
        {
            cout << "Invalid amount.\n";
        }
    }

    // Virtual withdrawal function
    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        }
        else
        {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    // Virtual interest calculation
    virtual void calculateInterest()
    {
        cout << "Interest calculation is not defined for base Account.\n";
    }

    // Display account details
    virtual void display()
    {
        cout << "\n-----------------------------";
        cout << "\nAccount Number : " << accountNumber;
        cout << "\nHolder Name    : " << holderName;
        cout << "\nBalance        : Rs. " << balance;
        cout << "\n-----------------------------\n";
    }

    // Virtual destructor
    virtual ~Account() {}
};


// Savings Account
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal)
    {
        interestRate = 4.0;
    }

    // Calculate savings interest
    void calculateInterest() override
    {
        double interest = balance * interestRate / 100;
        balance += interest;

        cout << "Savings Account Interest: Rs. "
             << interest << endl;
    }

    // Display savings account
    void display() override
    {
        cout << "\n===== SAVINGS ACCOUNT =====";
        Account::display();
        cout << "Interest Rate  : " << interestRate << "%\n";
    }
};


// Current Account
class CurrentAccount : public Account
{
private:
    double interestRate;

public:
    CurrentAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal)
    {
        interestRate = 2.0;
    }

    // Current account withdrawal
    void withdraw(double amount) override
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawal successful from Current Account.\n";
        }
        else
        {
            cout << "Withdrawal failed.\n";
        }
    }

    // Calculate current account interest
    void calculateInterest() override
    {
        double interest = balance * interestRate / 100;
        balance += interest;

        cout << "Current Account Interest: Rs. "
             << interest << endl;
    }

    // Display current account
    void display() override
    {
        cout << "\n===== CURRENT ACCOUNT =====";
        Account::display();
        cout << "Interest Rate  : " << interestRate << "%\n";
    }
};


// Fixed Deposit Account
class FixedDepositAccount : public Account
{
private:
    double interestRate;
    int duration;

public:
    FixedDepositAccount(int accNo, string name,
                        double bal, int years)
        : Account(accNo, name, bal)
    {
        interestRate = 7.0;
        duration = years;
    }

    // FD withdrawal
    void withdraw(double amount) override
    {
        cout << "Withdrawal is not allowed before FD maturity.\n";
    }

    // Calculate FD interest
    void calculateInterest() override
    {
        double interest =
            balance * interestRate * duration / 100;

        balance += interest;

        cout << "Fixed Deposit Interest: Rs. "
             << interest << endl;
    }

    // Display FD
    void display() override
    {
        cout << "\n===== FIXED DEPOSIT ACCOUNT =====";
        Account::display();
        cout << "Interest Rate  : " << interestRate << "%";
        cout << "\nDuration       : " << duration << " years\n";
    }
};


// Main function
int main()
{
    // Creating objects
    SavingsAccount savings(
        101,
        "Rahul",
        50000
    );

    CurrentAccount current(
        102,
        "Amit",
        75000
    );

    FixedDepositAccount fixedDeposit(
        103,
        "Priya",
        100000,
        3
    );

    int choice;
    double amount;

    do
    {
        cout << "\n\n====================================";
        cout << "\n       BANKING SYSTEM";
        cout << "\n====================================";

        cout << "\n1. Display Savings Account";
        cout << "\n2. Display Current Account";
        cout << "\n3. Display Fixed Deposit Account";

        cout << "\n4. Deposit in Savings Account";
        cout << "\n5. Withdraw from Savings Account";

        cout << "\n6. Deposit in Current Account";
        cout << "\n7. Withdraw from Current Account";

        cout << "\n8. Deposit in Fixed Deposit";
        cout << "\n9. Withdraw from Fixed Deposit";

        cout << "\n10. Calculate Savings Interest";
        cout << "\n11. Calculate Current Interest";
        cout << "\n12. Calculate FD Interest";

        cout << "\n13. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            savings.display();
            break;

        case 2:
            current.display();
            break;

        case 3:
            fixedDeposit.display();
            break;

        case 4:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            savings.deposit(amount);
            break;

        case 5:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            savings.withdraw(amount);
            break;

        case 6:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            current.deposit(amount);
            break;

        case 7:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            current.withdraw(amount);
            break;

        case 8:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            fixedDeposit.deposit(amount);
            break;

        case 9:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            fixedDeposit.withdraw(amount);
            break;

        case 10:
            savings.calculateInterest();
            break;

        case 11:
            current.calculateInterest();
            break;

        case 12:
            fixedDeposit.calculateInterest();
            break;

        case 13:
            cout << "\nThank you for using Banking System!";
            break;

        default:
            cout << "\nInvalid choice!";
        }

    } while (choice != 13);

    return 0;
}
