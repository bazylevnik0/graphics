#include <iostream>

void c () 
{
   std::cout << "c" << std::endl;  
}

int d (void)
{
	return 4;
}

int main()
{
   unsigned int a {1};
   char b {'b'};
   
   std::cout << a   << '\n'
             << b   << '\n'
             << static_cast<int>(b) << std::endl;
                c();
   std::cout << d() << std::endl;
   
   long long int e{1234567890}; 
   std::cout << e << std::endl;
   float f{0.123456789};
   std::cout << f << std::endl;
   bool g{true};
   std::cout << g << std::endl;
   
   std::string h{"abc"};
   std::cout << h << std::endl;
     
   return 0;   
}
