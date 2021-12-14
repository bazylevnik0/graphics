#include <iostream>

int main()
{
   for ( int i{0} ; i < 10; ++i) 
   {
      std::cout << i;
   }
   for ( int a{0} , b{0} ; a * b < 100; ++a , ++b) 
   {
      std::cout << a << " " << b << " " << a * b << "\n";
   }     
   
      std::cout << std::endl;
   return 0;
}
