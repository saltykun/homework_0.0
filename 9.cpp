// 在指定位置插入元素
void insert(int index, T x) {
    size_++;
    if (size_ >= capacity_) {
        capacity_ *= 2;
    }

    T* buf2 = new T[capacity_];
    for (int i = 0; i < index; i++) {
        buf2[i] = buf_[i];
    }
    buf2[index] = x;
    for (int i = index + 1; i < size_; i++) {
        buf2[i] = buf_[i - 1];
    }

    delete[] buf_;
    buf_ = buf2;
}
