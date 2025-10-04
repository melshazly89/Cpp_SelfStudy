#include <iostream>
#include <stdexcept>

class MyException:public std::exception
{
    public:
    std::string message;
    MyException(const std::string& msg):message(msg)
    {};
    const char*what() const noexcept override{return message.c_str();}
};
void funcB()
{
    try
    {
        throw MyException("Runtime Error");
    }
    catch(const MyException& e)
    {
        std::cout << "Caught Exception in function B:" << e.what() << std::endl;
        std::cout << "Rethrowing Exception Caught by the caller:" << e.what() << std::endl;
        throw;
    }
}
void funcA()
{
    try
    {
        funcB();
    }
    catch(const MyException e)
    {
        std::cout << "Caught Exception in function A:" << e.what() << std::endl;
    }
}
int main()
{
    try
    {
        funcA();
    }
    catch(const MyException& e)
    {
        std::cout << "Caught Exception in main:" << e.what() << std::endl;
    }
}