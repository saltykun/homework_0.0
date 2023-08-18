#include <iostream>

template<typename T>
class Vector {
private:
    int size_;      
    int capacity_;
    T* buf_;

public:
    // 构造函数
    Vector() : size_(0), capacity_(2), buf_(new T[2]) {}

    // 析构函数
    ~Vector() {
        delete[] buf_;
    }

    // 拷贝构造函数
    Vector(const Vector& x) : size_(x.size_), capacity_(x.capacity_), buf_(new T[x.capacity_]) {
        for (int i = 0; i < size_; i++) {
            buf_[i] = x.buf_[i];
        }
    }

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

    // []运算符重载函数 - 用于取出第index个元素
    T& operator[](int index) {
        return buf_[index];
    }

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

    // 删除Vector对象最后一个元素
    void pop_back() {
        size_--;
    }

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

    // 删除指定位置的元素
    void erase(int index) {
        size_--;
        for (int i = index; i < size_; i++) {
            buf_[i] = buf_[i + 1];
        }
    }

    // 获取Vector对象的第一个元素
    T front() {
        T temp = buf_[0];
        size_--;
        for (int i = 0; i < size_; i++) {
            buf_[i] = buf_[i + 1];
        }
        return temp;
    }

    // 获取Vector对象的最后一个元素
    T back() {
        size_--;
        return buf_[size_];
    }

    // 获取Vector对象的元素首地址的迭代器
    T* begin() {
        return buf_;
    }

    // 获取Vector对象的最后一个元素的下一个地址的迭代器
    T* end() {
        return buf_ + size_;
    }

    // 获取Vector对象的元素个数
    int size() const {
        return size_;
    }

    // 获取Vector对象的最大容量
    int capacity() const {
        return capacity_;
    }

    // 判断Vector对象是否为空
    bool empty() const {
        return size_ == 0;
    }
};


