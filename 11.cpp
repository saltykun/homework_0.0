// ��ȡVector����ĵ�һ��Ԫ��
T front() {
    T temp = buf_[0];
    size_--;
    for (int i = 0; i < size_; i++) {
        buf_[i] = buf_[i + 1];
    }
    return temp;
}