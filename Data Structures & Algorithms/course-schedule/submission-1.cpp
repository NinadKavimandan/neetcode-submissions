class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> preReqs(numCourses, 0);
        bool response = false;
        queue<int> courseQueue;
        for (vector<int>& item : prerequisites)
        {
            adjList[item[1]].push_back(item[0]);
            preReqs[item[0]]++;
        }

        for (int i = 0;i < numCourses;i++)
        {
            if (preReqs[i] == 0)
            {
                courseQueue.push(i);
            }
        }

        while (!courseQueue.empty())
        {
            int course = courseQueue.front();

            for (int& next : adjList[course])
            {
                preReqs[next]--;
                if (preReqs[next] == 0)
                {
                    courseQueue.push(next);
                }
            }

            courseQueue.pop();
        }

        for (int i=0;i < numCourses;i++)
        {
            if (preReqs[i] != 0)
            {
                return false;
            }
        }

        return true;
    }
};

/*

pick out courses with 0 pre-requisites each cycle, if at any cycle you don't find any such courses, it means you cannot finish the courses. to implement this, we need a map that stores the in-degree of each course, and we can perhaps use bfs for the cycle, with courses with 0 pre-req as the starting point, add all courses you can move on to after the 0 pre-req course into the queue.

*/