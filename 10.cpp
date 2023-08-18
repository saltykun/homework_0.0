// 删除指定位置的元素
void erase(int index) {
    size_--;
    for (int i = index; i < size_; i++) {
        buf_[i] = buf_[i + 1];
    }
}