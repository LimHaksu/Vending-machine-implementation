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
	cout << "소계\t\t\t" << subTotal << endl;
	cout << "부가세\t\t\t" << vat << endl;
	cout << "합계\t\t\t" << total << endl;
	cout << "대금을 입력해 주십시오. : ";
	cin >> payment;
	if( payment < total ){
		cout << "대금이 부족합니다." << endl;
		return;
	}
	cout << "결제가 완료되었습니다." << endl;
	if( payment > total)
		cout << "거스름돈은 " <<  payment - total <<"원입니다." <<endl;
	
	return;*/
	cart.printList();
	if( cart.getTheNumOfProduct() == 0 ){
		cout << "장바구니가 비었습니다."<< endl;
		return;
	}
	cout <<"---------------------------------------"<<endl;
	int total = cart.calTotalPrice();
	int vat = total / 11;
	int subtotal = total - vat;
	cout << "소계\t\t\t\t"<< subtotal <<"원"<<endl;
	cout << "부가세\t\t\t\t "<< total - subtotal <<"원"<<endl;
	cout << "합계\t\t\t\t" << total <<"원" << endl;

	int payment;
	do{
		cout <<"대금을 입력해 주십시오(취소 0) : ";
		cin >> payment;
		if( payment == 0){
			break;
		}else if( total > payment ){
			cout << "대금이 부족합니다.\n"<< endl;
			continue;
		}else{
			int n = cart.getTheNumOfProduct(); 
			while( n-- > 0 ){
				string productName = cart.getNthProduct( 1 )->getProductName();
				int productAmount = cart.getNthProduct( 1 )->getAmount();
				cart.sub( productName , productAmount );
			}
			cout << "결제가 완료되었습니다." <<endl;
			if( payment > total )
				balance = payment - total;
				cout << "거스름돈은 "<< balance <<"원입니다."<< endl;
			break;
		}
	}while(1);
	return ;
}