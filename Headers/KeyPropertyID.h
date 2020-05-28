#pragma once
#include "Property.h"
//#include "InterfaceRecord.h"
class KeyPropertyID : Key
{
private:
	Zaznam * pointerToRecord;
	
public:
	int id;
	int blockIndex;

	int getId();
	int getBlockIndex();
	KeyPropertyID();

	void setPointerToRecord(Zaznam * newPointer);
	void setId(int newId);
	void setBlockIndex(int newBi);

	Zaznam * getZaznam() {
		return pointerToRecord;
	}

	int compare(Key *kluc) {
		if (this->id == static_cast<KeyPropertyID*>(kluc)->id) {
			return 0;
		}
		if (this->id > static_cast<KeyPropertyID*>(kluc)->id) {
			return 1;
		}
		if (this->id < static_cast<KeyPropertyID*>(kluc)->id) {
			return -1;
		}
	}

	KeyPropertyID *newInstance() {
		KeyPropertyID * newPI = new KeyPropertyID();
		return newPI;
	}

	std::string toString() {
		return "Id:" + std::to_string(id) + " Blok index: " + std::to_string(blockIndex);
	}

	void fromByteArray(char * record) {
		char bufferId[4];
		char bufferBlockIndex[4];
		for (int i = 0; i < this->getSize(); i++) {
			if (i >= 0 && i < 4) {
				bufferId[i] = record[i];
			}
			else {
				bufferBlockIndex[i - 4] = record[i];
			}
			
		}
		memcpy(&id, bufferId, 4);
		memcpy(&blockIndex, bufferBlockIndex, 4);
	}

	virtual std::vector<unsigned char> *toByteArray(std::vector<unsigned char> *vec) {
		unsigned char buffer[4];
		memset(buffer, 0, 4);
		memcpy(buffer, &id, 4);
		vec->insert(vec->end(), buffer, buffer + 4);

		unsigned char buffer1[4];
		memset(buffer, 0, 4);
		memcpy(buffer1, &blockIndex, 4);
		vec->insert(vec->end(), buffer1, buffer1 + 4);
		return vec;
	}
	int getSize() {
		return 4 + 4;
	}
	
};

