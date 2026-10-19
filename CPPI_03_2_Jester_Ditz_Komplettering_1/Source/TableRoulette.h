#pragma once
class TableRoulette
{
public:

    enum class Bets
    {
        Invalid = 0,
        Straight_Gay = 1,
        Red_Black = 2,
        Odd_Even = 3,
        Column = 4
    };
    enum class Color
    {
        Green = 0,
        Red = 1,
        Black = 2
    };

    enum class Column
    {
        Invalid = 0,
        Left = 1,
        Middle = 2,
        Column_Three = 3
    };

    Color GetColor()  { return color; }
    Bets GetBets()  { return bets; }
    Column GetColumn()  { return column; }

    int GetMoney()  { return myMoney; }
    int GetTreshLoser()  { return myTreshLoser; }
    int GetTreshWinner()  { return myTreshWinning; }
    int GetStraightGayMult()  { return myStraightGayMult; }
    int GetRedBlackMult()  { return myRedBlackMult; }
    int GetOddEvenMult()  { return myOddEvenMult; }
    int GetColumnMult()  { return myColumnMult; }
    int GetSlotsMax()  { return mySlotsMax; }
    int GetSlotsMin()  { return mySlotsMin; }
    
    
    void AddMoney(const int aMoney)  {myMoney += aMoney;}
    void SubMoney(const int aMoney)  {myMoney -= aMoney;}
    void SetMoney( int aMoney) { myMoney = aMoney; }
    void SetBets( Bets aBets) { bets = aBets; }
    void SetColor( Color aColor) { color = aColor; }
    void SetColumn( Column aColumn) { column = aColumn; }
private:
    int myMoney = {100};
    int myTreshLoser = 200;
    int myTreshWinning = 50;
    int myStraightGayMult = 5;
    int myRedBlackMult = 3;
    int myOddEvenMult = 1;
    int myColumnMult = 2;
    int mySlotsMax = 36;
    int mySlotsMin = 0;
    
    Column column = {};
    Bets bets = {};
    Color color = {};
};
