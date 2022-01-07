#include <iostream>
#include <ctime>


void PrintIntructions(int Difficulty)
{
      std::cout << "You are a secret agent breaking into a secure server room.\n";
      std::cout << "Playing at difficulty \n" << Difficulty;
     std::cout << "Enter the correct code to continue...\n";
}

bool PlayGame(int Difficulty)
{
   const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    int PlayerGuessA, PlayerGuessB, PlayerGuessC = 0;

    std::cout  << std::endl;
    PrintIntructions(Difficulty);
    std::cout << "Enter the guess A\n";
    std::cin >> PlayerGuessA;
    std::cout << "Enter the guess B\n";
    std::cin >> PlayerGuessB;
    std::cout << "Enter the guess C\n";
    std::cin >> PlayerGuessC;
    int GuesSum = PlayerGuessA + PlayerGuessB + PlayerGuessC;
    int GuesProduct = PlayerGuessA * PlayerGuessB * PlayerGuessC;

    if(GuesSum == GuesProduct && GuesProduct == CodeProduct)
    {
        std::cout << "You have successfully entered the correct code.\n";
        return true;
    }
    else
    {
        std::cout << "You have entered the wrong code.\n";
        return false;
    }

}


int main()
{

    srand(time(NULL));

    int LevelDifficulty = 0;
    const int MaxDifficulty = 5;
    while (LevelDifficulty <= MaxDifficulty)
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if(bLevelComplete)
        {
           ++LevelDifficulty;
        }
       
    }
    

   


}