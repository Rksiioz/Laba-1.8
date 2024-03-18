
#include "Account.h"

Account::Money::Money()
{
    this->init(0, 0);
}

Account::Money::Money(double amount)
{
    double intPart;
    double fracPart;

    fracPart = modf(amount, &intPart);

    this->init(intPart, fracPart * 100);
}

const long Account::Money::getBanknote() const
{
    return this->banknote;
}

const long Account::Money::getCoin() const
{
    return this->coin;
}

void Account::Money::init(long hrn, unsigned char kop)
{
    this->banknote = hrn;
    this->coin = kop;
}

void Account::Money::init(long long coin)
{
    this->init(coin / 100, coin % 100);
}

void Account::Money::read()
{
    std::cout << "Hrn: ";
    std::cin >> this->banknote;
    std::cout << "Kop: ";
    std::cin >> (int &)this->coin;
}

void Account::Money::display() const
{
    std::cout << this->toString() << std::endl;
}

std::string Account::Money::toString() const
{
    std::string result;

    result = std::to_string(this->banknote) + '.' + std::to_string(this->coin);

    return result;
}

void Account::Money::setBanknote(long hrn)
{
    this->banknote = hrn;
}

void Account::Money::setCoin(unsigned char kop)
{
    this->coin = kop;
}

Account::Money Account::Money::add(Money money)
{
    int kop = money.banknote * 100 + money.coin;

    return this->add(kop);
}

Account::Money Account::Money::add(int coins)
{
    Money result;

    int coin = this->banknote * 100 + this->coin + coins;

    result.init(coin);

    return result;
}

Account::Money Account::Money::minus(Money money)
{
    int coin = money.banknote * 100 + money.coin;

    return this->minus(coin);
}

Account::Money Account::Money::minus(int c)
{
    Money result;
    int coin = (this->banknote * 100 + this->coin) - c;
    result.init(coin);

    return result;
}

Account::Money Account::Money::div(int divider)
{
    Money result;
    int coin = (this->banknote * 100 + this->coin) / divider;
    result.init(coin);
    return result;
}

Account::Money Account::Money::div(double divider)
{
    Money result;
    double coin = (this->banknote * 100 + this->coin) / divider;
    result.init((long long)coin);

    return result;
}

Account::Money Account::Money::mul(double times)
{
    Money result;
    double coin = (this->banknote * 100 + this->coin) * times;

    result.init((long long)coin);

    return result;
}

bool Account::Money::equal(Money money)
{
    return this->banknote == money.banknote && this->coin == money.coin;
}

Account::Money Account::Money::operator+(Account::Money money)
{
    return this->add(money);
}

Account::Money Account::Money::operator+(int kop)
{
    return this->add(kop);
}

Account::Money Account::Money::operator-(Account::Money money)
{
    return this->minus(money);
}

Account::Money Account::Money::operator-(int coin)
{
    return this->minus(coin);
}

Account::Money Account::Money::operator/(int divider)
{
    return this->div(divider);
}

Account::Money Account::Money::operator/(double divider)
{
    return this->div(divider);
}

Account::Money Account::Money::operator*(double times)
{
    return this->mul(times);
}

bool Account::Money::operator==(Account::Money money)
{
    return this->equal(money);
}
