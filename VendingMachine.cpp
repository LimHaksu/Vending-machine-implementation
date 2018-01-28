#include <iostream>
using namespace std;

#include <string>
#include "VendingMachine.h"
#include "ShoppingCart.h"
#include "Catalog.h"
#include "Payment.h"

VendingMachine::VendingMachine():catalog(),cart(catalog),list(){}

void VendingMachine::management()
{
	int select;
	string productName;
	int amount;
	do{
		cout << "\n����-��ǰ ����" << endl;
		cout << "  1. ��ǰ �߰��ϱ�\n  2. ��ǰ ��� ����\n  3. ����\n  ��ȣ�� �����ϼ���. : ";
		cin >> select;

		switch(select){
		case 1: // ��ǰ �߰��ϱ�
			cout <<"\n����-��ǰ����-��ǰ �߰��ϱ�"<<endl;
			cout << "  ��ǰ �Է� : ";
			cin >> productName >> amount;
			addProduct(productName, amount);
			break;
		case 2: // ��ǰ ��� ����
			cout <<"\n����-��ǰ����-��ǰ ��� ����"<<endl;
			printProductList();
			break;
		case 3: // ����
			cout <<"\n����-��ǰ����-����"<<endl;
			cout <<"     ��ǰ������ �����մϴ�."<<endl;
			return ;
		default :
			cout << "�߸� �Է��ϼ̽��ϴ�.\n" << endl;
		}
	}while(1);
}

void VendingMachine::addProduct(string productName, int amount)
{
	if( amount > 50 ){
		cout << "��ǰ �Է� ���� (��ǰ ���� �ʰ�, �ִ� 50��)"<< endl;
		return;
	}
	if(catalog.isInCatalog(productName)){
		int n = 0;
		while( n++ < list.getTheNumOfProduct() ){
			if( list.getNthProduct(n)->getProductName() == productName ){
				int sum = list.getNthProduct(n)->getAmount() + amount;
				if( sum > 50){
					cout << "��ǰ �߰� ���� (��ǰ ���� �ʰ�, �ִ� 50��)"<<endl;
					return;
				}
				list.getNthProduct(n)->setAmount( sum );
				return;
			}
		}
		list.add(productName, amount);
	}
}


void VendingMachine::subProduct(string productName, int amount)
{
	if(catalog.isInCatalog(productName)){
		int n=0;
		while( n++ < list.getTheNumOfProduct() ){
			if(list.getNthProduct( n )->getProductName() == productName){
				int remainder = list.getNthProduct( n )->getAmount() - amount;
				if( remainder < 0 ){
					cout << "��ǰ ���� ���� ( ���� ���� �������� ���� ���� ������ �� ) " << endl;
					return;
				}else if (remainder == 0){
					list.sub(productName, amount);
					return;
				}else{
					list.getNthProduct( n )->setAmount( remainder );
					return;
				}
			}
		}
	}
}

void VendingMachine::printProductList()
{
	cout << "   ��ǰ��" <<'\t'<< "�ܰ�" <<'\t'<<"����"<< endl;
	int n=0;
	while(n++ < list.getTheNumOfProduct()){
		string productName = list.getNthProduct(n)->getProductName();
		cout << n <<". "<< productName <<'\t'
			<<  catalog.findProduct( productName ).getPrice() <<'\t'
			<<  list.getNthProduct(n)->getAmount() << endl;
	}
	return;
}

