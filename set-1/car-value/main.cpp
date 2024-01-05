#include <iostream>
using namespace std;

int main(){
    // input first line of string that are separated by spaces
    int duration, num;
    double downPayment, loanAmount;

    cin >> duration >> downPayment >> loanAmount >> num;

    // input the next few line of string that are separated by spaces
    int month[num+1];
    double rate[num+1];
    for(int i = 0; i < num; i++){
        cin >> month[i] >> rate[i];
    }

    double monthPayment = loanAmount / duration;
    double newAmount = downPayment + loanAmount;
    newAmount -= newAmount * rate[0];

    if(newAmount > loanAmount){
        cout << "0 months" << endl;
        return 0;
    }

    double newRate;
    int i = 1, count = 1;
    while (newAmount != 0)
    {
        // cout << "newAmount: " << newAmount << endl;
        // cout << "loanAmount: " << loanAmount << endl;
        if(i > duration) break;
        if(count < num && month[count] == i){
            newRate = rate[count];
            count++;
            // cout << "count: " << count << endl;
        }

        loanAmount -= monthPayment;
        newAmount -= newAmount * newRate;

        if(newAmount > loanAmount){
            cout << i << " month" << (count == 1 ? "" : "s") << endl;
            break;
        }
        i++;
    }
    return 0;
}