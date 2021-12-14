#include <iostream>

int main()
{
   int a{5};
   int b{0};
	
 goPoint:
   std::cin >> b;
   
   if ((a + b) < 10)
      goto goPoint;
    
   return 0; 
}
