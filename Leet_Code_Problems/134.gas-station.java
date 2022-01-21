/*
 * @lc app=leetcode id=134 lang=java
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
    public int canCompleteCircuit(int[] gas, int[] cost) {

        //totalGas -> stores the gas remaining after traverlling around the circuit, 
        //currGas -> stores the gasRem after filling up at a stn & trvaelling to next station, if that's not possible, stores 0
        //station -> stores the index from which we can start and finish a round circuit

        int totalGas = 0, i, currGas = 0, station = 0, len = gas.length;

        for (i = 0; i < len; i++) {
            totalGas = totalGas + (gas[i] - cost[i]);
            currGas = currGas + (gas[i] - cost[i]);

            if (currGas < 0) // negative cost
            {
                currGas = 0;
                station = i + 1;
            }
        }

        //  If the Total Gas in the NET JOURNEY is Negative then return -1
        return (totalGas < 0) ? -1 : station;
    }
}
// @lc code=end
