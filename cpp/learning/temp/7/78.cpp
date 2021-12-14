#include <iostream>

int main()
{
	int c{0};
	while (c < 26) 
	{
		std::cout << static_cast<int>('a') + c 
			  << static_cast<char>(static_cast<int>('a') + c) 
			  << "\n";
		++c;  
	}
		std::cout << std::endl;
	return 0;

}
