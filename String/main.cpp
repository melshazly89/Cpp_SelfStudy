#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

class String{
    private:
        char* m_data;
    public:
        String(char* data):m_data(data)    
        {
            //std::cout<<"Constructor called!"<<std::endl;
            this->m_data = new char [strlen(data)+1];
            strcpy(m_data,data);
        }
        void display()
        {
            std::cout<<"Result:" <<m_data<<std::endl;
        }
        void setchar(char value)
        {
            *m_data = value;
        }
        String(const String& other) // Copy Constructor
        {
            //std::cout<<"Copy Constructor called!"<<std::endl;
            //deep copy
            m_data = new char [strlen(other.m_data)+1];
            strcpy(m_data,other.m_data);
        }
        String& operator=(const String& other) // Copy Assignment Operator
        {
            //std::cout<<"Copy Assignment Operator called!"<<std::endl;
            if(this != &other)
            {
                //deep copy
                m_data = new char [strlen(other.m_data)+1];
                strcpy(m_data,other.m_data);
            }
            return *this;
        }
        ~String()
        {
            //std::cout<<"Destructor called!"<<std::endl;
            delete[] m_data;
        }
        String(String&& other) noexcept // Move Constructor
        {
            //std::cout<<"Move Constructor called!"<<std::endl;
            m_data = other.m_data;
            other.m_data = nullptr;
        }
        char operator[](int index)
        {
            /*Access String by index*/
            return this->m_data[index];
        }
        const String &operator+=(const String &other)
        {
            std::cout<<"Concatenation Operator called!"<<std::endl;
            size_t newLength = strlen(this->m_data) + strlen(other.m_data) + 1;
            char* newData = new char[newLength];
            strcpy(newData, this->m_data);
            strcat(newData, other.m_data);
            /*Move Concatenated Strings to Result*/
            String temp(std::move(String{newData}));
            /*Take Ownership*/
            m_data = temp.m_data;
            /*Prevent double deletion*/
            temp.m_data = nullptr; 
            return *this;
        }
        const bool operator>(const String& other)
        {
            return strlen(this->m_data) > strlen(other.m_data);

        }

    
};


int main()
{
    char array[] = "Hello World!";
    String str1 {array};
    /*shallow Copy*/
    /*Copy Constructor*/
    String str2(str1);
    str1.setchar('@');
    str1.display();
    str2.display();
    /*Copy Assignment */
    String str3 = str1;
    str3.display();
    /*Move Constructor*/
    String str4 = std::move(str1);
    str4.display();
    std::cout<<"Third character in str4:"<<str4[2]<<std::endl;
    String str5 = String{const_cast<char*>(" Goodbye!")};
    String str6 = String{const_cast<char*>(" Mahmoud")};
    /*Concatenate Strings*/
    str5 += str6 ;
    str5.display();
    /*Compare between Strings*/
    bool resutl = str5 > str6 ;
    std::cout<<"Comparison Result:"<<resutl<<std::endl;
    return 0;
}