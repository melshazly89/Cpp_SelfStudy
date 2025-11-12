#include <iostream>
using namespace std;


class Shape
{
    /*Abstract Class*/
    public:
    virtual void draw() = 0; /*Pure virtual Function */
    virtual ~Shape() = default; /*Virtual Destructor*/
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

void func(Shape &shape)
{
    /*Dynamic Cast Example*/
    Square *square = dynamic_cast<Square*>(&shape);
    if (square != nullptr)
    {
        /*It's a Square*/
        square->draw();
    }

}
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

    func(square); /*Dynamic Cast Example*/
    return 0;
}