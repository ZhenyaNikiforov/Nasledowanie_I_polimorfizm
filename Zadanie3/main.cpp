#include <iostream>
#include <Windows.h>
using namespace std;

class Figure //-Базовый класс;
{
public:
  Figure(int sides)
  {
    this->sides = sides;
  }

  virtual void print_info() //-Выводим информацию о фигуре;
  {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Количество сторон: " << this->sides << "\n";
  }

  virtual bool check() //-Проверяем правильность фигуры;
  {
    if (this->sides == 0)
    {
      return true;
    };
    return false;
  }

  virtual ~Figure() {}; //-Виртуальный деструктор

protected:
  int sides;
};

class Triangle : public Figure //-Класс обычного треугольника
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

  void print_info() override //-Выводим информацию о треугольнике;
  {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Количество сторон: " << this->sides << "\n";
    cout << "Стороны: " << "a=" << this->a << " b=" << this->b << " c=" << this->c << "\n";
    cout << "Углы: " << "A=" << this->A << " B=" << this->B << " C=" << this->C << "\n";
  }

  bool check() override //-Проверяем правильность треугольника;
  {
    if ((this->A + this->B + this->C == 180) && (this->sides == 3))
    {
      return true;
    };
    return false;
  }

protected:
  int a;
  int b;
  int c;
  int A;
  int B;
  int C;
};

class RightTriangle : public Triangle //-Класс прямоугольного треугольника;
{
public:
  using Triangle::Triangle;

  bool check() override //-Проверяем правильность прямоугольного треугольника;
  {
    if (Triangle::check() && (this->C == 90))
    {
      return true;
    };
    return false;
  }
};

class IsoscelesTriangle : public Triangle //-равнобедренный треугольник
{
public:
  using Triangle::Triangle;
  bool check() override //-Проверяем правильность равнобедренного треугольника;
  {
    if (Triangle::check() && (this->A == this->C) && (this->a == this->c))
    {
      return true;
    };
    return false;
  }
};

class EquilateralTriangle : public Triangle //-Равносторонний треугольник
{
public:
  using Triangle::Triangle;
  bool check() override //-Проверяем правильность равностороннего треугольника;
  {
    bool parityABC = (this->A == this->B) && (this->B == this->C) && (this->A == 60);
    bool parityabc = (this->a == this->b) && (this->b == this->c);

    if (Triangle::check() && parityABC && parityabc)
    {
      return true;
    };
    return false;
  }
};

class Quadrangle : public Triangle //-Класс четырёхугольника;
{
public:
  Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, int sides) : Triangle(a, b, c, A, B, C, sides)
  {
    this->d = d;
    this->D = D;
  }

  void print_info() override //-Выводим информацию о четырёхугольнике;
  {
    SetConsoleOutputCP(CP_UTF8);
    cout << "Количество сторон: " << this->sides << "\n";
    cout << "Стороны: " << "a=" << this->a << " b=" << this->b << " c=" << this->c << " d=" << this->d << "\n";
    cout << "Углы: " << "A=" << this->A << " B=" << this->B << " C=" << this->C << " D=" << this->D << "\n";
  }

  bool check() override //-Проверяем правильность четырёхугольника;
  {
    if ((this->A + this->B + this->C + this->D == 360) && (this->sides == 4))
    {
      return true;
    };
    return false;
  }

protected:
  int d;
  int D;
};

class Rectangl : public Quadrangle //-Класс прямоугольник;
{
public:
  using Quadrangle::Quadrangle;
  bool check() override //-Проверяем правильность прямоугольника;
  {
    bool parityABCD = (this->A == this->B) && (this->B == this->C) && (this->C == this->D);
    bool parityabcd = (this->a == this->c) && (this->b == this->d);
    if (Quadrangle::check() && parityABCD && parityabcd)
    {
      return true;
    };
    return false;
  }
};

