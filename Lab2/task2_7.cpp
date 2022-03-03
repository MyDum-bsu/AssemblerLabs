#include <iostream>
int CalculateTask2_7(int n, int m) {
    int result = 0;
    _asm {
            mov ecx, m; ecx = m
            mov eax, n; eax = n
            mov ebx, 10; ebx = 10
            _step:
            cdq; edx = 0
            div ebx; eax = n / 10
            add result, edx; result += n % 10
            loop _step
    }
    return result;
}

int main() {
    std::cout << "Enter the numbers to calculate task 2.7\n";
    int n;
    int m;
    std::cin >> n;
    std::cin >> m;
    int r = n;
    int result = 0;
    for (int i = 0; i < m; i++) {
        result += r % 10;
        r /= 10;
    }
    std::cout << "task2.7\nC++: " << result;
    std::cout << "\nASSembler: " << CalculateTask2_7(n, m) << "\n\n\n";
    return 0;
}