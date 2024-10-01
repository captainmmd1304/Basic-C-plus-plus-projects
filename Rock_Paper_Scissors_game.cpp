#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer);

int main () {
    char player;
    char computer;  

    player = getUserChoice();

    std :: cout << "Your choice is: ";
    showChoice (player);

    computer = getComputerChoice();
    std :: cout << "Computer's choice is: ";
    showChoice (computer);

    chooseWinner(player, computer);

    return 0;

}

char getUserChoice(){
    char player;

    std :: cout << "Rock Paper Scissors game!\n";
    std :: cout << "*************************\n";

    do {
    
    std :: cout << "*************************\n";
    std :: cout << "Enter 'r' for rock\n";
    std :: cout << "Enter 'p' for paper\n";
    std :: cout << "Enter 's' for scissors\n";
    std :: cin >> player;

    } while( player != 'r' && player != 'p' && player != 's' );

    
    return player;
}
char getComputerChoice(){

    srand (time (0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1: return 'r';
        break;
        case 2: return 'p';
        break;
        case 3: return 's';
        break;
    }


    return 0;
}
void showChoice(char player){

    switch(player){
        case 'r': 
        std :: cout << "Rock\n";
        break;

        case 'p': 
        std :: cout << "Paper\n";
        break;

        case 's': 
        std :: cout << "Scissors\n";
        break;

        }

}
void chooseWinner(char player, char computer){

    switch(player) {
        case 'r': if (computer == 'r') {
            std :: cout << "It's a tie!\n";
        }
        else if (computer == 'p') {
            std :: cout << "You lose!\n";
             }

             else {
                std:: cout << "You win!\n";
             }

             break;


             case 'p': if (computer == 'p') {
            std :: cout << "It's a tie!\n";
        }
        else if (computer == 'r') {
            std :: cout << "You lose!\n";
             }

             else {
                std:: cout << "You win!\n";
             }

             break;
       case 's': if (computer == 's') {
            std :: cout << "It's a tie!\n";
        }
        else if (computer == 'r') {
            std :: cout << "You lose!\n";
             }

             else {
                std:: cout << "You win!\n";
             }

             break;

     }

}