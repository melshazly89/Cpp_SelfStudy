#include <iostream>
#include <exception>
template <class T>
class MySmartPointer
{
    public :
    T* M_ptr;
    MySmartPointer(T* ptr = nullptr):M_ptr(ptr)
    {
        std::cout << "Constructor " << std::endl;
    }
    ~MySmartPointer()
    {
        delete M_ptr;
        std::cout << "Free" << std::endl;
    }
    T& operator*()
    {
        if (nullptr != this->M_ptr)
        {
            return *(this->M_ptr);
        }
        else
        {
            throw std::runtime_error("Cannot dereference null ptr");
        }
    }
    /*return Pointer value*/
    T* get()
    {
        return (this->M_ptr);
    }
    /*Move Ownership*/
    MySmartPointer (MySmartPointer&& other) noexcept
    {
        M_ptr = other.M_ptr;
        other.M_ptr = nullptr;
    }
    /*Prevent Copying Constructor*/
    MySmartPointer(const MySmartPointer&) = delete;
    MySmartPointer& operator=(const MySmartPointer&) = delete;


};
int main()
{
    /*Create a variable in heap ,and make smart pointer points to it*/
    MySmartPointer<int> p1(new int(5));
    std::cout << p1.get()<< std::endl;
    std::cout << *p1 << std::endl;

    MySmartPointer<int> p2(std::move(p1));
    // std::cout << p1.get() << " " << *p1<< std::endl;

    MySmartPointer<std::string> p3(new std::string("Mahmoud"));
    std::cout << p3.get()<< std::endl;
    std::cout << *p3 << std::endl;
    std::cout << &p3 << std::endl;


}