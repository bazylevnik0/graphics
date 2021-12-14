#include <iostream>

int main() 
{
   int outer{5};
   while (outer > 0)
   {
      int inner{0};
      int add {5};
      add = add - outer;
      while (add > 0)
      {
        std::cout << " ";
        --add;
      }
      while (inner < outer)
      {
        std::cout << ".";
        ++inner;
      }
      
      std::cout << "\n";
      --outer;
   }
   std::cout << std::endl;;
   
   return 0;
}
