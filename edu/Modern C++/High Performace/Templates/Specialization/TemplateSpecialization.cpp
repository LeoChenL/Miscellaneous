// TemplateSpecialization.cpp

#include <iostream>

class Account{
public:
  explicit Account(double b): balance(b){}
  double getBalance() const {
    return balance;
  }
private:
  double balance;
};

template <typename T, int Line, int Column>
class Matrix{
  std::string getName() const { return "Primary Template"; }
};

template <typename T>
class Matrix<T,3,3>{
  std::string name{"Partial Specialization"};
};

template <>
class Matrix<int,3,3>{};


template<typename T>
bool isSmaller(T fir, T sec){
  return fir < sec;
}

template <>
bool isSmaller<Account>(Account fir, Account sec){
  return fir.getBalance() < sec.getBalance();
}

int main(){

  std::cout << std::boolalpha << std::endl;

  Matrix<double,3,4> primaryM;
  Matrix<double,3,3> partialM;
  Matrix<int,3,3> fullM;

  std::cout << "isSmaller(3,4): "  << isSmaller(3,4) << std::endl;
  std::cout << "isSmaller(Account(100.0),Account(200.0)): "<< isSmaller(Account(100.0),Account(200.0) ) << std::endl;

  std::cout << std::endl;

}

/*
Explanation #
In the above code, we are modifying the example that we have used in template
arguments example.

Primary template is called when we use values other than Matrix<data_type, 3, 3> (line 43).

Partial specialization is called when we instantiate Matrix<data_type, 3, 3>
where data_type is not int (line 44).

Full specialization is called when we explicitly use int as a data type: Matrix<int, 3, 3> (line 45)

Full specialization of the function template isSmaller is only applicable for
Accounts. This allows the functions to compare two Accounts based on their balance (line 48).
*/
