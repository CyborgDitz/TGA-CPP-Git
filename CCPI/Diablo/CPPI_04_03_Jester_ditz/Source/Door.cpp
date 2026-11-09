#include "Door.h"
#include <iostream>
#include <ostream>
#include <vector>
#include "Library.h"

void Door::LockPick(const int aPlayerAttribute)
{
    if (aPlayerAttribute > myDC)
    {
        std::cout << "The lock clicks open!" << std::endl;
        myIsLocked = false;
    }
    else
    {
        std::cout << "The lock is stll closed!" << std::endl;
    }
}

Room& Door::PickDoor(const std::vector<Door>& aDoors)
{
    const int maxInput = static_cast<int>(aDoors.size());
    const int input = Library::SetInput(1, maxInput);
    std::cout << "I didnt go int" << aDoors[input].GetPrevRoom().GetName() << std::endl;
    std::cout << "I am going into " << aDoors[input].GetNextRoom().GetName() << std::endl;
    Room& room = aDoors[input].GetNextRoom();
    std::cout << "debug get dc from doors " << aDoors[input].GetDC() << std::endl;

    return room;
}

void Door::UnlockDoor(const Player& aPlayer)
{
    if (myIsLocked == true)
    {
        std::cout << "Door: " << myDoorID << " is locked!" << std::endl;
        std::cout << "lock dc  " << GetDC() << std::endl;

        const int minValue = 1;
        const int maxValue = 2;
        while (myIsLocked == true)
        {
            std::cout << "Do you want to unlock the door with 1: Bash, 2: Picklock" << std::endl;
            const Unlock input = static_cast<Unlock>(Library::SetInput(minValue, maxValue));
            if (input == Unlock::Bash)
            {
                Bash(aPlayer.GetStr());
            }
            else if (input == Unlock::Picklock)
            {
                LockPick(aPlayer.GetDex());
            }
            else
            {
                std::cout << "Door " << myDoorID << " unlocked!" << std::endl;
                return;
            }
        }
    }
    else
    {
        std::cout << "Door " << myDoorID << " unlocked!" << std::endl;
    }
}

void Door::Bash(const int aPlayerAttribute)
{
    if (aPlayerAttribute >= myDC)
    {
        std::cout << "The lock is bashed broken!" << std::endl;
        myIsLocked = false;
    }
    else
    {
        std::cout << "The lock is still closed!" << std::endl;
    }
}

void Door::MoveToRoom(const Room& aFromRoom) const
{
    if (aFromRoom.GetName() == myPrevRoom->GetName())
    {
        std::cout << "Door exited! " << myPrevRoom->GetName() << std::endl;

        std::cout << "Door entered! " << myNextRoom->GetName() << std::endl;
    }
    else
    {
        std::cout << "Door entered! " << myNextRoom->GetName() << std::endl;
        std::cout << "Door exited! " << myPrevRoom->GetName() << std::endl;
    }
}
