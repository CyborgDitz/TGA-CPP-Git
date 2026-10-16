#pragma once

class Player
{
public:
    
   const char* GetName() { return myName; }
    int GetMoney() { return myMoney; }
    int GetStreakMax() const { return streakArrayMax; }
    int* GetWinStreak()  { return myWinStreak; }
    bool GetIsWin() const { return myIsWin; };
    bool GetIsPoor() const { return myIsPoor; };

    void SetName();
   void SayName();
   void SetMoney(const int aMoney) { myMoney = aMoney; }
    void SetIsWin(const bool aIsWin) { myIsWin = aIsWin; };
    void SetIsPoor(const bool aIsPoor) { myIsPoor = aIsPoor; }
    void SetWinStreak(const int aIndex, const int aValue) { myWinStreak[aIndex] = aValue; }
    
    
    void AddMoney (const int aMoney) { myMoney += aMoney; }
    void SubMoney (const int aMoney) { myMoney -= aMoney; }
    
private:
    char myName[17] = {};
    int myMoney = 9999;
    const int streakArrayMax = 5;
    int myWinStreak[5] = {0};
    bool myIsWin = {};
    bool myIsPoor = false;
};
