#include <vector>
#include <functional>
#include <iostream>
#include <map>

//#include "tests.h"
#include "candle.h"

//массив всех тестов, который мы заполняем в функции mk_initTests
std::map<std::string, std::function<bool()>> mk_tests;
//'body_contains'
bool test_body_contains1()
{
//    Candle::Candle(Price _open, Price _high, Price _low, Price _close)
    Candle candle{ 0.0, 5.0, 0.0, 3.0 };
    return candle.body_contains(3.0);
}
bool test_body_contains2()
{
    //    Candle::Candle(Price _open, Price _high, Price _low, Price _close)
    Candle candle{ 0.0, 5.0, 0.0, 3.0 };
    return candle.body_contains(0.0);
}
bool test_body_contains3()
{
    //    Candle::Candle(Price _open, Price _high, Price _low, Price _close)
    Candle candle{ 5.0, 5.0, 0.0, 1.0 };
    return candle.body_contains(1.0);
}
bool test_contains1()
{
    Candle candle{ 1.0, 5.0, 0.0, 3.0 };
    return candle.contains(5.0);
}
bool test_contains2()
{
    Candle candle{ 1.0, 5.0, 0.0, 3.0 };
    return candle.contains(0.0);
}
bool test_contains3()
{
    Candle candle{ 3.0, 5.0, 0.0, 1.0 };
    return candle.contains(0.0);
}
bool test_full_size1()
{
    Candle candle{ 1.0, 5.0, 0.0, 3.0 };
    return candle.full_size() == abs(5.0 - 0);
}
bool test_full_size2()
{
    Candle candle{ 1.0, 0.0, 5.0, 3.0 };
    return candle.full_size() == abs(5.0 - 0);
}
bool test_full_size3()
{
    Candle candle{ 3.0, 0.0, 5.0, 1.0 };
    return candle.full_size() == abs(5.0 - 0);
}
bool test_is_green1()
{
    Candle candle{ 3.0, 0.0, 5.0, 5.0 };
    if (candle.is_green() == true) return true;
    else return false;
}
bool test_is_green2()
{
    Candle candle{ 5.0, 0.0, 5.0, 5.0 };
    if (candle.is_green() == false) return true;
    else return false;
}
bool test_is_green3()
{
    Candle candle{ 5.0, 0.0, 5.0, 3.0 };
    if (candle.is_green() == false) return true;
    else return false;
}
bool test_is_red1()
{
    Candle candle{ 5.0, 0.0, 5.0, 3.0 };
    return candle.is_red();
}
bool test_is_red2()
{
    Candle candle{ 3.0, 0.0, 5.0, 5.0 };
    return !candle.is_red();
}
bool test_is_red3()
{
    Candle candle{ 5.0, 0.0, 5.0, 5.0 };
    //close < open
    return !candle.is_red();
}

void mk_initTests()
{
    mk_tests["test_body_contains1"]=  test_body_contains1;
    mk_tests["test_body_contains2"] = test_body_contains2;
    mk_tests["test_body_contains3"] = test_body_contains3;
    mk_tests["test_contains1"] = test_contains1;
    mk_tests["test_contains2"] = test_contains2;
    mk_tests["test_contains3"] = test_contains3;

    mk_tests["test_full_size1"] = test_full_size1;
    mk_tests["test_full_size2"] = test_full_size2;
    mk_tests["test_full_size3"] = test_full_size3;

    mk_tests["test_is_green1"] = test_is_green1;
    mk_tests["test_is_green2"] = test_is_green2;
    mk_tests["test_is_green3"] = test_is_green3;

    mk_tests["test_is_red1"] = test_is_red1;
    mk_tests["test_is_red2"] = test_is_red2;
    mk_tests["test_is_red3"] = test_is_red3;

}


static std::vector<std::function<bool()>> tests;

//тест 1
bool test1()
{
  //пример какого-то теста
  return 42 == (41 + 1); //passed
}

//тест 2
bool test2()
{
  //пример какого-то теста
  return 42 != (41 + 1); //failed
}

//тест 3
bool test3()
{
  Candle candle{ 0.0, 3.0, 3.0, 3.0 };

  //пример какого-то теста
  return candle.high == 3.0;
}

void initTests()
{
  tests.push_back(test1);
  tests.push_back(test2);
  tests.push_back(test3);
  //tests.push_back(test4);
  //tests.push_back(test5);
}

int launchTests()
{
  int total = 0;
  int passed = 0;

  //for (const auto& test : tests)
  //{
  //  std::cout << "test #" << (total + 1);
  //  if (test())
  //  {
  //    passed += 1;
  //    std::cout << " passed\n";
  //  }
  //  else
  //  {
  //    std::cout << " failed\n";
  //  }
  //  total += 1;
  //}
 // for (const auto& [product, price] : products)
 //     std::cout << product << "\t" << price << std::endl;
  //for (const auto& [name_fun_str, name_fun_] : mk_tests)
  for (const auto& element : mk_tests)
  //        std::cout << element.first << "\t" << element.second << std::endl;
  {
      if (element.second()) {
           passed += 1;
           std::cout << element.first  << " passed\n";
            
      }
      else {
          std::cout << element.first << "  failed\n";

      }
      total += 1;

  }
  std::cout << "\ntests " << passed << "/" << total << " passed!" << std::endl;

  //0 = success
  return total - passed;
}

int main()
{
  initTests();
  mk_initTests();
  return launchTests();
}
