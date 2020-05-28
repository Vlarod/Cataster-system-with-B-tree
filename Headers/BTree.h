#include <vector>
#include "InterfaceRecord.h"
#include <iostream>
#include <fstream>
#include <bitset>
#include <cstring>
#include <stack> 
#pragma once



class Block
{
private:
	Block *parent;

	int index;
	int adress;

public:
	Block *leftBrother;
	Block *rightBrother;

	Block *getParent();
	void setParent(Block *newParent);

	std::vector<Key*> *records;
	std::vector<int> *sonsAdreses;

	int getIndex();

	void setIndex(int newIndex);


	Block();

	Block(char *stringBlock);

};


inline Block * Block::getParent()
{
	return parent;
}

inline void Block::setParent(Block * newParent)
{
	parent = newParent;
}

inline int Block::getIndex()
{
	return index;
}



inline void Block::setIndex(int newIndex)
{
	index = newIndex;
}


inline Block::Block()
{
	/*TU!!*/	records = new std::vector<Key*>;
	/*TU!!*/	sonsAdreses = new std::vector<int>;
	parent = nullptr;
}

inline Block::Block(char * stringBlock)
{
	records = new std::vector<Key*>;
	sonsAdreses = new std::vector<int>;
	parent = nullptr;
	char* stringRecord;
}



class Btree
{
private:
	Block *root;
	int treeDegree;
	int lastAdressIndex;
	std::string fileName;

public:
	Key * searchKeyInBlock(std::vector<Key*> *vector, Key *key);
	void searchBlockViaIndex(int index, int blockSize, Key *key);
	Block *searchBlockViaKey(Key *key);
	Key *searchKey(Key *key);
	bool insert(Key * key);
	void writeBlockToFile(Block *block);
	int intFromBytes(char * bytes);
	char *readBlockBinFile(int adress);
	char *fromBitsBlock(char * str);
	Block *getBlockFromChar(char * str);
	void sequenceOutPrint();
	void inOrderOutPrint();
	void inOrderRecordOutprint();

	int getLastAdressIndex();
	void setLastAdress(int newAdressIndex);

	int getAdressViaIndex(int index);

	int getRecordSize();

	int getRootIndex();

	std::vector<Block*> *getSequenceBlocks();
	Btree(int degree, std::string filN);
	Btree();
	~Btree();

};

inline Key * Btree::searchKeyInBlock(std::vector<Key*>* vector, Key *key)
{
	for (int i = 0; i < vector->size(); i++) {
		if (key->compare(vector->at(i)) == 0) {
			return vector->at(i);
		}
	}
	return nullptr;
}

