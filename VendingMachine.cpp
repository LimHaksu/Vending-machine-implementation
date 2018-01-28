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
		cout << "\n시작-상품 관리" << endl;
		cout << "  1. 상품 추가하기\n  2. 상품 목록 보기\n  3. 종료\n  번호를 선택하세요. : ";
		cin >> select;

		switch(select){
		case 1: // 상품 추가하기
			cout <<"\n시작-상품관리-상품 추가하기"<<endl;
			cout << "  상품 입력 : ";
			cin >> productName >> amount;
			addProduct(productName, amount);
			break;
		case 2: // 상품 목록 보기
			cout <<"\n시작-상품관리-상품 목록 보기"<<endl;
			printProductList();
			break;
		case 3: // 종료
			cout <<"\n시작-상품관리-종료"<<endl;
			cout <<"     상품관리를 종료합니다."<<endl;
			return ;
		default :
			cout << "잘못 입력하셨습니다.\n" << endl;
		}
	}while(1);
}

void VendingMachine::addProduct(string productName, int amount)
{
	if( amount > 50 ){
		cout << "상품 입력 실패 (상품 개수 초과, 최대 50개)"<< endl;
		return;
	}
	if(catalog.isInCatalog(productName)){
		int n = 0;
		while( n++ < list.getTheNumOfProduct() ){
			if( list.getNthProduct(n)->getProductName() == productName ){
				int sum = list.getNthProduct(n)->getAmount() + amount;
				if( sum > 50){
					cout << "상품 추가 실패 (상품 개수 초과, 최대 50개)"<<endl;
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
					cout << "상품 빼기 실패 ( 현재 보관 수량보다 많은 양을 빼려고 함 ) " << endl;
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
	cout << "   상품명" <<'\t'<< "단가" <<'\t'<<"수량"<< endl;
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
		cout<<"\n시작-상품판매"<<endl;
		cout<<"  1. 장바구니에 상품 추가"<<endl;
		cout<<"  2. 장바구니서 상품 삭제"<<endl;
		cout<<"  3. 장바구니 보기"<<endl;
		cout<<"  4. 결제"<<endl;
		cout<<"  5. 판매취소"<<endl;
		cout<<"  번호를 선택하세요 : ";
		cin >> select;

		switch(select){
		case 1: // 장바구니에 상품 추가
			cout <<"\n시작-상품판매-장바구니에 물품 추가"<<endl;
			cout << "  현재 상품 목록" << endl;
			printProductList();
			addToCart();
			break;
		case 2: // 장바구니서 상품 삭제
			cout <<"\n시작-상품판매-장바구니서 상품 삭제"<<endl;
			cout <<"  현재 장바구니 목록"<<endl;
			cart.printList();
			subFromCart();
			break;
		case 3: // 장바구니 보기
			cout <<"\n시작-상품판매-장바구니 보기"<<endl;
			cout <<"  현재 장바구니 목록"<<endl;
			cart.printList();
			break ;
		case 4: // 결제
			cout <<"\n시작-상품판매-결제"<< endl;
			pay();
			break;
		case 5: // 판매취소
			cancelSale();
			return;
		default : 
			cout << "잘못 입력하셨습니다.\n" << endl;
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
		cout <<"대금을 입력해 주십시오. : ";
		cin >> payment;
		if( total > payment ){
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
				cout << "거스름돈은 "<< payment - total <<"원입니다."<< endl;
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
		cout << "  자판기 내에 상품이 없습니다."<<endl;
		return;
	}
	cout << "   상품을 선택하세요(취소 0) : ";
	int number;
	cin >> number;
	if( number == 0)
		return;
	else if( number > list.getTheNumOfProduct() || number < 0){
		cout << "   없는 번호를 선택하셨습니다."<< endl;
		return;
	}
	cout << "   수량을 선택하세요 : ";
	int inputAmount;
	cin >> inputAmount;
	string productName = list.getNthProduct ( number )->getProductName();
	int productAmount = list.getNthProduct( number )->getAmount();
	if( productAmount >= inputAmount ){
		cart.add( productName, inputAmount );
		subProduct( productName, inputAmount );
	}else
		cout << "  선택하신 \""<< productName <<"\"은(는) "<< productAmount <<"개만 가능합니다."<< endl;
	return;
}

void VendingMachine::subFromCart()
{
	if(cart.getTheNumOfProduct() == 0){
		cout << "  장바구니 안에 상품이 없습니다. " << endl;
		return;
	}
	cout << "   삭제할 상품을 선택하세요(취소 0) : ";
	int number;
	cin >> number;
	if( number == 0)
		return;
	else if( number > cart.getTheNumOfProduct() || number < 0){
		cout << "   없는 번호를 선택하셨습니다."<< endl;
		return;
	}
	string productName = cart.getNthProduct( number )->getProductName();
	int productAmount = cart.getNthProduct( number )->getAmount();
	cart.sub( productName , productAmount );
	addProduct( productName, productAmount );
	
	return;
}

