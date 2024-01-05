#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string final_direction(string instructions[], int L){


}

int main()
{
    int L = 0;
    cin >> L;
    string direction = "+x", input;
    // process the string separated by spaces
    cin.ignore();
    getline(cin, input);
    istringstream iss(input); // Create a stringstream to tokenize the input
    
    string word;
    vector<string> store;
    while (iss >> word) {
        store.push_back(word);
    }

    for(auto turn: store){
        if(turn == "No") continue;
        else if((direction == "+z" || direction == "-z") && (turn == "+y" || turn == "-y")) continue;
        else if((direction == "+y" || direction == "-y") && (turn == "+z" || turn == "-z")) continue;

        else if(direction == "+z"){
            if(turn == "+z") direction = "-x";
            else if (turn == "-z") direction = "+x";
        }

        else if(direction == "-z"){
            if(turn == "+z") direction = "+x";
            else if (turn == "-z") direction = "-x";
        }

        else if(direction == "+y"){
            if(turn == "+y") direction = "-x";
            else if (turn == "-y") direction = "+x";
        }

        else if(direction == "-y"){
            if(turn == "+y") direction = "+x";
            else if (turn == "-y") direction = "-x";
        }

        else if(direction == "+x") direction = turn;
        else if(direction == "-x")
        {
            if(turn == "+y") direction = "-y";
            else if(turn == "-y") direction = "+y";
            else if(turn == "+z") direction = "-z";
            else if(turn == "-z") direction = "+z";
        }
    }

    cout << direction;
    return 0;
}