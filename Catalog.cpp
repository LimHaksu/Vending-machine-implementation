#include <iostream>
using namespace std;

#include "Catalog.h"
#include <fstream>
#include <string>

Catalog::Catalog()
{
	ifstream file("catalog.dat", ios::binary);
	string name;
	int price;
	int i = 0;
	for( ; (i < 20 ) && !file.eof() ; i++){
		file >> name >> price;
		list[i].setName(name);
		list[i].setPrice(price);
	}
	setSort(i);
	file.close();
}

bool Catalog::isInCatalog(string name) const
{
	for( int i=0; i< sort ; i++){
		if(list[i].getName() == name)
			return true;
	}
	cout << "īŻ�α׿� ��ġ�ϴ� ��ǰ�� �����ϴ�"<< endl;
	return false;
}

ProductSpec Catalog::findProduct(string name) const
{
	for (int i=0; i< sort ; i++){
		if(list[i].getName() == name )
			return list[i];
	}
	cout << "Catalog::findProduct() - ��ġ�ϴ� ��ǰ�� �����ϴ�." << endl;
	exit(123);
}

void Catalog::setSort(int number)
{
	sort = number;
}

