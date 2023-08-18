// ¿½±´¹¹Ôìº¯Êý
Vector(const Vector& x) : size_(x.size_), capacity_(x.capacity_), buf_(new T[x.capacity_]) {
    for (int i = 0; i < size_; i++) {
        buf_[i] = x.buf_[i];
    }
}
