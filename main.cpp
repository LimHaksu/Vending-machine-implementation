#include <iostream>
using namespace std;

#include <string>
#include "VendingMachine.h"

int main(void)
{
	VendingMachine ven;
	int select;
	do{
		cout << "\n����" << endl;
		cout << "  1. ��ǰ����\n  2. ��ǰ �Ǹ�\n  3. ����\n  ��ȣ�� �����ϼ���. : ";
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
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
	}while(1);
}
