class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Build graph (adjacency list) and in-degree array.
        vector<vector<int>> adjL(numCourses);
        vector<int> inDegree(numCourses, 0);
        
        // Process each prerequisite pair only once.
        for (auto it : prerequisites) {
            // For pair [a, b]: to take course a, you first need course b.
            // So add an edge b -> a.
            adjL[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
        }
        
        // Initialize the queue with all courses that have no prerequisites.
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0)
                q.push(i);
        }
        
        vector<int> order;  // This will store the valid course order.
        
        // BFS using Kahn's Algorithm.
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            
            for (int neighbor : adjL[course]) {
                // Decrement the in-degree for neighbors.
                if (--inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Check if all courses are included in the order.
        if (order.size() == numCourses)
            return order;
        else
            return vector<int>();  // Return empty vector if it is impossible.
    }
};