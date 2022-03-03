#include <iostream>
int DepthOfTheNumber(int number) {
    int depth = 0;
    _asm {
            mov eax, number; eax = number
            mov ebx, 10; ebx = 10
            mov ecx, 0
            step_d:
            cdq
            div ebx; eax /= 10
            inc ecx; ecx++
            cmp eax, 0; eax != 0
            jne step_d
            mov depth, ecx
    }
    return depth;
}

int main() {
    int number;
    std::cin >> number;
    std::cout << DepthOfTheNumber(number);
    return 0;
}