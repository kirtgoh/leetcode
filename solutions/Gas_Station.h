/*********************************************************************************
 *  Author:      	Kirt Goh, kirtgoh@gmail.com
 *  Date:        	Aug 15, 2014
 *  Problem:     	Gas Station
 *  Difficulty:  	Easy
 *  Source:      	https://oj.leetcode.com/problems/gas-station/
 *
 *  Notes:
 * 	There are N gas stations along a circular route, where the amount of gas at
 * 	station i is gas[i].
 *
 * 	You have a car with an unlimited gas tank and it costs cost[i] of gas to
 * 	travel from station i to its next station (i+1). You begin the journey with
 * 	an empty tank at one of the gas stations.
 *
 * 	Return the starting gas station's index if you can travel around the circuit
 * 	once, otherwise return -1.
 *
 * 	Note:
 * 	The solution is guaranteed to be unique.
 *
 *  Solution: 		
*********************************************************************************/

#ifndef GAS_STATION_H
#define GAS_STATION_H

#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
};

int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost)
{
    int N = gas.size();

    // clockwise
    for (int i = 0; i < N; i++)
    {
        int tank = 0;
        bool can = true;

        for (int j = 0; j < N; j++)
        {
            int nextStation = (i + j) % N;

            tank += gas[nextStation];
            if ((tank -= cost[nextStation]) < 0 )
            {
                can = false;
                break;
            }
        }
        if (can) return i;
    }

    // counter-clockwise 
    for (int i = 0; i < N; i++)
    {
        int tank = 0;
        bool can = true;

        for (int j = 0; j < N; j++)
        {
            int preStation = ((i - j) + N) % N;

            tank += gas[preStation];
            if ((tank -= cost[preStation]) < 0 )
            {
                can = false;
                break;
            }
        }
        if (can) return i;
    }

    return -1;
}

#endif /* GAS_STATION_H */

