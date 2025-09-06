#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

class complex
{
    public:
        int real;
        float imag;
    complex()=default;
    /*single argument constructor shall be declared explicitly*/
    explicit complex (int real):real(real){}
    complex(int real,float imag):real(real),imag(imag)
    {

    }
    int operator+ (int num)
    {
        return this->real + num;
    }
    float operator+ (float num)
    {
        return this->imag + num;
    }
    complex operator+(const complex& temp)
    {
        complex result;
        result.real = this->real + temp.real;
        result.imag = this->imag + temp.imag;
        return result;
    }
    /*Post increment operator overloading*/
    complex operator++(int x)
    {
        complex result;
        result.real = this->real ++;
        result.imag = this->imag ++;
        return result;

    }
    /*Pre increment operator overloading*/
    complex operator++()
    {
        complex result;
        result.real = this->real + 1;
        result.imag = this->imag + 1;
        return result;

    }
    /*Operator overloading for less than operator*/
    bool operator<(const complex& num)
    {
        
        if (this->real < num.real && this->imag < num.imag)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    /*Functor*/
    void operator()(void)
    {
        cout << "Real is " << real << endl;
        cout << "img is " << imag << endl;
    }

    /*External Operator overloading definition for output stream operator*/
    friend ostream& operator<<(ostream& os,const complex& c);

    
};

/*declaration for Operator overloading Output stream  */
std::ostream& operator<<(std::ostream& os, const complex& c) {
    os << "(" << c.real << ", " << c.imag << ")";
    return os;
}


int main()
{
    complex A =complex(1,5.0);
    complex B = complex(2,6.0);
    complex C ={};
    /*Call Operator overloading for "+"*/
    cout << A.operator+(B.real) << endl;
    cout << A.operator+(B.imag) <<endl;
    C.operator = (A.operator+(B));
    vector<complex> v{A,B,C};
    /*Sort Complex Numbers vector*/
    std::sort(v.begin(),v.end());
    
    /*Print sorted vector*/
    for(auto it =v.begin();it<v.end();it++)
    {
        cout << *it<<endl;
    }
    
    /*call Functor */
    cout << "call the functor :\n";
    B();
    //complex();  /*it will do nothing*/

    complex D(5,5.0);
    cout << D.operator++(0)<<endl;
    cout << ++D<<endl;

    complex E=static_cast<complex>(2); /*Implicit casting (complex)(2)*/
    return 0;
}