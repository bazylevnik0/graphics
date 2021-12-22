#include <iostream>

int main()
{
   int x {1};
   std::cout << "variable: "          << x     << std::endl;
   std::cout << "adress: "            << &x    << std::endl;
   std::cout << "value from adress: " << *(&x) << std::endl;
   
   int* ptr_x { &x };
   std::cout <<  ptr_x << std::endl;
   std::cout << *ptr_x << std::endl;
   std::cout << &ptr_x << std::endl;
   
   return 0;
};
