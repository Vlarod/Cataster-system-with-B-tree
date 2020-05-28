#include <string.h>
#include <iostream>
#include <bitset>

class Zaznam
{
public:
	virtual int getSize() = 0; // velkost zaznamu podla typov
	virtual std::string toString() = 0;
	virtual void toByteArray(std::vector<unsigned char> *vec) = 0;
	virtual void fromByteArray(char* buff) = 0;
};

class Key
	//interface
{
public:
	virtual int compare(Key *key) = 0;
	virtual std::string toString() = 0;
	virtual void fromByteArray(char * record) = 0;
	virtual Zaznam *getZaznam() = 0;
	virtual Key *newInstance() = 0;
	virtual std::vector<unsigned char> *toByteArray(std::vector<unsigned char> *vec) = 0;
	virtual int getSize() = 0;
	//virtual int compareTo() = 0;
	//new INstance a instancia zdedi alebo reflexia
};


