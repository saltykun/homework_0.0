// []运算符重载函数 - 用于取出第index个元素
T& operator[](int index) {
    return buf_[index];