#include<bits/stdc++.h>
using namespace std;
struct Node{
	int parent;
	int rank;
};
class Solution {

public:
	int findRoot(int element,vector<Node> &parent){
		if(parent[element].parent==-1)
			return element;
		parent[element].parent = findRoot(parent[element].parent,parent);
        return parent[element].parent;
	}

	void groupUnion(int root1,int root2,vector<Node> &parent){
		if(parent[root1].rank>parent[root2].rank){
			parent[root2].parent = root1;
		}
		else if(parent[root1].rank < parent[root2].rank){
			parent[root1].parent = root2;
		}
		else{
			parent[root1].parent = root2;
			parent[root2].rank++;
		}
	}
	bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
		vector<Node> parent(n);
		for(int i=0;i<n;i++){
			parent[i].parent = -1;
			parent[i].rank = 0;
		}

		for(int i=0;i<edges.size();i++){
			int root1 = findRoot(edges[i][0],parent);
			int root2 = findRoot(edges[i][1],parent);
			if(root1!=root2)
            {
              groupUnion(root1,root2,parent);
            }
		}

        int root1 = findRoot(source,parent);
        int root2 = findRoot(destination,parent);
		return root1==root2;
	}
};
