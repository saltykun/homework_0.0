// ==��������غ��� - �ж�����Vector�����Ƿ����
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