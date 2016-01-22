// CSE 101 Winter 2016, PA 1
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help:
// Due: 1/22/2016 at 11:59 PM

#ifndef __DFS_CPP__
#define __DFS_CPP__

#include "Graph.hpp"
#include <set>
// include more libraries as needed

template <class T>
std::set<T> dfs(Graph<T>& g, T t){
    std::set<T> visited;
	explore(g,t,visited);
    return visited;
}

template <class T>
void explore(Graph<T>& g, T t,std::set<T>& visited){
    if(g.vertices[t]->visited==false){
    	visited.insert(t);
    	g.vertices[t]->visited=true;
    	for (typename std::list<T>::iterator it=(g.vertices[t])->edges.begin(); it!=(g.vertices[t])->edges.end(); ++it){
    		explore(g,*it,visited);
    	}
    }
}

#endif
