#include <iostream>
#include <functional>
#include <vector>
#include <tuple>

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

void sep(const char * info)
{
	std::cout << std::endl << "------------------------------------------";
	std::cout << std::endl << info << std::endl << std::endl;
}

int main()
{
	const char * welcomeText = 
		"*************************************\n"
		"* Simple C++11 feature testing app. *\n"
		"*************************************\n";
	std::cout << std::endl << welcomeText << std::endl;
	sep("Auto. Lambdas.");
	
    auto x = 90;
    x++;
    auto f = [](int & b){ return b--; };
    std::cout << x << std::endl << [](int a, int b){ return a * b; }(6, 6) << std::endl;
    std::cout << f(x) << std::endl;
    std::cout << x << std::endl;
	auto g = getF(10);
	std::cout << g(5) << std::endl;
	
	sep("Initializer list. For (:).");
	
	std::vector<int> v = getValues();
	
	for (auto i : v)
	{
		std::cout << "v: " << i << std::endl;
	}
	
	sep("Custom suffix.");
	
	mynum m = 87_num;
	
	std::cout << m.a << " -- " << m.b << std::endl;
	
	m = 0.97_num;
	
	std::cout << m.a << " -- " << m.b << std::endl;
	
	sep("Tuples.");
	
	auto myTuple = std::tuple<int, int, double, std::string>(0, 67, 0.54, "cool");
	
	std::cout << std::get<3>(myTuple) << std::endl;
	
    return 0;
}
