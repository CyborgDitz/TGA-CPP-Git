#pragma once
#include <vector>

#include "Room.h"

class Door
{
public:
    Door(int aDoorID, Room& aPrevRoom, Room& aNextRoom, const int aDC, const bool aIsLocked)
        : myPrevRoom(&aPrevRoom), myNextRoom(&aNextRoom)
    {
        myDoorID = aDoorID;
        myDC = aDC;
        myIsLocked = aIsLocked;
    }

    enum class Unlock
    {
        Exit = 0,
        Bash = 1,
        Picklock = 2,
        Count = 3
    };

    int GetDC() const { return myDC; }
    void LockPick(int aPlayerAttribute);
    bool GetIsLocked() const { return myIsLocked; }
    int GetDoorID() const { return myDoorID; }
    Room& PickDoor(const std::vector<Door>& aDoors);
    void UnlockDoor(const Player& aPlayer);
    void Bash(int aPlayerAttribute);
    void MoveToRoom(const Room& aFromRoom) const;
    Room& GetPrevRoom() const { return *myPrevRoom; }
    Room& GetNextRoom() const { return *myNextRoom; }

private:
    int myDoorID;
    Room* myPrevRoom;
    Room* myNextRoom;
    bool myIsLocked{};
    int myDC{};
};
