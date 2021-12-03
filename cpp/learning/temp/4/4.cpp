#include <iostream>

double calc( double x , double y , char op )
{
   double answer{0.0};
   if ( op == '+' ) answer = x + y;
   if ( op == '-' ) answer = x - y;
   if ( op == '*' ) answer = x * y;
   if ( op == '/' ) answer = x / y;

   return answer;
};

int main()
{
   double a {0.0};
   double b {0.0};
   char act {' '};
   
   std::cout << "Enter sequence( a act b ): ";
   std::cin  >> a >> act >> b;

   std::cout << "Answer: " << calc(a,b,act) << std::endl;
   return 0;
}