void VendingMachine::sale()
{
	int select;
	do{
		cout<<"\n����-��ǰ�Ǹ�"<<endl;
		cout<<"  1. ��ٱ��Ͽ� ��ǰ �߰�"<<endl;
		cout<<"  2. ��ٱ��ϼ� ��ǰ ����"<<endl;
		cout<<"  3. ��ٱ��� ����"<<endl;
		cout<<"  4. ����"<<endl;
		cout<<"  5. �Ǹ����"<<endl;
		cout<<"  ��ȣ�� �����ϼ��� : ";
		cin >> select;

		switch(select){
		case 1: // ��ٱ��Ͽ� ��ǰ �߰�
			cout <<"\n����-��ǰ�Ǹ�-��ٱ��Ͽ� ��ǰ �߰�"<<endl;
			cout << "  ���� ��ǰ ���" << endl;
			printProductList();
			addToCart();
			break;
		case 2: // ��ٱ��ϼ� ��ǰ ����
			cout <<"\n����-��ǰ�Ǹ�-��ٱ��ϼ� ��ǰ ����"<<endl;
			cout <<"  ���� ��ٱ��� ���"<<endl;
			cart.printList();
			subFromCart();
			break;
		case 3: // ��ٱ��� ����
			cout <<"\n����-��ǰ�Ǹ�-��ٱ��� ����"<<endl;
			cout <<"  ���� ��ٱ��� ���"<<endl;
			cart.printList();
			break ;
		case 4: // ����
			cout <<"\n����-��ǰ�Ǹ�-����"<< endl;
			pay();
			break;
		case 5: // �Ǹ����
			cancelSale();
			return;
		default : 
			cout << "�߸� �Է��ϼ̽��ϴ�.\n" << endl;
		}
	}while(1);
}

void VendingMachine::pay()
{
	/*cart.printList();
	cout <<"---------------------------------------"<<endl;
	int total = cart.calTotalPrice();
	int payment;
	do{
		cout <<"����� �Է��� �ֽʽÿ�. : ";
		cin >> payment;
		if( total > payment ){
			cout << "����� �����մϴ�.\n"<< endl;
			continue;
		}else{
			int n = cart.getTheNumOfProduct(); 
			while( n-- > 0 ){
				string productName = cart.getNthProduct( 1 )->getProductName();
				int productAmount = cart.getNthProduct( 1 )->getAmount();
				cart.sub( productName , productAmount );
			}
			cout << "������ �Ϸ�Ǿ����ϴ�." <<endl;
			if( payment > total )
				cout << "�Ž������� "<< payment - total <<"���Դϴ�."<< endl;
			break;
		}
	}while(1);*/
	Payment pay(cart);
	pay.printResult();
	return ;
}

void VendingMachine::cancelSale()
{
	int n = cart.getTheNumOfProduct(); 
	while( n-- > 0 ){
		string productName = cart.getNthProduct( 1 )->getProductName();
		int productAmount = cart.getNthProduct( 1 )->getAmount();
		cart.sub( productName , productAmount );
		addProduct( productName, productAmount );		
	}
	
	return;
}

void VendingMachine::addToCart()
{
	if(list.getTheNumOfProduct() == 0){
		cout << "  ���Ǳ� ���� ��ǰ�� �����ϴ�."<<endl;
		return;
	}
	cout << "   ��ǰ�� �����ϼ���(��� 0) : ";
	int number;
	cin >> number;
	if( number == 0)
		return;
	else if( number > list.getTheNumOfProduct() || number < 0){
		cout << "   ���� ��ȣ�� �����ϼ̽��ϴ�."<< endl;
		return;
	}
	cout << "   ������ �����ϼ��� : ";
	int inputAmount;
	cin >> inputAmount;
	string productName = list.getNthProduct ( number )->getProductName();
	int productAmount = list.getNthProduct( number )->getAmount();
	if( productAmount >= inputAmount ){
		cart.add( productName, inputAmount );
		subProduct( productName, inputAmount );
	}else
		cout << "  �����Ͻ� \""<< productName <<"\"��(��) "<< productAmount <<"���� �����մϴ�."<< endl;
	return;
}

void VendingMachine::subFromCart()
{
	if(cart.getTheNumOfProduct() == 0){
		cout << "  ��ٱ��� �ȿ� ��ǰ�� �����ϴ�. " << endl;
		return;
	}
	cout << "   ������ ��ǰ�� �����ϼ���(��� 0) : ";
	int number;
	cin >> number;
	if( number == 0)
		return;
	else if( number > cart.getTheNumOfProduct() || number < 0){
		cout << "   ���� ��ȣ�� �����ϼ̽��ϴ�."<< endl;
		return;
	}
	string productName = cart.getNthProduct( number )->getProductName();
	int productAmount = cart.getNthProduct( number )->getAmount();
	cart.sub( productName , productAmount );
	addProduct( productName, productAmount );
	
	return;
}

