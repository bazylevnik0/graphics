#include <iostream>
//with constructor & destructor
int main()
{
   class Object 
   {
      private:
         int id {};
         std::string name{};
      public:
         Object (int in_id , std::string in_name) 
         {
            id = in_id;
            name = in_name;
         }
         
         ~Object ()
         {
            id = 0;
            name = "";
            std::cout << "deleted" << std::endl;
         }
         void print () 
         {
            std::cout << id << " " << name << " " << std::endl;
         }
   };
   
   Object* a = new Object { 1 , "a"};
   a->print();
   
   delete a;
   return 0;

}

/*
//with constructor
int main()
{
   class Object 
   {
      private:
         int id {};
         std::string name{};
      public:
         Object (int in_id , std::string in_name) 
         {
            id = in_id;
            name = in_name;
         }
         void print () 
         {
            std::cout << id << " " << name << " " << std::endl;
         }
   };
   
   Object a { 1 , "a"};
   a.print();
   
   return 0;

}
*/
/* simple
int main()
{
   class Object 
   {
      //private:
         int secret {8};
      public:
         int id{};
         std::string name {};
         void set (int in_id , std::string in_name)
         {
            id = in_id;
            name = in_name;
         }
         void print () 
         {
            std::cout << id << " " << name << " " << secret << std::endl;
         }
   };
   
   Object a;
   a.set( 1 , "a");
   a.print();
   
   return 0;

}

*/
