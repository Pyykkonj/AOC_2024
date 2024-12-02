#include "day2.hpp"
#include "../Helpers/filehandler.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool is_lane_safe(vector<int> line)
{
    bool safe = true;
    bool increasing = true;
    bool first = true;

    for(int j = 1; j < line.size(); j++)
    {
        int differ = line.at(j) - line.at(j-1);

        if(first)
        {           
            if(differ > 0)
            {
                increasing = true;
            }
            else
            {
                increasing = false;
            }
            first = false;
        }

        if(differ > 0 && differ < 4)
        {
            if(increasing == false)
            {
                safe = false;
                break;
            }
        }
        else if(differ < 0 && differ > -4)
        {   
            if(increasing == true)
            {
                safe = false;
                break;
            }
        }
        else
        {
            safe = false;
            break;
        }

    }

    return safe;
}

void run_day2()
{

    ifstream f = h_read_file("day2.txt");

    vector<vector<int>> data;

    string str;
    while(h_read_line(f, str) > 0)
    {
        vector<int> line;
        while(true)
        {

            int num = atoi(str.c_str());
            line.push_back(num);

            int nextInd = str.find(" ", 0);

            if(nextInd == -1)
            {
                break;
            }

            str = str.substr(nextInd + 1);

            //printf(" %d ", num);
        }
        //printf("\n");

        data.push_back(line);
    }

    int safeCount = 0;
    for(int i = 0; i<data.size(); i++)
    {
        if(is_lane_safe(data[i]))
        {
            safeCount++;
        }

        // for(int j = 0; j < data[i].size(); j++)
        // {
        //     printf("%d ", data[i].at(j));
        // }
        // printf(" safe? %s \n",safe ? "YES" : "NO");
    }

    printf("(A) Safecount: %d \n", safeCount);

    /***************** PART B **********************/

    safeCount = 0;
    for(int i = 0; i<data.size(); i++)
    {
        if(is_lane_safe(data[i]))
        {
            safeCount++;
        }
        else
        {
            for(int j = 0; j < data[i].size(); j++)
            {
                vector<int> manipulatedLine = data[i];
                manipulatedLine.erase(manipulatedLine.begin() + j);
                
                if(is_lane_safe(manipulatedLine))
                {
                    safeCount++;
                    break;
                }

            }

        }
    }

    printf("(B) Safecount: %d \n", safeCount);

}