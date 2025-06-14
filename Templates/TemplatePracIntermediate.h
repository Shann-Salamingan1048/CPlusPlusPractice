/*
	IMPORTANT REMINDER!!!

	IN ORDER TO DELETE A NODE, IT SHOULD BE POINTER BY ONE POINTER BEFORE DELETING IT OTHERWISE IT WILL ERROR!!!


*/

#pragma once
#include <iostream>
#include <concepts>
#include <vector>
#include <array>
#include <numeric>
template <typename T>
struct Node
{
	T data;
	Node* next;
	Node() : data(), next(nullptr) {}
	Node(const T& val) : data(val), next(nullptr) {}
};

template<typename T>
class LinkedList
{
public:
	LinkedList() : m_head(nullptr) {}
	LinkedList(const T& val) : m_head(nullptr)
	{
		insertAtHead(val);
	}
	~LinkedList()
	{
		Node<T>* current = m_head;
		while (current != nullptr)
		{
			Node<T>* nextNode = current->next;
			delete current;
			current = nextNode;
		}
		m_head = nullptr;
	}

public:

	void insertAtHead(const T& val)
	{
		Node<T>* nextNode = new Node<T>(val);
		nextNode->next = m_head;
		m_head = nextNode;
		incrementSize();
	}
	void insertIndex(const T& val, size_t index)
	{
		if (index >= m_size)
		{
			throw std::out_of_range("Index out of bounds!");
		}
		if (index == 0)
		{
			insertAtHead(val);
			return;
		}
		if (index == m_size - 1)
		{
			insertAtTail(val);
			return;
		}

		// Find the node before the insertion point
		Node<T>* current = m_head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		// 0(2) 1(10) 2
		// so Current(index 1, and data 10 and next is to index 2)
		// newNode. next = nullptr
		// newNode.next = current->next (which is index 2)
		// Insert the new node
		Node<T>* newNode = new Node<T>(val);
		newNode->next = current->next;
		// current-next = newNode
		current->next = newNode;


		incrementSize();
	}
	void insertAtTail(const T& val)
	{
		Node<T>* newNode = new Node<T>(val);
		// Handle empty list case
		if (m_head == nullptr)
		{
			m_head = newNode;
			incrementSize();
			return;
		}

		// Find the last node (not nullptr)
		Node<T>* current = m_head;
		while (current->next != nullptr)
		{
			current = current->next;
		}

		// Connect the new node to the end of the list
		current->next = newNode;
		incrementSize();
	}
public:
	void deleteHead()
	{
		// Check if list is empty
		if (m_head == nullptr)
		{
			return; // or throw an exception if preferred
		}

		// Store the node to be deleted
		Node<T>* nodeToDelete = m_head;

		// Move head to the next node
		m_head = m_head->next;

		// Delete the old head
		delete nodeToDelete;

		decrementSize();
	}
	void deleteTail()
	{
		if (m_head == nullptr)
		{
			return;
		}
		if (m_head->next == nullptr)
		{
			delete m_head;
			m_head = nullptr;
			return;
		}
		Node<T>* current = m_head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}
		Node<T>* nodeToDelete = current->next;
		delete nodeToDelete;
		current->next = nullptr;

		decrementSize();
	}
	void deleteIndex(size_t index)
	{
		if (index == 0)
		{
			deleteHead();
			return;
		}
		if (index == m_size - 1)
		{
			deleteTail();
			return;
		}
		if (index >= m_size)
		{
			throw std::out_of_range("Index out of bounds!");
		}
		Node<T>* current = m_head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}

		Node<T>* nodeToDelete = current->next;
		current->next = current->next->next;
		delete nodeToDelete;

		decrementSize();
	}
public:
	void print() const
	{
		Node<T>* current = m_head;
		std::cout << "Linkedlist Current Size: " << size() << '\n';
		while (current != nullptr)
		{
			std::cout << current->data << " -> ";
			current = current->next;

		}
		std::cout << "NULL\n";
	}
	size_t size() const
	{
		return m_size;
	}
private:
	void incrementSize()
	{
		++m_size;
	}
	void decrementSize()
	{
		--m_size;
	}
private:
	Node<T>* m_head;
	size_t m_size;
};


