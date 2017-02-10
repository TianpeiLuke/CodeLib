/*
implementation of Dijkstra's algorithm to find the minimal path from 
one single source s to every other node in directed graph.

Note that the distance on each edge is non-negative

===========================================================
Let X = {s}
A[s] = 0 = shortest path distance from s-s

naive implementation:
while (X != V){
   Ex = {edges from X -> V-X }
   for( (v,w) in Ex){
        find w such that A[v]+ d[v,w] is minimized
   }
   X = X \cup w
   A[w] = A[v] + d[v,w] where (v,w) is the minimizer given 
}

naive implementation need O(m*n)

=============================================================

could use min Heap data structure (at every node, key<= children's keys)
    extract-min by swapping up last leaf, bubbling down O(log(n))
    insert via bubbling up O(log(n))

Invariant #1:
    all elemnts (node) in heap =  vertices in V-X

Invariant #2
    for v in V-X
       key[v] = smallest Dijkstra's greedy score of an edge (u,v) in E with u in X
   note that key[v] = \infty  if not directed link from X -> v 

The min-heap will find the minimizer of Dijkstra's greedy score in O(1) time 


To maintain invariant #2: when a new node x added to X, the frontier changes. This will add more edges ((w->*) for * in V-X) so those corresponding vertices will have key[*] decrease. 

for(each edge (w,v) in E){
   if(v in V-X){
      delete v in heap
      recompute key[v] = min{key[v], A[w]+d(w,v)}
      insert v according to new key[v]
   }
}

in total O(m+n) = O(m) for large m, heap operations,  running time O(m*log(n))

*/
#include "../../include/graph_construct.hpp"
#include "../../include/graph_topology.hpp"

struct greaterNode{
    bool operator()(const pair<int, int>& node1, const pair<int, int>& node2) const{
        return (node1.second > node2.second);
    }
};


int visited_number(const unordered_map<int, bool> visited){
   int result = 0;
   for(auto it=visited.begin(); it!=visited.end(); it++){
        if(it->second) result ++;
   }
   return result;
}


void dijkstra_routine(const unordered_map<int, vector<int>> adjList, const unordered_map<int, vector<int>> weights,  unordered_map<int, bool>& visited, vector<pair<int,int>>& nodeHeap, unordered_map<int, int>& min_path){
     int loop_n = 0; 
     int barWidth = 60;
     double progress = 0.0;
     while(!nodeHeap.empty()){
        loop_n ++;
        //cout<<"Loop "<<loop_n<<endl<<endl;
        //=================== progress bar ===========================
        progress = double(visited_number(visited))/double(visited.size());
        cout << "[";
        int pos = barWidth * progress;
        for (int i = 0; i < barWidth; ++i) {
            if (i < pos) std::cout << "=";
            else if (i == pos) std::cout << ">";
            else std::cout << " ";
        }
        cout << "] " << int(progress * 100.0) << " % "<<"Loop "<<loop_n<<"\r";
        cout.flush();
        //=========================================================

        //begin by poping up the smallest key value in the heap
        pair<int, int> frontNode = nodeHeap.front(); 
        int source = frontNode.first;
        int key = 0;
        if(visited[source]){ 
           // visited before, drop it
           pop_heap(nodeHeap.begin(), nodeHeap.end(), greaterNode());
           nodeHeap.pop_back();
           continue;
        }
         
        visited[source] = true; //visited it
        key = frontNode.second;
        min_path[source] = key;  //minimal path 
        cout<<endl<<"visited node"<<source<<" min-path "<<key<<endl;
        pop_heap(nodeHeap.begin(), nodeHeap.end(), greaterNode());
        nodeHeap.pop_back();


        vector<int> neighbors = adjList.at(source);
        vector<int> neighbor_weights = weights.at(source);
 
        //cout<<"recompute the min-path from visited group to unvisited group"<<endl;
        for(int i=0; i< neighbors.size(); i++){
            int neighbor = neighbors[i];
            if(visited[neighbor] == false){
                //delete neighbor
                frontNode = nodeHeap.front();
                stack<pair<int,int>> tracker;
                tracker.push(frontNode);
                while(frontNode.first != neighbor && !nodeHeap.empty()){
                    pop_heap(nodeHeap.begin(), nodeHeap.end(), greaterNode());
                    nodeHeap.pop_back();
                    frontNode = nodeHeap.front();
                    tracker.push(frontNode);
                }
                if(nodeHeap.empty()){//by construction, node1 should in heap
                    cerr<<"No node "<<neighbor<<"in heap"<<endl;
                    return;
                }
                // update key value for neighbor
                int min_key = frontNode.second;
                min_key = min(min_key, min_path[source]+neighbor_weights[i]);
                tracker.top() = make_pair(frontNode.first, min_key);
                // push back to heap
                while(!tracker.empty()){
                    pair<int, int> cur_node = tracker.top();
                    nodeHeap.push_back(cur_node);
                    push_heap(nodeHeap.begin(), nodeHeap.end(), greaterNode());
                    tracker.pop();
                }
            }
        }
     }
}

void dijkstra(const unordered_map<int, vector<int>> adjList, const unordered_map<int, vector<int>> weights, unordered_map<int, bool>& visited,  int source, unordered_map<int, int>& min_path){
/*
    compute the minimum path from source to every other nodes 

*/
     min_path.clear();
     vector<pair<int, int>> edgeList;
     adjList_to_edgeList(adjList, edgeList);
  
     int edge_size = edgeList.size();
     // build a max-heap for dijkstra algorithm 
     // key is the second argument, 
     vector<pair<int, int>> nodeHeap; 
     // initialize 
     min_path[source] =  0;
     visited[source] = true;
     cout<<"visited node"<<source<<" min-path "<<0<<endl;
  
     vector<int> neighbors = adjList.at(source);
     vector<int> neighbor_weights = weights.at(source);
     cout<<"min-heap construction for unvisited nodes"<<endl;
     for(auto it=adjList.begin(); it!=adjList.end(); it++){
        if(visited[it->first] == false){
           //element in minheap should be unvisited nodes
           auto findit = find(neighbors.begin(), neighbors.end(), it->first);
           int disp = distance(neighbors.begin(), findit);
           if(findit!= neighbors.end()){
              nodeHeap.push_back(make_pair(it->first, neighbor_weights[disp]));
              min_path[it->first] = neighbor_weights[disp];
           }else{
              nodeHeap.push_back(make_pair(it->first, INT_MAX));
              min_path[it->first] = INT_MAX;
           }
        }
     }
     // make min-heap 
     make_heap(nodeHeap.begin(), nodeHeap.end(), greaterNode());
     // call sub-routinue to loop over edges and unvisited nodes
     dijkstra_routine(adjList, weights, visited, nodeHeap, min_path);
  
}
