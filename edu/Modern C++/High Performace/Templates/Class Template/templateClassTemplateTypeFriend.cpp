#include <iostream>

template <typename T>
class Bank{
  std::string secret{"Import secret from the bank."};
  friend T;
};

class Account{
public:
  Account(){
    Bank<Account> bank;
    std::cout << bank.secret << std::endl;
  }
};

int main(){

  std::cout << std::endl;

  Account acc;

  std::cout << std::endl;

}

/*
Explanation #
In the above code, we created an Account class that contains the Bank class
object. We can access the Bank class member secret with the help of friend. Now,
the value stored in secret is accessible in the Account class.
*/