inline void Btree::searchBlockViaIndex(int index, int blockSize, Key *key)
{
	int BLOCK_SIZE = ((key->getSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	int blockAdress = index * ((key->getSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::streampos size;
	char *block;
	std::ifstream file(fileName, std::ios::out | std::ios::binary);
	if (file.is_open())
	{

		size = BLOCK_SIZE;
		block = new char[size];
		file.seekg(blockAdress, std::ios::beg);
		file.read(block, size);
		file.close();

	}

	int valueIndex = 0; //kolko mam recordov vo vectore bloku
	int indx = 0; // index v zazname
	char * record;
	char *adress = new char[4];
	char *validRecords = new char[4];
	bool recIn = false;
	bool recCompl = false;
	int valRec = 0;
	record = new char[key->getSize()];

	Block *newBlock = new Block();
	for (int i = 0; i < BLOCK_SIZE; i++) {

		if (i < 4) {
			validRecords[i] = block[i];
		}

		else if (i >= 4) {
			if (valueIndex == valRec && recCompl == false) {
				i = (i + (((treeDegree - 1) - valueIndex) *key->getSize()));
				indx = 0;
				valueIndex = treeDegree - 1;
				recCompl = true;
			}

			record[indx] = block[i];

			if (valueIndex == (treeDegree - 1)) {
				adress[indx] = block[i];
			}

			if ((indx + 1) % key->getSize() == 0 && valueIndex < (treeDegree - 1) && newBlock->records->size() <= valRec) {

				Key * newKey = key->newInstance();

				newKey->fromByteArray(record);
				newBlock->records->push_back(newKey);
				memset(record, 0, strlen(record));
				valueIndex++;
				indx = -1;
			}

			else if (valueIndex == (treeDegree - 1) && (indx + 1) % 4 == 0) {

				if (adress[0] == 0 && adress[1] == 0 && adress[2] == 0 && adress[3] == 0) {
					break;
				}
				int newAdress = this->intFromBytes(adress);
				newBlock->sonsAdreses->push_back(newAdress);
				indx = -1;
				memset(adress, 0, 4);
			}


		}

		if (i == 3 && recIn == false) {
			valRec = this->intFromBytes(validRecords);
			indx = -1;
			recIn = true;
			memset(validRecords, 0, 4);
		}
		indx++;
	}
	root = newBlock;
}

inline Block * Btree::searchBlockViaKey(Key * key)
{
	int BLOCK_SIZE = ((key->getSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);

	Block *myRoot = root;
	Key *leftB;
	Key *rightB;
	int blockIndex;
	int blockAdress;
	while (myRoot != nullptr) {
		for (int i = 0; i < myRoot->records->size(); i++) {

			if (i != 0) {
				leftB = myRoot->records->at(i - 1);
			}
			else {
				leftB = nullptr;
			}
			if (i != myRoot->records->size() - 1) {
				rightB = myRoot->records->at(i + 1);
			}
			else {
				rightB = nullptr;
			}

			if (key->compare(myRoot->records->at(i)) == 0) {
				return myRoot;
			}

			else if (myRoot->sonsAdreses->size() == 0) {
				return myRoot;
			}

			else if (leftB == nullptr && key->compare(myRoot->records->at(i)) == -1) {
				blockIndex = 0;
				break;
			}
			else if (key->compare(myRoot->records->at(i)) == -1 && key->compare(leftB) == 1) {
				blockIndex = i;
				break;
			}

			else if (key->compare(myRoot->records->at(i)) == 1 && rightB == nullptr) {
				blockIndex = myRoot->sonsAdreses->size() - 1;
				break;
			}
			else if (key->compare(myRoot->records->at(i)) == 1 && key->compare(rightB) == -1) {
				blockIndex = i + 1;
				break;
			}
		}
		if (myRoot->sonsAdreses->size() != 0) {

			blockAdress = myRoot->sonsAdreses->at(blockIndex);//blockIndex

			int originalBlockIndex = blockAdress / ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
			char *block = readBlockBinFile(blockAdress);

			int valueIndex = 0; //kolko mam recordov vo vectore bloku
			int index = 0; // index v zazname
			char * record;
			char *adress = new char[4];
			char *validRecords = new char[4];
			bool recIn = false;
			bool recCompl = false;
			int valRec = 0;
			record = new char[this->getRecordSize()];

			Block *newBlock = new Block();
			for (int i = 0; i < BLOCK_SIZE; i++) {

				if (i < 4) {
					validRecords[i] = block[i];
				}

				else if (i >= 4) {
					if (valueIndex == valRec && recCompl == false) {
						i = (i + (((treeDegree - 1) - valueIndex) * this->getRecordSize()));
						index = 0;
						valueIndex = treeDegree - 1;
						recCompl = true;
					}

					record[index] = block[i];

					if (valueIndex == (treeDegree - 1)) {
						adress[index] = block[i];
					}

					if ((index + 1) % this->getRecordSize() == 0 && valueIndex < (treeDegree - 1) && newBlock->records->size() <= valRec) {

						Key * newKey = key->newInstance();

						newKey->fromByteArray(record);
						newBlock->records->push_back(newKey);
						memset(record, 0, strlen(record));
						valueIndex++;
						index = -1;
					}

					else if (valueIndex == (treeDegree - 1) && (index + 1) % 4 == 0) {

						if (adress[0] == 0 && adress[1] == 0 && adress[2] == 0 && adress[3] == 0) {
							break;
						}
						int newAdress = this->intFromBytes(adress);
						newBlock->sonsAdreses->push_back(newAdress);
						index = -1;
						memset(adress, 0, 4);
					}


				}

				if (i == 3 && recIn == false) {
					valRec = this->intFromBytes(validRecords);
					index = -1;
					recIn = true;
					memset(validRecords, 0, 4);
				}
				index++;
			}

			newBlock->setParent(myRoot);
			newBlock->setIndex(originalBlockIndex);
			myRoot = newBlock;

		}
		else {

			return myRoot;
		}
	}
}

inline Key * Btree::searchKey(Key * key)
{
	if (root != nullptr) {
		Block *findBlock = this->searchBlockViaKey(key);
		for (int i = 0; i < findBlock->records->size(); i++) {
			if (key->compare(findBlock->records->at(i)) == 0) {
				return findBlock->records->at(i);
			}
		}
		return nullptr;
	}
	else {
		return nullptr;
	}
}

inline bool Btree::insert(Key * key)
{

	int BLOCK_SIZE = ((key->getSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::streampos size;
	size = BLOCK_SIZE;
	bool inserted = false;
	bool notPlace = false;
	int adress1;
	int adress2;
	int adress2_1;
	int recordIndex;
	Key *iKey = key;
	if (root != nullptr) {	//ak root neexistuje
		Block *findBlock = searchBlockViaKey(iKey);

		if (searchKeyInBlock(findBlock->records, iKey) == nullptr) { //ak sa kluc nenachadza v strukture

			while (inserted == false) {
				if (findBlock == nullptr) {
					Block * newRoot = new Block();
					newRoot->setIndex(lastAdressIndex);
					setLastAdress(lastAdressIndex + 1);
					if (lastAdressIndex == 8) {
						int aaee = 0;
					}
					newRoot->sonsAdreses->push_back(adress1);
					newRoot->sonsAdreses->push_back(adress2);
					findBlock = newRoot;
					root = newRoot;
				}
				if (findBlock->records->size() != (treeDegree - 1)) { //ak je v bloku miesto
					findBlock->records->push_back(iKey);
					int recSize = findBlock->records->size();
					if (recSize > 1) {
						for (int i = findBlock->records->size() - 2; i >= 0; i--) {
							if (iKey->compare(findBlock->records->at(i)) == 1) {
								findBlock->records->at(i + 1) = iKey;
								recordIndex = i + 1;
								break;
							}
							else if (i == 0) {
								findBlock->records->at(i + 1) = findBlock->records->at(i);
								findBlock->records->at(i) = iKey;
								recordIndex = i;
							}
							else {
								findBlock->records->at(i + 1) = findBlock->records->at(i);
							}
						}
					}
					else {
						if (iKey->compare(findBlock->records->at(0)) == 0) {
							writeBlockToFile(findBlock);
							break;
						}
						if (iKey->compare(findBlock->records->at(0)) != 1) {
							findBlock->records->push_back(iKey);
							findBlock->records->at(1) = findBlock->records->at(0);
							findBlock->records->at(0) = iKey;
							recordIndex = 0;
						}

					}
					if (notPlace == true) {
						//preusporiadanie adries
						for (int i = findBlock->sonsAdreses->size() - 2; i >= 0; i--) {
							if (i == recordIndex) {
								findBlock->sonsAdreses->at(i + 1) = adress2;
								break;
							}
							else {
								findBlock->sonsAdreses->at(i + 1) = findBlock->sonsAdreses->at(i);
							}
						}
					}
					writeBlockToFile(findBlock);
					return true;
				}
				else { //ak v bloku miesto nie je

					adress1 = getAdressViaIndex(findBlock->getIndex());

					Block *alocBlock = new Block();
					alocBlock->setParent(findBlock->getParent());
					alocBlock->setIndex(lastAdressIndex);
					setLastAdress(lastAdressIndex + 1);
					if (lastAdressIndex == 8) {
						int aaee = 0;
					}


					//rozdelenie adries

					findBlock->records->push_back(iKey);
					if (findBlock->records->size() > 1) {
						for (int i = findBlock->records->size() - 2; i >= 0; i--) {
							if (iKey->compare(findBlock->records->at(i)) == 1) {
								findBlock->records->at(i + 1) = iKey;
								recordIndex = i + 1;
								break;
							}
							else if (i == 0) {
								findBlock->records->at(i + 1) = findBlock->records->at(i);
								findBlock->records->at(i) = iKey;
								recordIndex = i;
							}
							else {
								findBlock->records->at(i + 1) = findBlock->records->at(i);
							}
						}
					}
					else {

						if (iKey->compare(findBlock->records->at(0)) != 1) {
							findBlock->records->push_back(iKey);
							findBlock->records->at(1) = findBlock->records->at(0);
							findBlock->records->at(0) = iKey;
							recordIndex = 0;
						}
					}
					//
					if (notPlace == true) {
						//preusporiadanie adries
						for (int i = findBlock->sonsAdreses->size() - 2; i >= 0; i--) {
							if (i == recordIndex) {
								findBlock->sonsAdreses->at(i + 1) = adress2;
								break;
							}
							else {
								findBlock->sonsAdreses->at(i + 1) = findBlock->sonsAdreses->at(i);
							}
						}
					}
					//
					adress2 = getAdressViaIndex(alocBlock->getIndex());
					//
					if (findBlock->sonsAdreses->size() > treeDegree) {

						int numChangAdress = round(findBlock->sonsAdreses->size() / 2);
						int pomNum = 0;
						for (int a = numChangAdress; a < findBlock->sonsAdreses->size(); a++) {
							alocBlock->sonsAdreses->push_back(findBlock->sonsAdreses->at(a));
							findBlock->sonsAdreses->erase(findBlock->sonsAdreses->begin() + a);
							a--;
						}
					}
					//
					int indexmedian = (round(findBlock->records->size() - 1) / 2);
					iKey = findBlock->records->at(indexmedian);
					for (int i = indexmedian + 1; i < findBlock->records->size(); i++) {
						Key *nKey = findBlock->records->at(i);
						alocBlock->records->push_back(nKey);
						findBlock->records->erase(findBlock->records->begin() + i);
						i--;
					}
					notPlace = true;
					findBlock->records->erase(findBlock->records->begin() + indexmedian);
					writeBlockToFile(findBlock);

					if (findBlock->getParent() != nullptr) {
						findBlock->getParent()->sonsAdreses->push_back(adress2);

						/*	if (findBlock->getParent()->sonsAdreses->size() <= treeDegree) {
						writeBlockToFile(findBlock->getParent());
						}*/
					}
					writeBlockToFile(alocBlock);
					findBlock = findBlock->getParent();
				}

			}

		}
		else {
			return false;
		}
	}
	else {
		std::vector<unsigned char> * bytes = new std::vector<unsigned char>;
		for (int i = 0; i < BLOCK_SIZE; i++) {
			bytes->push_back(0);
		}
		root = new Block(); //vytvorenie roota
		root->setIndex(lastAdressIndex);
		root->setParent(nullptr);
		setLastAdress(getLastAdressIndex() + 1);
		root->records->push_back(key);

		unsigned char buffer[4];
		int x = 1;
		memcpy(buffer, &x, 4);
		bytes->insert(bytes->end(), buffer, buffer + 4);

		key->toByteArray(bytes);

		int freeRecords = ((treeDegree - 1) - 1) * (key->getSize());
		if (freeRecords != 0) {
			for (int i = 0; i < freeRecords; i++) {
				bytes->push_back(0);
			}
		}

		int freeSizeAdress = ((treeDegree) * 4);
		if (freeSizeAdress > 0) {
			for (int i = 0; i < freeSizeAdress; i++) {
				bytes->push_back(0);
			}
		}

		std::ofstream OutFile;
		OutFile.open(fileName, std::ios::in | std::ios::binary);
		OutFile.write((char*)&*(bytes->begin()), bytes->size());
		OutFile.close();
		return true;

	}

}

inline void Btree::writeBlockToFile(Block * block)
{
	std::vector<unsigned char> * bytes = new std::vector<unsigned char>;
	int BLOCK_SIZE = ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::streampos size;
	size = BLOCK_SIZE;

	unsigned char buffer[4];
	int x = block->records->size();
	memcpy(buffer, &x, 4);
	bytes->insert(bytes->end(), buffer, buffer + 4);


	for (int i = 0; i < block->records->size(); i++)
	{
		block->records->at(i)->toByteArray(bytes);
	}

	int freeRecords = ((treeDegree - 1) - block->records->size()) * this->getRecordSize();
	if (freeRecords != 0) {
		for (int i = 0; i < freeRecords; i++) {
			bytes->push_back(0);
		}
	}

	for (int j = 0; j < block->sonsAdreses->size(); j++)
	{
		unsigned char buffer[4];
		int x = block->sonsAdreses->at(j);
		memcpy(buffer, &x, 4);
		bytes->insert(bytes->end(), buffer, buffer + 4);
	}


	int freeSizeAdress = ((treeDegree - block->sonsAdreses->size()) * 4);
	if (freeSizeAdress > 0) {
		for (int i = 0; i < freeSizeAdress; i++) {
			bytes->push_back(0);
		}
	}

	std::ofstream OutFile;
	OutFile.open(fileName, std::ios::in | std::ios::binary);
	OutFile.seekp(getAdressViaIndex(block->getIndex()));
	int add = getAdressViaIndex(block->getIndex());
	OutFile.write((char*)&*(bytes->begin()), bytes->size());
	OutFile.close();
}


inline int Btree::intFromBytes(char * bytes)
{
	int result;
	memcpy(&result, bytes, 4);

	return result;
}

inline char * Btree::readBlockBinFile(int adress)
{
	std::streampos size;
	char * memblock;
	int BLOCK_SIZE = ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::ifstream file(fileName, std::ios::out | std::ios::binary);
	if (file.is_open())
	{

		size = BLOCK_SIZE;
		memblock = new char[size];
		file.seekg(adress, std::ios::beg);
		file.read(memblock, size);
		file.close();

		return memblock;
	}
}

inline char * Btree::fromBitsBlock(char * str)
{
	int BLOCK_SIZE = ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::streampos size;
	size = BLOCK_SIZE;
	char *compStr = new char[size];

	char parsed = 0;
	int index = 0;
	int pom = 0;
	int ind = 0;
	for (int i = 0; i < size; i++) {
		pom++;
		if (str[i] == '1') {
			parsed |= 1 << (7 - (ind));
		}
		ind++;
		if (pom % 8 == 0 && i != 0) {
			compStr[index] = parsed;
			index++;
			parsed = 0;
			ind = 0;
		}
	}
	return compStr;
}

inline Block * Btree::getBlockFromChar(char * str)
{
	int BLOCK_SIZE = ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);


	int valueIndex = 0; //kolko mam recordov vo vectore bloku
	int index = 0; // index v zazname
	char * record;
	char adress[4];
	char validRecords[4];
	bool recIn = false;
	bool recCompl = false;
	int valRec = 0;
	record = new char[this->getRecordSize()];

	Block *newBlock = new Block();
	for (int i = 0; i < BLOCK_SIZE; i++) {

		if (i < 4) {
			validRecords[i] = str[i];
		}

		else if (i >= 4) {
			if (valueIndex == valRec && recCompl == false) {
				i = (i + (((treeDegree - 1) - valueIndex) * this->getRecordSize()));
				index = 0;
				valueIndex = treeDegree - 1;
				recCompl = true;
			}

			record[index] = str[i];

			if (valueIndex == (treeDegree - 1)) {
				adress[index] = str[i];
			}

			if ((index + 1) % this->getRecordSize() == 0 && valueIndex < (treeDegree - 1)) {

				Key * newKey = root->records->at(0)->newInstance();

				newKey->fromByteArray(record);
				newBlock->records->push_back(newKey);

				valueIndex++;
				index = -1;
			}

			else if (valueIndex == (treeDegree - 1) && (index + 1) % 4 == 0) {

				if ((adress[0] == 0)) {
					break;
				}
				int newAdress = this->intFromBytes(adress);
				newBlock->sonsAdreses->push_back(newAdress);
				index = -1;
			}


		}

		if (i == 3 && recIn == false) {
			valRec = this->intFromBytes(validRecords);
			index = -1;
			recIn = true;
		}
		index++;
	}

	return newBlock;
}

inline void Btree::sequenceOutPrint()
{
	int BLOCK_SIZE = ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::ofstream myfile("sequenceOut.txt");

	for (int g = 0; g < this->getLastAdressIndex(); g++) {
		int blockAdress = this->getAdressViaIndex(g);
		char *block = readBlockBinFile(blockAdress);

		int valueIndex = 0; //kolko mam recordov vo vectore bloku
		int index = 0; // index v zazname
		char * record;
		char *adress = new char[4];
		char *validRecords = new char[4];
		bool recIn = false;
		bool recCompl = false;
		int valRec = 0;
		record = new char[this->getRecordSize()];

		Block *newBlock = new Block();
		for (int i = 0; i < BLOCK_SIZE; i++) {

			if (i < 4) {
				validRecords[i] = block[i];
			}

			else if (i >= 4) {
				if (valueIndex == valRec && recCompl == false) {
					i = (i + (((treeDegree - 1) - valueIndex) * this->getRecordSize()));
					index = 0;
					valueIndex = treeDegree - 1;
					recCompl = true;
				}

				record[index] = block[i];

				if (valueIndex == (treeDegree - 1)) {
					adress[index] = block[i];
				}

				if ((index + 1) % this->getRecordSize() == 0 && valueIndex < (treeDegree - 1) && newBlock->records->size() <= valRec) {

					Key * newKey = this->root->records->at(0)->newInstance();

					newKey->fromByteArray(record);
					newBlock->records->push_back(newKey);
					memset(record, 0, strlen(record));
					valueIndex++;
					index = -1;
				}

				else if (valueIndex == (treeDegree - 1) && (index + 1) % 4 == 0) {

					if (adress[0] == 0 && adress[1] == 0 && adress[2] == 0 && adress[3] == 0) {
						break;
					}
					int newAdress = this->intFromBytes(adress);
					newBlock->sonsAdreses->push_back(newAdress);
					index = -1;
					memset(adress, 0, 4);
				}


			}

			if (i == 3 && recIn == false) {
				valRec = this->intFromBytes(validRecords);
				index = -1;
				recIn = true;
				memset(validRecords, 0, 4);
			}
			index++;
		}

		if (myfile.is_open())
		{
			myfile << "\nBlock: " << g << "\n";
			for (int b = 0; b < newBlock->records->size(); b++) {
				myfile << "Zaznam: " << newBlock->records->at(b)->toString() << ";  ";
			}
			myfile << "\n";
			for (int c = 0; c < newBlock->sonsAdreses->size(); c++) {
				myfile << "Adresa: " << newBlock->sonsAdreses->at(c) << ";  ";
			}
			myfile << "\n";
		}
	}
	myfile.close();
}

inline void Btree::inOrderOutPrint()
{
	std::vector<Block*>* vector = new std::vector<Block*>;

	std::stack<Block*> stack;
	std::stack<int> stackAdres;
	Block *current = root;

	while (current != nullptr || stack.empty() == false)
	{

		while (current != nullptr)
		{
			if (stack.size() == 0) {
				stack.push(current);
			}
			else {
				if (stack.top() != current) {
					stack.push(current);
				}
			}

			if (stack.size() > stackAdres.size()) {
				stackAdres.push(0);
			}
			if (stackAdres.top() != current->sonsAdreses->size() && current->sonsAdreses->size() != 0) {
				int indexadress = stackAdres.top();
				int adress = current->sonsAdreses->at(indexadress);
				Block *block = this->getBlockFromChar(this->readBlockBinFile(adress));
				block->setParent(current);
				current = block;
			}
			else {
				current = nullptr;
			}
		}


		current = stack.top();
		stack.pop();

		if (stackAdres.top() <= 1) {
			vector->push_back(current);
		}
		stackAdres.pop();

		current = current->getParent();
		if (stackAdres.size() > 0) {
			stackAdres.top()++;
		}
		if (stackAdres.size() > 0) {
			if (stackAdres.top() == 1) {
				vector->push_back(current);
			}
		}
	}

	std::ofstream myfile("inOrderOut.txt");
	for (int g = 0; g < vector->size(); g++) {
		if (myfile.is_open())
		{
			myfile << "\nBlock: " << g << "\n";
			for (int b = 0; b < vector->at(g)->records->size(); b++) {
				myfile << "Zaznam: " << vector->at(g)->records->at(b)->toString() << ";  ";
			}
			myfile << "\n";
			for (int c = 0; c < vector->at(g)->sonsAdreses->size(); c++) {
				myfile << "Adresa: " << vector->at(g)->sonsAdreses->at(c) << ";  ";
			}
			myfile << "\n";
		}
	}
	myfile.close();
}

inline void Btree::inOrderRecordOutprint()
{
	std::vector<Key*>* vector = new std::vector<Key*>;

	std::stack<Block*> stack;
	std::stack<int> stackAdres;
	Block *current = root;

	while (current != nullptr || stack.empty() == false)
	{

		while (current != nullptr)
		{
			if (stack.size() == 0) {
				stack.push(current);
			}
			else {
				if (stack.top() != current) {
					stack.push(current);
				}
			}

			if (stack.size() > stackAdres.size()) {
				stackAdres.push(0);
			}
			if (stackAdres.top() != current->sonsAdreses->size() && current->sonsAdreses->size() != 0) {
				int indexadress = stackAdres.top();
				int adress = current->sonsAdreses->at(indexadress);
				Block *block = this->getBlockFromChar(this->readBlockBinFile(adress));
				block->setParent(current);

				if (stackAdres.top() != 0) {
					if (stackAdres.top() != stack.top()->sonsAdreses->size()) {
						vector->push_back(current->records->at(stackAdres.top() - 1));
					}
				}

				current = block;

			}
			else {
				if (current->sonsAdreses->size() != stackAdres.top() || stackAdres.top() == 0) {
					vector->push_back(current->records->at(stackAdres.top()));
				}
				current = nullptr;
			}
		}


		current = stack.top();
		stack.pop();


		stackAdres.pop();

		current = current->getParent();
		if (stackAdres.size() > 0) {
			stackAdres.top()++;
		}

	}

	std::ofstream myfile("inOrderRecordOut.txt");

	if (myfile.is_open())
	{
		for (int b = 0; b < vector->size(); b++) {
			myfile << "Zaznam: " << vector->at(b)->toString() << ";  ";
		}
	}
	myfile.close();
}

inline int Btree::getLastAdressIndex()
{
	return lastAdressIndex;
}

inline void Btree::setLastAdress(int newAdressIndex)
{
	lastAdressIndex = newAdressIndex;
}

inline int Btree::getAdressViaIndex(int index)
{
	return index * ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);

}

inline int Btree::getRecordSize()
{
	return root->records->at(0)->getSize();
}

inline int Btree::getRootIndex()
{
	return root->getIndex();
}

inline std::vector<Block*>* Btree::getSequenceBlocks()
{
	int ss = getLastAdressIndex();
	int BLOCK_SIZE = ((this->getRecordSize() * (treeDegree - 1)) + (treeDegree * 4) + 4);
	std::vector<Block*> *blocks = new std::vector<Block*>;
	for (int g = 1; g < this->getLastAdressIndex(); g++) {
		int blockAdress = this->getAdressViaIndex(g);
		char *block = readBlockBinFile(blockAdress);

		int valueIndex = 0; //kolko mam recordov vo vectore bloku
		int index = 0; // index v zazname
		char * record;
		char *adress = new char[4];
		char *validRecords = new char[4];
		bool recIn = false;
		bool recCompl = false;
		int valRec = 0;
		record = new char[this->getRecordSize()];

		Block *newBlock = new Block();
		for (int i = 0; i < BLOCK_SIZE; i++) {

			if (i < 4) {
				validRecords[i] = block[i];
			}

			else if (i >= 4) {
				if (valueIndex == valRec && recCompl == false) {
					i = (i + (((treeDegree - 1) - valueIndex) * this->getRecordSize()));
					index = 0;
					valueIndex = treeDegree - 1;
					recCompl = true;
				}

				record[index] = block[i];

				if (valueIndex == (treeDegree - 1)) {
					adress[index] = block[i];
				}

				if ((index + 1) % this->getRecordSize() == 0 && valueIndex < (treeDegree - 1) && newBlock->records->size() <= valRec) {

					Key * newKey = this->root->records->at(0)->newInstance();

					newKey->fromByteArray(record);
					newBlock->records->push_back(newKey);
					memset(record, 0, strlen(record));
					valueIndex++;
					index = -1;
				}

				else if (valueIndex == (treeDegree - 1) && (index + 1) % 4 == 0) {

					if (adress[0] == 0 && adress[1] == 0 && adress[2] == 0 && adress[3] == 0) {
						break;
					}
					int newAdress = this->intFromBytes(adress);
					newBlock->sonsAdreses->push_back(newAdress);
					index = -1;
					memset(adress, 0, 4);
				}


			}

			if (i == 3 && recIn == false) {
				valRec = this->intFromBytes(validRecords);
				index = -1;
				recIn = true;
				memset(validRecords, 0, 4);
			}
			index++;
		}
		blocks->push_back(newBlock);
	}
	return blocks;
}

inline Btree::Btree(int degree, std::string fillNam)
{
	fileName = fillNam;
	root = nullptr;
	treeDegree = degree;
	lastAdressIndex = 1;
}

inline Btree::Btree()
{
}

inline Btree::~Btree()
{
}

