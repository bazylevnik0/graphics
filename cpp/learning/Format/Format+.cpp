#include <iostream>

int main()
{
   //user input(two nums)
   int a{0} , b{0};
   std::cout << "Enter two nums: ";
   std::cin  >> a >> b;
   //output
   std::cout << "---------------" << "\n"
             << "Add: " << a + b  << "\n"
             << "Sub: " << a - b  << std::endl;
             
   return 0;
}
