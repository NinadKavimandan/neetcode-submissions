class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int> order;
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> preReqsLeft(numCourses, 0);
        queue<int> courseQueue;

        for (vector<int>& item : prerequisites)
        {
            adjList[item[1]].push_back(item[0]);
            preReqsLeft[item[0]]++;
        }

        for (int i=0;i < numCourses;i++)
        {
            if (preReqsLeft[i] == 0)
            {
                courseQueue.push(i);
            }
        }

        while (!courseQueue.empty())
        {
            int course = courseQueue.front();
            order.push_back(course);
            for (int& nextCourse : adjList[course])
            {
                preReqsLeft[nextCourse]--;
                if (preReqsLeft[nextCourse] == 0)
                {
                    courseQueue.push(nextCourse);
                }
            }

            courseQueue.pop();
        }

        return order.size() == numCourses ? order : vector<int>();
    }
};

/*

use Kahn's topological sort to always remove the course with no pending pre-requisite (0 in-degree). return the order of courses enqueued only if there is no course 0 in-degree left.

*/