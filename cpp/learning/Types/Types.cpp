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
   float f{0.12e2};
   std::cout << f << std::endl;
   float g{0.123456789};
   std::cout << g << std::endl;
   bool h{true};
   std::cout << h << std::endl;
   
   std::string i{"abc"};
   std::cout << i << std::endl;
   
   std::cout << "------------\n";  
   int k{25};
   std::cout << k << "\n";
   k = 025;  
   std::cout << k << "\n";
   k = 0x25;   
   std::cout << k << "\n";
  
   std::cout << "------------\n";   
   int l = 0b11001;
   std::cout << l << "\n";
   std::cout << std::dec << l << "\n";
   std::cout << std::oct << l << "\n";
   std::cout << std::hex << l << std::endl;
   
   return 0;   
}
