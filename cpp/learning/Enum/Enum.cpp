#include <iostream>

int main()
{
   enum Num {
   	zero,
   	one,
   	two,
   	ten = 10,
   };
   
   std::cout << ten << one << std::endl;
   
   enum class NumClass {
   	zero_c,
   	one_c,
   	two_c,
   	ten_c = 10,
   };
 
   NumClass tenc {NumClass::ten_c};
   NumClass onec {NumClass::one_c};
   
   std::cout << static_cast<int>(tenc) << static_cast<int>(onec) << std::endl;
   
   
   return 0;
};
