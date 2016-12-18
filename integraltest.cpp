#include <QtTest/QTest>
#include "integraltest.h"
#include "functions.h"
#include <cmath>

// Константная функция
double constFunction(double x) {
  return 1;
}

double constFunction2(double x) {
  return 2;
}

double constFunction3(double x) {
  return 2.5;
}

#define DOUBLE_COMPARE(x,y) QVERIFY(fabs(x-y) < 0.01)

void IntegralTest::testConstant() {
  DOUBLE_COMPARE(integral(constFunction, 0, 10),
                 10.0 ); // 1e-10
  DOUBLE_COMPARE(integral(constFunction, 2, 10),
                 8.0 ); // 1e-10
  DOUBLE_COMPARE( integral(constFunction2, 2.0, 10),
                  16.0 ); // 1e-10
  DOUBLE_COMPARE( integral(constFunction3, 10, 20.0),
                  2.5 * 10 ); // 1e-10
}

// Константная функция
double xFunc(double x) {
  return x;
}

void IntegralTest::testLinear() {
  // y = x   0..1  -> 0.5
  DOUBLE_COMPARE( integral(xFunc, 0, 1), 0.5 );
  DOUBLE_COMPARE( integral(xFunc, -10, 10), 0.0 );
  DOUBLE_COMPARE( integral(xFunc, 0, 4), 8.0 );
}

double x2Func(double x) {
  return pow(x, 2);
}

void IntegralTest::testQuadratic() {
  // y = x^2  x^3/3   0..1  -> 1/3
  DOUBLE_COMPARE( integral(x2Func, 0, 1.0), 1.0 / 3.0 );
}

