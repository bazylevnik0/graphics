#include <iostream>

int doubleIt ( int num )
{
   return num * 2;
}

int main ()
{
   int num{0};
   std::cout << "Enter num: "; 
   std::cin  >> num;
   std::cout << doubleIt( num ) << std::endl; 
   return EXIT_SUCCESS;
}
