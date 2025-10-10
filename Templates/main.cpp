#include "iostream"

/*Function Template*/
template<typename T>
T sum(T a,T b)
{
    return a + b;
}

/*Class Template */
template <typename U>
class Data
{
    public :
    Data()
    {
        std::cout << "Generic Template" << std::endl;
    }
    void swap(U& a,U& b)
    {
        U temp;
        temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }
};
/*Template Specialization*/
template <> 
class Data <std::string>
{
    public :
    Data()
    {
        std::cout << "Specialized Template" << std::endl;
    }
    void swap(std::string& a,std::string& b)
    {
        std::string temp;
        temp = std::move(a);
        a = std::move(b);
        b = std::move(temp);
    }
};
/*Constant template expression*/
template<typename T,int Size>
class Myarray
{
    public:
    T m_array[Size];
    Myarray()
    {
        for (int i = 0; i < Size ;i++)
        {
            m_array[i] = i*i;
        }
    }
    void display()
    {
        for (int i = 0; i < Size ;i++)
        {
            std::cout << m_array[i] << std::endl;
        }

    }
};
/*Single Function Template*/
template <typename T >
void print(T Arg)
{
    std::cout << Arg << std::endl;
}
/*Varidic function template*/
template <typename T ,typename ... Args>
void print(T Arg,Args ... args)
{
    std::cout << Arg << std::endl;
    print(args...);  /*recursive call*/
}
int main()
{
    /*Function template*/
    int a = 5;
    int b = 6;
    float c = 8.5f;
    float d = 9.6f;
    std::cout << "Hello World!" << std::endl;
    std::cout << sum(1,2) << std::endl;
    std::cout << sum(1.0,2.5) << std::endl;
    std::cout << sum(1.5f,2.6f) << std::endl;
    /*Single argument class template*/
    Data <int> d1;
    d1.swap(a,b);
    std::cout << "a:" << a << " " << "b:" << b <<std::endl;
    Data <float> d2;
    d2.swap(c,d);
    std::cout << "c:" << c << " " << "d:" << d <<std::endl;
    std::string str1 = "Mahmoud";
    std::string str2 = "Omar";
    Data <std::string> d3;
    d3.swap(str1,str2);
    std::cout << "str1:" << str1 << " " << "str2:" << str2 <<std::endl;
    /*Constant template*/
    Myarray <float , 5> arr1;
    arr1.display();

    print(1,2.5,3.6f,"Hello Mahmoud!");

    std::tuple<int,std::string,float,char> m(5,"Yasmin",6.5f,'a');
    /*Accessing tuple*/
    std::cout << "Second Element in tuple:" << std::get<1>(m) << std::endl;
    std::cout << "First Element in tuple:" << std::get<0>(m) << std::endl;
    /*Modify tuple Element*/
    std::get<0>(m) = 80;
    std::cout << "First Element in tuple After Modyfication:" << std::get<0>(m) << std::endl;
}