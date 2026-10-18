class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<list<int>>graph(numCourses);
        for(int i = 0 ; i<n ; i++){
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];
            graph[src].push_back(dest);
        }
        vector<int>indegree(numCourses, 0);
        for(auto ele: graph){
            for(int x: ele){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i = 0 ; i<numCourses; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for(int ele: graph[curr]){
                indegree[ele]--;
                if(indegree[ele]==0)q.push(ele);
            }
        }
        if(ans.size() == numCourses) return ans;
        return {};
        
    }
};