#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n, m, num_participants, num_walkovers = 0;
    cin >> n >> m;
    num_participants = pow(2, n);

    // Use a 2D vector to represent the walkover_list
    vector<vector<bool> > walkover_list;
    walkover_list.push_back(vector<bool>(num_participants, true));

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        walkover_list[0][temp - 1] = false;
    }

    for (int i = 0; i < n; i++)
    {
        // Debug: Print the current round's walkover_list
        // cout << "i: " << i << endl;
        // for (auto val : walkover_list[i])
        //     cout << val << " ";
        // cout << endl;

        for (int j = 0; j < walkover_list[i].size(); j += 2)
        {
            if (walkover_list[i][j] && walkover_list[i][j + 1])
                walkover_list[i + 1].push_back(true);
            else if ((!walkover_list[i][j] && walkover_list[i][j + 1]) || (walkover_list[i][j] && !walkover_list[i][j + 1]))
            {
                walkover_list[i + 1].push_back(true);
                num_walkovers++;
            }
            else
                walkover_list[i + 1].push_back(false);
        }
    }

    cout << num_walkovers;

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <cmath>
// using namespace std;

// int main()
// {
//     int n, m, num_parcipants, num_walkovers = 0;
//     cin >> n >> m;
//     num_parcipants = pow(2, n);
    
//     vector<bool> walkover_list[n];
//     // set walkover_list[0] to num_parcipants of true
//     for(int i = 0; i < num_parcipants; i++)
//         walkover_list[0].push_back(true);

//     for(int i = 0; i < m; i++)
//     {
//         int temp;
//         cin >> temp;
//         walkover_list[0][temp-1] = false;
//     }

//     for(int i = 0; i < n; i++)
//     {
//         for(auto val: walkover_list[i])
//             cout << val << " ";
//         cout << endl;

//         for(int j = 0; j < walkover_list[i].size(); j+=2)
//         {
//             if(walkover_list[i][j] && walkover_list[i][j+1])
//                 walkover_list[i+1].push_back(true);
            
//             else if((!walkover_list[i][j] && walkover_list[i][j+1]) || (walkover_list[i][j] && !walkover_list[i][j+1]))
//             {
//                 walkover_list[i+1].push_back(true);
//                 num_walkovers++;
//             }
//             else
//                 walkover_list[i+1].push_back(false);
//         }
//     }

//     cout << num_walkovers;

//     return 0;
// }