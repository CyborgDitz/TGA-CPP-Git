#include "Player.h"
#include <iostream>
#include "Room.h"

    int Player::CalcPlayerAttack() const
    {
        int totalAtk = myAtk;
        if (GetInfinite() == true)
        {
          return totalAtk = 9999;
        }
        
       
        int StrStatMod = myStr;
        int DexStatMod= myDex;
        
        if (myInventory.empty() == false)
        {
           
            for (int i = 0; i < myInventory.size(); i++)
            {
                if (myInventory[i].GetMainMod() >0)
                {
                 StrStatMod = myInventory[i].GetMainMod();
                    
                }
                
                if (myInventory[i].GetSecondMod() >0)
                {
                    DexStatMod= myInventory[i].GetSecondMod();
                }
            }
            totalAtk += StrStatMod + DexStatMod + totalAtk;
        }
      
        return totalAtk;
    }
void Player::PrintStats() const
{
    std::cout << myName << "stats are : \n " <<
        "Current HP: " << myHealth << '\t' <<
        "MaxHP: " << myMaxHealth << '\n' << 
        "Atk: " << myAtk << '\t' <<  
        "Def: " << myDefense << '\n' << 
        "STR: " << myStr << '\t' <<
        "DEX: " << myDex << '\t' <<
        "VIT " << myVit << '\t' <<
        "Carrying Cap: " << myCarryCap << '\n' <<std::endl;
        system("pause");
}

void Player::PopulateSpells(Spell& aSpell)
{
    const int mySpellBookSize = static_cast <int> (mySpellBook.size() + 1);
    for (int i = 0; i < mySpellBookSize; i++)
    {
        mySpellBook.push_back(aSpell);
    }

}

void Player::CastSpell()
{
        if (mySpellBook.empty() == false && myHasSpellActive == false)
        {
            for (int i = 0; i < static_cast<int>(mySpellBook.size()); i++)
            {
                if (mySpellBook[i].GetMainMod() >0)
                {
                    myStr += mySpellBook[i].GetMainMod();
                    myDex += mySpellBook[i].GetMainMod();
                    myVit += mySpellBook[i].GetMainMod();
                    std::cout<< "My MAIN stats are altered by by: " << mySpellBook[i].GetMainMod() << std::endl;
                }
                
                if (mySpellBook[i].GetSecondModifier() >0)
                {
                    myAtk += mySpellBook[i].GetSecondModifier();
                    myDefense += mySpellBook[i].GetSecondModifier();
                    myCarryCap += mySpellBook[i].GetSecondModifier();
                    std::cout<< "My SECONDARY stats are altered by by: " << mySpellBook[i].GetSecondModifier() << std::endl;
                }
               
            }
          
           myHasSpellActive = true;
        }
        
        
}
void Player::RemoveSpell()
    {
        if (mySpellBook.empty() == false && myHasSpellActive == true)
        {
           
            for (int i = 0; i < static_cast<int>(mySpellBook.size()); i++)
            {
                if (mySpellBook[i].GetMainMod() >0)
                {
                    myStr -= mySpellBook[i].GetMainMod();
                    myDex -= mySpellBook[i].GetMainMod();
                    myVit -= mySpellBook[i].GetMainMod();
                    
                }
                
                if (mySpellBook[i].GetSecondModifier() >0)
                {
                    myAtk -= mySpellBook[i].GetSecondModifier();
                    myDefense -= mySpellBook[i].GetSecondModifier();
                    myCarryCap -= mySpellBook[i].GetSecondModifier();
                }
            }
            mySpellBook.clear();
            myHasSpellActive  = false;
        }
    }

void Player::PopulateInventory(Item& aItem)
{  
    const int myInventorySize = static_cast<int>(myInventory.size())+1;
         const int totalWeight = myWeight;
        const int itemWeight = aItem.GetWeight();
        if (itemWeight + totalWeight > myCarryCap)
        {
            std::cout << "Inventory is full.. The item broke now oops" << std::endl;
           return;
        }
        for (int i = 0; i <= myInventorySize; i++)
        { 
     
        myInventory.push_back(aItem);
          
         }
        myWeight += itemWeight;
        std::cout << "I took the " << aItem.GetName() << " and put it into my inventory." << std::endl;
}

void Player::RemoveFromInventory(Item& aItem)
{
    if (myInventory.empty()==true)
    {
        std::cout << "I have no items in my inventory" << std::endl;
        return;
    }
    
    for (int i = 0; i < myInventory.size(); i++)
    {
        const bool removedItem = myInventory[i].GetName() == aItem.GetName();
        if (removedItem)
        {
            std::cout << "I removed item " << aItem.GetName() << " from inventory" << std::endl;
            myInventory.erase(myInventory.begin() + i);
        }
    }
}


void Player::TakeDamage(const int aDamage)
{
   
    if (myHasGodMode == true)
    {
        std::cout << "I am a god! " << std::endl;
        return;
    }
    const int myCurrentHealth = myHealth;
    myHealth -= aDamage;
    myHealth = std::max(myHealth, 0);
    std::cout << "Player " << myName << " has currently " << myCurrentHealth << " health\n" <<
       " and takes " << aDamage << ". Now has " << myHealth <<  
           " health left!" <<std::endl;
    
    if (myHealth <= 0)
    {
        myIsAlive = false;
        std::cout << "I am dead and game ends bleh.." << std::endl;
        system("pause");
        return;
    }
    std::cout << "I am still standing!" << std::endl;
}

