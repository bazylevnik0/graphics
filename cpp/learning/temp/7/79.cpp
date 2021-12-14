#include <iostream>

int sumTo(int x)
{
   int sum{0};
   while(x>0)
   {
      sum += x;
      --x;
   }
   return sum;
}

int main()
{
   int num{0};
   std::cin >> num;
   std::cout << sumTo(num) << std::endl;
   
   return 0;
}
