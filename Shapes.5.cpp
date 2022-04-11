// Programmer: Younghyun Kwon
// Programmer's ID: 1651849
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

#include "iShapes.h"

vector<string> parseString(string);
const vector<const Shape*> bag(ifstream&, ofstream&,const vector<int>&);
void deleteBag(const vector<const Shape*>&,const vector<int>&);
void readBag(ofstream&,const vector<const Shape*>&,const vector<int>&);

int main()
{
  cout << "Programmer: Younghyun Kwon\n";
  cout << "Programmer's ID: 1651849\n";
  cout << "File: " << __FILE__ << endl;
  ifstream fin;
  ofstream fout;
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");
  const vector<int> bagsType;
  const vector<const Shape*> bags = bag(fin,fout,bagsType);

  readBag(fout,bags,bagsType);
  deleteBag(bags,bagsType);
  fin.close();
  fout.close();
}

vector<string> parseString(string str)
{
 stringstream s(str);
 istream_iterator<string> begin(s), end;
 return vector<string>(begin, end);
}

const vector<const Shape*> bag(ifstream& in, ofstream& out,const vector<int>& bagType)
{
  string shape;
  vector<string> tokens;
  const vector<const Shape*> myBag;
  while(!in.eof())
  {
    getline(in,shape);
    if(shape.find_first_not_of(" ") != string::npos)
    {
      tokens = parseString(shape);
      if(tokens[0] == "SQUARE")
      {
        const Square* const square = new Square(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(square);
        const_cast<vector<int>&>(bagType).push_back(1);
      }
      else if(tokens[0] == "RECTANGLE")
      {
        const Rectangle* const rectangle = new Rectangle(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(rectangle);
        const_cast<vector<int>&>(bagType).push_back(2);
      }
      else if(tokens[0] == "CIRCLE")
      {
        Circle* circle = new Circle(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(circle);
        const_cast<vector<int>&>(bagType).push_back(3);
      }
      else if(tokens[0] == "TRIANGLE")
      {
        const Triangle* const triangle = new Triangle(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(triangle);
        const_cast<vector<int>&>(bagType).push_back(4);
      }
      else if(tokens[0] == "CUBE")
      {
        const Cube* const cube = new Cube(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(cube);
        const_cast<vector<int>&>(bagType).push_back(5);
      }
      else if(tokens[0] == "BOX")
      {
        const Box* const box = new Box(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(box);
        const_cast<vector<int>&>(bagType).push_back(6);
      }
      else if(tokens[0] == "CYLINDER")
      {
        const Cylinder* const cylinder = new Cylinder(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(cylinder);
        const_cast<vector<int>&>(bagType).push_back(7);
      }
      else if(tokens[0] == "PRISM")
      {
        const Prism* const prism = new Prism(tokens);
        const_cast<vector<const Shape*>&>(myBag).push_back(prism);
        const_cast<vector<int>&>(bagType).push_back(8);
      }
      else if(shape.compare("EOF") == 0) break;
      else{ cout << tokens[0] << " invalid object" << endl; }
    }
  }
  return myBag;
}

void deleteBag(const vector<const Shape*>& myBag,const vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      delete pSquare;
    }
    else if(myBagType[i] == 2)
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      delete pRectangle;
    }
    else if(myBagType[i] == 3)
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      delete pCircle;
    }
    else if(myBagType[i] == 4)
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      delete pTriangle;
    }
    else if(myBagType[i] == 5)
    {
      {
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        delete pCube;
      }
    }
    else if(myBagType[i] == 6)
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      delete pBox;
    }
    else if(myBagType[i] == 7)
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      delete pCylinder;
    }
    else if(myBagType[i] == 8)
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      delete pPrism;
    }
  }
}

void readBag(ofstream& out, const vector<const Shape*>& myBag,const vector<int>& myBagType)
{
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 1)
    {
      const Square* const pSquare = reinterpret_cast<const Square*>(myBag[i]);
      const Square& rSquare = *pSquare;
      rSquare.output(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 2)
    {
      const Rectangle* const pRectangle = reinterpret_cast<const Rectangle*>(myBag[i]);
      const Rectangle& rRectangle = *pRectangle;
      rRectangle.output(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 3)
    {
      const Circle* const pCircle = reinterpret_cast<const Circle*>(myBag[i]);
      const Circle& rCircle = *pCircle;
      rCircle.output(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 4)
    {
      const Triangle* const pTriangle = reinterpret_cast<const Triangle*>(myBag[i]);
      const Triangle& rTriangle = *pTriangle;
      rTriangle.output(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 5)
    {
      {
        const Cube* const pCube = reinterpret_cast<const Cube*>(myBag[i]);
        const Cube& rCube = *pCube;
        rCube.output(out);
      }
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 6)
    {
      const Box* const pBox = reinterpret_cast<const Box*>(myBag[i]);
      const Box& rBox = *pBox;
      rBox.output(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 7)
    {
      const Cylinder* const pCylinder = reinterpret_cast<const Cylinder*>(myBag[i]);
      const Cylinder& rCylinder = *pCylinder;
      rCylinder.output(out);
    }
  }
  for(unsigned int i = 0; i < myBag.size(); ++i)
  {
    if(myBagType[i] == 8)
    {
      const Prism* const pPrism = reinterpret_cast<const Prism*>(myBag[i]);
      const Prism& rPrism = *pPrism;
      rPrism.output(out);
    }
  }
}
