#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void findRoutes(int node, vector<int> route, int end_point, unordered_map<int, set<int> >& corner_list) {
    // base case 1: if number of nodes in route is more than total number of nodes
    if (route.size() > corner_list.size()) {
        return;
    }

    // base case 2: if node is the end point
    if (node == end_point) {
        // print the route
        route.push_back(node);
        for (int i = 0; i < route.size(); i++) {
            cout << route[i];
            if (i != route.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
        return;
    }
    
    // base case 3: if node is not in corner_list
    if (corner_list.find(node) == corner_list.end()) {
        return;
    }

    // recursive case: if node is in corner_list
    for (int end : corner_list[node]) {
        // if end is not in route
        if (find(route.begin(), route.end(), end) == route.end()) {
            // add end to route
            route.push_back(node);
            // recursively call findRoutes with end as node
            findRoutes(end, route, end_point, corner_list);
            // remove end from route
            route.pop_back();
        }
    }
}


int main() {
    int end_point;
    cin >> end_point;
    cin.ignore();

    unordered_map<int, set<int> > corner_list;
    set<int> tracker;
    vector<int> current_route;

    while (true) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        int start, end;
        iss >> start >> end;

        if (start == 0 && end == 0)
            break;

        corner_list[start].insert(end);
        corner_list[end].insert(start);
    }

    findRoutes(1, current_route, end_point, corner_list);

    return 0;
}

/*

2: 3 4 
5: 6 
4: 6 
3: 4 5 
1: 2 3 

Example 1
Input:
6
1 2
1 3
3 4
3 5
4 6
5 6
2 3
2 4
0 0

Output:
1 2 3 4 6
1 2 3 5 6
1 2 4 3 5 6
1 2 4 6
1 3 2 4 6
1 3 4 6
1 3 5 6
There are 7 routes from the initial position to corner 6.

Example 2
Input:
4
2 3
3 4
5 1
1 6
7 8
8 9
2 5
5 7
3 1
1 8
4 6
6 9
0 0

Output:
1 3 2 5 7 8 9 6 4
1 3 4
1 5 2 3 4
1 5 7 8 9 6 4
1 6 4
1 6 9 8 7 5 2 3 4
1 8 7 5 2 3 4
1 8 9 6 4
There are 8 routes from the initial position to corner 4.

*/