// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double result = 1;
  for (int i = 0; i < n; i++) {
    result *= value;
  }
  return result;
}

uint64_t fact(uint16_t n) {
  if (n == 0 || n == 1) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  double sum = 0;
  sum += (pown(x, n) / fact(n));
  return sum;
}

double expn(double x, uint16_t count) {
  double ex = 1, n = 1;
  for (int i = 0; i < count; i++) {
    ex += calcItem(x, n);
    n++;
  }
  return ex;
}

double sinn(double x, uint16_t count) {
  double result = 0.0, n = 1;
  for (int i = 0; i < count; i++) {
    result += pown(-1, n - 1) * calcItem(x, 2 * n - 1);
    n++;
  }
  return result;
}

double cosn(double x, uint16_t count) {
  double result = 0, n = 1;
  for (int i = 0; i < count; i++) {
    result += pown(-1, n - 1) * calcItem(x, 2 * n - 2);
    n++;
  }
  return result;
}
