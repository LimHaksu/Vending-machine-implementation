#ifndef _CATALOG_
#define _CATALOG_

#include "ProductSpec.h"

class Catalog
{
public:
	Catalog();
	bool isInCatalog(string) const;
	ProductSpec findProduct(string) const ; // ��� ����ұ�?
	void setSort(int);
private:
	ProductSpec list[20];
	int sort;
};

#endif