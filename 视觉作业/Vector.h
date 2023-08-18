#include <iostream>

template<typename T>
class Vector {
private:
    int size_;      // ʹ���»���������
    int capacity_;
    T* buf_;

public:
    // ���캯��
    Vector() : size_(0), capacity_(2), buf_(new T[2]) {}

    // ��������
    ~Vector() {
        delete[] buf_;
    }

    // �������캯��
    Vector(const Vector& x) : size_(x.size_), capacity_(x.capacity_), buf_(new T[x.capacity_]) {
        for (int i = 0; i < size_; i++) {
            buf_[i] = x.buf_[i];
        }
    }

    // ��ֵ��������غ���
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

    // []��������غ��� - ����ȡ����index��Ԫ��
    T& operator[](int index) {
        return buf_[index];
    }

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

    // ��Vector����β�����Ԫ��
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

    // ɾ��Vector�������һ��Ԫ��
    void pop_back() {
        size_--;
    }

    // ��ָ��λ�ò���Ԫ��
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

    // ɾ��ָ��λ�õ�Ԫ��
    void erase(int index) {
        size_--;
        for (int i = index; i < size_; i++) {
            buf_[i] = buf_[i + 1];
        }
    }

    // ��ȡVector����ĵ�һ��Ԫ��
    T front() {
        T temp = buf_[0];
        size_--;
        for (int i = 0; i < size_; i++) {
            buf_[i] = buf_[i + 1];
        }
        return temp;
    }

    // ��ȡVector��������һ��Ԫ��
    T back() {
        size_--;
        return buf_[size_];
    }

    // ��ȡVector�����Ԫ���׵�ַ�ĵ�����
    T* begin() {
        return buf_;
    }

    // ��ȡVector��������һ��Ԫ�ص���һ����ַ�ĵ�����
    T* end() {
        return buf_ + size_;
    }

    // ��ȡVector�����Ԫ�ظ���
    int size() const {
        return size_;
    }

    // ��ȡVector������������
    int capacity() const {
        return capacity_;
    }

    // �ж�Vector�����Ƿ�Ϊ��
    bool empty() const {
        return size_ == 0;
    }
};


