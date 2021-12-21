#include <iostream>

int main()
{
	int arr[10]{0,1,2,3,4,5,6,7,8,9};
	
	int num{0};
      goCin:
        std::cout << "Enter num [0-9]: ";
        std::cin.clear();
	std::cin >> num;
	if ((num < 0) || (num > 9))
      		goto goCin;
      		
      	int answer{0};
      	for (int i {0}; i < 10; i++)
      	{
      		std::cout << arr[i];
      		if( num == arr[i]) answer = i + 1;
      	} 
      		std::cout << answer;
      	
      	return 0;
}
