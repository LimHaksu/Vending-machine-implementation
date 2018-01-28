#ifndef _SHOPPING_CART_
#define _SHOPPING_CART_

#include "ProductLinkedList.h"
#include "Catalog.h"

class ShoppingCart
{
public:
	ShoppingCart(const Catalog&);
	void add(string, int);
	void sub(string, int);
	void printList();
	int calTotalPrice();

	int getTheNumOfProduct() const;
	Product* getNthProduct(int);
private:
	ProductLinkedList list;
	const Catalog& catalog;
};

#endif