#include <iostream>

int main()
{
    __int16 a3, a2, a1;
    __int16 b3, b2, b1;
    std::cout << "Enter numbers:\n";
    std::cin >> a3 >> a2 >> a1 >> b3 >> b2 >> b1;
    __int16 c3 = 0, c2 = 0, c1 = 0;
    __asm {
    mov ax, a1
    add ax, b1
    mov c1, ax

    mov ax, a2
    adc ax, b2
    mov c2, ax

    mov ax, a3
    adc ax, b3
    mov c3, ax
    }

    printf("a3 = %d\t a2 = %d\t a1 = %d\nb3 = %d\t b2 = %d\t b1 = %d\nc3 = %#x c2 = %#x c1 = %#x\n", a3, a2, a1, b3, b2, b1, c3, c2, c1);
    std::cout << (c3 << 32 | c2 << 16 | c1);
}