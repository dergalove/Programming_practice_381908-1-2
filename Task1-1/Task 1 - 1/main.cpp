/* Разработать класс Rational(рациональное число).

Класс должен хранить корректные дроби n / m(знаменатель не равен 0).

Дробь должна храниться в несократимом виде.

Класс должен содержать все необходимые конструкторы и деструктор.

В классе должны быть перегружены операции :
присваивания
4 стандартные арифметические операции
сравнения
ввода / вывода в поток */

class Rational {

private:
  int n, m;

public:
  Rational plus (Rational& a, Rational& b)
  {
    Rational res;
    res.n = a.n + b.n;
    if (a.m + b.m != 0) res.m = a.m + b.m;
    //функция сокращения
    return res;
  }
  Rational minus(Rational& a, Rational& b)
  {
    Rational res;
    res.n = a.n - b.n;
    res.m = a.m - b.m;
    //сокращение
    return res;
  }
  Rational Simplify (Rational a)
  {
    int i = 2;
    while (!(a.n % i == 0 && a.m % i == 0))
    {
      i++;
    }
    a.n /= i;
    a.m /= i;
    }
  };

