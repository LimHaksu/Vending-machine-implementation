#include <iostream>
using namespace std;
#include <string>

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart(const Catalog& c):catalog(c){}

void ShoppingCart::add(string productName, int amount)
{
	int theNumOfProduct = getTheNumOfProduct();
	int n=0;
	while( n++ < theNumOfProduct ){
		if( getNthProduct( n )->getProductName() == productName ){
			getNthProduct( n )->setAmount( getNthProduct( n )->getAmount() + amount);
			return;
		}
	}
	if( list.getTheNumOfProduct() < 10){ 
		list.add(productName, amount);
	}else{
		cout << "장바구니에는 10가지 상품만 넣을 수 있습니다.\n" <<endl;
	}

	return;
}

void ShoppingCart::sub(string productName, int amount)
{
	if( list.getTheNumOfProduct() > 0){
		list.sub(productName, amount);
	}else{
		cout <<"장바구니에 상품이 없습니다.\n"<< endl;
	}
	return;
}

void ShoppingCart::printList()
{
	cout << "   상품명"<<'\t'<< "단가" <<'\t'<< "수량" <<'\t'<< "합계" << endl;
	int n=0;
	while(n++ < list.getTheNumOfProduct()){
		string productName = list.getNthProduct( n )->getProductName();
		int amount = list.getNthProduct( n )->getAmount();
		int price = catalog.findProduct( productName ).getPrice();
		cout << n <<". "<< productName <<'\t'<< price <<'\t'<< amount <<'\t'<<  price * amount << endl;
	}
	return;
}

int ShoppingCart::calTotalPrice()
{
	int total=0;
	int n=0;
	while(n++ < list.getTheNumOfProduct())
		total = catalog.findProduct( list.getNthProduct(n)->getProductName() ).getPrice() * (*list.getNthProduct( n )).getAmount();

	//int subtotal = total*10/11;
	//cout << "소계\t\t\t\t"<< subtotal <<"원"<<endl;
	//cout << "부가세\t\t\t\t "<< total - subtotal <<"원"<<endl;
	//cout << "합계\t\t\t\t" << total <<"원" << endl;
	return total;
}

Product* ShoppingCart::getNthProduct(int n)
{
	return list.getNthProduct( n );
}

int ShoppingCart::getTheNumOfProduct() const
{
	return list.getTheNumOfProduct();
}