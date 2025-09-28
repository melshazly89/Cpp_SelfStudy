#include <iostream>
using namespace std;


class Shape
{
    public:
    virtual void draw() = 0; /*Pure virtual Function */


};
class Square : virtual public Shape
{
    public:
    void draw() override /*Override shall be added*/
    {
        std::cout << "Drawing a Square" << std::endl;
    }

};
class Circle : virtual public Shape
{
    public:
    void draw() override 
    {
        std::cout << "Drawing a Circle "<< std::endl;
    }
};
class Triangle : virtual public Shape
{
    public:
    void draw() override 
    {
        std::cout << "Drawing a Triangle "<< std::endl;
    }

};


int main()
{
    Square  square;
    Circle circle;
    Triangle triangle;
    
    Shape *shapes[]={&square,&circle,&triangle};
    for (auto shape: shapes)
    {
        /*Using Abstraction to draw different shapes*/
        shape->draw();
    }

    return 0;
}