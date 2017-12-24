# include <iostream>
# include <algorithm>
# include <vector>

int FindPrimeNumber(std::vector<int>& primeNumbers, int max = 1000)
{
	std::vector<int> integers;
	
	for (int i = 2; i <= max; ++i)
	{
		integers.push_back(i);
	}
	
	
	for (int i = 0; i < integers.size(); ++i)
	{
		auto rmvIter = std::remove_if(integers.begin()+i+1,integers.end(),
			[&](int num){
				return (num % integers[i]) == 0;
			}
		);
		
		integers.erase(rmvIter, integers.end());
	}
	
	primeNumbers = integers;
	
	return 0;
}

int main()
{
	int value = 0;
	std::cout << "‘fˆö”•ª‰ð‚µ‚½‚¢”Žš‚ð“ü—Í -> ";
	std::cin >> value;
	
	std::vector<int> primeNumbers;
	FindPrimeNumber(primeNumbers, 10000);
	
	std::vector<int> primeFactors;
	
	const int primeNumbersSize = primeNumbers.size();
	for (int i = 0; i < primeNumbersSize; ++i)
	{
		if (value % primeNumbers[i] == 0)
		{
			value /= primeNumbers[i];
			primeFactors.push_back(primeNumbers[i]);
			--i;
		}
	}
	
	for(int i = 0; i < primeFactors.size(); ++i)
	{
		std::cout << primeFactors[i] << " ";
	}
	
	return 0;
}
