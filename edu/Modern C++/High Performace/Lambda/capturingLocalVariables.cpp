#include <functional>

std::function<int(int)> makeLambda(int a){
    return [a](int b){ return a + b; };
}

int main(){

    auto add5 = makeLambda(5);

    auto add10 = makeLambda(10);

    add5(10) == add10(5);

}

/*
The function, makeLambda, returns a lambda expression. The lambda expression
takes an int and returns an int. This is the type of the polymorph function
wrapper, std::function: std::function<int(int)>, in line 3.

Invoking makeLambda(5) in line 9 creates a lambda expression that captures a
which is, in this case, is 5. The same argument holds for makeLambda(10) in
line 11; therefore, add5(10) and add10(5) are both 15 in line 13.
*/
