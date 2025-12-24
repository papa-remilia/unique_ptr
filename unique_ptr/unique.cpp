#include <iostream>
#include <utility> 
template <typename T>
class unique_ptr {
private:
    T* ptr;
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;
public:
    // 构造
    unique_ptr(T* p = nullptr) : ptr(p) {}

    // 移动构造
    unique_ptr(unique_ptr&& other) {
        ptr = other.ptr;
        other.ptr = nullptr;
    }

    // 移动赋值操作符
    unique_ptr& operator=(unique_ptr&& other) {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    ~unique_ptr() {
        delete ptr;
    }


    T* get() const {
        return ptr;
    }

    T& operator*() const {
        return *ptr;
    }

    T* operator->() const {
        return ptr;
    }


};
