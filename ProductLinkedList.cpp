#include <iostream>
using namespace std;

#include <string>
#include "ProductLinkedList.h"

ProductLinkedList::ProductLinkedList():header(NULL),theNumOfProduct(0){}

void ProductLinkedList::add(string productName, int productAmount) // list �������� �ش� ��ü�� ���δ�.
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

	cout << "��ǰ�߰� ����" << endl;
	return;
}

void ProductLinkedList::sub(string productName, int productAmount) // �ش� ��ü�� list���� �����Ѵ�.
{
	Product* temp = header;
	while(temp != NULL){
		if( temp->getProductName() == productName ){
			if( temp->getAmount() < productAmount ){
				cout << "��ǰ ���� ���� : ����������� �� ���� ���� �� �� �����ϴ�. "<< endl;
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
	cout << "��ǰ ���� ���� : ��ġ�ϴ� ��ǰ�� �����ϴ�. "<< endl;
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