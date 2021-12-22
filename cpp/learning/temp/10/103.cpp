#include <iostream>

int main()
{
   int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
   int array_length = sizeof(array)/sizeof(array[0]);
   for(int i{0} ; i < array_length; i++)
   {
      std::cout << array[i];
   }
      std::cout << std::endl;
   
   bool array_check{false};
   while (array_check == false)
   {
 	for (int i{1}; i < array_length; i++)
 	{
 	   if (array[i-1] > array[i]) std::swap(array[i-1],array[i]);
 	}	  
   
   	array_check = true;
   	for(int i{1} ; i < array_length; i++)
   	{
   	   if ( array[i-1] > array[i] ) array_check = false;
   	}
   }
   
   
   for(int i{0} ; i < array_length; i++)
   {
      std::cout << array[i];
   }
      std::cout << std::endl;
   
   
   return 0;
}
