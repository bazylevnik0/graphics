#include <iostream>
struct Monster
{
   int type   {};
   int name   {};
   int health {};
};
//enum class!
enum type {
	ork,
	human,
};

enum name {
	maksim,
	jesika,
};

void print ( Monster obj )
{
   std::string type_out{};
   switch (obj.type) 
   {
      case ork :  
      	type_out = "Ork";
      	break;
      case human :
        type_out = "Human";
        break;
   };
   std::string name_out{};
   switch (obj.name) 
   {
      case maksim :  
      	name_out = "Maksim";
      	break;
      case human :
        name_out = "Jesica";
        break;
   };
   std::cout << type_out << " " << name_out << " " << obj.health << std::endl;
};

int main() 
{
   Monster first {1,1,100};
   Monster second {0,1,100};
   print(first);
   print(second);
   return 0;
};
