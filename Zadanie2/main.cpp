#include <iostream>
#include <Windows.h>
using namespace std;

class Triangle //-Обычный треугольник;
{
public:
  Triangle(int a, int b, int c, int A, int B, int C)
  {
    this->a = a;
    this->b = b;
    this->c = c;
    this->A = A;
    this->B = B;
    this->C = C;
  }

  void print_info()
  {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << endl;
    cout << "Углы: А=" << this->A << " B=" << this->B << " C=" << this->C << endl;
  }

protected:
  int a;
  int b;
  int c;
  int A;
  int B;
  int C;
};

class RightTriangle : public Triangle //-Прямоугольный
{
public:
  using Triangle::Triangle;
};

class IsoscelesTriangle : public Triangle //-Равнобедренный
{
public:
  using Triangle::Triangle;
};

class EquilateralTriangle : public Triangle //-Равносторонний
{
public:
  using Triangle::Triangle;
};

class Quadrangle : public Triangle //-Обычный четырёхугольник
{
public:
  Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Triangle(a, b, c, A, B, C)
  {
    this->d = d;
    this->D = D;
  };

  void print_info()
  {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Стороны: a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << endl;
    cout << "Углы: А=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << endl;
  }

protected:
  int d;
  int D;
};

class Rectangl : public Quadrangle //-Прямоугольник
{
  using Quadrangle::Quadrangle;
};

class Square : public Quadrangle //-Квадрат
{
  using Quadrangle::Quadrangle;
};

class Parallelogram : public Quadrangle //-Параллелограмм
{
  using Quadrangle::Quadrangle;
};

class Rhombus : public Quadrangle //-Ромб
{
  using Quadrangle::Quadrangle;
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);

  Triangle tr(10, 20, 30, 50, 60, 70);             //-Треугольник;
  RightTriangle rtr(10, 20, 30, 50, 60, 90);       //-Прямоугольный треугольник;
  IsoscelesTriangle itr(10, 20, 10, 50, 60, 50);   //-Равнобедренный треугольник;
  EquilateralTriangle etr(30, 30, 30, 60, 60, 60); //-Равносторонний треугольник;

  Quadrangle qa(10, 20, 30, 40, 50, 60, 70, 80);    //-Четырёхугольник;
  Rectangl rc(10, 20, 10, 20, 90, 90, 90, 90);      //-Прямоугольник;
  Square sq(20, 20, 20, 20, 90, 90, 90, 90);        //-Квадрат;
  Parallelogram pr(20, 30, 20, 30, 30, 40, 30, 40); //-Параллелограмм;
  Rhombus rb(30, 30, 30, 30, 30, 40, 30, 40);       //-Ромб;

  cout << "Треугольник: \n";
  tr.print_info();

  cout << "\nПрямоугольный треугольник:\n";
  rtr.print_info();

  cout << "\nРавнобедренный треугольник:\n";
  itr.print_info();

  cout << "\nРавносторонний треугольник:\n";
  etr.print_info();

  cout << "\nЧетырёхугольник:\n";
  qa.print_info();

  cout << "\nПрямоугольник:\n";
  rc.print_info();

  cout << "\nКвадрат:\n";
  sq.print_info();

  cout << "\nПараллелограмм:\n";
  pr.print_info();

  cout << "\nРомб:\n";
  rb.print_info();

  return 0;
}