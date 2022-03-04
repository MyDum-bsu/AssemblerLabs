#include <iostream>

int CalculateTask1_1(int x) {
    int result = 0;
    __asm{
            mov eax, x
            imul x
            imul x
            mov ebx, eax

            mov eax, ebx
            imul x
            imul x
            add result, eax
            mov eax, 2
            imul x
            imul x
            sub eax, 8
            add eax, x
            add eax, result

            cdq
            idiv ebx

            mov result, eax
    }
    return result;
}

int main() {
    std::cout << "Enter the number to calculate task1.1\n";
    int x;
    std::cin >> x;
    std::cout << "task1.1\nC++: " << (x * x * x * x * x + 2 * (x * x - 4) + x) / (x * x * x);
    std::cout << "\nASSembler: " << CalculateTask1_1(x) << "\n\n\n";
    return 0;
}