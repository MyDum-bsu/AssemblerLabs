#include <iostream>

int main() {
    int fib_array[47];
    int count{};
    __asm {
        xor ecx, ecx
        xor esi, esi
        mov eax, 0
        mov ebx, 1

        mov fib_array[esi*4], eax
        inc esi
        inc ecx
    _loop:
        mov fib_array[esi*4], ebx
        inc esi
        inc ecx
        mov edx, eax; edx = a
        mov eax, ebx; //eax = b
        add edx, eax; edx = a + b
        mov ebx, edx; //ebx = a + b
        jno _loop
        mov count, ecx
    }
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << "\t" << fib_array[i] << "\n";
    }
    return 0;
}
