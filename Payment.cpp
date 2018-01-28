#include <iostream>
using namespace std;

#include "Payment.h"

Payment::Payment(ShoppingCart& shopping):cart(shopping){}

void Payment::setPayment(int number)
{
	payment = number;
}

int Payment::getPayment() const
{
	return payment;
}

void Payment::setBalance( int number )
{
	balance = number;
}

int Payment::getBalance() const
{
	return balance;
}

void Payment::setSubTotal(int number)
{
	subTotal = number;
}

int Payment::getSubTotal() const
{
	return subTotal;
}

void Payment::setVat(int number)
{
	vat = number;
}

int Payment::getVat() const
{
	return vat;
}

void Payment::setTotal( int number )
{
	total = number;
}

int Payment::getTotal() const
{
	return total;
}

void Payment::printResult()
{
	/*cart.printList();
	total = cart.calTotalPrice();
	subTotal = total*10 / 11;
	vat = total - subTotal;
	cout << "-------------------------------" <<endl;
	cout << "�Ұ�\t\t\t" << subTotal << endl;
	cout << "�ΰ���\t\t\t" << vat << endl;
	cout << "�հ�\t\t\t" << total << endl;
	cout << "����� �Է��� �ֽʽÿ�. : ";
	cin >> payment;
	if( payment < total ){
		cout << "����� �����մϴ�." << endl;
		return;
	}
	cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
	if( payment > total)
		cout << "�Ž������� " <<  payment - total <<"���Դϴ�." <<endl;
	
	return;*/
	cart.printList();
	if( cart.getTheNumOfProduct() == 0 ){
		cout << "��ٱ��ϰ� ������ϴ�."<< endl;
		return;
	}
	cout <<"---------------------------------------"<<endl;
	int total = cart.calTotalPrice();
	int vat = total / 11;
	int subtotal = total - vat;
	cout << "�Ұ�\t\t\t\t"<< subtotal <<"��"<<endl;
	cout << "�ΰ���\t\t\t\t "<< total - subtotal <<"��"<<endl;
	cout << "�հ�\t\t\t\t" << total <<"��" << endl;

	int payment;
	do{
		cout <<"����� �Է��� �ֽʽÿ�(��� 0) : ";
		cin >> payment;
		if( payment == 0){
			break;
		}else if( total > payment ){
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
				balance = payment - total;
				cout << "�Ž������� "<< balance <<"���Դϴ�."<< endl;
			break;
		}
	}while(1);
	return ;
}