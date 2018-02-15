//
//  fBullCowGame.cpp
//  cowGame
//
//  Created by Monkey on 24/10/17.
//  Copyright © 2017 Monkey. All rights reserved.
//

#include "fBullCowGame.hpp"

FBullCowGame::FBullCowGame() {
  Reset();
}

void FBullCowGame::Reset(){
  constexpr int32 MY_CURRENT_TRY = 1;
  constexpr int32 MY_MAX_TRIES = 8;
  const FString HIDDEN_WORD = "ant";
  
  MyHiddenWord = HIDDEN_WORD;
  MyCurrentTry = MY_CURRENT_TRY;
  MyMaxTries = MY_MAX_TRIES;
  return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

int32 FBullCowGame::GetCurrentTry() const {  return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const {  return false; }

EGuessStatus FBullCowGame::CheckGuestValidity(FString Guess) {
  if(false) {
    return EGuessStatus::Not_Isogram;
  }
  else if(false) {
    return EGuessStatus::Not_Lowercase;
  }
  else if(Guess.length() != GetHiddenWordLength()) {
    return EGuessStatus::Wrong_Length;
  }
  else{
    return EGuessStatus::OK;
  }
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess){
  MyCurrentTry ++;
  FBullCowCount FBullCowCount;
  int32 HiddernWordLength = MyHiddenWord.length();
  
  for(int32 MHWChar = 0; MHWChar < HiddernWordLength; MHWChar ++) {
    for(int32 GuessChar = 0; GuessChar < HiddernWordLength; GuessChar++) {
      if(Guess[GuessChar] == MyHiddenWord[MHWChar]) {
        if( MHWChar == GuessChar) {
          FBullCowCount.Bulls ++ ;
        }
        else {
          FBullCowCount.Cows ++ ;
        }
      }
    }
  }
  
  return FBullCowCount;
}
