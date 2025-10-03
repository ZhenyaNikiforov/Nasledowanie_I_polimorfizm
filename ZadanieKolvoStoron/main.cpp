#include <iostream>
#include <Windows.h> //- Для кириллицы
using namespace std;

class Figure
{
public:
  Figure(int signum)
  {
    this->sides_count = signum;
  };

  int get_sides_count()
  {
    return this->sides_count;
  };

private:
  int sides_count;
};

class Triangle : public Figure
{
public:
  Triangle(int m) : Figure(m) {};
};

class Quadrangle : public Figure
{
public:
  Quadrangle(int m) : Figure(m) {};
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);

  Figure fg(0);
  Triangle tg(3);
  Quadrangle qg(4);

  cout << "Количество сторон:\n";
  cout << "Фигура: " << fg.get_sides_count() << "\n";
  cout << "Треугольник: " << tg.get_sides_count() << "\n";
  cout << "Четырёхугольник: " << qg.get_sides_count() << "\n";

  return 0;
}