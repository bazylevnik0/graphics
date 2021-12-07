#include <iostream>

namespace space
{
   int a {1};
   void b () {
      std::cout << 2 << std::endl;
   }
   namespace c
   {
      int c{3};
   }
};

namespace space::d
{
   int d{4};
};

int main()
{
   std::cout << space::a << std::endl;
   space::b();
   std::cout << space::c::c << std::endl;
   std::cout << space::d::d << std::endl;
   
   return 0;
};

