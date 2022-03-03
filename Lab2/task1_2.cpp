#include <iostream>

int CalculateTask1_2(int x) {
    int result = 0;
    _asm {
            mov eax, 2; eax = 2
            mov ebx, x; ebx = x
            imul ebx; eax = 2x
            sub eax, 1; eax = 2x - 1

            add ebx, 3; ebx = x + 3
            imul ebx; eax = (2x - 1) * (x + 3)
            sub ebx, 2; ebx = x + 1
            add ebx, x; ebx = 2x + 1
            imul ebx;  eax = (2x - 1) * (x + 3) * (2x + 1)

            sub ebx, 1; ebx = 2x
            cdq
            idiv ebx; (2x - 1)* (x + 3)* (2x + 1) / (2x)
            mov result, eax; result = (2x - 1) * (x + 3) * (2x + 1) / (2x)
    }
    return result;
}

int main() {
    std::cout << "Enter the number to calculate task1.2\n";
    int x;
    std::cin >> x;
    std::cout << "task1.2\nC++: " << (2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x);
    std::cout << "\nASSembler: " << CalculateTask1_2(x) << "\n\n\n";
    return 0;
}