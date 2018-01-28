#include <iostream>
using namespace std;
#include <string>

#include "ProductSpec.h"

string ProductSpec::getName() const 
{
	return name;
}

void ProductSpec::setName(string str)
{
	name = str;
}

int ProductSpec::getPrice() const 
{
	return price;
}

void ProductSpec::setPrice(int number)
{
	price = number;
}