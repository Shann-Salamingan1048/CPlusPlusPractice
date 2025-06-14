#pragma once
#include <iostream>
#include<numeric>
/*
    The ... is the fold expression operator in C++17. It expands the parameter pack into multiple expressions.
    The ... takes the pattern (std::cout << typeid(Args).name() << ": " << args << " ") and 
    repeats it for each type/argument pair in the parameter pack.
*/
template<typename... Args>
void printMultipleArguments(Args... args)
{
    ((std::cout << typeid(Args).name() << ": " << args << " "), ...);
    std::cout << '\n';

};
template<typename T>
concept ArithmeticHard = std::is_arithmetic_v<T>;

template<typename... ArithmeticHard>
auto accumulation(ArithmeticHard... arith)
{
    return (arith + ...);
}

template<typename... ArithmeticHard>
auto multiplier(ArithmeticHard... arith)
{
    return (arith * ...);
}
template<typename T = size_t>
constexpr auto factorial(T i)
{
    if (i == 1 or i == 0) return T{ 1 };
    return i * factorial(i - 1);
};


/*
### 🔴 **Hard (21–30): Advanced Templates and Metaprogramming**

21. **Variadic Function Template to Print Multiple Arguments**
22. **Template Metaprogram to Compute Factorial at Compile Time**
23. **Type Traits: Implement `is_same<T, U>`**
24. **Enable/Disable Function Using `std::enable_if`**
25. **Create a Simple Tuple Class Using Variadic Templates**
26. **SFINAE Example: Enable Function Only for Integral Types**
27. **Tag Dispatching for Optimized Overloads**
28. **Recursive Variadic Template for Summing Numbers**
29. **Static Assert to Enforce Template Constraints**
30. **Custom Allocator Class Template**



*/