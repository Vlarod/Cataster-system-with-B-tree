#include "MainSystem.h"



Btree * MainSystem::getPropertiesViaID()
{
	return propertiesViaID;
}

Btree * MainSystem::getPropertiesViaIDandCA()
{
	return propertiesViaIDandCA;
}

int MainSystem::getCurrLoadPropDataIndex()
{
	return currLoadPropDataIndex;
}

int MainSystem::getPropertiesViaIdDegree()
{
	return propertiesViaIdDegree;
}

int MainSystem::getPropertiesViaIdAndCADegree()
{
	return propertiesViaIdAndCADegree;
}

int MainSystem::getPropertySize()
{
	return propertySize;
}

int MainSystem::getLastIndex()
{
	return lastIndex;
}

std::string MainSystem::getDataFileName()
{
	return dataFile;
}

std::string MainSystem::getPropertiesViaIdFile()
{
	return propertiesViaIdFile;
}

std::string MainSystem::getPropertiesViaIdAndCAFile()
{
	return propertiesViaIdAndCAFile;
}

bool MainSystem::addProperty(int idNumber, int zipNumber, std::string caName, std::string descr)
{
	KeyPropertyID * newKey = new KeyPropertyID();
	KeyPropertyIDandCA * newKeyCa = new KeyPropertyIDandCA();
	Property * newProperty = new Property(idNumber,zipNumber,caName,descr);
	 
	newKey->setPointerToRecord((Zaznam*)newProperty);
	newKey->setId(idNumber);
	newKey->setBlockIndex(lastIndex);

	newKeyCa->setPointerToRecord((Zaznam*)newProperty);
	newKeyCa->setZip(newProperty->getZIPNumber());
	newKeyCa->setCaName(newProperty->getCatasterName());
	newKeyCa->setBlockIndex(lastIndex);

	if (getPropertiesViaID()->searchKey((Key*)newKey) == nullptr) {
		if (getPropertiesViaIDandCA()->searchKey((Key*)newKeyCa) == nullptr) {
			writeDataToFile(newProperty);

			if (propertiesViaID->insert((Key*)newKey) == true) {
				if (propertiesViaIDandCA->insert((Key*)newKeyCa) == true) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				return false;
			}
		}
	}
}

bool MainSystem::setDescription(std::string newdescr, Property * prop)
{
	prop->setDescription(newdescr);
	this->updateDataInFile(prop);
	return true;
}

void MainSystem::writeDataToFile(Property * prop)
{
	std::vector<unsigned char> *vect = new std::vector<unsigned char>;
	prop->toByteArray(vect);
	this->setPropertySize(prop->getSize());

	std::ofstream OutFile;
	OutFile.open(dataFile, std::ios::in | std::ios::binary);
	OutFile.seekp(lastIndex * vect->size());
	OutFile.write((char*)&*(vect->begin()), vect->size());
	OutFile.close();

	lastIndex++;
}

void MainSystem::updateDataInFile(Property * prop)
{
	std::vector<unsigned char> *vect = new std::vector<unsigned char>;
	prop->toByteArray(vect);

	std::ofstream OutFile;
	OutFile.open(dataFile, std::ios::in | std::ios::binary);
	OutFile.seekp(this->getCurrLoadPropDataIndex() * vect->size());
	OutFile.write((char*)&*(vect->begin()), vect->size());
	OutFile.close();
}

void MainSystem::setCurrLoadPropDataIndex(int newInd)
{
	currLoadPropDataIndex = newInd;
}

void MainSystem::setPropertiesViaIdDegree(int newdeg)
{
	propertiesViaIdDegree = newdeg;
}

void MainSystem::setPropertiesViaIdAndCaDegree(int newdeg)
{
	propertiesViaIdAndCADegree = newdeg;
}

void MainSystem::setPropertySize(int newSize)
{
	propertySize = newSize;
}

void MainSystem::setLastIndex(int nLIndex)
{
	lastIndex = nLIndex;
}

void MainSystem::setDataFile(std::string newDataFile)
{
	dataFile = newDataFile;
}

void MainSystem::generateData(int numberOfD)
{
	for (int i = 0; i < numberOfD; i++) {
		KeyPropertyID *newKeyId = new KeyPropertyID();
		KeyPropertyIDandCA *newKeyIdCa = new KeyPropertyIDandCA();
		int id = 1 + rand() % ((1000 + 1) - 1);
		int zip = 1 + rand() % ((1000 + 1) - 1);
		std::string caName = this->randomStringGenerator(14);
		std::string descr = this->randomStringGenerator(19);
		Property *newProperty = new Property(id,zip,caName,descr);
		
		newKeyId->setBlockIndex(lastIndex);
		newKeyId->setId(id);
		newKeyId->setPointerToRecord((Zaznam*)newProperty);

		newKeyIdCa->setBlockIndex(lastIndex);
		newKeyIdCa->setZip(zip);
		newKeyIdCa->setCaName(caName);
		newKeyIdCa->setPointerToRecord((Zaznam*)newProperty);

		writeDataToFile(newProperty);

		propertiesViaID->insert((Key*)newKeyId);
		propertiesViaIDandCA->insert((Key*)newKeyIdCa);
	}
}

