// CSE 101 Winter 2016, PA 1
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help: 
// Due: 1/22/2016 at 11:59 PM

#ifndef __SCC_CPP__
#define __SCC_CPP__

#include "Graph.hpp"
#include <list>
#include <set>
#include "DFS.hpp"
// include more libraries as needed

template <class T>
std::list<T> top_order(Graph<T>& g) {
    std::list<T> topOrder;
    for (typename std::map<T, Vertex<T> *>::iterator it=g.vertices.begin(); it!=g.vertices.end(); ++it){
        explore(g,it->first,0,topOrder);
    }
    topOrder.reverse();
    return topOrder;
}

template <class T>
void explore(Graph<T>& g, T t,int c,std::list<T>& topOrder){
    if(g.vertices[t]->visited==false){
        g.vertices[t]->visited=true;
        g.vertices[t]->pre=c;
        c++;
        for (typename std::list<T>::iterator it=(g.vertices[t])->edges.begin(); it!=(g.vertices[t])->edges.end(); ++it){
            explore(g,*it,c,topOrder);
        }
        g.vertices[t]->post=c;
        c++;
        printf("%c",t);
        topOrder.push_back(t);
    }
}

template <class T>
std::list<std::set<T> > scc(Graph<T>& g){
    std::list<std::set<T>> SCCS;
    Graph<T> n = reverse(g);
    std::list<T> toporder = top_order(n);
    for (typename std::list<T>::iterator it=toporder.begin(); it!=toporder.end(); ++it){
    	if(g.vertices[*it]->visited==false){
    		SCCS.push_back(dfs(g,*it));
    	}
    }
    return SCCS;
}

template <class T>
Graph<T> reverse(Graph<T>& g){
	Graph<T> n;
	for (typename std::map<T, Vertex<T> *>::iterator it=g.vertices.begin(); it!=g.vertices.end(); ++it){
    	for (typename std::list<T>::iterator it2=(it->second)->edges.begin(); it2!=(it->second)->edges.end(); ++it2){
			if (n.vertices.count(it->first) == 0) {
                n.vertices[it->first] = new Vertex<T>(it->first);
            }
            if (n.vertices.count(*it2) == 0) {
                n.vertices[*it2] = new Vertex<T>(*it2);
            }
          	n.vertices[*it2]->edges.push_back(it->first);
    	}
    }
    return n;
}



#endif
