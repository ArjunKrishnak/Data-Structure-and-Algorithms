#include <list>
class Solution {
public:
    unordered_map<int,list<int> >  mAdjList;
    vector<vector<int> > mResult;
    vector<int> mVisitedTime, mLowTime;
    int mTime = 0;
    
    void trajans(unordered_map<int,bool> & visited, int currnode, int parent){
        visited[currnode] = true;
        mVisitedTime[currnode] =  mLowTime[currnode] = mTime++;
        for(int neighbour: mAdjList[currnode]){
            if( neighbour == parent )
                continue;
            if(!visited[neighbour]){
                trajans(visited,neighbour,currnode);
                // Updates low time of all nodes while travesing back in DFS
                mLowTime[currnode] = min(mLowTime[currnode],mLowTime[neighbour]);
                // Condition for critical edge
                if(mVisitedTime[currnode] < mLowTime[neighbour]){
                    mResult.push_back({currnode,neighbour});
                }
            }
            else{
                // Back edge
                mLowTime[currnode]=min(mLowTime[currnode],mVisitedTime[neighbour]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Build the graph
        for(int i=0;i<connections.size();i++){
            mAdjList[connections[i][0]].push_back(connections[i][1]);
            mAdjList[connections[i][1]].push_back(connections[i][0]);
        }
        unordered_map<int,bool> visited;
        mVisitedTime.resize(n);
        mLowTime.resize(n);
        trajans(visited,0,-1);
        return mResult;
    }
};

/*
nodes within a backedge:
    lowtime[currnode]=min(lowtime[currnode],visitedtime[neighbour]);
nodes within a backedge:
    if(lowtime[currnode] < lowtime[neighbour]);
        critical edge;
    else
        lowtime[currnode] = lowtime[neighbour];
[Node] [VisitedTime] [LowTime]
0       0               0
1       1               0
2       2               0
3       3               3

edge btw 1 and 3 is critical connection!

*/
