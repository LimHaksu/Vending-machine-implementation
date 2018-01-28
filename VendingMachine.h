#ifndef _VENDING_MACHINE_
#define _VENDING_MACHINE_

#include "Catalog.h"
#include "ShoppingCart.h"
#include "ProductLinkedList.h"

class VendingMachine
{
public:
	VendingMachine();
	void sale();
	void management();
	void addProduct(string, int);
	void subProduct(string, int);
	void printProductList();

private:
	
	void pay();
	void cancelSale();

	void addToCart();
	void subFromCart();

	Catalog catalog;
	ShoppingCart cart;
	ProductLinkedList list;
};

#endif