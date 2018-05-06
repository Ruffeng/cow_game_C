//
//  fBullCowGame.cpp
//  cowGame
//
//  Created by Monkey on 24/10/17.
//  Copyright © 2017 Monkey. All rights reserved.
//
#pragma once
#include "fBullCowGame.hpp"
#include <map>
#define Tmap std::map

FBullCowGame::FBullCowGame() {
  Reset();
}

void FBullCowGame::Reset(){
  constexpr int32 MY_CURRENT_TRY = 1;
  const FString HIDDEN_WORD = "planet";
  
  MyHiddenWord = HIDDEN_WORD;
  MyCurrentTry = MY_CURRENT_TRY;
  bGameIsWon = false;
  return;
}

int32 FBullCowGame::GetMaxTries() const {
  Tmap<int32, int32> WordLengthToMaxTries {
    {3,4},
    {4,7},
    {5,10},
    {6,16},
    {7,20}
  };
  return WordLengthToMaxTries[MyHiddenWord.length()];
}

int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

int32 FBullCowGame::GetCurrentTry() const {  return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

EGuessStatus FBullCowGame::CheckGuestValidity(FString Guess) {
  if(!IsIsogram(Guess)) {
    return EGuessStatus::Not_Isogram;
  }
  else if(!IsLowerCase(Guess)) {
    return EGuessStatus::Not_Lowercase;
  }
  else if(Guess.length() != GetHiddenWordLength()) {
    return EGuessStatus::Wrong_Length;
  }
  else{
    return EGuessStatus::OK;
  }
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess){
  MyCurrentTry ++;
  FBullCowCount FBullCowCount;
  int32 WordLength = MyHiddenWord.length();
  
  for(int32 MHWChar = 0; MHWChar < WordLength; MHWChar ++) {
    for(int32 GuessChar = 0; GuessChar < WordLength; GuessChar++) {
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
  if( FBullCowCount.Bulls == WordLength) {
    bGameIsWon = true;
  }
  else {
    bGameIsWon = false;
  }
  return FBullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const {
  if(Word.length() <= 1) { return true; }
  
  Tmap<char, bool> LetterSeen; // Could be a kind of Hash in Ruby
  
  for(auto Letter : Word) { // For all letters from the Word. This 'auto' is to set auto data type, the regular one would be char
    Letter = tolower(Letter);
    if(LetterSeen[Letter]) {
      return false;
    }
    else {
      LetterSeen[Letter] = true;
    }
    
  }
  return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const {
  
  for(auto Letter : Word) {
    if(!islower(Letter)) { return false; }
  }
  return true;
}
