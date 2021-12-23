#include <iostream>
#include <string>
#include <algorithm>

int main() 
{
        int length{0};
	std::cin >> length;
	std::cin.clear();
	std::cout << length << '\n';

	std::string* guests { new std::string [length]{} };
	for ( int i{0}; i < length; ++i) 
	{  
	   std::string name {""};
	   std::cin >> name;
	   std::cin.clear();
	   guests[i] = name;
	}

	std::sort(&guests[0], &guests[length] );
	
	for ( int i{0}; i < length; ++i) 
	{
	  std::cout << guests[i] << '\n';
	}
	
	return 0;
}

