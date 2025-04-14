class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDegrees(numCourses,0);

        for(auto it: prerequisites){
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
            inDegrees[course]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(inDegrees[i] == 0){
                q.push(i);
            }
        }
        
        int visited = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            visited++;

            for(int nbr: adj[course]){
                if(--inDegrees[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        return visited == numCourses;

    }
};