#include <iostream>

int convert(char x)
{
   return x;
}

int main()
{
   char c{' '};
   std::cin  >> c;
   std::cout << static_cast<int>(c) << '\n'
   	     << convert(c) << std::endl;
   return 0;
}
