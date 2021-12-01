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
             << b   << std::endl;
                c();
   std::cout << d() << std::endl;
   
   long long int e{1234567890}; 
   std::cout << e << std::endl;
      
   return 0;   
}
