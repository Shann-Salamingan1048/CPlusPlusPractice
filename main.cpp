#include <iostream>
#include "Templates/TemplatePracEasy.h"
#include <string>
#include <vector>
#include <array>
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
}
int main()
{
	easy();


	return 0;
}