#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

// Function to explore and mark islands in the area map
void explore_islands(vector<vector<int> >& area_map, int row, int col, int water_level) 
{
    // If the current cell's height is less than or equal to the water level, return
    if (area_map[row][col] <= water_level) 
        return;
    
    // Mark the current cell as visited (set its value to 0)
    area_map[row][col] = 0;
    
    // Explore neighboring cells in four directions
    // Right
    if (col + 1 < area_map[0].size()) 
        explore_islands(area_map, row, col + 1, water_level);

    // Down
    if (row + 1 < area_map.size()) 
        explore_islands(area_map, row + 1, col, water_level);

    // Left
    if (col - 1 >= 0) 
        explore_islands(area_map, row, col - 1, water_level);

    // Up
    if (row - 1 >= 0) 
        explore_islands(area_map, row - 1, col, water_level);
}

int main() 
{
    int num_rows, num_cols;
    cin >> num_rows >> num_cols;
    
    // Create a 2D vector to represent the land map
    vector<vector<int> > land_map;
    int row_count = num_rows;

    // Input the height values for the land map
    for(int i = 0; i < num_rows; i++) 
    {
        vector<int> row;
        for(int j = 0; j < num_cols; j++) 
        {
            int num;
            cin >> num;
            row.push_back(num);
        }
        land_map.push_back(row);
    }

    int num_water_levels;
    vector<int> water_levels;
    cin >> num_water_levels;
    
    // Input the water levels to be applied
    for(int i = 0; i < num_water_levels; i++) 
    {
        int water_level;
        cin >> water_level;
        water_levels.push_back(water_level);
    }

    vector<int> results;
    
    // Iterate through each water level and find the number of islands
    for(int i = 0; i < water_levels.size(); i++)
    {
        int level = water_levels[i], island_count = 0;
        vector<vector<int> > temp_land_map = land_map;
        
        // Iterate through the land map and explore islands
        for(int i = 0; i < num_rows; i++) 
        {
            for(int j = 0; j < num_cols; j++) 
            {
                if(temp_land_map[i][j] > level) 
                {
                    island_count++;
                    explore_islands(temp_land_map, i, j, level);
                }
            }
        }
        results.push_back(island_count);
    }
    
    // Output the results
    for(int i = 0; i < results.size(); i++) 
    {
        if(i == results.size() - 1) 
            cout << results[i] << endl;
        
        else 
            cout << results[i] << " ";
    }
    
    return 0;
}

/*

FUNCTION exploreIslands(areaMap, row, col, waterLevel):
    IF areaMap[row][col] <= waterLevel THEN
        RETURN
    END IF

    areaMap[row][col] = 0

    IF col + 1 < areaMap[0].size() THEN
        exploreIslands(areaMap, row, col + 1, waterLevel)
    END IF

    IF row + 1 < areaMap.size() THEN
        exploreIslands(areaMap, row + 1, col, waterLevel)
    END IF

    IF col - 1 >= 0 THEN
        exploreIslands(areaMap, row, col - 1, waterLevel)
    END IF

    IF row - 1 >= 0 THEN
        exploreIslands(areaMap, row - 1, col, waterLevel)
    END IF
END FUNCTION

FUNCTION main():
    Input num_rows, num_cols
    Create a 2D array landMap of size num_rows x num_cols
    
    FOR i from 0 to num_rows - 1:
        FOR j from 0 to num_cols - 1:
            Input land_height
            landMap[i][j] = land_height
    
    Input num_water_levels
    Create an empty array waterLevels
    
    FOR i from 0 to num_water_levels - 1:
        Input water_level
        Append water_level to waterLevels
    
    Create an empty array results
    
    FOR i from 0 to length(waterLevels) - 1:
        level = waterLevels[i]
        island_count = 0
        temp_land_map = Copy of landMap
        
        FOR row from 0 to num_rows - 1:
            FOR col from 0 to num_cols - 1:
                IF temp_land_map[row][col] > level THEN
                    island_count++
                    exploreIslands(temp_land_map, row, col, level)
                END IF
            END FOR
        END FOR
        
        Append island_count to results
    
    FOR i from 0 to length(results) - 1:
        IF i == length(results) - 1 THEN
            Output results[i]
        ELSE
            Output results[i] followed by space
        END IF
    END FOR
END FUNCTION


*/