#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T data;
	Node* next;
	Node() {}
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
	void insertIndex(const T& val, uint64_t index)
	{
		if (index > m_size - 1)
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
		for (uint64_t i = 0; i < index - 1; ++i)
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
	void deleteIndex(uint64_t index)
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
		if (index > m_size - 1)
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
	void print() 
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
	static const size_t& size()
	{
		return m_size;
	}
private:
	static void incrementSize()
	{
		++m_size;
	}
	static void decrementSize()
	{
		--m_size;
	}
private:
	Node<T>* m_head;
	static inline size_t m_size;


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