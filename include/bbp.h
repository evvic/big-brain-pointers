#ifndef BBP_H
#define BBP_H

#include "unique_ptr.h"

// big brain pointers
namespace bbp {

// remove_reference type trait
template <typename T>
struct remove_reference {
    using type = T;
};

template <typename T>
struct remove_reference<T&> {
    using type = T;
};

template <typename T>
struct remove_reference<T&&> {
    using type = T;
};

// forward function template
template <typename T>
T&& forward(typename remove_reference<T>::type& t) noexcept {
    return static_cast<T&&>(t);
}

template <typename T>
T&& forward(typename remove_reference<T>::type&& t) noexcept {
    return static_cast<T&&>(t);
}

// make_unique function template
template <typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args) {
    return unique_ptr<T>(new T(bbp::forward<Args>(args)...));
}

}

#endif // BBP_H