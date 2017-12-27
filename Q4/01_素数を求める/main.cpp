# include <iostream>
# include <algorithm>

int main()
{
    std::vector<int> integers;
    
    for (int i = 2; i < 1000; ++i)
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
    
    for (const auto& integer : integers)
    {
        std::cout << integer << std::endl;
    }
    
    return 0;
}