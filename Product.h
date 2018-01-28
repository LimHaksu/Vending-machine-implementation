#ifndef _PRODUCT_
#define _PRODUCT_

class Product
{
public:
	Product(string, int);

	void setLPointer(Product*);
	void setRPointer(Product*);
	Product* getLPointer() const;
	Product* getRPointer() const;
	
	void setAmount(int);
	int getAmount() const;
	string getProductName() const;
	bool operator==(const Product&) const;

private:
	Product* LPointer;
	Product* RPointer;
	string name;
	int amount;
};

#endif