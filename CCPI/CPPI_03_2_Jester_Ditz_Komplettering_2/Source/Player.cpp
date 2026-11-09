#include "Player.h"

#include <iostream>


void Player::SetName()
{
    while (true)
    {
        std::cout << "Name must at least 2 characters long and only contain letters" << std::endl;
        std::cin >> myName;

        //  std::cin.get(myName, 16);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "errorr brrr" << std::endl;
        }
        else
        {
            for (int i = 0; i < sizeof(myName); i++)
            {
                if (myName[i] == '\0')
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                   // std::cout << "errorr brrr" << std::endl;
                                        //std::cout << i;
                    return;
                }
                if (i == sizeof(myName))
                {
                    std::cout << i;
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "errorr brrr" << std::endl;
                    break;
                }
                if (myName[i] < 'A' || myName[i] > 'Z')
                {
                    if (myName[i] < 'a' || myName[i] > 'z')
                    {
                        std::cin.clear();
                        std::cin.ignore(1000, '\n');
                        std::cout << "errorr brrr" << std::endl;
                        break;
                    }
                }
            }
        }
    }
}


void Player::SayName()
{
    for (int i = 0; i < sizeof(myName); i++)
    {
        if (myName[i] == '\0')
        {
            std::cout << std::endl;
            return;
        }
        std::cout << myName[i];
    }
}
