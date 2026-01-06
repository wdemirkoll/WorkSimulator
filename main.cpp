#include <iostream>
#include <string>

// Rank names
std::string Ranks[4] = {"Rookie", "Educated", "Economist", "Economist King"};
std::string MyRank;
std::string Nickname;

// Player stats
double Money = 0;

int Stamina = 100;
int Hunger = 100;
int XP = 0;
int TotalWork = 0;

int Vote; // Menu Selection-Vote

// Keeps player stats within valid limits
void Game_Settings_Logic(){
    if(Stamina > 100)
        Stamina = 100;
    if(Stamina < 0)
        Stamina = 0;

    if(Hunger > 100)
        Hunger = 100;
    if(Hunger < 0)
        Hunger = 0;
}

// Determines player's rank based on XP
void RankLogic(){
    if(XP >= 0 && XP <= 100)
        MyRank = Ranks[0];

    if(XP >= 101 && XP <= 250)
        MyRank = Ranks[1];

    if(XP >= 251 && XP <= 650)
        MyRank = Ranks[2];

    if(XP >= 651)
        MyRank = Ranks[3];
}

// Gives bonus money based on total number of times worked
void Total_Working_Logic(){
    if(TotalWork == 5){
        Money += 50;
        std::cout << "You got a $50 bonus for working 5 times!" << std::endl << std::endl;
    }

    if(TotalWork == 10){
        Money += 100;
        std::cout << "You got a $100 bonus for working 10 times!" << std::endl << std::endl;
    }

    if(TotalWork == 15){
        Money += 150;
        std::cout << "You got a $150 bonus for working 15 times!" << std::endl << std::endl;
    }

    if(TotalWork == 20){
        Money += 200;
        std::cout << "You got a $200 bonus for working 20 times!" << std::endl << std::endl;
    }
}

// Displays player statistics
void StatisticsMenu(){
    std::cout << "--------------------------" << std::endl;
    std::cout << "Nickname: " << Nickname << std::endl;
    std::cout << "Rank: " << MyRank << std::endl;
    std::cout << "Total Work: " << TotalWork << std::endl;
    std::cout << "Money: $" << Money << std::endl;
    std::cout << "Stamina: " << Stamina << std::endl;
    std::cout << "Hunger: " << Hunger << std::endl;
    std::cout << "XP: " << XP << std::endl;
    std::cout << "--------------------------" << std::endl;
}

// Main menu options
void MainMenu(){
    std::cout << "[1] - Work" << std::endl;
    std::cout << "[2] - Relax" << std::endl;
    std::cout << "[3] - Eat" << std::endl;
    std::cout << "[4] - Exit" << std::endl;
}

// Default response for invalid input
void DefaultFunction(){
    std::cout << "Invalid Selection!" << std::endl << std::endl;
}

// Gets player input
void VoteFunction(){
    std::cout << "Vote:";
    std::cin >> Vote;
}

int main(){
    std::cout << "Welcome, enter your nickname, ";
    getline(std::cin,Nickname);

    while(true){
        Game_Settings_Logic();
        RankLogic();

        StatisticsMenu();
        MainMenu();
        VoteFunction();

        switch(Vote){
        case 1:
            if(Stamina >= 10 && Hunger >= 10){
                Stamina -= 20;
                Hunger -= 4;
                TotalWork++;

                Total_Working_Logic();

                // Rank bonus logic
                double moneyEarned = 300; // base money
                int xpEarned = 25;       // base XP

                if(MyRank == "Educated") {
                    moneyEarned *= 1.1; // +10%
                }
                else if(MyRank == "Economist") {
                    moneyEarned *= 1.2; // +20%
                    xpEarned += 10;
                }
                else if(MyRank == "Economist King") {
                    moneyEarned *= 1.5; // +50%
                    xpEarned += 25;
                }

                Money += moneyEarned;
                XP += xpEarned;

                std::cout << "You worked a little" << std::endl << std::endl;
            }
            else{
                std::cout << "You're not fit to work. Either rest a little or eat something!\n\n";
            }
            break;


        case 2:
            Stamina += 20;
            Hunger -= 5;

            std::cout << "You got some rest." << std::endl << std::endl;
            break;


        case 3:
            std::cout << "What do you want to eat?" << std::endl;
            std::cout << "[1] - Chocolate [$5]" << std::endl;
            std::cout << "[2] - Sandwich [$15]" << std::endl;
            std::cout << "[3] - Hamburger [$40]" << std::endl;
            std::cout << "[4] - I want to fill my stomach completely [$70]" << std::endl;
            VoteFunction();

            switch(Vote){
            case 1:
                if(Money >= 5){
                    Money -= 5;
                    Hunger += 5;
                }
                else{
                    std::cout << "You don't have enough money!" << std::endl << std::endl;
                }
                break;


            case 2:
                if(Money >= 15){
                    Money -= 15;
                    Hunger += 15;
                }
                else{
                    std::cout << "You don't have enough money!" << std::endl << std::endl;
                }
                break;


            case 3:
                if(Money >= 40){
                    Money -= 40;
                    Hunger += 45;
                }
                else{
                    std::cout << "You don't have enough money!" << std::endl << std::endl;
                }
                break;


            case 4:
                if(Money >= 70){
                    Money -= 70;
                    Hunger += 100;
                }
                else{
                    std::cout << "You don't have enough money!" << std::endl << std::endl;
                }
                break;


            default:
                DefaultFunction();
                break;
            }
            break;


        case 4:
            return 0;


        default:
            DefaultFunction();
            break;
        }
    }

    return 0;
}
