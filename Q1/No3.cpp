# include <iostream>
# include <vector>
# include <stdlib.h>
# include <time.h>

int main()
{
	srand((unsigned)time(NULL));
	std::vector<int> nums;
	
	for (int i = 0; i < 10; ++i)
	{
		nums.push_back(rand() % 9);
	}
	
	for (int i = 0; i < nums.size(); ++i)
	{
		std::cout << nums[i] << " ";
	}
	std::cout << std::endl;
	
	nums.push_back(rand() % 9);
	nums.push_back(rand() % 9);
	
	for (int i = 0; i < nums.size(); ++i)
	{
		std::cout << nums[i] << " ";
	}
	
	return 0;
}