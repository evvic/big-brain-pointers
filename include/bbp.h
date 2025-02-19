#ifndef BBP_H
#define BBP_H

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

/**
 *  @brief  Custom implementation of move - convert a value to an rvalue.
 *  @param  t  A thing of arbitrary type.
 *  @return The parameter cast to an rvalue-reference to allow moving it.
*/
template <typename T>
constexpr typename remove_reference<T>::type&&
move(T&& t) noexcept {
    return static_cast<typename remove_reference<T>::type&&>(t);
}

/**
 *  @brief  Replaces the value of an object with a new value and returns the old value.
 *  @param  obj  The object whose value will be replaced.
 *  @param  new_value  The new value to assign to obj.
 *  @return The old value of obj.
*/
template <typename T>
constexpr T exchange(T& obj, T&& new_value) {
    T old_value = bbp::move(obj);
    obj = bbp::move(new_value);
    return old_value;
}

// /***************************************
//  * BIG BRAIN POINTER FACTORY FUNCTIONS *
//  ***************************************/

// /**
//  *  @brief  Custom implementation of make_unique - create a unique_ptr.
//  *  @param  args  Arguments to pass to the constructor of T.
//  *  @return A unique_ptr that owns and manages a new object of type T.
// */
// template <typename T, typename... Args>
// unique_ptr<T> make_unique(Args&&... args) {
//     return unique_ptr<T>(new T(bbp::forward<Args>(args)...));
// }

} // namespace bbp

#endif // BBP_H