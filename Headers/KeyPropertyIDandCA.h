#pragma once
#include "Property.h"

class KeyPropertyIDandCA : Key
{
private:
	Zaznam * pointerToRecord;
public:
	int zip;
	std::string caName;
	int blockIndex;
	
	int getZip();
	std::string getcaName();
	int getBlockIndex();

	void setZip(int newZip);
	void setCaName(std::string newCa);
	void setBlockIndex(int newBI);
	void setPointerToRecord(Zaznam * newPointer);
	Zaznam * getZaznam() {
		return pointerToRecord;
	}

	int compare(Key *kluc) {
		if (this->zip == static_cast<KeyPropertyIDandCA*>(kluc)->zip) {
			if (this->caName == static_cast<KeyPropertyIDandCA*>(kluc)->caName) {
				return 0;
			}
			if (this->caName > static_cast<KeyPropertyIDandCA*>(kluc)->caName) {
				return 1;
			}
			if (this->caName < static_cast<KeyPropertyIDandCA*>(kluc)->caName) {
				return -1;
			}
		}
		if (this->zip > static_cast<KeyPropertyIDandCA*>(kluc)->zip) {
			return 1;
		}
		if (this->zip < static_cast<KeyPropertyIDandCA*>(kluc)->zip) {
			return -1;
		}
	}

	KeyPropertyIDandCA *newInstance() {
		KeyPropertyIDandCA * newPI = new KeyPropertyIDandCA();
		return newPI;
	}

	std::string toString() {
		return "Zip: " + std::to_string(zip) + " K.uzemie: " + caName + " Block index: " + std::to_string(blockIndex);
	}

	void fromByteArray(char * record) {
		char bufferId[4];
		char bufferCaName[15];
		char bufferBlockIndex[4];
		for (int i = 0; i < this->getSize(); i++) {
			if (i >= 0 && i < 4) {
				bufferId[i] = record[i];
			}
			else if (i >= 4 && i < 19) {
				bufferCaName[i - 4] = record[i];
			}
			else  {
				bufferBlockIndex[i - 19] = record[i];
			}
			
		}
		memcpy(&zip, bufferId, 4);
		caName = bufferCaName;
		memcpy(&blockIndex, bufferBlockIndex, 4);
	}

	virtual std::vector<unsigned char> *toByteArray(std::vector<unsigned char> *vec) {
		unsigned char buffer[4];
		memset(buffer, 0, 4);
		memcpy(buffer, &zip, 4);
		vec->insert(vec->end(), buffer, buffer + 4);

		char buffer1[15];
		memset(buffer, 0, 15);
		std::strcpy(buffer1, caName.c_str());
		vec->insert(vec->end(), buffer1, buffer1 + 15);

		unsigned char buffer2[4];
		memset(buffer, 0, 4);
		memcpy(buffer2, &blockIndex, 4);
		vec->insert(vec->end(), buffer2, buffer2 + 4);

		return vec;
	}

	int getSize() {
		return 4+15+4;
	}
	KeyPropertyIDandCA();
};

