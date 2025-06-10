#include <iostream>
#include "Templates/TemplatePracEasy.h"
#include <string>
#include <vector>
#include <array>
#include "Templates/TemplatePracIntermediate.h"
void easy()
{
	std::string x = "10";
	std::string y = "20";

	std::cout << "X: " << x << ", Y: " << y << '\n';
	swapTwoVariable(x, y);
	std::cout << "X: " << x << ", Y: " << y << '\n';

	int a = 10;
	int b = 20;

	std::cout << "Max: " << findMax(a, b) << '\n';

	std::array<std::string, 5> arr = { "Shann", "Delfin", "Caturla", "Salamingan", "III" };
	printElementArray(arr);

	std::vector<int> v = { 2,4,5,1,10,7,9 };
	sortArrayBubble(v);
	printElementVector(v);

	pair<std::string, int> p = { "Shann", 20 };
	std::cout << "First: " << p.first << ", Second: " << p.second << '\n';


	stackShann<int> s1;
	s1.push(3);
	s1.push(1);
	s1.push(19);
	s1.push(4);
	std::cout << "Custom Stack: ";
	for (const auto& i : s1)
	{
		std::cout << i << ", ";
	}
	std::cout << '\n';
	std::cout << "Stack First: " << s1.peek() << '\n';
	std::cout << "Stack top: " << s1.top() << '\n';
	s1.pop();
	std::cout << "Custom Stack: ";
	for (const auto& i : s1)
	{
		std::cout << i << ", ";
	}
	std::cout << '\n';

	// -1 = not found or does not exist
	std::cout << "Index of Value Caturla: " << findElementArray(arr, "Caturla") << '\n';
	std::cout << "Index of Value Shannyyy: " << findElementArray(arr, "Shannyyy") << '\n';


	int add1 = 10;
	double add2 = 12.4245;

	std::cout << addTwoNumbers(add1, add2) << '\n';
	reverseArray(arr);
	printElementArray(arr);


	Vec<std::string> vec;
	vec.pushback("asdadsa");
	vec[0] = "Shann";
	vec.pushback("asd");
	vec.pushback("Caturla");
	vec.pushback("Salamingan");
	vec.pushback("III");
	vec[1] = "Delfin";

	vec.print();
}
void med()
{
	LinkedList<int> l1 = LinkedList<int>(10); // 1
	l1.insertAtHead(2);  // 0
	l1.insertAtTail(22); // 2
	l1.insertAtTail(33); // 3
	l1.insertIndex(50, 2);

	
	l1.deleteHead();
	l1.deleteTail();
	l1.deleteIndex(1);
	l1.deleteIndex(1);
	l1.deleteIndex(0);
	l1.print();



	cirLinkedList<int> cl1;
	cl1.insertAtTail(110);
	cl1.insertAtHead(10);
	cl1.insertAtHead(20);
	cl1.insertAtHead(30);
	cl1.insertAtTail(60);
	cl1.insertAtIndex(40, 1);

	cl1.deleteHead();
	cl1.deleteTail();

	cl1.deleteIndex(2);
	cl1.print();

	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	std::array<double, 3> arr = { 1.5, 2.5, 3.5 };
	// std::vector<std::string> vec2 = { "Shann", "Delfin" };

	std::cout << calculateAverageArray(vec) << '\n';  // 3.0
	std::cout << calculateAverageArray(arr) << '\n';  // 2.5
	// std::cout << calculateAverageArray(vec2) << '\n';  // error using std::string. nice
}
int main()
{
	//easy();
	med();

	return 0;
}