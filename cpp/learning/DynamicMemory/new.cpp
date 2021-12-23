#include <iostream>

int main()
{
   int* more{ new int};
   *more = 1;
   std::cout << *more << std::endl;
   delete more;
   more = nullptr;
   
   std::cout << more << std::endl;
   
   int length{};
   std::cin >> length;

   int* array{ new int[length]{} }; 
   for ( int i{0}; i < length; i++ )
   {
      array[i] = i;
      std::cout << array[i] << " ";
   }
      std::cout << std::endl;
      delete [] array;
    
   return 0;
}
/* check request
int* value { new (std::nothrow) int{} }; // ask for an integer's worth of memory
if (!value) // handle case where new returned null
{
    // Do error handling here
    std::cerr << "Could not allocate memory\n";
}
*/
