#include <iostream>
using namespace std;

#include <string>
#include "VendingMachine.h"

int main(void)
{
	VendingMachine ven;
	int select;
	do{
		cout << "\n시작" << endl;
		cout << "  1. 상품관리\n  2. 상품 판매\n  3. 종료\n  번호를 선택하세요. : ";
		cin >> select;

		switch(select){
		case 1: 
			ven.management();
			break;
		case 2:
			ven.sale();
			break;
		case 3:
			return 0;
		default :
			cout << "잘못 입력하셨습니다." << endl;
		}
	}while(1);
}
