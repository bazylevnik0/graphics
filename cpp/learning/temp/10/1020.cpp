#include <iostream>

int main()
{
   std::string names [] {"Asd" , "Asdas", "Fsdada" , "Wwrqwr" , "Hdfdsfsdf"};
   
   for (std::string_view name : names)
   {
      std::cout << name <<"\n";
   } 
   
   std::string ask{""};   
   std::cin >> ask;
   for (std::string_view name : names)
   {
      if (name == ask)
            std::cout << "match" << std::endl;
   } 
   
     
   return 0;
}
