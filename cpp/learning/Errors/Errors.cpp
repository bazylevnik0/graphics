#include <cassert> 
#include <iostream>
#define CONST 1

int badFoo() 
{
  std::abort();
}

int goodFoo()
{
  return 1;
}

int main()
{
	int num{0};
	std::cin >> num;
  	std::cerr << num;
	static_assert(CONST == 1, "!=1");
	assert(num == 1);
	if (num) 
		std::cout << goodFoo();
	return 0;
}
