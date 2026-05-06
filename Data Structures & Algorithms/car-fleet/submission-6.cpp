class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        int fleets = 0;
        vector<pair<int, int>> sorted;

        for (int index=0;index<position.size();index++)
        {
            sorted.push_back({position[index], speed[index]});
        }

        sort(sorted.begin(), sorted.end(), [] (pair<int, int> a, pair<int, int> b) {
            return a.first > b.first;
        });

        double timeToReach = 0.0;

        for (int index=0;index<sorted.size();index++)
        {
            double curTimeToReach = (double)(target - sorted[index].first)/sorted[index].second;
            // if (timeToReach.empty())
            // {
            //     timeToReach.push(curTimeToReach);
            // }
            // else
            // {
            //     if (timeToReach.top() < curTimeToReach)
            //     {
            //         timeToReach.push(curTimeToReach);
            //     }
            // }

            if (timeToReach < curTimeToReach)
            {
                fleets++;
                timeToReach = curTimeToReach;
            }
        }

        return fleets;
    }
};

/*

basically look for all cars that reach the destination at the same time, is what I thought at first.
but the fleet point is the precondition for them to reach together, post which they move at the same speed and reach the destination together.
need a way to compute the fleet point, or better, just keep track of car ahead in each round, and if new position exceeds the car ahead, just make them equal and pick speed of the car that was ahead?

okay this didn't work. let's go with simpler approach and see when a car reaches destination.
*/