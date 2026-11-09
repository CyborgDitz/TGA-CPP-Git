#include "Player.h"

#include <iostream>


void Player::SetName()
{
    
    while (true)
    {
        std::cout << "Name must at least 2 characters long and only contain letters" << std::endl;
        std::cin.get(myName, 16);
        if (std::cin.fail())
        {  std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "errorr brrr" << std::endl;
        }
        else
        {
            for (int i = 0; i < sizeof(myName); i++)
            {
              
                if ((myName[i] > 'z' && myName[i] < 'a' || myName[i] < 'A' && myName[i] > 'Z'))
                {
                    break;
                }
                
                else if ( i >= 2 && myName[i] == '\0' )
                {
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    return;
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
