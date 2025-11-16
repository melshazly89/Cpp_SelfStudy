#include <iostream>
#include <algorithm>

class EnhancedString : public std::string
{
    public:
    /*Inherit constructors from std::string*/
    using std::string::string;
    void reverse()
    {
        std::reverse(this->begin(),this->end());
    }
    void toUpper()
    {
        /*Transform is STL Library Function used to apply certain operation on vectors*/
        std::transform(this->begin(),this->end(),this->begin(),::toupper);
    }
    void toLower()
    {
        /*Transform is STL Library Function used to apply certain operation on vectors*/
        std::transform(this->begin(),this->end(),this->begin(),::tolower);
    }
    

};

int main()
{
    EnhancedString str("Hello World!");
    std::cout << str <<std::endl;
    str.reverse();
    std::cout << str << std::endl;
    str.reverse();
    str.toUpper();
    std::cout << str << std::endl;
    str.toLower();
    std::cout << str << std::endl;

}