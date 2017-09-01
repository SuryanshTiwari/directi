//https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/#
queue<pair<int, int> > q;
void topo(int indegree[], vector<int> v[], vector<int> &visited){
    while(!q.empty()){
        pair<int,int> top = q.front();
        q.pop();
        if(visited[top.second] == 1)continue;
        visited[top.second] = 1;
        for(int i = 0; i < v[top.second].size(); i++){
            indegree[v[top.second][i]]--;
            if(indegree[v[top.second][i]] == 0)
                q.push(make_pair(indegree[v[top.second][i]],v[top.second][i]));
        }
    }    
}

int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    
    int indegree[A+1];
    memset(indegree, 0, sizeof indegree);
    while(!q.empty())q.pop();
    vector<int> v[A+1];
    for(int i = 0; i < B.size(); i++){
        indegree[C[i]]++;
        v[B[i]].push_back(C[i]);
    }
    vector<int> visited(A+1);
    // memset(visited, 0, sizeof visited);
    for(int i = 1; i <= A; i++){
        visited[i] = 0;
        if(indegree[i] == 0){
            q.push(make_pair(indegree[i],i));
        }
    }
    topo(indegree, v, visited);
    for(int i = 1; i <= A; i++){
        if(visited[i] == 0)
            return 0;
    }
    return 1;
}
