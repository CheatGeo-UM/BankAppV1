#ifndef BANKAPPV1_FORK_CHECKINGACCOUNT_H
#define BANKAPPV1_FORK_CHECKINGACCOUNT_H
#include <iostream>

#include "BankAccount.h"

class CheckingAccount:public BankAccount { //CheckingAccount is child class, BankAccount is parent class
private:
    double m_overDraftLimit;
public:
    CheckingAccount(const std::string &accHolder, const std::string &accNum, const double balance, double overDraftLimit):BankAccount(accHolder, accNum, balance) {
        m_overDraftLimit = overDraftLimit;
    }
    ~CheckingAccount() {

    }
    bool withdraw(double amount) {
        //override base class withdraw method - this is a form of polymorphism
        if (amount <= m_balance + m_overDraftLimit) {
            if (amount > m_balance) {
                m_overDraftLimit += (m_balance - amount);
            }
            m_balance -= amount;
            return true;
        }
        else {
                return false;
        }
    }

    void display() {
        BankAccount::display();
        std::cout << "Overdraft Limit: " << m_overDraftLimit << std::endl;
    }
};

#endif //BANKAPPV1_FORK_CHECKINGACCOUNT_H
