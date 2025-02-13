#ifndef UNIQUE_POINTER_H
#define UNIQUE_POINTER_H

#include "bbp.h"

// Custom implementation of default_delete
template <typename T>
struct default_delete {
    void operator()(T* ptr) const {
        delete ptr;
    }
};

template <typename T, typename Deleter = default_delete<T>>
class unique_ptr {
public:
    /**
     *  @brief  Constructor - creates a unique_ptr that manages a pointer.
     *  @return void.
     */
    explicit unique_ptr(T* ptr = nullptr, Deleter deleter = Deleter()) 
        : ptr_(ptr), deleter_(deleter) {}

    /**
     *  @brief  Destructor - calls the deleter on the managed object.
     *  @return void.
     */
    ~unique_ptr() { deleter_(ptr_); }

    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    /**
     *  @brief  Move constructor.
     *  @param  other  another unique_ptr to move from.
     *  @return a new unique_ptr that takes ownership of the other unique_ptr.
     */
    unique_ptr(unique_ptr&& other) noexcept 
        : ptr_(other.ptr_), deleter_(std::move(other.deleter_))
    {
        other.ptr_ = nullptr;
    }

    /**
     *  @brief  Move assignment operator.
     *  @param  other  another unique_ptr to move from.
     *  @return a reference to this unique_ptr.
     */
    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        if (this != &other) {
            deleter_(ptr_);
            ptr_ = other.ptr_;
            deleter_ = std::move(other.deleter_);
            other.ptr_ = nullptr;
        }
        return *this;
    }

    /**
     *  @brief  Dereference operator.
     *  @return a reference to the managed object.
     */
    T& operator*() const { return *ptr_; }

    /**
     *  @brief  Member access operator.
     *  @return a pointer to the managed object.
     */
    T* operator->() const { return ptr_; }

    /**
     *  @brief  Get the managed object.
     *  @return a pointer to the managed object.
     */
    T* get() const { return ptr_; }

    /**
     *  @brief  Release the ownership of the managed object without deleting it.
     *  @return a pointer to the managed object.
     */
    T* release() 
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    /**
     *  @brief  Reset the managed object - release the ownership of the 
     *          current object and take ownership of a new object, if provided.
     *  @param  ptr  a pointer to the new object to manage (optional).
     *  @return void.
     */
    void reset(T* ptr = nullptr) 
    {
        deleter_(ptr_);
        ptr_ = ptr;
    }

private:
    T* ptr_;
    Deleter deleter_;
};

#endif // UNIQUE_POINTER_H