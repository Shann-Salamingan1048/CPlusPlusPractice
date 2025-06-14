﻿/*
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
#include <initializer_list>
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
    const T& top() const
    {
        return data.back();
    }
    bool empty() const
    {
        return data.empty();
    }
    size_t size() const
    {
        return data.size();
    }
    const T& peek() const
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


template<typename T>
class Vec
{
public:
    Vec() : m_size(0), m_trueCap(1)
    {
        m_data = new T[1];

    }
    Vec(std::initializer_list<T> init) : m_size(init.size())
    {
        m_trueCap = m_size > 0 ? m_size : 1;
        m_data = new T[m_trueCap];

        size_t i = 0;
        for (const auto& item : init) 
            m_data[i++] = item;
    }
    Vec(const Vec& other) : m_size(other.m_size), m_trueCap(other.m_trueCap)
    {
        m_data = new T[m_trueCap];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_data[i] = other.m_data[i];
        }
    }
    ~Vec()
    {
        delete[] m_data;
    }

public:
    Vec& operator=(const Vec& obj)
    {
        if (this != &obj) // Self-assignment check
        {
            // clean up old memory
            delete[] m_data;

            m_trueCap = obj.m_trueCap;
            m_size = obj.m_size;
            m_data = new T[m_trueCap];

            for (size_t i = 0; i < m_size; ++i)
                m_data[i] = obj.m_data[i];
        }
        return *this; // Return reference to the current object
    }
    Vec& operator=(std::initializer_list<T> init)
    { // Shallow Copying Solved
        // Clean up old memory
        delete[] m_data;

        // Set new size and capacity
        m_size = init.size();
        m_trueCap = m_size > 0 ? m_size : 1;
        m_data = new T[m_trueCap];

        // Copy data
        size_t i = 0;
        for (const auto& item : init) 
            m_data[i++] = item;
        
        return *this;
    }
    T& operator[](size_t index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of bounds!");
        }
        return m_data[index];
    }

    const T& operator[](size_t index) const
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of bounds!");
        }
        return m_data[index];
    }
public:
    void pushback(const T& val)
    {
        
        if (m_size >= m_trueCap)
        {
            size_t newCap = m_trueCap * 2;
            T* temp = new T[newCap];

            for (size_t i = 0; i < m_size; ++i)
            {
                temp[i] = m_data[i];
            }

            delete[] m_data;
            m_trueCap = newCap;
            m_data = temp;
        }
        m_data[m_size] = val;
        ++m_size;
    }
    void print() const
    {
        std::cout << "Vec: ";
        for (size_t i = 0; i < m_size; ++i)
        {
            if (i != m_size - 1)
                std::cout << m_data[i] << ", ";
            else
                std::cout << m_data[i] << '\n';
        }
    }

private:
    T* m_data;
    size_t m_size;
    size_t m_trueCap;
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



*/