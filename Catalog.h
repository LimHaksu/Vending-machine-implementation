#ifndef _CATALOG_
#define _CATALOG_

#include "ProductSpec.h"

class Catalog
{
public:
	Catalog();
	bool isInCatalog(string) const;
	ProductSpec findProduct(string) const ; // 어디에 사용할까?
	void setSort(int);
private:
	ProductSpec list[20];
	int sort;
};

#endif