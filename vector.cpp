#include <iostream>
#include "Vector.h"  

int main() {
    Vector<int> numbers;  

    // 向Vector中添加元素
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // 输出Vector的内容
    std::cout << "Vector contents: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 删除最后一个元素
    numbers.pop_back();

    // 输出修改后的Vector的内容
    std::cout << "Vector contents after pop_back: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 插入元素
    numbers.insert(2, 5);

    // 输出修改后的Vector的内容
    std::cout << "Vector contents after insert: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 删除指定位置的元素
    numbers.erase(0);

    // 输出修改后的Vector的内容
    std::cout << "Vector contents after erase: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
