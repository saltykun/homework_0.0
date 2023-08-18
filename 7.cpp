// 向Vector对象尾部添加元素
void push_back(T x) {
    if (size_ >= capacity_) {
        capacity_ *= 2;
        T* buf2 = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            buf2[i] = buf_[i];
        }
        buf2[size_] = x;
        delete[] buf_;
        buf_ = buf2;
    }
    else {
        buf_[size_] = x;
    }
    size_++;
}
