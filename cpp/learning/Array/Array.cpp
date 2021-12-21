#include <iostream>
void changeArr ( int array[10] )
{
   array[9]=1;
};

int main()
{
   int arr[10] {1,2,3};
   std::cout << arr[0]
             << arr[1]
             << arr[9] << std::endl;
             
   changeArr( arr );
   std::cout << arr[0]
             << arr[1]
             << arr[9] << std::endl;
 
   return 0;
};
