#include <iostream>
#include "memory.h"

class Test {
public:
    Test() { std::cout << "Test object created\n"; }
    ~Test() { std::cout << "Test object destroyed\n"; }
    void sayHello() { std::cout << "Hello from Test object\n"; }
};

// Custom implementation of default_delete
template <typename T>
struct test_deleter {
    void operator()(T* ptr) const {
        std::cout << "Deleter invoked\n";
        delete ptr;
    }
};

int main() {
    {
        // Specify the custom deleter type explicitly
        unique_ptr<Test, test_deleter<Test>> ptr1(new Test(), test_deleter<Test>());
        ptr1->sayHello();

        unique_ptr<Test, test_deleter<Test>> ptr2 = bbp::move(ptr1);
        if (!ptr1.get()) {
            std::cout << "ptr1 is now null\n";
        }
        ptr2->sayHello();

        unique_ptr<Test, test_deleter<Test>> ptr3;
        ptr3 = std::move(ptr2);
        if (!ptr2.get()) {
            std::cout << "ptr2 is now null\n";
        }
        ptr3->sayHello();

        // test make_unique
        auto ptr = bbp::make_unique<Test>();
        ptr->sayHello();

    } // ptr3 goes out of scope and the Test object is destroyed

    return 0;
}