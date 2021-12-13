#include <iostream>

int main()
{
   int num {0};
   std::cin >> num;
   switch (num) 
   {
   	case 0  : std::cout << "-"; break;
   	case 1  : std::cout << ""; [[fallthrough]];
   	default : std::cout << "+"; break; 
   }
   		  std::cout << std::endl;
   return 0;
}
