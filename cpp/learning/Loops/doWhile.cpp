#include <iostream>

int main()
{
   int a{0};
   
   do 
   { 
     std::cout << a;
     ++a;
   } while (a < 10);
     std::cout << std::endl;
        
   return 0;
}
