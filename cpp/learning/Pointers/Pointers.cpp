#include <iostream>

int main()
{
   int x {1};
   std::cout << "variable: "          << x     << std::endl;
   std::cout << "adress: "            << &x    << std::endl;
   std::cout << "value from adress: " << *(&x) << std::endl;
   
   int* ptr_x { &x };
   std::cout <<  ptr_x << std::endl;
   std::cout << *ptr_x << std::endl;
   std::cout << &ptr_x << std::endl;
   
   
   int a {1};
   int& b{a};
   b = 0;
   std::cout << a << std::endl;
   a = 1;
   std::cout << b << std::endl;

   return 0;
};

/*
struct Person
{
    int age{};
    double weight{};
};
Person person{};

// Member selection using pointer to struct
Person* ptr{ &person };
ptr->age = 5;
//(*ptr.age) = 5;
*/

