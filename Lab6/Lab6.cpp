#include<iostream>

using namespace std;

class bankAccount
{
    int accountNumber;
    double balance;
    string ownerName;
    
    public:
        bankAccount(){} // Default constructor
        bankAccount(int accountNumber, double balance, string ownerName)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
        }

        int getAccountNumber() {return this->accountNumber;}
        void setAccountNumber(int accountNumber) {this->accountNumber = accountNumber;}

        int getBalance() {return this->balance;}
        void setBalance(double balance) {this->balance = balance;}

        void withdrawMoney(double amount) {setBalance(getBalance()-amount);}
        void depositMoney(double amount) {setBalance(getBalance()+amount);}
        
        string getOwnerName() {return this->ownerName;}
        void setOwnerName(string ownerName) 
        {
            this->ownerName = ownerName;
            if(ownerName == "Richie Rich")
            {
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$,,,$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$\"OOO\"$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$!OOO!$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$,\"OOO\",$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$,\"OOOOOOO\",$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$!\"OOOOOOOOOOO\"!$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$,\"OOOOOOOOOOOOOOO\",$$$$$$$$$" << endl;
                cout << "$$$$$$$$,1OOOOOOOOOOOOOOOOOOO7,$$$$$$$" << endl;
                cout << "$$$$$$,!OOOOOOOOOOOOOOOOOOOOOO\"$$$$$$$" << endl;
                cout << "$$$$$$!OOOOOOOOO/\"\"\"\"\'\\OOOOOOOO1$$$$$$" << endl;
                cout << "$$$$$$\"OOOOOOOOOO\"$$$$!OOOOOOOO\"$$$$$$" << endl;
                cout << "$$$$$$\"OOOOOOOOOOO!$$$\",OOOOOOO!$$$$$$" << endl;
                cout << "$$$$$$$\",OOOOOOOOOO\",$$$\"\"\"\"\"\"\"$$$$$$$" << endl;
                cout << "$$$$$$$$\"!OOOOOOOOOOO\",$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$\",OOOOOOOOOOO\",$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$\"OOOOOOOOOOOO\",$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$\"!OOOOOOOOOOOO\"+$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$\"==OOOOOOOOOOO,$$$$$$$$" << endl;
                cout << "$$$$$$$$,,,,,,$$$$\",OOOOOOOOOO\",$$$$$$" << endl;
                cout << "$$$$$$,\"OOOOOO',$$$$\",OOOOOOOOO!$$$$$$" << endl;
                cout << "$$$$$$1OOOOOOOO.\"~~~\"OOOOOOOOOO!$$$$$$" << endl;
                cout << "$$$$$$!OOOOOOOOOOOOOOOOOOOOOOO1$$$$$$$" << endl;
                cout << "$$$$$$\",OOOOOOOOOOOOOOOOOOOOO,\"$$$$$$$" << endl;
                cout << "$$$$$$$\",OOOOOOOOOOOOOOOOOOO!$$$$$$$$$" << endl;
                cout << "$$$$$$$$$1OOOOOOOOOOOOOOOO,1$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$\"~~,OOOOOOOOOO,\"$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$\"\"\"1OOO1\"'$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$!OOO!$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$,OOO,$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$\"\"\"$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
            }
        }

        virtual void writeCheck(string recipient, string date, string address, double amount, string memo) 
        {
            cout << "\n\nCheck written. Details:\n----------------------------" << endl;
            cout << "Pay to the Order of: " << recipient << endl;
            cout << "Date: " << date << endl;
            cout << "Address: " << address << endl;
            cout << "Amount: " << amount << endl;
            cout << "Memo: " << memo << endl;
        };

};

class checkingAccount : public bankAccount
{
    double monthlyCharge;
    double interest;
    double minimumBalance;
    bool lowInterest;
    bool limitedCheckWriting;

    public:
        checkingAccount(){} // Default constructor
        checkingAccount(int accountNumber, double balance, string ownerName, double monthlyCharge) // Monthly service charge, limited check writing, no minimum balance, and no interest
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setMonthlyCharge(monthlyCharge);
            // Limited check writing
            setLimitedCheckWriting(true);
        } 
        // No monthly service charge, a minimum balance requirement, unlimited check writing, and lower interest
        // Also covers the 3rd type of account with higher interest rate and higher minimum requirement
        checkingAccount(int accountNumber, double balance, string ownerName, double minimumBalance, double interest, bool lowInterest)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setMinimumBalance(minimumBalance);
            setInterest(interest);
            // Unlimited check writing
            setLimitedCheckWriting(false);
        } 
    
        double getMonthlyCharge() {return this->monthlyCharge;}
        void setMonthlyCharge(double monthlyCharge) {this->monthlyCharge = monthlyCharge;}

        double getInterest() {return this->interest;}
        void setInterest(double interest) {this->interest = interest;}

        double getMinimumBalance() {return this->minimumBalance;}
        void setMinimumBalance(double minimumBalance) {this->minimumBalance = minimumBalance;}

        bool getLowInterest() {return this->lowInterest;}
        void setLowInterest(bool lowInterest) {this->lowInterest = lowInterest;}

        bool getLimitedCheckWriting() {return this->limitedCheckWriting;}
        void setLimitedCheckWriting(bool limitedCheckWriting) {this->limitedCheckWriting = limitedCheckWriting;}
};

class certificateOfDeposit : public bankAccount
{

