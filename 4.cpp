// 赋值运算符重载函数
Vector& operator=(Vector x) {
    if (this == &x) {
        return *this;
    }

    delete[] buf_;
    size_ = x.size_;
    capacity_ = x.capacity_;
    buf_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        buf_[i] = x.buf_[i];
    }
    return *this;
}