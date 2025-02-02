#include<bits/stdc++.h>
using namespace std;
class Solution {

public:
	int findRoot(vector<int> &parent,int element1){
		if(parent[element1]==-1)
			return element1;
		int root =  findRoot(parent, parent[element1]);
        parent[element1] = root;
        return root;
	}
	
	void groupUnion(vector<int> &parent,int element1,int element2){
		int root1 = findRoot(parent,element1);
		int root2 = findRoot(parent,element2);

		if(root1==root2)
			return;
		parent[root1] = root2;

	}
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		vector<int> parent(n,-1);

		for(int i=0;i<edges.size();i++){
			groupUnion(parent,edges[i][0],edges[i][1]);
		}
		int root1 = findRoot(parent,source);
		int root2 = findRoot(parent,destination);
		return root1==root2;
	}
};
