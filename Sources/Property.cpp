#include "Property.h"



int Property::getIdNumber()
{
	return idNumber;
}

int Property::getZIPNumber()
{
	return ZIPnumber;
}

std::string Property::getCatasterName()
{
	return catasterName;
}

std::string Property::getDescription()
{
	return description;
}

void Property::toByteArray(std::vector<unsigned char>* vec)
{
	unsigned char buffer[4];
	memset(buffer, 0, 4);
	memcpy(buffer, &idNumber, 4);
	vec->insert(vec->end(), buffer, buffer + 4);

	char buffer1[15];
	memset(buffer1, 0, 15);
	std::strcpy(buffer1, catasterName.c_str());
	vec->insert(vec->end(), buffer1, buffer1 + 15);

	unsigned char buffer2[4];
	memset(buffer2, 0, 4);
	memcpy(buffer2, &ZIPnumber, 4);
	vec->insert(vec->end(), buffer2, buffer2 + 4);

	char buffer3[20];
	memset(buffer3, 0, 20);
	std::strcpy(buffer3, description.c_str());
	vec->insert(vec->end(), buffer3, buffer3 + 20);

}

void Property::fromByteArray(char * buff)
{
	char bufferId[4];
	char bufferCaName[15];
	char bufferZip[4];
	char bufferDescr[20];
	for (int i = 0; i < this->getSize(); i++) {
		if (i >= 0 && i < 4) {
			bufferId[i] = buff[i];
		}
		else if (i >= 4 && i < 19) {
			bufferCaName[i - 4] = buff[i];
		}
		else if (i >= 19 && i < 23) {
			bufferZip[i - 19] = buff[i];
		}
		else {
			bufferDescr[i - 23] = buff[i];
		}
	}
	memcpy(&idNumber, bufferId, 4);
	catasterName = bufferCaName;
	memcpy(&ZIPnumber, bufferZip, 4);
	description = bufferDescr;
}

void Property::setIdNumber(int newId)
{
	idNumber = newId;
}

void Property::setZIPNumber(int newZIP)
{
	ZIPnumber = newZIP;
}

void Property::setCatasterName(std::string newCatasterName)
{
	catasterName = newCatasterName;
}

void Property::setDescription(std::string newDesc)
{
	description = newDesc;
}

int Property::getSize()
{
	return 4 + 4 + 15 + 20;
}

std::string Property::toString()
{
	return "ID: " + std::to_string(getIdNumber()) + " Zip: " + std::to_string(getZIPNumber()) + " K.uzemie: " + getCatasterName() + " Popis: " + getDescription();
}

Property::Property()
{
}

Property::Property(int idNum, int zip, std::string caName, std::string desc): idNumber(idNum), ZIPnumber(zip), catasterName(caName), description(desc)
{
}
