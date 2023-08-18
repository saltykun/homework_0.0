#include <iostream>
#include "Vector.h"  

int main() {
    Vector<int> numbers;  

    // ��Vector�����Ԫ��
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // ���Vector������
    std::cout << "Vector contents: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ɾ�����һ��Ԫ��
    numbers.pop_back();

    // ����޸ĺ��Vector������
    std::cout << "Vector contents after pop_back: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ����Ԫ��
    numbers.insert(2, 5);

    // ����޸ĺ��Vector������
    std::cout << "Vector contents after insert: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // ɾ��ָ��λ�õ�Ԫ��
    numbers.erase(0);

    // ����޸ĺ��Vector������
    std::cout << "Vector contents after erase: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
