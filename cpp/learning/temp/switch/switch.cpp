#include <iostream>

//Write a program that asks the user to enter two integers, one named smaller, the other named larger. 
//If the user enters a smaller value for the second integer, use a block and a temporary variable to swap the smaller and larger values. 
//Then print the values of the smaller and larger variables. Add comments to your code indicating where each variable dies. 
//Note: When you print the values, smaller should hold the smaller input and larger the larger input, no matter which order they were entered in.
int main()
{
   int smaller {0}, larger {0};
   std::cin >> smaller >> larger;
   if (larger < smaller)
   	{
   	 int larger_temp  = smaller; 
   	 int smaller_temp = larger;
   	 larger  = larger_temp;
   	 smaller = smaller_temp;
   	} 
   
   std::cout << smaller << larger << std::endl; 
   return 0;
}

