// ɾ��ָ��λ�õ�Ԫ��
void erase(int index) {
    size_--;
    for (int i = index; i < size_; i++) {
        buf_[i] = buf_[i + 1];
    }
}