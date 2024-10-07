#include <iostream>
#include <ctime>

int main (){
    int a=1;
    int b=1;

    std :: cout << "********** Fibonacci series generator **********\n";
    std :: cout << "Enter number: \n";

    int n;

    std :: cin >>n;

    for (int i=0; i<n; i++){
        int sum = a+b;
        std :: cout << sum << " ";
        a=b;
        b=sum;

    }


}



