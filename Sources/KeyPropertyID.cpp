#include "KeyPropertyID.h"



void KeyPropertyID::setId(int newId)
{
	id = newId;
}

void KeyPropertyID::setBlockIndex(int newBi)
{
	blockIndex = newBi;
}

int KeyPropertyID::getId()
{
	return id;
}

int KeyPropertyID::getBlockIndex()
{
	return blockIndex;
}

KeyPropertyID::KeyPropertyID()
{
}

void KeyPropertyID::setPointerToRecord(Zaznam * newPointer)
{
	pointerToRecord = newPointer;
}
