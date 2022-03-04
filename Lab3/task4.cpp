#include <iostream>


int gcd(int a, int b) {
    int first = abs(a);
    int second = abs(b);
    int rez = 0;
    __asm{
        mov eax, first
        mov ebx, second
    _base:
        cmp eax, 0
        jne _step1
        jmp _out
    _step1:
        cmp ebx, 0
        jne _step2
        jmp _out
    _step2:
        cmp eax, ebx
        ja _step3_1
        jmp _step3_2
    _step3_1:
        cdq
        div ebx; eax /= ebx
        mov eax, edx; eax %= ebx
        jmp _base
    _step3_2:
        mov ecx, eax
        mov eax, ebx; eax = second
        mov ebx, ecx; ebx = first
        cdq
        div ebx
        mov eax, edx;  second = second % first
        mov ecx, eax
        mov eax, ebx
        mov ebx, ecx
        jmp _base
    _out:
        add eax, ebx
        mov rez, eax
    }
    return rez;
}

int main() {
    int n;
    int d;
    std::cout <<  " Numerator = ";
    std::cin >> n;
    std::cout << "Denominator = ";
    label:
    std::cin >> d;
    if (d == 0) {
        std::cout << "division by zero\nTry again. Denominator = ";
        goto label; 
    }
    int numerator = abs(n);
    int denominator = abs(d);
    int reduction = gcd(numerator, denominator);
    __asm {
        mov eax, numerator
        mov ebx, reduction
        cdq
        div ebx
        mov numerator, eax

        mov eax, denominator
        cdq
        div ebx
        mov denominator, eax
    }
    if (denominator == 1) {
        std::cout << (((n * d) >= 0) ? " " : "-") << numerator << "\n";
    } else {
    std::cout << (((n * d) > 0) ? " " : "-") << numerator << "/" << denominator << "\n"; }
    return 0;
}