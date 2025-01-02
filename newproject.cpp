#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int accountnumber = 0;
string name;
string newname;
string newnumber;
string newemail;
int storedaccountnumber = 0;
string number;
string cnic;
string email;
double interestrate;
int initialdeposit = 0;
double depositamount = 0;
int withdrawamount = 0;
double interesetamount = 0;
double finalamount = 0;
char option;
char choice2;
char choice;

void menu() /*1st Function*/
{

    cout << "-----------------------------------------" << endl;
    cout << "C++ Bank" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Please select an option:" << endl;
    cout << "1. Create an Account" << endl;
    cout << "2. Deposit Money" << endl;
    cout << "3. Withdraw Money" << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Calculating Interest" << endl;
    cout << "6. Check Information" << endl;
    cout << "7. Change Information" << endl;
    cout << "8. Exit" << endl;

    cout << "-----------------------------------------" << endl;
    cout << " " << endl;
    cin >> choice;
    cout << " " << endl;
}

int generateaccountnumber() /*2nd Function*/
{
    srand(time(0));
    return 1 + rand() % 5000;
}

void creatacc() /*3rd Function*/
{
    cin.ignore();
    cout << "Please enter your name: ", getline(cin, name);
    do
    {
        cout << "Enter number: +92", cin >> number;
        if (number.length() != 10)
        {
            cout << "Error: Number must be of 10 digits. Please try again." << endl;
        }
    } while (number.length() != 10);
    cin.ignore();

    do
    {
        cout << "Enter Cnic: ", cin >> cnic;
        if (cnic.length() != 13)
        {
            cout << "Error: Number must be of 13 digits. Please try again." << endl;
        }
    } while (cnic.length() != 13);
    cin.ignore();
    do
    {
        cout << "Enter Email: ";
        getline(cin, email);

        // Check if the email contains '@'
        if (email.find('@') == string::npos)
        {
            cout << "Error: Email must contain '@'. Please try again." << endl;
        }
    } while (email.find('@') == string::npos);
    cout << "Enter initial deposit amount: ", cin >> initialdeposit;
    if (initialdeposit < 0)
    {
        cout << "Invalid Input!" << endl;
        cout << " " << endl;
        return;
    }
    finalamount = initialdeposit;
    storedaccountnumber = generateaccountnumber();
    cout << " " << endl;
    cout << "Account created successfully!" << endl;
    cout << "Account Number: " << storedaccountnumber << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << "$" << finalamount << endl;
    cout << " " << endl;
}

void deposit() /*4rth Function*/
{

    cout << "Enter Account Number: ", cin >> accountnumber;
    if (accountnumber == storedaccountnumber)
    {
        cout << "Enter deposit amount: ", cin >> depositamount;

        if (depositamount < 0)
        {
            cout << "Invalid Input!" << endl;
            cout << " " << endl;
            return;
        }
        cout << " " << endl;
        cout << "Deposit successful!" << endl;
        finalamount += depositamount;
        cout << "Updated Balance: " << "$" << finalamount << endl;
        cout << " " << endl;
    }
    else
    {
        cout << "Incorrect Account Number! " << endl;
        cout << " " << endl;
        return;
    }
}

void withdraw() /*5th Function*/
{

    cout << "Enter Account Number: ", cin >> accountnumber;
    if (accountnumber == storedaccountnumber)
    {
        cout << "Enter withdrawal amount: ", cin >> withdrawamount;
        if (withdrawamount < 0)
        {
            cout << "Invalid Input!" << endl;
            cout << " " << endl;
            return;
        }
        if (withdrawamount > finalamount)
        {
            cout << "Insufficient Balance! Can't withdraw money." << endl;
            cout << " " << endl;
            return;
        }
        cout << " " << endl;
        cout << "Withdrawal successful!" << endl;
        finalamount -= withdrawamount;
        cout << "Updated Balance: " << "$" << finalamount << endl;
        cout << " " << endl;
    }
    else
    {
        cout << "Incorrect Account Number! " << endl;
        cout << " " << endl;
        return;
    }
}

void balance() /*6th Function*/
{
    cout << "Enter Account Number: ", cin >> accountnumber;
    cout << " " << endl;
    if (accountnumber == storedaccountnumber)
    {
        cout << "Account Balance for " << name << ":" << endl;
        cout << "Balance: " << "$" << finalamount << endl;
        cout << " " << endl;
        return;
    }
    else
    {
        cout << "Incorrect Account Number! " << endl;
        cout << " " << endl;
        return;
    }
}

