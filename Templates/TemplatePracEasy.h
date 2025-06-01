/*
        REMINDER!!

        Templates are supposed to be defined in the header file

*/

#pragma once
#include <type_traits>
#include <array>
#include <concepts>
#include <vector>
#include <deque>
#include <utility>
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
void printElementVector(const std::vector<T>& v)
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

    pair() = default;
    pair(const a& f, const b& s) : first(f), second(s) {}
};
template<typename T>
class stackShann
{
public:
    void push(const T& item)
    {
        data.push_back(item);
    }

    void pop()
    {
        if (!empty())
        {
            data.pop_back();
        }
    }
    T& top()
    {
        return data.back();
    }
    const bool empty() const
    {
        return data.empty();
    }
    const size_t size() const
    {
        return data.size();
    }
    T& peek()
    {
        return data.front();
    }
    // Iterator support for range-based for loops
    auto begin() { return data.begin(); }
    auto end() { return data.end(); }
    auto begin() const { return data.begin(); }
    auto end() const { return data.end(); }
private:
    std::deque<T> data;
};

template<typename T, size_t size, typename U>
long findElementArray(const std::array<T, size>& arr,  U&& target)
{
    size_t left = 0; 
    size_t right = arr.size() - 1;

    while (left <= right)
    {
        if (arr[left] == target) return left;
        if (arr[right] == target) return right;

        left++;
        right--;
    }
    return -1;
}

template<typename a, typename b>           // Two template parameters allow different types
constexpr                                  // Enables compile-time evaluation when possible
decltype(auto)                            // Auto-deduces return type, preserves value category
addTwoNumbers(a&& val1, b&& val2)         // Universal references - bind to ANY value category
{
    return std::forward<a>(val1) + std::forward<b>(val2);
    //     ^^^^^^^^^^^^^^^^^^^   ^^^^^^^^^^^^^^^^^^^
    //     Perfect forwarding - preserves value category and const-ness
    //     Avoids unnecessary copies for temporaries and rvalues
}

/*
OPTIMIZATION BREAKDOWN:

1. template<typename a, typename b>
   - Allows mixing different types (int + double, float + int, etc.)
   - Compiler generates specialized versions for each type combination

2. constexpr
   - Function can be evaluated at compile-time when arguments are compile-time constants
   - Example: constexpr auto result = addTwoNumbers(5, 10); // Computed at compile-time
   - Zero runtime cost for constant expressions

3. decltype(auto)
   - Automatically deduces the correct return type based on the expression
   - Preserves value category (lvalue/rvalue) and cv-qualifiers
   - No manual type specification needed

4. a&& and b&& (Universal References)
   - NOT rvalue references in template context - they're "forwarding references"
   - Bind to ANYTHING: lvalues, rvalues, const, non-const
   - Enable perfect forwarding without overload explosion

5. std::forward<a>(val1) and std::forward<b>(val2)
   - Perfect forwarding: preserves the value category of the original arguments
   - If argument was rvalue → forwards as rvalue (enables move semantics)
   - If argument was lvalue → forwards as lvalue (normal reference)
   - Eliminates unnecessary copies for temporary objects
*/
 
template<typename T, size_t size>
void reverseArray(std::array<T, size>& arr) 
{
    std::reverse(arr.begin(), arr.end());
}
 
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