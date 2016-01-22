// CSE 101 Winter 2016, PA 1
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help:
// Due: 1/22/2016 at 11:59 PM

#ifndef __WORM_CPP__
#define __WORM_CPP__

#include "Graph.hpp"
#include "Worm.hpp"
#include <list>
#include <set>
#include "DFS.hpp"
#include <iostream>
// include other libraries as needed

class tile{
public:
	tile(){}
	tile(int a, int b){
		this->a = a>b?a:b;
		this->b = a>b?b:a;
	}
	int a;
	int b;
};
bool operator<(const tile & a, const tile & b ){ 
	if(a.a < b.a){
		return true;
	}
	if(a.b < b.b){
		return true;
	}
	return false;
}
template <class T>
void generategraph(Graph<T>& g,int n, std::list<int> o){
	for(int i=0;i<n*(n-1);i++){
		if((i+1)%n==0){
			g.vertices[tile(i,i+n)] = new Vertex<T>(tile(i,i+n));
		}else{
			g.vertices[tile(i,i+n)] = new Vertex<T>(tile(i,i+n));
			g.vertices[tile(i,i+1)] = new Vertex<T>(tile(i,i+1));
		}
	}
	for(int i=n*(n-1);i<n*n-1;i++){
		g.vertices[tile(i,i+1)] = new Vertex<T>(tile(i,i+1));
	}
    for (typename std::map<T, Vertex<T> *>::iterator it=g.vertices.begin(); it!=g.vertices.end(); ++it){
    	if(g.vertices.count(tile((it->second->id).a,(it->second->id).b+n+1)) != 0){
    		it->second->edges.push_back(tile((it->second->id).a,(it->second->id).b+n+1));
    	}
    	if(g.vertices.count(tile((it->second->id).a-1,(it->second->id).b+n)) != 0){
    		it->second->edges.push_back(tile((it->second->id).a-1,(it->second->id).b+n));
    	}
    	if(g.vertices.count(tile((it->second->id).a-n,(it->second->id).b+1)) != 0){
    		it->second->edges.push_back(tile((it->second->id).a-n,(it->second->id).b+1));
    	}
    	if(g.vertices.count(tile((it->second->id).a-n-1,(it->second->id).b)) != 0){
    		it->second->edges.push_back(tile((it->second->id).a-n-1,(it->second->id).b));
    	}
    }
	for(typename std::list<int>::iterator it=o.begin();it!=o.end();++it){
		if(g.vertices.count(tile(*it,(*it)+1))!=0){
			g.vertices[tile(*it,(*it)+1)]->visited=true;
		}
		if(g.vertices.count(tile(*it,(*it)-1))!=0){
			g.vertices[tile(*it,(*it)-1)]->visited=true;
		}
		if(g.vertices.count(tile(*it,(*it)+n))!=0){
			g.vertices[tile(*it,(*it)+n)]->visited=true;
		}
		if(g.vertices.count(tile(*it,(*it)-n))!=0){
			g.vertices[tile(*it,(*it)-n)]->visited=true;
		}	
	}
}
bool canReachBed(int n, int s1, int s2, int d1, int d2, std::list<int> o) {
    Graph<tile> g;
    generategraph(g,n,o);
    tile s = tile(s1,s2);
    tile d = tile(d1,d2);
	std::set<tile> visited = dfs(g,s);
	for(typename std::set<tile>::iterator it=visited.begin();it!=visited.end();++it){
		printf("%d %d\n", it->a,it->b);
	}
	if(visited.count(d)==0){
		return false;
	}else{
		return true;
	}
}

#endif
