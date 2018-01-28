#include <iostream>
using namespace std;

#include <string>
#include "ProductLinkedList.h"

ProductLinkedList::ProductLinkedList():header(NULL),theNumOfProduct(0){}

void ProductLinkedList::add(string productName, int productAmount) // list 마지막에 해당 개체를 붙인다.
{
	Product* item = new Product(productName, productAmount);
	item->setRPointer(NULL);
	if(header == NULL){
		item->setLPointer(NULL);
		header = item;
		theNumOfProduct++;
		return;
	}

	Product* temp;
	temp = header;
	do{
		if(temp->getRPointer() == NULL ){
			temp->setRPointer(item);
			item->setLPointer(temp);
			theNumOfProduct++;
			return;
		}
		else
			temp = temp->getRPointer();
	}while(1);

	cout << "상품추가 실패" << endl;
	return;
}

void ProductLinkedList::sub(string productName, int productAmount) // 해당 개체를 list에서 제거한다.
{
	Product* temp = header;
	while(temp != NULL){
		if( temp->getProductName() == productName ){
			if( temp->getAmount() < productAmount ){
				cout << "상품 빼기 실패 : 현재수량보다 더 많은 양을 뺄 수 없습니다. "<< endl;
				return;
			}else
				temp->setAmount( temp->getAmount() - productAmount );
			if ( temp->getAmount() == 0 ){
				if(temp->getLPointer() == NULL){
					if(temp->getRPointer() == NULL){
						delete temp; 
						theNumOfProduct--;
						header = NULL;						
						return;
					}else
						temp->getRPointer()->setLPointer( NULL );
					header = temp->getRPointer();	
				}else if(temp->getRPointer() == NULL){
					temp->getLPointer()->setRPointer( NULL );
				}else{
					temp->getLPointer()->setRPointer( temp->getRPointer()->getLPointer() );
					temp->getRPointer()->setLPointer( temp->getLPointer()->getRPointer() );
				}
				delete temp;
				theNumOfProduct--;
				return;
			}
		}
	}
	cout << "상품 빼기 실패 : 일치하는 상품이 없습니다. "<< endl;
	return;
}

Product* ProductLinkedList::getNthProduct(int n)
{
	Product* temp = header;
	for( ; n > 1 ; n--)
		temp = temp->getRPointer();
	return temp;
}

int ProductLinkedList::getTheNumOfProduct() const
{
	return theNumOfProduct;
}