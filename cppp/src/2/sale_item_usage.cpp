#include <iostream>
#include <string>
#include "sale.h"

int main(int argc, char *argv[]) {

  Sales_data data1, data2;

  double price = 2.5;
  data1.bookNo = "1";
  data1.units_sold = 1;
  data1.revenue = price * data1.units_sold;
}
