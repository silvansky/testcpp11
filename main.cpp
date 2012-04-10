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

struct mynum {
	int a;
	double b;
};

mynum operator "" _num(unsigned long long x)
{
	mynum mn;
	mn.a = x;
	mn.b = x / 100.0;
	return mn;
}

mynum operator "" _num(long double x)
{
	mynum mn;
	mn.a = x * 100;
	mn.b = x;
	return mn;
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
	
	mynum m = 87_num;
	
	std::cout << m.a << " -- " << m.b << std::endl;
	
	m = 0.97_num;
	
	std::cout << m.a << " -- " << m.b << std::endl;
	
    return 0;
}