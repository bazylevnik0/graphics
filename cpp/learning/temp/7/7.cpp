#include <iostream>

int main()
{
   int a {1} , b {1};
   char op {'='};
   std::cin >> a >> op >> b;
   switch (op)
   {
      case '+' : std::cout << a + b; break;
      case '-' : std::cout << a - b; break;
      case '/' : std::cout << a / b; break;
      case '%' : std::cout << a % b; break;
      default  : std::cout << "???";
   }
   		 std::cout << std::endl;
   return 0;
}
