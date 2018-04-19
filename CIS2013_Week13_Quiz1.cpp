#include <iostream>
#include <cstring>

using namespace std;

class BankAccount
{

	public:
		string name;
		int acctNumber;
		long long phone;
		long long balance;
		int rate;
		string accountType;

		string getName()
		{
			return name;
		}	
		int getAcctNumber()
		{
			return acctNumber;
		}	
		long long getPhone()
		{
			return phone;
		}	
		int getBalance()
		{
			return balance;
		}	
		int getRate()
		{
			return rate;
		}	
		void setName(string inputName)
		{
			name = inputName;
		}	
		void setAcctNumber(int inputAcctNumber)
		{
			acctNumber = inputAcctNumber;
		}	
		void setPhone(int inputPhone)
		{
			phone = inputPhone;
		}	
		void setBalance(int inputBalance)
		{
			balance = inputBalance;
		}	
		void setRate(int inputRate)
		{
			rate = inputRate;
		}			

		void printBalance()
		{
			cout << "Current balance is: " << balance;
			system("pause");
		}
		
		void depositMoney(int amount)
		{
			system("CLS");
			cout << "\n\n\n		How much would you like to deposit?	\n";
			cout << "\n\n\n			-regular		\n";
		}

		int withdrawMoney(int amount)
		{
			system("CLS");
			cout << "\n\n\n		How much would you like to withdraw?	\n";
			cout << "\n\n\n			-regular		\n";
		}
		void displayAccountInformation()
		{
			cout << "Name: " << name << endl;
			cout << "Account Number: " << acctNumber << endl;
			cout << "Phone: " << phone << endl;
			cout << "Balance: " << balance << endl;
			cout << "Rate: " << rate << endl;
			cout << "Account Type: " << accountType << endl << endl << endl;
			system("pause");
		}


};
class Regular: public BankAccount
{
public:
	Regular(int i)
	{
		system("CLS");
		string inputName;
		long long inputPhone;
		long long inputBalance;
		cout << "Please enter your account's name: ", cin >> inputName;
		name = inputName;
		cout << "Please enter your account's phone: ", cin >> inputPhone;
		phone = inputPhone;
		cout << "Please enter your account's balance: ", cin >> inputBalance;
		balance = inputBalance;

		cout << "Bank account made!\n\n";
		acctNumber = i;
		accountType = "Regular";
		displayAccountInformation();
	}
};
class Saving: public BankAccount
{
	public:
		int minimumBalance = 1000;
		int withdrawLimit = 800;
		Saving(int i)
		{
			system("CLS");
			string inputName;
			long long inputPhone;
			long long inputBalance;
			cout << "Please enter your account's name: ", cin >> inputName;
			name = inputName;
			cout << "Please enter your account's phone: ", cin >> inputPhone;
			phone = inputPhone;
			cout << "Please enter your account's balance: ", cin >> inputBalance;
			balance = inputBalance;
			accountType = "Savings";
			cout << "Bank account made!\n\n";
			acctNumber = i;
			displayAccountInformation();
		}
};

class Checking: public BankAccount
{
	public:
		int overdraftFee = 50;
		int minimumBalance = 300;
		int withdrawLimit = 800;
		Checking(int i)
		{
			system("CLS");
			string inputName;
			long long inputPhone;
			long long inputBalance;
			cout << "Please enter your account's name: ", cin >> inputName;
			name = inputName;
			cout << "Please enter your account's phone: ", cin >> inputPhone;
			phone = inputPhone;
			cout << "Please enter your account's balance: ", cin >> inputBalance;
			balance = inputBalance;

			cout << "Bank account made!\n\n";
			accountType = "Checking";
			acctNumber = i;
			displayAccountInformation();
		}
		
};



string PrintMenu();
string PrintNewAccountMenu();
string AccountMenu();
void MainMenuLogic(string);



string PrintMenu();
string PrintNewAccountMenu();
void MainMenuLogic(string);
BankAccount *accounts[100];

int numberOfAccounts = 1;

int main()
{

	system("CLS");
	cout << "\n\n\nWelcome to the infamous bank account application.\n\n\n";
	system("pause");
	while(true)
	{
		string decision = PrintMenu();	
		MainMenuLogic(decision);
	}

	return 0;
}






void MainMenuLogic(string decision)
{
	if(decision == "o" || decision == "O")
	{
		string newAccountDecision = PrintNewAccountMenu();

		if(newAccountDecision == "r" || newAccountDecision == "R")
		{
			accounts[numberOfAccounts] = new Regular(numberOfAccounts);
			numberOfAccounts++;
		}
		else if(newAccountDecision == "s" || newAccountDecision == "S")
		{
			accounts[numberOfAccounts] = new Saving(numberOfAccounts);
			numberOfAccounts++;
		}
		else if(newAccountDecision == "c" || newAccountDecision == "C")
		{
			accounts[numberOfAccounts] = new Checking(numberOfAccounts);
			numberOfAccounts++;			
		}
	}
	else if(decision == "C" || decision == "c")
	{
		system("CLS");
		int inputAcctNumber;
		cout << "Please enter the account number: ";
		cin >> inputAcctNumber;
		accounts[inputAcctNumber]->displayAccountInformation();

		string accountDecision = AccountMenu();


		if(accountDecision == "d")
		{
			accounts[inputAcctNumber]->withdrawMoney(1);
		}
		else if(accountDecision == "w")
		{
			accounts[inputAcctNumber]->depositMoney(2);
		}


		
	}
	else
	{

		cout << "You entered something else...\n\n";
		system("pause");
	}
}


string PrintMenu()
{
	system("CLS");
	cout << "\n\n		Main Menu		\n";
	cout << "\n			-Open new bank account		(o)\n";
	cout << "\n			-Check a bank account		(c)\n";
	string decision;
	cin >> decision;
	return decision;
}

string AccountMenu()
{
	system("CLS");
	cout << "\n\n		What would you like to do?		\n";
	cout << "\n			-deposit money		(d)\n";
	cout << "\n			-withdraw money		(w)\n";
}

string PrintNewAccountMenu()
{
	system("CLS");
	cout << "\n\n\n		Which type of account?		\n";
	cout << "\n\n\n			-regular		(r)\n";
	cout << "\n\n\n			-savings		(s)\n";
	cout << "\n\n\n			-checking		(c)\n";
	string decision;
	cin >> decision;
	return decision;
}
