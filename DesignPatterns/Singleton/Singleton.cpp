#include<string>
#include<iostream>
using namespace std;


class Shape{
    public: 
    virtual void draw() = 0;
    virtual ~Shape(){
        cout<<"Virtual Shape Destructor"<<endl;
    }
};

class Circle: public Shape{
    public:
    void draw(){
        cout<<"Drawing Circle"<<endl;
    }
    
};

class Square: public Shape{
    public:
    void draw(){
        cout<<"Drawing Square"<<endl;
    }
    
};

class Rectangle: public Shape{
    public:
    void draw(){
        cout<<"Drawing Rectanle"<<endl;
    }
    
};

class ShapeFactory{
    public: 
    virtual Shape* createShape() = 0;
    virtual ~ShapeFactory(){
        cout<<"Virtual ShapeFactory Destructor"<<endl;
    }
};

class CircleFactory:public ShapeFactory{
    public:
        Shape* createShape(){
            return  new Circle();
        }
};

class SquareFactory:public ShapeFactory{
    public:
        Shape* createShape(){
            return  new Square();
        }
};


int main(){
    ShapeFactory* circleFactory = new CircleFactory();
    ShapeFactory* squareFactory = new SquareFactory();

    Shape* circle = circleFactory->createShape();
    Shape* square = squareFactory->createShape();

    circle->draw();
    square->draw();

    delete circleFactory;
    delete squareFactory;
    delete circle;
    delete square;


    return 0;
}

