#pragma once
#include <string>
#include "BTree.h"
//#include "BTree.h"
class Property : Zaznam
{
private:
	int idNumber;
	int ZIPnumber;
	std::string catasterName;
	std::string description;
public:
	int getIdNumber();
	int getZIPNumber();
	std::string getCatasterName();
	std::string getDescription();

	void toByteArray(std::vector<unsigned char> *vec);
	void fromByteArray(char* buff);
	void setIdNumber(int newId);
	void setZIPNumber(int newZIP);
	void setCatasterName(std::string newCatasterName);
	void setDescription(std::string newDesc);

	int getSize(); 	
	std::string toString();
/*	Zaznam *newInstance() {
		Property * newProperty = new Property();
		return newProperty;
	}*/
	Property();
	Property(int idNum, int zip, std::string caName, std::string desc);
};

