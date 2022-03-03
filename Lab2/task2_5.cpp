#include <iostream>
int AmountOf_1_InBinaryForm(int number) {
    int result = 0;
    _asm {
            mov eax, number
            xor ecx, ecx
            shl eax, 1
            _loop:
            shr eax, 1
            cmp eax, 0
            jz _out
            test eax, 1
            jz _loop
            inc ecx
            jmp _loop
            _out :
            mov result, ecx

    }
    return result;
}
int main() {
    std::cout << "Enter the numbers to calculate task 2.5\n";
    int number;
    std::cin >> number;
    std::cout << "task2.5\nASSembler: " << AmountOf_1_InBinaryForm(number);
    return 0;
}