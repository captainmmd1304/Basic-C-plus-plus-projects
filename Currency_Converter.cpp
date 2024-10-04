#include <iostream>
#include <ctime>

char GetUserChoice ();
double Amount ();
double total;
char getUserChoice ();
double A;
void Converter (char currency , char Currency, double total, double A);


int main () {
    char currency;
    char Currency;

    std :: cout << "*****Currency converter!*****\n";

    currency = GetUserChoice();
    total = Amount();
    Currency = getUserChoice();

    Converter(currency, Currency, total, A);

    return 0;

    
}

char GetUserChoice(){
    char currency;

    do {
        std :: cout << "Choose the currency you want to enter: \n";

        std :: cout << "Enter I for Indian Rupee.\n";
        std :: cout << "Enter U for US Dollar.\n";
        std :: cout << "Enter P for British Pound.\n";
        std :: cout << "Enter D for Dhiram (UAE).\n";
        std :: cin >> currency;

        } while (currency != 'I' && currency != 'U' && currency != 'P' && currency != 'D');

        return currency;

}

double Amount () {
    std :: cout << "Enter the amount: ";
    std :: cin >> total;
    return total;
}

char getUserChoice() {

    char Currency;
    do {
        std :: cout << "Choose the currency you want to convert to: \n";

        std :: cout << "Enter I for Indian Rupee.\n";
        std :: cout << "Enter U for US Dollar.\n";
        std :: cout << "Enter P for British Pound.\n";
        std :: cout << "Enter D for Dhiram (UAE).\n";
        std :: cin >> Currency;

        } while (Currency != 'I' && Currency != 'U' && Currency != 'P' && Currency != 'D');

        return Currency;

    }

    void Converter(char currency , char Currency , double total , double A) {


        switch (currency) {
            case 'I': if (Currency == 'U'){
                A = total * 0.012;
                std :: cout << A << " Dollars";

            }

            else if(Currency == 'P'){
                A = total * 0.0091;
                std :: cout << A << " Pound";
            }

            else if(Currency == 'D'){
                A = total * 0.044;
                std :: cout << A << " Dhiram";
            }

            break;

            case 'U': if (Currency == 'I'){
                A = total * 83.96;
                std :: cout << A << " Rupees";

            }

            else if(Currency == 'P'){
                A = total * 0.76;
                std :: cout << A << " Pound";
            }

            else if(Currency == 'D'){
                A = total * 3.67;
                std :: cout << A << " Dhiram";
            }

            break;

            case 'P': if (Currency == 'U'){
                A = total * 1.31;
                std :: cout << A << " Dollars";

            }

            else if(Currency == 'I'){
                A = total * 110.22;
                std :: cout << A << " Rupees";
            }

            else if(Currency == 'D'){
                A = total * 4.82;
                std :: cout << A << " Dhiram";
            }

            break;

           case 'D': if (Currency == 'U'){
                A = total * 0.27;
                std :: cout << A << " Dollars";

            }

            else if(Currency == 'P'){
                A = total * 0.21;
                std :: cout << A << " Pound";
            }

            else if(Currency == 'I'){
                A = total * 22.86;
                std :: cout << A << " Rupees";
            }

        }

    }