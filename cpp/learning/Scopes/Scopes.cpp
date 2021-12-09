#include <iostream>
#include "Scopes.h"

constexpr char a {'a'};
 
void loop()
{
	static int x {0};
	std::cout << x << std::endl;
	++x;
};

int main()
{
   loop();
   loop();
   loop();
     
   std::cout << a << std::endl;
   std::cout << consts::b << std::endl;
   {
      char c {'c'};
      std::cout << c << std::endl;
   }
   return 0;
};
