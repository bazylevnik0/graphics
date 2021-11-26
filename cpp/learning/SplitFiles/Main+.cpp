#include <iostream>
#include "Add.cpp"

int add(int x , int y);

int main()
{
   int n{add(2,2)};
   std::cout << n << std::endl;
   return 0;
}
