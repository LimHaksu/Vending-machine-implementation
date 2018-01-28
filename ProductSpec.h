#ifndef _PRODUCT_SPEC_
#define _PRODUCT_SPEC_

class ProductSpec
{
public:
	string getName() const ;
	void setName(string);
	int getPrice() const ;
	void setPrice(int);
private:
	string name;
	int price;	
};

#endif