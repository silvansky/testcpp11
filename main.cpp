#include <iostream>
#include <functional>
#include <vector>

auto getValues() -> std::initializer_list<int>
{
	return {67, 87, 233, 43, 22, 92, 3};
}

auto getF(int p) -> std::function<int (int)>
{
    return [=](int a){ return a * p; };
}

int main()
{
    auto x = 90;
    x++;
    auto f = [](int & b){ return b--; };
    std::cout << x << std::endl << [](int a, int b){ return a * b; }(6, 6) << std::endl;
    std::cout << f(x) << std::endl;
    std::cout << x << std::endl;
	auto g = getF(10);
	std::cout << g(5) << std::endl;
	
	std::vector<int> v = getValues();
	
	for (auto i : v)
	{
		std::cout << "v: " << i << std::endl;
	}
	
    return 0;
}