    double interestRate;
    double withdrawPenalty;
    double currentMaturity;
    double timeUntilMature;

    public:
        certificateOfDeposit(){} // Default constructor
        certificateOfDeposit(int accountNumber, double balance, string ownerName, double interestRate, double withdrawPenalty, double timeUntilMature)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setInterestRate(interestRate); // Higher interest rates
            setWithdrawPenalty(withdrawPenalty); // Penalty is stiff
            setCurrentMaturity(0); // Starts from 0
            setTimeUntilMature(timeUntilMature);
        }

        double getInterestRate() {return this->interestRate;}
        void setInterestRate(double interestRate) {this->interestRate = interestRate;}

        double getWithdrawPenalty() {return this->withdrawPenalty;}
        void setWithdrawPenalty(double withdrawPenalty) {this->withdrawPenalty = withdrawPenalty;}
        
        double getCurrentMaturity() {return this->currentMaturity;}
        void setCurrentMaturity(double currentMaturity) {this->currentMaturity = currentMaturity;}

        double getTimeUntilMature() {return this->timeUntilMature;}
        void setTimeUntilMature(double timeUntilMature) {this->timeUntilMature = timeUntilMature;}
};

class savingsAccount : public bankAccount
{

    double minimumBalance;
    double interest;
    double monthlyCharge;

    public:
        savingsAccount(){} // Default constructor

        // No minimum balance, lower interest rate
        savingsAccount(int accountNumber, double balance, string ownerName, double monthlyCharge, double interest)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setInterest(interest);
            setMonthlyCharge(monthlyCharge);
            setMinimumBalance(0);
        } 

        // Minimum balance required, higher interest rate
        savingsAccount(int accountNumber, double balance, string ownerName, double monthlyCharge, double minimumBalance, double interest)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setMinimumBalance(minimumBalance);
            setInterest(interest);
            setMonthlyCharge(monthlyCharge);
        } 

        double getMinimumBalance() {return this->minimumBalance;}
        void setMinimumBalance(double minimumBalance) {this->minimumBalance = minimumBalance;}

        double getInterest() {return this->interest;}
        void setInterest(double interest) {this->interest = interest;}

        double getMonthlyCharge() {return this->monthlyCharge;}
        void setMonthlyCharge(double monthlyCharge) {this->monthlyCharge = monthlyCharge;}
};

//Does not pay any interest, allows the account holder to write a limited number of checks each month, and does not require any minimum balance
class serviceChargeChecking : public checkingAccount
{
    int checkLimit;
    double checksWritten = 0; // Start at 0

    public:
        serviceChargeChecking(){}
        serviceChargeChecking(int accountNumber, double balance, string ownerName, double monthlyCharge, int checkLimit)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setCheckLimit(checkLimit);
            setMonthlyCharge(monthlyCharge);
            setInterest(0);
        }

        int getCheckLimit() {return this->checkLimit;}
        void setCheckLimit(int checkLimit) {this->checkLimit = checkLimit;}

        void writeCheck(string recipient, string date, string address, double amount, string memo) 
        {
            if(checksWritten < checkLimit)
            {
            cout << "\n\nCheck written. Details:\n----------------------------" << endl;
            cout << "Pay to the Order of: " << recipient << endl;
            cout << "Date: " << date << endl;
            cout << "Address: " << address << endl;
            cout << "Amount: " << amount << endl;
            cout << "Memo: " << memo << endl;
            checksWritten++;
            }
            else
            {
                cout << "Check limit exceeded";
            }
            
        };
};

class noServiceChargeChecking : public checkingAccount
{
    public:
        noServiceChargeChecking(){}
        noServiceChargeChecking(int accountNumber, double balance, string ownerName, double interest, double minimumBalance)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setMonthlyCharge(0); // No monthly charge
            setInterest(interest);
            setMinimumBalance(minimumBalance);
        }
};

class highInterestChecking : public noServiceChargeChecking
{
    public:
        highInterestChecking(){}
        highInterestChecking(int accountNumber, double balance, string ownerName, double interest, double minimumBalance)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setMonthlyCharge(0);
            setInterest(interest); // Higher interest than noServiceChargeChecking
            setMinimumBalance(minimumBalance);
        }
};

class highInterestSavings : public savingsAccount
{
    public:
        highInterestSavings(){}
        highInterestSavings(int accountNumber, double balance, string ownerName, double monthlyCharge, double minimumBalance, double interest)
        {
            setAccountNumber(accountNumber);
            setBalance(balance);
            setOwnerName(ownerName);
            setMinimumBalance(minimumBalance);
            setInterest(interest);
            setMonthlyCharge(monthlyCharge);
        }
};

int main()
{
    checkingAccount c = checkingAccount(1234, 1501.03, "Ronald Regan", 11.02);
    c.writeCheck("Tyler Harrison", "04/26/2021", "614 Holleman Dr E", 100.02, "Pizza money");
    serviceChargeChecking s = serviceChargeChecking(1234, 1501.03, "Dr. Gooch", 11.02, 2);
    s.writeCheck("Tyler Harrison", "04/26/2021", "614 Holleman Dr E", 100.02, "Pizza money");
    s.writeCheck("Tyler Harrison", "04/26/2021", "614 Holleman Dr E", 100.02, "Pizza money");
    cout << endl;
    s.writeCheck("Tyler Harrison", "04/26/2021", "614 Holleman Dr E", 100.02, "Pizza money"); // This should 
    return 0;
}