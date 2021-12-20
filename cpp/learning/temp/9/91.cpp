#include <iostream>
  struct Ad 
   {
     int views      {};
     int percents   {};
     double average {};
   };
void compute ( Ad obj )
{
   std::cout << obj.views * obj.percents * obj.average << std::endl;
};

Ad getAd (  ) {
	Ad obj {};
	std::cin >> obj.views >> obj.percents >> obj.average;
	return obj;
}
int main() 
{
 
   Ad anon {2,14,10.5};
   compute(getAd());
   return 0;
};
