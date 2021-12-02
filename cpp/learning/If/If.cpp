#include <iostream>

int main()
{
   int num;
   std::cout << "Enter num(0-9]: " << std::endl;
   std::cin  >> num;
   
   std::cout << "This num is ";
   if ( num == 2 ||
        num == 3 || 
        num == 5 ||
        num == 7 )
        std::cout << "prime.";
   else 
	std::cout << "not a prime.";
	std::cout << std::endl;
  
   return 0;
}
