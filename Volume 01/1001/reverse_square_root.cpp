#include <cmath>
#include <stack>
#include <iostream>
#include <iomanip>

int main()
{
    std::stack<double> stk; 
    double num;

    while (std::cin >> num)
        stk.push(num);                  

    std::cout << std::fixed;
    std::cout << std::setprecision(4);

    while (!stk.empty()) {
        std::cout << sqrt(stk.top()) << std::endl;
        stk.pop();
    }

    return 0;
}
