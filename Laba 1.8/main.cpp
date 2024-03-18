#include "Account.h"


int main() {
    Account acc;
    acc.init("Nazar", 22, 15, 20.35);
    acc.accrual();
    acc.display();
    acc.changeOwner("Bohdan");
    acc.withdraw(1.05);
    acc.display();
    Account::Money m(10);
    acc.deposit((m / 0.5) / 2);
    acc.display();
    std::cout << boolalpha << (m == Account::Money(10)) << std::endl;

    return 0;
}