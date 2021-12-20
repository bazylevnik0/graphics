#include <iostream>

int main ()
{
   struct Obj
   {
      int id{};
      char s{};
   };
   
   Obj somebody{1,'a'};
   std::cout << somebody.id << " " << somebody.s << std::endl;
   somebody.s = 'b';
   std::cout << somebody.id << " " << somebody.s << std::endl;
   return 0;
}
