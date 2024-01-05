#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

struct coordinates{
    float x;
    float y;
    int position;
};

// function to check if two coordinates overlap
bool check_overlap(coordinates point1, coordinates point2, float radius)
{
    // float distance = sqrt(pow((point1.x - point2.x), 2) - pow((point1.y - point2.y), 2));
    float distance = sqrt(pow((point1.x - point2.x), 2) + pow((point1.y - point2.y), 2));

    if(radius >= distance)
    {
        return true;
    }
    return false;
}

// function to create union if overlap

int main()
{
    int n;
    float radius;
    vector<coordinates> coordinate_list;

    cin >> n >> radius;
    while(n--)
    {
        float x, y;
        cin >> x >> y;

        coordinates point;
        point.x = x;
        point.y = y;
        point.position = n;

        coordinate_list.push_back(point);
    }

    // check for overlap
    for(int i = 0; i < coordinate_list.size(); i++)
    {
        for(int j = i + 1; j < coordinate_list.size(); j++)
        {
            if(check_overlap(coordinate_list[i], coordinate_list[j], radius))
            {
                coordinate_list[j].position = coordinate_list[i].position;
            }
        }
    }

    // create a bst that stores the position of the overlapping circles
    set<int> bst;
    for(auto val: coordinate_list)
    {
        bst.insert(val.position);
    }

    cout << bst.size();

    return 0;
}
