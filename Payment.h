#ifndef _PAYMENT_
#define _PAYMENT_

#include "ShoppingCart.h"

class Payment
{
public:
	Payment(ShoppingCart&);
	void setPayment(int);
	int getPayment() const;
	void setBalance(int);
	int getBalance() const;
	void setSubTotal(int);
	int getSubTotal() const;
	void setVat(int);
	int getVat() const;
	void setTotal(int);
	int getTotal() const;
	void printResult();

private:
	ShoppingCart& cart;
	int subTotal;
	int vat;
	int total;
	int payment;
	int balance;
};

#endif