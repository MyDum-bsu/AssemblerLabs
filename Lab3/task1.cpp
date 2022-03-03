#include <iostream>
#include <cmath>

int CalculateTask1(int a) {
    int result{};
    _asm{
            mov eax, a
            add result, eax; result = a
            mul eax; eax = a ^ 2
            mul eax; eax = a ^ 4
            mov ebx, eax; ebx = a ^ 4
            mul eax; eax = a ^ 8
            add result, eax; result = a ^ 8 + a
            mul ebx; eax = a ^ 12
            add result, eax; result = a ^ 12 + a ^ 8 + a

    }
    return result;
}

int main() {
    int a;
    std::cin >> a;
    std::cout << "C++: " <<pow(a, 12) + pow(a, 8) + a << "\n\n\n";
    std::cout << "ASSembler: "<< CalculateTask1(a);
}