void MainSystem::saveConf(std::string nameFile)
{
	std::ofstream myfile;
	myfile.open("conf.txt");
	myfile << lastIndex << "\n";
	myfile << dataFile << "\n";
	myfile << propertySize << "\n";

	myfile << propertiesViaIdDegree << "\n";	
	myfile << propertiesViaIdFile << "\n";
	myfile << this->getPropertiesViaID()->getRootIndex() << "\n";
	myfile << this->getPropertiesViaID()->getLastAdressIndex() << "\n";
	
	myfile << propertiesViaIdAndCADegree << "\n";	
	myfile << propertiesViaIdAndCAFile << "\n";
	myfile << this->getPropertiesViaIDandCA()->getRootIndex() << "\n";
	myfile << this->getPropertiesViaIDandCA()->getLastAdressIndex();

	myfile.close();
}

void MainSystem::readConf(std::string nameFile)
{
	std::string line;
	std::ifstream myfile("conf.txt");
	if (myfile.is_open())
	{
		int lastIndex1;
		int propertiesViaIdDegree1;
		int propertiesViaIdLastIndex;
		int propertiesViaIdAndCADegree1;
		int propertiesViaIdAndCALastIndex;

		std::string propertiesViaIdFile1;
		std::string propertiesViaIdAndCAFile1;
		std::string dataFile1;

		int propertySize1;
		int viaIdRootIndex1;
		int viaZipCaRootIndex1;

		getline(myfile, line);
		lastIndex1 = stoi(line);
		getline(myfile, line);
		dataFile1 = line;
		getline(myfile, line);
		propertySize1 = stoi(line);


		getline(myfile, line);
		propertiesViaIdDegree1 = stoi(line);
		getline(myfile, line);
		propertiesViaIdFile1 = line;
		getline(myfile, line);
		viaIdRootIndex1 = stoi(line);
		getline(myfile, line);
		propertiesViaIdLastIndex = stoi(line);


		getline(myfile, line);
		propertiesViaIdAndCADegree1 = stoi(line);
		getline(myfile, line);
		propertiesViaIdAndCAFile1 = line;
		getline(myfile, line);
		viaZipCaRootIndex1 = stoi(line);
		getline(myfile, line);
		propertiesViaIdAndCALastIndex = stoi(line);

		myfile.close();

		this->setLastIndex(lastIndex1);
		this->setPropertySize(propertySize1);
		this->setDataFile(dataFile1);

		propertiesViaID = new Btree(propertiesViaIdDegree1, propertiesViaIdFile1);
		propertiesViaIDandCA = new Btree(propertiesViaIdAndCADegree1, propertiesViaIdAndCAFile1);

		KeyPropertyID *newKid = new KeyPropertyID();
		KeyPropertyIDandCA *newKidCa = new KeyPropertyIDandCA();
		propertiesViaID->searchBlockViaIndex(viaIdRootIndex1, propertySize1,(Key*)newKid);
		propertiesViaID->setLastAdress(propertiesViaIdLastIndex);
		propertiesViaIDandCA->searchBlockViaIndex(viaZipCaRootIndex1, propertySize1,(Key*)newKidCa);
		propertiesViaIDandCA->setLastAdress(propertiesViaIdAndCALastIndex);
	}
}

std::string MainSystem::randomStringGenerator(int size)
{
	std::string str = "";
	str.resize(size);
	for (int i = 0; i < size; i++) {
		str[i] = rand() % 26 + 65;
	}
	return str;
}

Property * MainSystem::searchPropertyViaId(int id)
{
	KeyPropertyID* sProperty = new KeyPropertyID();
	sProperty->setId(id);
	KeyPropertyID * fProperty = (KeyPropertyID*)getPropertiesViaID()->searchKey((Key*)sProperty);
	if (fProperty != nullptr) {
		Property * newProp = new Property();
		newProp->fromByteArray(readDataFromFile(fProperty->getBlockIndex()));
		this->setCurrLoadPropDataIndex(fProperty->getBlockIndex());
		return newProp;
	}
	else {
		return nullptr;
	}
}

Property * MainSystem::searchPropertyViaIdanCA(int id, std::string ca)
{
	KeyPropertyIDandCA* sProperty = new KeyPropertyIDandCA();
	sProperty->setZip(id);
	sProperty->setCaName(ca);
	KeyPropertyIDandCA * fProperty = (KeyPropertyIDandCA*)getPropertiesViaIDandCA()->searchKey((Key*)sProperty);
	if (fProperty != nullptr) {
		Property * newProp = new Property();
		newProp->fromByteArray(readDataFromFile(fProperty->getBlockIndex()));
		this->setCurrLoadPropDataIndex(fProperty->getBlockIndex());
		return newProp;
	}
	else {
		return nullptr;
	}
}

char * MainSystem::readDataFromFile(int index)
{
	std::streampos size;
	char * memblock;
	std::ifstream file(dataFile, std::ios::in | std::ios::binary | std::ios::ate);
	if (file.is_open())
	{
		size = this->getPropertySize();
		memblock = new char[size];
		file.seekg(index * size, std::ios::beg);
		file.read(memblock, size);
		file.close();

		return memblock;
	}
}


MainSystem::MainSystem()
{

}

MainSystem::MainSystem(int idDegree, int idCaDegree)
{
	propertiesViaID = new Btree(idCaDegree, "viaId.bin");
	propertiesViaIDandCA = new Btree(idCaDegree, "viaIDandCA.bin");
	lastIndex = 0;
}

MainSystem::MainSystem(int idDegree, int zipCaDegree, std::string datafile, std::string idFile, std::string zipCaFile) :propertiesViaIdDegree(idDegree), propertiesViaIdAndCADegree(zipCaDegree),dataFile(datafile), propertiesViaIdFile(idFile), propertiesViaIdAndCAFile(zipCaFile) {
	propertiesViaID = new Btree(idDegree, idFile);
	propertiesViaIDandCA = new Btree(zipCaDegree, zipCaFile);
	lastIndex = 0;
}

	

