#pragma once
#include <iostream>
template<typename T>
class LinkedList
{
public:
	LinkedList()
	{

	}
	LinkedList(T val)
	{
		m_data = val;
	}
	~LinkedList()
	{
		delete m_next;
		delete m_prev;
	}


private:
	T m_data;
	LinkedList<T>* m_next;
	LinkedList<T>* m_prev;


};






/*

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



*/