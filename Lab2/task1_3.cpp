#include <iostream>
int CalculateTask1_3(int x) {
    int result = 0;
    _asm {
            mov eax, x; eax = x
            mov ebx, 4; ebx = 4
            imul ebx; eax = 4x
            sub eax, 1; eax = 4x - 1
            mov ebx, eax; ebx = 4x - 1
            add ebx, 2; ebx = 4x + 1
            imul ebx; eax = (4x - 1) * (4x + 1)
            mov ebx, 4; ebx = 4
            cdq
            idiv ebx; eax = (4x - 1) * (4x + 1) / 4
            mov result, eax; result = (4x - 1) * (4x + 1) / 4
    }
    return result;
}

int main() {
    std::cout << "Enter the number to calculate task1.3\n";
    int x;
    std::cin >> x;
    std::cout << "task1.3\nC++: " << (4 * x - 1) * (4 * x + 1) / 4;
    std::cout << "\nASSembler: " << CalculateTask1_3(x) << "\n\n\n";
    return 0;
}