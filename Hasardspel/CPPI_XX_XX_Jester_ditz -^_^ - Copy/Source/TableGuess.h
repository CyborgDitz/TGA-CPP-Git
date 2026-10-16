#pragma once


class  TableGuess
{
public:
  TableGuess(const int aBetMin, const int aBetMax)
  {
      myBetMin = aBetMin;
      myBetMax = aBetMax;
      myTreshWinning = 50+ myTableMultiplier * aBetMin;
      myTreshLoser =  200 + myTableMultiplier * aBetMax;
      myMoney = myTreshLoser / 2;
  }
    
    
    int GetMoney()  {return myMoney;}
    int GetTreshLoser()  {return myTreshLoser;}
    int GetTreshWinner()  {return myTreshWinning;}
    int GetTableMultiplier()  {return myTableMultiplier;}
    int GetTableBonus()  {return myTableBonus;}
    int GetBetMin()  {return myBetMin;}
    int GetBetMax()  {return myBetMax;}
    
    void AddMoney(const int aMoney)  {myMoney += aMoney;}
    void SubMoney(const int aMoney)  {myMoney -= aMoney;}
    void SetMoney(const int aMoney) {myMoney = aMoney;}
    void SayGuessTreshHold();
    void SayGuessRules() ;
   
private:
        int myMoney = 100;
        int myTreshLoser = 20;
        int myTreshWinning = 5;
        int myTableMultiplier = 2;
        int myTableBonus = 0;
         int myBetMin = 2;
         int myBetMax = 12;
};
