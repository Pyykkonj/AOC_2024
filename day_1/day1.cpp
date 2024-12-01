#include "day1.hpp"
#include "../Helpers/filehandler.hpp"

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


void run_day1()
{
    ifstream f = h_read_file("day1.txt");

    vector<int> l_list;
    vector<int> r_list;

    string str;
    while(h_read_line(f, str) > 0)
    {
        int left, right;    
        string right_str;

        left = atoi(str.c_str());

        right_str = str.substr(str.find("   ")+3);

        right = atoi(right_str.c_str());

        //printf("Left: %d, right: %d \n", left, right);

        l_list.push_back(left);
        r_list.push_back(right);
    }

    std::sort(l_list.begin(), l_list.end());
    std::sort(r_list.begin(), r_list.end());

    int sumDelta = 0;
    for(int i = 0; i<l_list.size(); i++)
    {
        int delta = abs(l_list[i]-r_list[i]);
        sumDelta += delta;
        //printf("Left %d, right %d, delta: %d\n", l_list[i], r_list[i], delta);
    }

    printf("(A) Sumdelta: %d \n", sumDelta);



    /************** B PART   *************/

    int sumSimScore = 0;
    for(int i = 0; i<l_list.size(); i++)
    {
        int simScoreBase = l_list[i];
        int simScoreMult = 0;
        for(int j = 0; j<r_list.size(); j++)
        {
            if (r_list[j] == simScoreBase)
            {
                simScoreMult++;
            }
        }

        int simScore = simScoreBase * simScoreMult;
        sumSimScore += simScore;

        //printf("Left %d, simScore: %d\n", l_list[i], simScore);
    }

    printf("(B) sum simSocre: %d\n", sumSimScore);
    
}