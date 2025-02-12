#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

template <typename T>
class unique_ptr {
public:
    explicit unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}
    ~unique_ptr() { delete ptr_; }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    unique_ptr(unique_ptr&& other) noexcept : ptr_(other.ptr_) { other.ptr_ = nullptr; }
    unique_ptr& operator=(unique_ptr&& other) noexcept {
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
    // relinquishes ownership of the managed object without deleting it
    T* release() {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }
    // releases the ownership of the currently managed object (if any), 
    // deletes it using the associated deleter,
    // and then takes ownership of a new object, if provided
    void reset(T* ptr = nullptr) {
        delete ptr_;
        ptr_ = ptr;
    }

private:
    T* ptr_;
};

#endif // UNIQUE_POINTER_H
