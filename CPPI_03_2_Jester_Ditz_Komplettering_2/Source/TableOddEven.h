#pragma once


class TableOddEven
{
    public:
    int GetMoney()  {return myMoney;}
    int GetTreshLoser()  {return myTreshLoser;}
    int GetTreshWinner()  {return myTreshWinning;}
    int GetTableMultiplier()  {return myTableMultiplier;}
    int GetTableBonus()  {return myTableBonus;}
    void AddMoney(const int aMoney)  {myMoney += aMoney;}
    void SubMoney(const int aMoney)  {myMoney -= aMoney;}
    void SetMoney(int aMyMoney){myMoney = aMyMoney;}
    private: 
        int myMoney = {100};
        int myTreshLoser = 200;
        int myTreshWinning = 50;
        int myTableMultiplier =3;
        int myTableBonus = 55;
};
