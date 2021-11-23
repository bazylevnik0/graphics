#include <iostream>

int main() 
{
	int a {} , b {} , c {};
	std::cout << "Enter one num:" << std::endl;
	std::cin  >> a;
	std::cout << "Your num is: " << a << std::endl;

	std::cout << "Enter two nums:" << std::endl;
	std::cin  >> a >> b;
	std::cout << "Your nums is: " << a  << " " << b << std::endl;

	return 0;
}
