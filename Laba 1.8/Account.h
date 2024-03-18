#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Account
{
public:
    class Money
    {
    private:
        long banknote;
        unsigned char coin;

    public:
        Money();
        Money(double amount);
        const long getBanknote() const;
        const long getCoin() const;
        void init(long banknote, unsigned char coin);
        void init(long long coin);
        void read();
        void display() const;
        std::string toString() const;
        void setBanknote(long banknote);
        void setCoin(unsigned char coin);
        Money add(Money money);
        Money add(int coin);
        Money minus(Money money);
        Money minus(int coin);
        Money div(int divider);
        Money div(double divider);
        Money mul(double times);
        bool equal(Money money);

        Money operator+(Money money);
        Money operator+(int coin);
        Money operator-(Money money);
        Money operator-(int coin);
        Money operator/(int divider);
        Money operator/(double divider);
        Money operator*(double times);
        bool operator==(Money money);
    };
    void read();
    void init(std::string name, int accNumber, double interest, Money sum);
    void display() const;
    std::string toString() const;
    void changeOwner(std::string name);
    void withdraw(Money amount);
    void deposit(Money amount);
    void accrual();
    Money toDollars() const;
    Money toEuro() const;
    std::string numberToWords(int number) const;

public:
    int getAccNumber() const;
    void setAccNumber(int accNumber);
    double getInterest() const;
    void setInterest(double interest);
    const string &getName() const;
    void setName(const string &name);
    const Money &getSum() const;
    void setSum(const Money &sum);

private:
    int accNumber;
    double interest;
    string name;
    Money sum;
};