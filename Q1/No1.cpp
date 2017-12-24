# include <iostream>
# include <string>
# include <stdio.h>

std::string toFizzBuzz(int value)
{
	if (value % 15 == 0)
	{
		return "FizzBuzz";
	}
	else if (value % 5 == 0)
	{
		return "Buzz";
	}
	else if (value % 3 == 0)
	{
		return "Fizz";
	}
	else
	{
		// なぜかstd::to_stringが使えなかったので。
		// 普通はto_stringで良いと思います。
		char integer[3] = {'\0'};
		sprintf(integer, "%d", value);
		return integer;
	}
}

int main()
{
	for (int i = 1; i <= 50; ++i)
	{
		std::cout << toFizzBuzz(i) << " ";
	}
	
	return 0;
}