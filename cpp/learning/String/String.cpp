#include <iostream>

int main()
{
   std::string name{"   "};
   int age {0};
   
   std::cout << "Enter your full name: ";
   std::getline(std::cin >> std::ws, name);
   std::cout << "Enter your age: ";
   std::cin  >> age;
   
   std::cout << name.length() << std::endl;
   
   char string_too[] {"string c"};
   std::cout << string_too << std::endl;
   
   return 0;
}
