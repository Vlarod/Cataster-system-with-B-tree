#include "KeyPropertyIDandCA.h"



int KeyPropertyIDandCA::getZip()
{
	return zip;
}

std::string KeyPropertyIDandCA::getcaName()
{
	return caName;
}

int KeyPropertyIDandCA::getBlockIndex()
{
	return blockIndex;
}

void KeyPropertyIDandCA::setZip(int newZip)
{
	zip = newZip;
}

void KeyPropertyIDandCA::setCaName(std::string newCa)
{
	caName = newCa;
}

void KeyPropertyIDandCA::setBlockIndex(int newBI)
{
	blockIndex = newBI;
}

void KeyPropertyIDandCA::setPointerToRecord(Zaznam * newPointer)
{
	pointerToRecord = newPointer;
}

KeyPropertyIDandCA::KeyPropertyIDandCA()
{
}
