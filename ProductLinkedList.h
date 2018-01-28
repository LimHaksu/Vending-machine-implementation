#ifndef _PRODUCT_LINKED_LIST_
#define _PRODUCT_LINKED_LIST_
#include "Product.h"

class ProductLinkedList
{
public:
	ProductLinkedList();
	void add(string,int);
	void sub(string,int);
	Product* getNthProduct(int);
	int getTheNumOfProduct() const;

private:
	Product* header;
	int theNumOfProduct;
};


#endif