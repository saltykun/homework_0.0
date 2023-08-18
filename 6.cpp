// ==运算符重载函数 - 判断两个Vector对象是否相等
bool operator==(const Vector& x) const {
    if (size_ != x.size_) {
        return false;
    }
    for (int i = 0; i < size_; i++) {
        if (buf_[i] != x.buf_[i]) {
            return false;
        }
    }
    return true;
}