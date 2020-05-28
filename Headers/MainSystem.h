#pragma once
#include <fstream>
#include <iostream>

#include "Property.h"
#include "KeyPropertyID.h"
#include "KeyPropertyIDandCA.h"
class MainSystem
{
private:
	Btree * propertiesViaID;
	Btree * propertiesViaIDandCA;
	int lastIndex;
	int currLoadPropDataIndex;
	int propertiesViaIdDegree;
	int propertiesViaIdAndCADegree;
	std::string propertiesViaIdFile;
	std::string propertiesViaIdAndCAFile;
	std::string dataFile;
	int propertySize;

public:
	Btree * getPropertiesViaID();
	Btree * getPropertiesViaIDandCA();
	int getCurrLoadPropDataIndex();
	int getPropertiesViaIdDegree();
	int getPropertiesViaIdAndCADegree();
	int getPropertySize();
	int getLastIndex();
	std::string getDataFileName();
	std::string getPropertiesViaIdFile();
	std::string getPropertiesViaIdAndCAFile();

	bool addProperty(int idNumber, int zipNumber, std::string caName, std::string descr);
	bool setDescription(std::string newdescr, Property * prop);

	void writeDataToFile(Property * prop);
	void updateDataInFile(Property * prop);
	void setCurrLoadPropDataIndex(int newInd);
	void setPropertiesViaIdDegree(int newdeg);
	void setPropertiesViaIdAndCaDegree(int newdeg);
	void setPropertySize(int newSize);
	void setLastIndex(int nLIndex);
	void setDataFile(std::string newDataFile);
	void generateData(int numberOfD);
	void saveConf(std::string nameFile);
	void readConf(std::string nameFile);

	std::string randomStringGenerator(int size);

	Property * searchPropertyViaId(int id);
	Property * searchPropertyViaIdanCA(int id, std::string ca);
	char* readDataFromFile(int index);
	MainSystem();
	MainSystem(int idDegree, int idCaDegree);
	MainSystem(int idDegree, int zipCaDegree, std::string datafile, std::string idFile, std::string zipCaFile);
};

