#include <iostream>

int main()
{
   std::cout << "Enter a number: " 
             << std::endl;

   int num {0};
   std::cin  >> num;
	
   //print double
   std::cout << "Double: "
             << num * 2
             << "\n";
   //print triple	
   std::cout << "Triple: "
             << num * 3
             << std::endl;
             
   return 0;
}
