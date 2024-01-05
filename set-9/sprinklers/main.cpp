#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct Circle {
    int x;
    double start;
    double end;
};

struct CompareStart {
    inline bool operator()(const Circle& c1, const Circle& c2) {
        return (c1.start < c2.start);
    }
};

struct CompareEnd {
    inline bool operator()(const Circle& c1, const Circle& c2) {
        return (c1.end > c2.end);
    }
};

int main() {
    int n, l;
    double w;
    cin >> n >> l >> w;

    vector<Circle> inputList;
    for (int i = 0; i < n; ++i) {
        int x, radius;
        cin >> x >> radius;

        if(radius <= w/2)
        {
            continue;
        }

        double new_radius = sqrt(radius * radius - (w / 2) * (w / 2));
        double start = x - new_radius;
        double end = x + new_radius;

        Circle circle;
        circle.x = x;
        circle.start = start;
        circle.end = end;
        inputList.push_back(circle);
    }

    sort(inputList.begin(), inputList.end(), CompareStart());

    double start = 0;
    double end = l;
    int count = 0;

    for (size_t i = 0; i < inputList.size(); ++i) {
        // haven't reached the end but the input list is empty
        if(start < end && i == inputList.size() - 1)
        {
            cout << -1 << endl;
            return 0;
        }

        // If the first circle in the input list does not cover the current start
        if (inputList[i].start > start) {
            cout << -1 << endl;
            return 0;
        }

        // If start >=end, we are done
        if (start >= end) {
            cout << count << endl;
            return 0;
        }

        // Find the circles that cover the current start and store them in a list
        size_t j = i;
        double current_end = inputList[j].end;
        while (j < inputList.size() && inputList[j].start <= start) {
            current_end = max(current_end, inputList[j].end);
            ++j;
        }
        start = current_end;
        count++;
    }

    return 0;
}


/*

Input
The first line contains integer numbers n, l and w with 1 <= n <= 10,000, 1 <= l <= 10,000,000, and 1 <= w <=
100. The next n lines contain two integers giving the position x (0 <= x <= l) and radius of operation r (1 <= r
<= 1000) of a sprinkler.
The picture above illustrates the first case from the sample input.

Output
Output one integer followed by a newline: the minimum number of sprinklers needed to water the entire strip.
If it is impossible to water the entire strip, output -1.

Example 1 (shown in the image above)
Input:
8 20 2
5 3
4 1
1 2
7 2
10 2
13 3
16 2
19 4
Output:
6

Example 2
Input:
3 10 1
3 5
9 3
6 1
Output:
2

Example 3
Input:
3 10 1
5 3
1 1
9 1
Output:
-1

*/