void interest() /*7th Function*/
{
    cout << "Enter Account Number: ", cin >> accountnumber;
    if (accountnumber == storedaccountnumber)
    {
        cout << "Enter interest rate (%): ", cin >> interestrate;
        if (interestrate < 0)
        {
            cout << "Error Occured!" << endl;
            cout << " " << endl;
            return;
        }
        cout << " " << endl;
        interesetamount = finalamount * (interestrate / 100);
        cout << "Calculated interest on balance: " << interesetamount << endl;
        finalamount += interesetamount;
        cout << "Your balance with interest is: " << finalamount << endl;
        cout << " " << endl;
    }
    else
    {
        cout << "Incorrect Account Number! " << endl;
        cout << " " << endl;
        return;
    }
}

void checkinfo() /*8th Function*/
{

    cout << "Enter Account Number: ", cin >> accountnumber;
    cout << " " << endl;
    if (accountnumber == storedaccountnumber)
    {
        cout << "Name: " << name << endl;
        cout << "Phone Number: +92" << number << endl;
        cout << "Cnic: " << cnic << endl;
        cout << "Email: " << email << endl;
        cout << " " << endl;
    }
    else
    {
        cout << "Incorrect Account Number!" << endl;
        cout << " " << endl;
        return;
    }
}
void changeinfo() /*9th Function*/
{
    cout << "Enter Account Number: ", cin >> accountnumber;
    cout << " " << endl;
    if (accountnumber == storedaccountnumber)
    {

        cout << "Which information do you want to change: " << endl;
        cout << "1. Name" << endl;
        cout << "2. Number" << endl;
        cout << "3. Email" << endl;
        cout << " " << endl;
        cout << ">";
        cin >> choice2;
        switch (choice2)
        {
        case '1':
            cin.ignore();
            cout << "Enter New Name: ";
            getline(cin, newname);
            name = newname;
            cout << "Your new name is: " << name << endl;
            cout << " " << endl;
            break;

        case '2':
            cin.ignore();
            do
            {
                cout << "Enter new number: +92", cin >> newnumber;
                if (newnumber.length() != 10)
                {
                    cout << "Error: Number must be of 10 digits. Please try again." << endl;
                }
            } while (newnumber.length() != 10);

            number = newnumber;
            cout << "Your new number is: 0" << number << endl;
            cout << " " << endl;
            break;

        case '3':
            cin.ignore();
            do
            {
                cout << "Enter Email: ";
                getline(cin, email);

                // Check if the email contains '@'
                if (email.find('@') == string::npos)
                {
                    cout << "Error: Email must contain '@'. Please try again." << endl;
                }
            } while (email.find('@') == string::npos);
            email = newemail;
            cout << "Your new email is: " << email << endl;
            cout << " " << endl;
            break;
        default:
            cout << "Invalid Input!" << endl;
            cout << " " << endl;
            break;
        }
    }
    else
    {
        cout << "Incorrect Account Number!" << endl;
        cout << " " << endl;
        return;
    }
}
void exit() /*10th Function*/
{
    cout << "Thank you for using the Bank System. Goodbye!" << endl;
    cout << "-----------------------------------------" << endl;
}

int main()
{

    do
    {
        menu();

        if (choice == '1' || choice == '2' || choice == '3' || choice == '4' || choice == '5' || choice == '6' || choice == '7' || choice == '8')
        {

            switch (choice)
            {

            case '1':

                creatacc();

                break;
            case '2':
                deposit();
                break;
            case '3':
                withdraw();
                break;
            case '4':
                balance();
                break;
            case '5':
                interest();
                break;
            case '6':
                checkinfo();
                break;
            case '7':
                changeinfo();
                break;
            case '8':
                exit();
                return 0;
            }
        }

        else
        {
            cout << "Invalid Input! Please enter choice from 1 to 8." << endl;
            cout << " " << endl;
        }

        cout << "Do you want to continue (y/n): ", cin >> option;
        cout << " " << endl;
    } while (option == 'y' || option == 'Y');
    if (option == 'n')
        cout << "Program Ended!" << endl;
}