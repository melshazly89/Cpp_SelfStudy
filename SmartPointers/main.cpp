#include <iostream>
#include <memory>
void foo(){
        int x = 5;
    std::shared_ptr<int> p3 = std::make_shared<int>(x);
    auto p4 = p3;
    std::cout << "P3 pointer Address:" << p3.get() << std::endl;
    std::cout << "P4 pointer Address:" << p4.get() << std::endl;
    std::cout << "refCount:" << p3.use_count() << std::endl;
    std::cout << "value" << *p3 << *p4 << std::endl;
}
int main()
{
    int *ptr = new int[3] {1,2,3};
    std::cout << "Address:" << ptr << ", Value:" << *ptr << std::endl;
    delete []ptr;
    ptr = NULL;
    std::cout << "Address:" << ptr << std::endl;

    /*Smart Pointers */
    std::unique_ptr<int> p = std::make_unique<int>();  /*Creates Entry in heap*/
    std::cout << "Address:" << p.get() << std::endl;
    *p =5;
    std::cout << "Address:" << p.get() << ",Value:" << *p << std::endl;

    std::unique_ptr<int>p1 = std::make_unique<int>();
    p1=std::move(p); /*unique pointers are movable*/
    std::cout << "Address:" << p1.get() << " " << p.get() << ",Value:" << *p1 << std::endl;
    //auto p3 = p1;  /*unique pointer not copyable*/


}