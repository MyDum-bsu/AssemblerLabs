#include <iostream>

int main() {
    int x = 22;
    int y = 2;
    int array_of_solutions[16];
    __asm {
        xor esi, esi
        mov eax, x
        mov ebx, y
    _loop:
        mov array_of_solutions[esi*4], eax
        inc esi
        mov array_of_solutions[esi*4], ebx
        inc esi
        add ebx, 2
        sub eax, 3
        jns _loop
    }
    for (int i = 0; i < 16; i += 2) {
        std::cout << "50 = " << "2 * " << array_of_solutions[i] << " + 3 * " << array_of_solutions[i + 1] << "\n";
    }
    return 0;
}

