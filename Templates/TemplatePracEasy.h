/*
        REMINDER!!

        Templates are supposed to be defined in the header file

*/

#pragma once
#include <type_traits>
#include <array>
#include <concepts>
#include <vector>
template<typename T>
void swapTwoVariable(T& val1, T& val2)
{
    // Works in string, float, and integers
    T temp = val1;
    val1 = val2;
    val2 = temp;
}

template<typename T>
decltype(auto) findMax(T val1, T val2)
{
    return val1 > val2 ? val1 : val2;
}

template<typename T, size_t size>
void printElementArray(const std::array<T, size>& arr)
{
    std::cout << "Array: ";
    for (size_t i = 0; i < size; ++i)
    {
        if (i != size - 1)
            std::cout << arr[i] << ", ";
        else
            std::cout << arr[i] << '\n';
    }
}

template<typename T>
void printElementVector(const std::vector<T> v)
{
    std::cout << "Vector: ";
    for (size_t i = 0; i < v.size(); ++i)
    {
        if (i != v.size() - 1)
            std::cout << v[i] << ", ";
        else
            std::cout << v[i] << '\n';
    }
}

template<typename T>
requires std::is_arithmetic_v<T>
void sortArrayBubble(std::vector<T>& arr)
{
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i)
    {
        bool swapped = false;

        // Last i elements are already sorted
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap elements
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no swapping occurred, array is sorted
        if (!swapped)
        {
            break;
        }
    }
};
template<typename a, typename b>
class pair
{
public:
    a first;
    b second;


};




/*
Sure! Here's a list of **30 C++ template tasks** ranging from **easy to hard**, designed to help you progressively master **function templates**, **class templates**, **template specialization**, **variadic templates**, and **metaprogramming**.

---

### 🟢 **Easy (1–10): Basics of Templates**

1. **Function Template for Swapping Two Variables**
2. **Function Template for Finding Maximum of Two Values**
3. **Template to Print Elements of an Array**
4. **Function Template for Sorting an Array (Bubble Sort)**
5. **Class Template for a Simple Pair**
6. **Class Template for a Stack**
7. **Template Function for Searching an Element in an Array**
8. **Function Template for Adding Two Numbers**
9. **Function Template for Reversing an Array**
10. **Class Template for a Simple Vector Wrapper**

---

### 🟡 **Medium (11–20): Intermediate Template Usage**

11. **Class Template for a Linked List**
12. **Class Template for a Queue**
13. **Function Template for Calculating Average of Array**
14. **Class Template with Default Type Parameter**
15. **Function Template with Non-Type Parameter (e.g., array size)**
16. **Template Specialization for Printing `int` and `std::string` Differently**
17. **Partial Specialization of a Class Template**
18. **Overload a Template Function for `char*`**
19. **Create a Generic Comparator Using Function Templates**
20. **Create a Class Template that Works as a Matrix**

---

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

---

Would you like the **code examples** or **detailed instructions** for any of these tasks?



*/