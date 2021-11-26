#include <iostream>
#define MACRO "TEXT"
#define LOG_TRUE

int main()
{
   std::cout << MACRO;

   using namespace std;
   cout << MACRO << endl;
   
   #ifdef LOG_TRUE
   cout << "LOG_TRUE" << endl;
   #endif
   #ifndef LOG_FALSE
   cout << "LOG_FALSE" << endl;
   #endif
       
   return 0;
}
