#include <iostream>
#include <iomanip>

extern "C" void _cdecl task2 (double* result, int* percision);
extern "C" void _cdecl task3(double* result, int* percision);
extern "C" void _cdecl task5(double* x, double* result);
void task2b() {
	std::cout << "Task2b: Pi calculation\n";
	double* pi = new double(0);
	int* percision = new int[3];
	percision[0] = 0;
	percision[1] = 0;
	percision[2] = 0;
	task2(pi, percision);
	std::cout << "Pi aprocsimation is " << std::setprecision(12) << *pi
		<< std::endl;
	std::cout << "Series members required to get 5 digits is " << percision[0]
		<< std::endl;
	std::cout << "Series members required to get 7 digits is " << percision[1]
		<< std::endl;
	std::cout << "Series members required to get 9 digits is " << percision[2]
		<< std::endl;
}

void task3A() {
	std::cout << "\nTask3 Ln2 calculation\n";
	double* ln2 = new double(0.0);
	int* percision1 = new int[3];
	percision1[0] = 0;
	percision1[1] = 0;
	percision1[2] = 0;
	task3(ln2, percision1);
	std::cout << "Ln2 aprocsimation is " << std::setprecision(12) << *ln2
		<< std::endl;
	std::cout << "Series members required to get 5 digits is " << percision1[0]
		<< std::endl;
	std::cout << "Series members required to get 7 digits is " << percision1[1]
		<< std::endl;
	std::cout << "Series members required to get 9 digits is " << percision1[2]
		<< std::endl;
}

int main()
{	
	task2b();
	task3A();
	double x = 2.5;
	double result{};
	task5(&x, &result);
	std::cout << result;
	return 0;
}
