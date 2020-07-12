class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rest = 0, run = 0, start = 0;
        for(int i=0; i<gas.size(); i++)
        {
            run += gas[i] - cost[i];    
            rest += gas[i] - cost[i];  
            //假设从编号为0站开始，一直到k站都正常，在开往k+1站时车子没油了。这时，应该将起点设置为k+1站
            if(run < 0)
            {
                start = i + 1;
                run = 0;
            }
        }
        return rest<0 ? -1 : start;
    }
};