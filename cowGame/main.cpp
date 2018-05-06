
#pragma once

#include "fBullCowGame.hpp"
#include <iostream>
// Didn't work the cin unless it's invoked the library
#include <string>
// So you can just tell to the system that you are working with this library
//using namespace std;
// Because we want  the main on the very top, we just say that we have
//on the bottom a method that will be used in the main

using FText = std::string; // Concrete for UE4
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSumary();
FBullCowGame BCGame;

int main() {
  do {
    PrintIntro();
    PlayGame();
    
  } while(AskToPlayAgain());
  return 0;
}

void PlayGame(){
  BCGame.Reset();
  
  int32 MaxTries = BCGame.GetMaxTries();
  std::cout << MaxTries << std::endl;
  
  while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
    FText Guess = GetValidGuess();
    
    FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
    std::cout << "Bulls" << BullCowCount.Bulls;
    std::cout << "Cows" << BullCowCount.Cows << "\n\n";
  }
  PrintGameSumary();
  std::cout << std::endl;
  return; 
}

void PrintIntro() {
  // Intro of the game
  std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
  std::cout << std::endl;
  std::cout << "          }   {         ___ " << std::endl;
  std::cout << "          (o o)        (o o) " << std::endl;
  std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
  std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
  std::cout << " *  |-,--- |              |------|  * " << std::endl;
  std::cout << "    ^      ^              ^      ^ " << std::endl;
  std::cout << "Can you guess the "<< BCGame.GetHiddenWordLength();
  std::cout <<" letter isogram I'm thinking off? \n";
  std::cout << std::endl;
  return;
}

FText GetValidGuess(){
  FText Guess = "";
  EGuessStatus Status = EGuessStatus::Invalid_Status;
  do {
    int32 CurrentTry = BCGame.GetCurrentTry();
    // User's input. String is coming from namespace FText
    std::cout << "Try "<< CurrentTry <<" of " << BCGame.GetMaxTries() << ".Enter your guess\n";
    //  cin >> Guess;
    std::getline(std::cin, Guess);
                
    Status = BCGame.CheckGuestValidity(Guess);
    
    switch(Status) {
      case EGuessStatus::Wrong_Length:
        std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word \n";
        break;
      case EGuessStatus::Not_Isogram:
        std::cout << " Please enter a word without repeating letters. \n";
        break;
      case EGuessStatus::Not_Lowercase:
        std::cout << "Please enter all lower case letters";
        break;
      default:
        break;
    }
    
  } while(Status != EGuessStatus::OK);
  return Guess;
}

bool AskToPlayAgain() {
  std::cout << "Would you like to play again?(y/n)";
  FText Response = "";
  std::getline(std::cin, Response);
  return (Response[0]== 'y') || (Response[0]=='Y');

}

void PrintGameSumary() {
  if(BCGame.IsGameWon()) {
    std::cout << "CONGRATS! YOU WON THE GAME";
    return;
  }
  else {
    std:: cout << "Sorry, you lost the game";
    return;
  }
}
