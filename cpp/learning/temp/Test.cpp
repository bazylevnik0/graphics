#include <iostream>

int main()
{
	int x;
	x = 0;
	
	std::cout << (x = x + 1) << std::endl;
	std::cout << x << std::endl;
	return 0;
}
