#include <iostream>
using namespace std;

#include <string>

#include "Product.h"

Product::Product(string productName, int productAmount):name(productName)
{
	amount = productAmount < 1 ? 1 : productAmount;
}

void Product::setLPointer(Product* pointer)
{
	LPointer = pointer;
}

void Product::setRPointer(Product* pointer)
{
	RPointer = pointer;
}

Product* Product::getLPointer() const
{
	return LPointer;
}

Product* Product::getRPointer() const
{
	return RPointer;
}

void Product::setAmount(int number)
{
	amount = number;
}

int Product::getAmount() const
{
	return amount;
}

string Product::getProductName() const
{
	return name;
}

bool Product::operator==(const Product& product2) const 
{
	if( (*this).getProductName() == product2.getProductName() )
		return true;
	else 
		return false;
}