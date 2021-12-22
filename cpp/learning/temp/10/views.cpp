#include <iostream>
#include <string>
#include <string_view>

int main()
{
   std::cout << "change text:" << std::endl;
   std::string text{"text"};
   std::cout << text << std::endl;
   text[0] = 'k';
   std::cout << text << std::endl;
 
   std::cout << "change view, check text:" << std::endl;
   std::string_view view{text};	   
   std::cout << view << std::endl;
   view[0] = 'l';
   std::cout << text << std::endl;  
   std::cout << view << std::endl;
 
   return 0;
}
