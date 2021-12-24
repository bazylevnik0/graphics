#include <iostream>

int main()
{
   int array [10] {0,1,2,3,4,5,6,7,8,9};
   for ( int el : array )
   {
      std::cout << el;
   }
      std::cout << std::endl;
   
   return 0;
}

/*
 for ( int i{0}; int el : array )
   {
      ++i;
      std::cout << el;
   }

*/
