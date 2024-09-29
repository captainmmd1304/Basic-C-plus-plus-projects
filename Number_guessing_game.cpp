#include <iostream>
#include <ctime>

int main () {
    int num;
    int guess;
    int tries;

    srand (time (NULL));
    num = (rand () % 100) + 1;

    std :: cout << "*****NUMBER GUESSING GAME*****\n";

    do {
        std :: cout << "Guess a number between 1-100: ";
        std :: cin >> guess;
        tries++;

        if (guess > num) {
            std :: cout << "Too high\n";
        }

        else if (num > guess) {
            std :: cout << "Too low\n";
        }

        else {
            std :: cout << "CORRECT!\n";
            std :: cout << "Number of tries: " << tries;
        }


    }
while (guess != num);

return 0;

}