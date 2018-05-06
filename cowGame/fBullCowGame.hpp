#pragma once
#include <string>
// Never do this on a header -> using namespace std;
using FString = std::string; // FOR UE4:w
using int32 = int;


struct FBullCowCount {
  int32 Bulls = 0;
  int32 Cows = 0;
};

enum class EGuessStatus {
  Invalid_Status,
  OK,
  Not_Isogram,
  Wrong_Length,
  Not_Lowercase
};

class FBullCowGame {
public:
  FBullCowGame (); // Constructor of the class

  void Reset();
  
  int32 GetMaxTries() const;
  int32 GetCurrentTry() const;
  int32 GetHiddenWordLength() const; 
  
  bool IsGameWon() const;
  EGuessStatus CheckGuestValidity(FString);
  
  FBullCowCount SubmitValidGuess(FString);
  
private:
  int32 MyCurrentTry ;
  FString MyHiddenWord;
  bool bGameIsWon;
  // functions
  bool IsIsogram(FString) const;
  bool IsLowerCase(FString) const; 
};
