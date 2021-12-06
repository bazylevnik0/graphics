#include <iostream>

bool isEven (int x)
{
   bool answer;
   if ( x % 2 == 0 )
   	answer = true;
   else answer = false;
   return answer;
};

int main ()
{
   int num {0};
   std::cin >> num;
   std::cout << isEven(num) << std::endl;
   return 0;
};
