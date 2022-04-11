// Programmer: Younghyun Kwon
// Programmer's ID: 1651849
#include "iostream"
#include "fstream"
#include <string>
#include <vector>
using namespace std;

#include <cmath>

#include "iShapes.h"

ostream& roundingTwo(ostream& out)
  {
    out.setf(ios::fixed);
    out.precision(2);
    return out;
  }

ostream& roundingOff(ostream& out)
  {
    out.unsetf(ios::fixed);
    out.precision(6);
    return out;
  }

Square& Square::operator=(const Square& square)
{
  Square& host = *this;
  if(this != &square)
  {
    const_cast<double&>(host.side)= square.side;
  }
  return *this;
}


void Square::output(ofstream& out) const
{
  double side = this->side;
  double area = side*side;
  double perimeter = side*4;
  cout << "SQUARE side=" << side;
  out << "SQUARE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

Rectangle& Rectangle::operator=(const Rectangle& rectangle)
{
  Rectangle& host = *this;
  if(this != &rectangle)
  {
    const_cast<double&>(host.length)= rectangle.length;
    const_cast<double&>(host.width)= rectangle.width;
  }
  return *this;
}

void Rectangle::output(ofstream& out) const
{
  double length = this->length;
  double width = this->width;
  double area = length*width;
  double perimeter = length*2 + width*2;
  cout << "RECTANGLE length=" << length << " width=" << width;
  out << "RECTANGLE length=" << length << " width=" << width;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

Circle& Circle::operator=(const Circle& circle)
{
  Circle& host = *this;
  if(this != &circle)
  {
    const_cast<double&>(host.radius)= circle.radius;
  }
  return *this;
}

void Circle::output(ofstream& out) const
{
  double radius = this->radius;
  double area = M_PI*radius*radius;
  double perimeter = 2*M_PI*radius;
  cout << "CIRCLE radius=" << radius;
  out << "CIRCLE radius=" << radius;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

Triangle& Triangle::operator=(const Triangle& triangle)
{
  Triangle& host = *this;
  if(this != &triangle)
  {
    const_cast<double&>(host.side)= triangle.side;
  }
  return *this;
}

void Triangle::output(ofstream& out) const
{
  double side = this->side;
  double area = (sqrt(3)*side*side)/4;
  double perimeter = 3*side;
  cout << "TRIANGLE side=" << side;
  out << "TRIANGLE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " perimeter=" << perimeter << endl;
  out << " area=" << area << " perimeter=" << perimeter << endl;
  roundingOff(cout);
  roundingOff(out);
}

Cube& Cube::operator=(const Cube& cube)
{
  Cube& host = *this;
  if(this != &cube)
  {
    const_cast<double&>(host.side)= cube.side;
  }
  return *this;
}

void Cube::output(ofstream& out) const
{
  double side = this->side;
  double area = side*side*6;
  double volume = side*side*side;
  cout << "CUBE side=" << side;
  out << "CUBE side=" << side;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

Box& Box::operator=(const Box& box)
{
  Box& host = *this;
  if(this != &box)
  {
    const_cast<double&>(host.length)= box.length;
    const_cast<double&>(host.width)= box.width;
    const_cast<double&>(host.height)= box.height;
  }
  return *this;
}

void Box::output(ofstream& out) const
{
  double length = this->length;
  double width = this->width;
  double height = this->height;
  double area = length*width*2 + width*height*2 + length*height*2;
  double volume = length*width*height;
  cout << "BOX side=" << length << " width=" << width << " height=" << height;
  out << "BOX side=" << length << " width=" << width << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

Cylinder& Cylinder::operator=(const Cylinder& cylinder)
{
  Cylinder& host = *this;
  if(this != &cylinder)
  {
    const_cast<double&>(host.radius)= cylinder.radius;
    const_cast<double&>(host.height)= cylinder.height;
  }
  return *this;
}

void Cylinder::output(ofstream& out) const
{
  double radius = this->radius;
  double height = this->height;
  double area = M_PI*radius*radius*2 + height*2*M_PI*radius;
  double volume = M_PI*radius*radius*height;
  cout << "CYLINDER radius=" << radius << " height=" << height;
  out << "CYLINDER radius=" << radius << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}

Prism& Prism::operator=(const Prism& prism)
{
  Prism& host = *this;
  if(this != &prism)
  {
    const_cast<double&>(host.side)= prism.side;
    const_cast<double&>(host.height)= prism.height;
  }
  return *this;
}

void Prism::output(ofstream& out) const
{
  double side = this->side;
  double height = this->height;
  double area = (sqrt(3)*side*side*2)/4 + 3*side*height;
  double volume = (sqrt(3)*side*side*height)/4;
  cout << "PRISM side=" << side << " height=" << height;
  out << "PRISM side=" << side << " height=" << height;
  roundingTwo(cout);
  roundingTwo(out);
  cout << " area=" << area << " volume=" << volume << endl;
  out << " area=" << area << " volume=" << volume << endl;
  roundingOff(cout);
  roundingOff(out);
}
