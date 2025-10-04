#include <iostream>
#include <Windows.h>
using namespace std;

class Figure
{
public:
  Figure(int sides)
  {
    this->sides = sides;
  }
  int getSides() { return this->sides; }

protected:
  int sides;
};

class Triangle : public Figure
{
public:
  Triangle(int a, int b, int c, int A, int B, int C, int sides) : Figure(sides)
  {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
  }
  int geta() { return this->a; }
  int getb() { return this->b; }
  int getc() { return this->c; }
  int getA() { return this->A; }
  int getB() { return this->B; }
  int getC() { return this->C; }

protected:
  int a;
  int b;
  int c;
  int A;
  int B;
  int C;
};

class Quadrangle : public Triangle
{
public:
  Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, int sides) : Triangle(a, b, c, A, B, C, sides)
  {
    this->d = d;
    this->D = D;
  }
  int getd() { return this->d; }
  int getD() { return this->D; }

protected:
  int d;
  int D;
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);

  Figure fg(0);
  Triangle tr(10, 20, 30, 50, 60, 70, 3);
  Quadrangle qa(10, 20, 30, 40, 50, 60, 70, 80, 4);

  cout << "Фигура:\n";
  cout << "Количество сторон: " << fg.getSides() << endl;
  cout << "\nТреугольник\n";
  cout << "Количество сторон: " << tr.getSides() << endl;
  cout << "Стороны: a=" << tr.geta() << " b=" << tr.getb() << " c=" << tr.getc() << endl;
  return 0;
}