#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    // take the inputs
    int num_words, num_sentences;
    cin >> num_words >> num_sentences;
    cin.ignore();

    // create a map to store the scores of each word
    unordered_map<string, long long > word_scores;
    while(num_words--)
    {
        string word;
        long long  score;
        cin >> word >> score;
        word_scores[word] = score;
    }

    cin.ignore(); // why is this needed?

    string input;
    long long  score = 0;
    vector<long long > score_list;
    vector<string> sentence_list;
    while(num_sentences > 0)
    {
        getline(cin,input);
   
        istringstream iss(input);
        string temp;
        bool flag = true;
        while(iss >> temp)
        {
            // case 1: a period (end of sentence)
            if (temp == "." && flag)
            {
                // store the score into a list and clear score
                score_list.push_back(score);
                score = 0;
                num_sentences--;
            }
            // case 2: new sentence
            else if(word_scores.find(temp) != word_scores.end())
            {
                score += word_scores[temp];
                flag = false;
            }
        }
        
    }
    // print the score list
    for(auto val: score_list)
    {
        cout << val << endl;
    }
    return 0;
}

// 1 2
// pp 100000
// the incumbent will administer the spending of kindergarden milk money
// and exercise responsibility for making change he or she will share
// responsibility for the task of managing the money with the assistant
// whose skill and expertise shall ensure the successful spending exercise
// .
// this individual must have the skill to perform a heart transplant and
// expertise in rocket science
// .
