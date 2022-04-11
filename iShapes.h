// Programmer: Younghyun Kwon
// Programmer's ID: 1651849
#ifndef ISHAPES_H
#define ISHAPES_H

#include<string>
#include<vector>
#include <cstdlib>
using namespace std;

struct Shape
{
};

class Square : public Shape
{
protected:
  const double side;

public:
  Square(const vector<string>& tokens): side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  Square& operator=(const Square&);
  void output(ofstream&) const;
};

class Rectangle : public Shape
{
protected:
  const double length;
  const double width;

public:
  Rectangle(const vector<string>& tokens): length(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0), width(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  Rectangle& operator=(const Rectangle&);
  void output(ofstream&) const;
};

class Circle : public Shape
{
protected:
  const double radius;

public:
  Circle(const vector<string>& tokens): radius(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  Circle& operator=(const Circle&);
  void output(ofstream&) const;
};

class Triangle : public Shape
{
protected:
  const double side;

public:
  Triangle(const vector<string>& tokens): side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0){}
  Triangle& operator=(const Triangle&);
  void output(ofstream&) const;
};

class Cube : public Square
{
public:
  Cube(const vector<string>& tokens): Square(tokens){}
  Cube& operator=(const Cube&);
  void output(ofstream&) const;
};

class Box : public Rectangle
{
protected:
  const double height;

public:
  Box(const vector<string>& tokens): Rectangle(tokens), height(tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0){}
  Box& operator=(const Box&);
  void output(ofstream&) const;
};

class Cylinder : public Circle
{
protected:
  const double height;

public:
  Cylinder(const vector<string>& tokens): Circle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  Cylinder& operator=(const Cylinder&);
  void output(ofstream&) const;
};

class Prism : public Triangle
{
protected:
  const double height;

public:
  Prism(const vector<string>& tokens): Triangle(tokens), height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0){}
  Prism& operator=(const Prism&);
  void output(ofstream&) const;
};

#endif
