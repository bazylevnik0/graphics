#include "io.h"

int main()
{
   int numA{0},numB{0};
   numA = readNumber();
   numB = readNumber();
   
   int answer{numA + numB};
   writeNumber(answer);
   return 0;
}
