#include <iostream>

int main()
{
   int num{0};
   std::cin >> num;
   
   while (num > 0)
   {
      --num;
      std::cout << num;
   }
      std::cout << std::endl;
      
   return 0;
}