template <typename T>
class cirLinkedList
{
public:
	~cirLinkedList()
	{
		if (m_head == nullptr) return;

		Node<T>* tail = m_head;
		while (tail->next != m_head)
		{
			tail = tail->next;
		}
		if (tail->next == m_head)
			tail->next = nullptr;

		Node<T>* current = m_head;
		Node<T>* nextNode;
		while (current != nullptr)
		{
			nextNode = current->next;
			delete current;
			current = nextNode;
		}
		m_head = nullptr;
	}
	cirLinkedList() : m_size(0), m_head(nullptr) {}
	cirLinkedList(const T& val)
	{
		insertAtHead(val);
	}

public:
	void insertAtHead(const T& val)
	{
		Node<T>* nextNode = new Node<T>(val);
		if (m_head == nullptr)
		{
			m_head = nextNode;
			m_head->next = m_head;
		}
		else
		{
			Node<T>* tail = m_head;
			while (tail->next != m_head)
			{
				tail = tail->next;
			}
			nextNode->next = m_head;
			tail->next = nextNode;
			m_head = nextNode;
		}
		incrementSize();
	}
	void insertAtTail(const T& val)
	{
		Node<T>* newTail = new Node<T>(val);
		if (m_head == nullptr)
		{
			m_head = newTail;
			m_head->next = m_head;
		}
		else
		{
			Node<T>* tail = m_head;
			while (tail->next != m_head)
			{
				tail = tail->next;
			}
			newTail->next = m_head;
			tail->next = newTail;
		}
		incrementSize();
	}
	void insertAtIndex(const T& val, size_t index)
	{
		if (index >= getSize())
		{
			throw std::out_of_range("Out of bounds!");
			return;
		}
		if (index == 0)
		{
			insertAtHead(val);
			return;
		}
		if (index == getSize() - 1)
		{
			insertAtTail(val);
			return;
		}
		Node<T>* newNode = new Node<T>(val);
		Node<T>* current = m_head;

		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		incrementSize();
	}
public:
	void deleteHead()
	{
		if (m_head == nullptr) return;
		if (m_head->next == m_head) // only one node
		{
			delete m_head;
			m_head = nullptr;
			return;
		}
		Node<T>* nodeToDelete = m_head;
		Node<T>* tail = m_head;

		while (tail->next != m_head)
		{
			tail = tail->next;
		}
		m_head = m_head->next;
		tail->next = m_head;
		 
		delete nodeToDelete;
		decrementSize();
	}
	void deleteTail()
	{
		if (m_head == nullptr)  return;
		if (m_head->next == m_head) // only one node
		{
			delete m_head;
			m_head = nullptr;
			return;
		}
		Node<T>* tail = m_head; 
		while (tail->next->next != m_head)
		{
			tail = tail->next;
		}
		Node<T>* nodeToDelete = tail->next;
		tail->next = m_head;
		delete nodeToDelete;

		decrementSize();
	}

	void deleteIndex(size_t index)
	{
		if (index >= getSize())
		{
			std::cout << "Out of Bounds!\n";
			return;
		};
		if (index == 0)
		{
			deleteHead();
			return;
		}
		if (index == getSize() - 1)
		{
			deleteTail();
			return;
		}

		Node<T>* chosenNodeIndex = m_head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			chosenNodeIndex = chosenNodeIndex->next;
		}
		Node<T>* nodeToDelete = chosenNodeIndex->next;
		chosenNodeIndex->next = chosenNodeIndex->next->next;

		delete nodeToDelete;
		decrementSize();
	}
public:
	void print() const
	{
		if (m_head == nullptr)
		{
			std::cout << "Empty!\n";
			return;
		}
		Node<T>* tail = m_head;
		std::cout << "Circular LinkedList: " << getSize() << "(size)\n";

		do
		{
			std::cout << tail->data;
			tail = tail->next;
			if (tail != m_head)
			{
				std::cout << " -> ";
			}
		} while (tail != m_head);
		std::cout << '\n';
	}
public:
	size_t getSize() const
	{
		return m_size;
	}
private:

	void decrementSize()
	{
		--m_size;
	}
	void incrementSize()
	{
		++m_size;
	}
private:
	Node<T>* m_head;
	size_t m_size;


};

// typename T:: gets the type 
// typename T::value_type gets the value type like if it is string, double, etc
template<typename T>
concept arithmeticOnly = std::is_arithmetic_v<T>; // only numeric type like double, float,int, etc
template<typename T>
concept IsVectorOrArray = requires
{	
	// requires in order is not big deal
	requires arithmeticOnly<typename T::value_type>; // ensures the container's value_type is numeric
	requires (
		std::is_same_v<T, std::vector<typename T::value_type, typename T::allocator_type>> // check if T matches std::vector<value_type, allocator_type>
or
		std::is_same_v<T, std::array<typename T::value_type, std::tuple_size<T>::value>>
			 ); // check if T matches std::array<value_type, size>
	
	// Order does not matter
};
template<IsVectorOrArray T>
double calculateAverageArray(const T& container)
{
	if (container.empty()) return 0.0;
		return static_cast<double>(
			std::accumulate(container.begin(), container.end(), 0.0)
			) / container.size();

}

