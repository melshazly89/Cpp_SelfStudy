#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;


class String
{
    private:
        char* str;
        int m_length;
    public:
        String (char* str)
        {
            std::cout << "calling constructor" << std::endl;
            this->m_length = strlen(str);
            this->str = new char (m_length + 1);
            strcpy(this->str,str);
        }
        String (const String& copy)
        {
            /*Deep Copy constructor*/
            std::cout << "calling copy constructor" << std::endl;
            this->m_length = copy.m_length;
            /*Dynamic allocation in heap */
            this->str =new char(m_length+1);
            strcpy(this->str,copy.str);

        }

        String (String&& move)
        {
            std::cout << "calling move constructor" << std::endl;
            this->m_length = move.m_length;
            this->str = move.str;
            move.m_length = 0;
            move.str = nullptr;

        }

        String& operator=(String&& move)
        {
            std::cout << "Assignation Move constructor" << std::endl;
            if (&move != this)
            {
                this->m_length = move.m_length;
                move.m_length = 0;
                if (this->str)
                {
                    delete [] str;
                }
                this->str = move.str;
                move.str = nullptr;
            }
            return *this;
        }
        String& operator=(const String& other)
        {
            std::cout << "Assignment Copy Constructor" << std::endl;
            if (&other != this)
            {
                this->m_length = other.m_length;
                if (this->str)
                {
                    delete [] this->str;
                }
                this->str =new char (m_length +1);
                strcpy(this->str ,other.str);
            }
            return *this;
        }
        
        const bool operator>(const String& other)
        {
            std::cout << strlen(this->str)  << " " << strlen(other.str) << std::endl;
            return strlen(this->str) > strlen(other.str);

        }
        ~String ()
        {
            /*Destructor to free memory*/
            std::cout << "calling destructor" << std::endl;
            delete [] str;
            str = nullptr;
        }
        void printString()
        {
            cout << str <<endl;
        }
        void set1stchar(char value)
        {
            *str=value;
        }

};

int main()
{
    char array[]="Hello";
    String t1{array};
    // String t2(t1);   /*Copy Constructor*/ /*Shallow Copy*/
    // t1.set1stchar('M'); /*Change in t1*/
    // t1.printString();
    // t2.printString();
    // t2=t1;
    // t2.printString();

    // String t3(std::move(t1));
    // t3=std::move(t1);

    String t4{array};
    bool ret = t4 > t1;
    std::cout << ret <<std::endl;
    return 0;
}