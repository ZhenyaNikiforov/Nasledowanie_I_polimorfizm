#include <iostream>
#include <Windows.h> //- Для кириллицы
using namespace std;

class Figure //-Базовый класс;
{
public:
  Figure(string name = "Фигура", int signum = 0)
  {
    this->name = name;
    this->sides_count = signum;
  };

  string getName()
  {
    return this->name;
  };

  int get_sides_count()
  {
    return this->sides_count;
  };

private:
  string name;
  int sides_count;
};

class Triangle : public Figure
{
public:
  Triangle() : Figure("Треугольник", 3) {};
};

class Quadrangle : public Figure
{
public:
  Quadrangle() : Figure("Четырёхугольник", 4) {};
};

int main()
{
  SetConsoleOutputCP(CP_UTF8);

  Figure fg;
  Triangle tg;
  Quadrangle qg;

  cout << "Количество сторон:\n";
  cout << fg.getName() << ": " << fg.get_sides_count() << "\n";
  cout << tg.getName() << ": " << tg.get_sides_count() << "\n";
  cout << qg.getName() << ": " << qg.get_sides_count() << "\n";

  return 0;
}