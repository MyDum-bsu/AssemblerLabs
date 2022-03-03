#include <iostream>

bool IsPositiveNumber(int number) {
    int rez{};
    _asm {
            mov eax, number
            shr eax, 31
            ;//test eax, 1
            mov rez, eax
    }
    return (1 - rez);
}

int main() {
    int n;
    std::cin >> n;
    std::cout << IsPositiveNumber(n);
    return 0;
}