class Square : public Quadrangle //-Класс квадрат;
{
public:
  using Quadrangle::Quadrangle;
  bool check() override //-Проверяем правильность квадрата;
  {
    bool parityABCD = (this->A == this->B) && (this->B == this->C) && (this->C == this->D) && (this->D == 90);
    bool parityabcd = (this->a == this->b) && (this->b == this->c) && (this->c == this->d);
    if (Quadrangle::check() && parityABCD && parityabcd)
    {
      return true;
    };
    return false;
  }
};

class Paralelogram : public Quadrangle //-Класс параллелограмм;
{
public:
  using Quadrangle::Quadrangle;
  bool check() override //-Проверяем правильность параллелограмма;
  {
    bool parityABCD = (this->A == this->C) && (this->B == this->D);
    bool parityabcd = (this->a == this->c) && (this->b == this->d);
    if (Quadrangle::check() && parityABCD && parityabcd)
    {
      return true;
    };
    return false;
  }
};

class Rhomb : public Quadrangle //-Класс ромб;
{
public:
  using Quadrangle::Quadrangle;
  bool check() override //-Проверяем правильность ромба;
  {
    bool parityABCD = (this->A == this->C) && (this->B == this->D);
    bool parityabcd = (this->a == this->b) && (this->b == this->c) && (this->c == this->d);
    if (Quadrangle::check() && parityABCD && parityabcd)
    {
      return true;
    };
    return false;
  }
};

void showInfo(Figure *f) //-Выводим стороны и углы;
{
  f->print_info();
};

void showTrueOrFalse(Figure *f) //-Выводим правильность;
{
  SetConsoleOutputCP(CP_UTF8);
  if (f->check())
  {
    cout << "Правильная\n";
    return;
  }
  cout << "Неправильная\n";
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);

  Figure fg(0);                                       //-Экземпляр фигуры;
  Triangle tr(10, 20, 30, 50, 60, 70, 3);             //-Экземпляр треугольника;
  RightTriangle rtr1(10, 20, 30, 50, 60, 90, 3);      //-Прямоугольный треугольник-1;
  RightTriangle rtr2(10, 20, 30, 50, 40, 90, 3);      //-Прямоугольный треугольник-2;
  IsoscelesTriangle itr(10, 20, 10, 50, 60, 50, 3);   //-Равнобедренный треугольник
  EquilateralTriangle etr(30, 30, 30, 60, 60, 60, 3); //-Равносторонний треугольник
  Quadrangle qa(10, 20, 30, 40, 50, 60, 70, 80, 4);   //-Экземпляр четырёхугольника;
  Rectangl rc(10, 20, 10, 20, 90, 90, 90, 90, 4);     //-Прямоугольник
  Square sq(20, 20, 20, 20, 90, 90, 90, 90, 4);       //-Квадрат;
  Paralelogram pg(20, 30, 20, 30, 30, 40, 30, 40, 4); //-Параллелограмм;
  Rhomb rb(30, 30, 30, 30, 30, 40, 30, 40, 4);        //-Ромб;

  cout << "Фигура:\n";
  showTrueOrFalse(&fg);
  showInfo(&fg);

  cout << "\nТреугольник:\n";
  showTrueOrFalse(&tr);
  showInfo(&tr);

  cout << "\nПрямоугольный треугольник:\n";
  showTrueOrFalse(&rtr1);
  showInfo(&rtr1);

  cout << "\nПрямоугольный треугольник:\n";
  showTrueOrFalse(&rtr2);
  showInfo(&rtr2);

  cout << "\nРавнобедренный треугольник\n";
  showTrueOrFalse(&itr);
  showInfo(&itr);

  cout << "\nРавносторонний треугольник\n";
  showTrueOrFalse(&etr);
  showInfo(&etr);

  cout << "\nЧетырёхугольник:\n";
  showTrueOrFalse(&qa);
  showInfo(&qa);

  cout << "\nПрямоугольник\n";
  showTrueOrFalse(&rc);
  showInfo(&rc);

  cout << "\nКвадрат\n";
  showTrueOrFalse(&sq);
  showInfo(&sq);

  cout << "\nПараллелограмм\n";
  showTrueOrFalse(&pg);
  showInfo(&pg);

  cout << "\nРомб\n";
  showTrueOrFalse(&rb);
  showInfo(&rb);

  return 0;
}