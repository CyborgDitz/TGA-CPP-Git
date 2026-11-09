#pragma once
#include <string.h>

class ItemType
{
public:
    ItemType();
    ItemType(const char* aName, int aMainMod, int aSecondMod);

    const char* GetName() const { return myName; }
    int GetMainMod() const { return myMainMod; }
    int GetSecondMod() const { return mySecondMod; }
    int GetWeight() const { return myWeight; }

    void SetName(const char* aName) { strcpy_s(myName, aName); }
    void SetMainMod(const int aMainMod) { myMainMod = aMainMod; }
    void SetSecondMod(const int aSecondMod) { mySecondMod = aSecondMod; }
    void SetWeight(const int aWeight) { myWeight = aWeight; }

    void PrintStats() const;

private:
    char myName[31] = {};
    int myMainMod{};
    int mySecondMod{};
    int myWeight{};
};
