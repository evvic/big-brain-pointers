#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template <typename T>
class UniquePointer {
public:
    explicit UniquePointer(T* ptr = nullptr) : ptr_(ptr) {}
    ~UniquePointer() { delete ptr_; }

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other) noexcept : ptr_(other.ptr_) { other.ptr_ = nullptr; }
    UniquePointer& operator=(UniquePointer&& other) noexcept {
        if (this != &other) {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    T& operator*() const { return *ptr_; }
    T* operator->() const { return ptr_; }
    T* get() const { return ptr_; }
    T* release() {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }
    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

private:
    T* ptr_;
};

#endif // UNIQUE_POINTER_H
