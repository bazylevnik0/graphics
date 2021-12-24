#include <iostream>
//*
#include <array>
//
//*2
#include <vector>
//
void changeArr ( int array[10] )
{
   array[9]=1;
};

//void changeArr ( std::array<int, 3>& myArray )

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
             
   //*           
   std::array<int, 3> myArray;
   		      myArray[0] = 0;
   		      myArray[1] = 1;
   		      myArray.at(2) = 2;
   std::cout << myArray[0]
   	     << myArray[1]
             << myArray[2] 
             << myArray.size() << std::endl;
   //		    
   //*2
   std::vector myVector{1,2,3};
   std::cout << myVector[0]
             << myVector.at(1);
   myVector.resize(5);
   myVector[4]=5;
   std::cout << myVector[4] << std::endl;
   //  
 
   return 0;
};
