#include <iostream>
#include "Templates/TemplatePracEasy.h"
#include <string>
#include <vector>
#include <array>
int main()
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

	return 0;
}