template <typename T>
struct NodeDouble
{
	T data;
	NodeDouble<T>* prev;
	NodeDouble<T>* next;

	NodeDouble() : data(), prev(nullptr), next(nullptr) {}
	NodeDouble(const T& val) : data(val), prev(nullptr), next(nullptr) {}
};
template<typename T>
class DoublyLinkedList
{
public:
	DoublyLinkedList() : m_size(0), m_head(nullptr) {}
	DoublyLinkedList(const T& val)
	{
		insertAtHead(val);
	}
	~DoublyLinkedList()
	{
		clear();
	}
	void clear()
	{
		NodeDouble<T>* current = m_head;
		while (current != nullptr)
		{
			NodeDouble<T>* nextNode = current->next;
			delete current;
			current = nextNode;
		}
		m_head = nullptr;
		m_size = 0;
	}
public:
	void insertAtHead(const T& val)
	{
		NodeDouble<T>* newNode = new NodeDouble<T>(val);
		newNode->next = m_head;
		if (m_head != nullptr)
			m_head->prev = newNode;
		m_head = newNode;
		incrementSize();
	}
	void insertAtTail(const T& val)
	{
		if (m_head == nullptr)
		{
			insertAtHead(val);
			return;
		}
		NodeDouble<T>* newNode = new NodeDouble<T>(val);
		NodeDouble<T>* tail = m_head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		tail->next = newNode;
		newNode->prev = tail;
		incrementSize();
	}
	void insertAtIndex(const T& val, size_t index)
	{
		if (index >= getSize())
		{
			throw std::out_of_range("Out of bounds!");
			return;
		}
		if (index == 0)
		{
			insertAtHead(val);
			return;
		}
		if (index == getSize() - 1)
		{
			insertAtTail(val);
			return;
		}
		NodeDouble<T>* newNode = new NodeDouble<T>(val);
		NodeDouble<T>* current = m_head;
		for (size_t i = 0; i < index - 1; ++i)
		{
			current = current->next;
		}
		newNode->next = current->next;
		newNode->prev = current;
		current->next = newNode;
		
		incrementSize();

	}
public:
	void print() const
	{
		if (m_head == nullptr)
		{
			std::cout << "Empty!\n";
			return;
		}
		NodeDouble<T>* current = m_head;
		std::cout << "Double Linkedlist Current Size: " << getSize() << '\n';
		std::cout << "nullptr <-> ";
		while (current != nullptr)
		{
			std::cout << current->data << " <-> ";
			current = current->next;

		}
		std::cout << "nullptr\n";
	}
public:
	const size_t getSize() const
	{
		return m_size;
	}
private:
	void decrementSize()
	{
		--m_size;
	}
	void incrementSize()
	{
		++m_size;
	}
private:
	NodeDouble<T>* m_head;
	size_t m_size;
};

template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

template<Arithmetic T, size_t N>
class Matrix
{
public:
	Matrix(std::initializer_list<T> init)
	{
		std::copy(init.begin(), init.end(), m_data.begin());
	}
	Matrix() : m_data{} {}

public:
	T& operator[](size_t i) { return m_data[i]; }
	const T& operator[](size_t i) const { return m_data[i]; }

public:
	const T accumulate() const
	{
		return std::accumulate(m_data.begin(), m_data.end(), T{ 0 });
	}

	T dot(const Matrix<T, N>& other) const
	{
		T result = T{ 0 };
		for (size_t i = 0; i < N; ++i)
		{
			result += m_data[i] * other.m_data[i];
		}
		return result;
	}

	// Cross product only for 3D vectors
	Matrix<T, 3> cross(const Matrix<T, 3>& other) const requires (N == 3)
	{
		return Matrix<T, 3>{
			m_data[1] * other.m_data[2] - m_data[2] * other.m_data[1],
				m_data[2] * other.m_data[0] - m_data[0] * other.m_data[2],
				m_data[0] * other.m_data[1] - m_data[1] * other.m_data[0]
		};
	}

public:
	void print() const
	{
		std::cout << "Matrix" << N << "d<" << typeid(T).name() << ">: (";
		for (size_t i = 0; i < N; ++i)
		{
			std::cout << m_data[i];
			if (i < N - 1) std::cout << ", ";
		}
		std::cout << ")\n";
	}

private:
	std::array<T, N> m_data;
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