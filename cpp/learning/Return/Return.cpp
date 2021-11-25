#include <iostream>

void say ()
{
   std::cout << "running" << std::endl;
}
int main () 
{
   say();
   std::cout << EXIT_SUCCESS << std::endl;
   std::cout << EXIT_FAILURE << std::endl;
   return 1;
}
