#include <iostream>

int main() {
    __int32 size_of_array;
    std::cout << "Enter the size(0< size < 100) of array:";
    std::cin >> size_of_array;
    while (size_of_array > 100 || size_of_array <= 0) {
        std::cout << "Wrong size. Try again.\n";
        std::cout << "Enter the size(0< size < 100) of array:";
        std::cin >> size_of_array;
    }
    std::cout << "Enter the elements of array:\n";
    auto *array = new __int16[size_of_array];
    for (__int32 i = 0; i < size_of_array; i++) {
        std::cin >> array[i];
    }
    /*
     * for (array)
     * if array[i] < 0 сохр.
     * if array[j] >= 0 сохр.
     * поменять.
     * начинать с i+1 again
     *
     * mov ecx, size_of_array
    xor esi, esi
    _loop:
    mov eax, array[esi*2]
    cmp ax, 0
    jb _try_to_find_positive
    jmp _loop
    _try_to_find_positive:
    mov bx, ax; //ebx keep negative number
    inc esi
    mov edx, array[esi*2]
    cmp dx, 0
    inc count
    jae _if_found
    jmp _try_to_find_positive
    _if_found:
    mov temp, dx
    mov array[esi*2 - count], edx
    loop _loop*/
    __asm {
        xor esi, esi
        xor ecx, ecx
        mov ebp, array
    _loop:
        inc esi
        cmp esi, size_of_array
        je _end
        dec esi
        cmp byte ptr [ebp][esi*2], 0
        jb _find_negative
        jmp _loop
    _find_negative:
        mov eax, byte ptr [ebp][esi*2]
        inc esi
        cmp byte ptr [ebp][esi*2], 0
        jae _find_positive
        inc ecx
        jmp _find_negative
    _find_positive:
        mov edx, byte ptr [ebp][esi*2]; positive
        mov byte ptr [ebp][esi*2 - ecx], edx
        mov byte ptr [ebp][esi*2], eax
        inc esi
        jmp _loop
    _end:

    }

    delete[] array;
    return 0;
}
