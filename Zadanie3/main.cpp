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

  Figure fg(0);                                     //-Экземпляр фигуры;
  Triangle tr(10, 20, 30, 50, 60, 70, 3);           //-Экземпляр треугольника;
  Quadrangle qa(10, 20, 30, 40, 50, 60, 70, 80, 4); //-Экземпляр четырёхугольника;

  cout << "Фигура:\n";
  showTrueOrFalse(&fg);
  showInfo(&fg);

  cout << "\nТреугольник:\n";
  showTrueOrFalse(&tr);
  showInfo(&tr);

  cout << "\nЧетырёхугольник:\n";
  showTrueOrFalse(&qa);
  showInfo(&qa);

  return 0;
}