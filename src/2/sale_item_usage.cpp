#include <iostream>
#include <string>
#include "sale.h"

void sale_item_usage() {

  Sales_data data1, data2;

  double price = 2.5;
  data1.bookNo = "1";
  data1.units_sold = 1;
  data1.revenue = price * data1.units_sold;
}
