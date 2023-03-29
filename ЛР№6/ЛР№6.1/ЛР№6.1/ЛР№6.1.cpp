#include<iostream>
using namespace std;

class Figure {
public:
    virtual double getArea() = 0; // абстрактний метод
};

class Rectangle : public Figure {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    virtual double getArea() override {   // перевизначення методу з базового класу
        cout << "Rectangle: " << endl;
        return length * width;
    }
};

class Circle : public Figure {
private:
    const double PI = 3.1415926535;
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    virtual double getArea()override {   // перевизначення методу з базового класу
        cout << "Circle: " << endl;
        return (PI * radius * radius);
    }
};

class RightTriangle : public Figure {
private:
    int base_;
    int height_;
public:
    RightTriangle(int b, int h) {
        base_ = b;   height_ = h;
    }

    virtual double getArea() override {  // перевизначення методу з базового класу  
        cout << "RightTriangle: " << endl;
        return ((base_ * height_) / 2);
    }
};

class Trapezoid :public Figure {
private:
    int a_, b_, h_;
public:

    Trapezoid(int a, int  b, int h) {
        a_ = a; b_ = b; h_ = h;
    }

    virtual double getArea() override {  //перевизначення функції-члена базового класу
        cout << "Trapezoid: " << endl;
        return ((a_ + b_) * h_) / 2;
    }
};

void printArea(Figure& fig) {
    cout << "Square: " << fig.getArea() << endl;
}

int main() {
    Rectangle rect(5, 10);
    Circle circ(7);
    RightTriangle rtrig(4, 6);
    Trapezoid trapez(3, 4, 8);

    printArea(rect);    // виведе площу прямокутника з довжиною 5 і шириною 10
    printArea(circ);    // виведе площу кола з радіусом 7
    printArea(rtrig);   // виведе площу правильного трикутника з основою 4 і висотою ​​6
    printArea(trapez);	//вилведе плошту трапезоїди з даними параметрами

    return 0;
}