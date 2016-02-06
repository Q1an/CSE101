// CSE 101 Winter 2016, PA 2
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help: 
// Due: February 5th, 2016 at 11:59 PM

#ifndef __PRIM_DIJK_CPP__
#define __PRIM_DIJK_CPP__

#include "Graph.hpp"
#include <queue>
// include more libraries as needed

template <class T>
struct compare  
{  
  bool operator()(const std::pair<T, float>& l, const std::pair<T, float>& r)  
  {  
      return l.second > r.second;  
  }  
};  

template <class T>
float primdijk(Graph<T>& g, T src, float c) {
    float cost = 0.0;
    std::priority_queue<std::pair<T, float>,std::vector<std::pair<T, float> >,compare<T> > pq;  
    // for (auto it=g.vertices.begin(); it!=g.vertices.end(); ++it){
    // 		std::pair<int, float> tp (it->first,it->second->default_distance);
    // 		pq.push(tp);
    // 	}
    pq.push(std::make_pair(src,0));
    //g.vertices[src]->visited = true;
    g.vertices[src]->prev = src;
    g.vertices[src]->distance = 0;
    while (!pq.empty())  
    { 
    	int current_vertex = pq.top().first;
    	pq.pop();
    	//printf("current: %d status: %d\n",current_vertex,g.vertices[current_vertex]->visited);
    	if(g.vertices[current_vertex]->visited == false){
    		g.vertices[current_vertex]->visited = true;
    		cost += g.get_weight(current_vertex,g.vertices[current_vertex]->prev);
    		for(auto it = g.vertices[current_vertex]->edges.begin();it != g.vertices[current_vertex]->edges.end();it++){
    			float alt = c*g.vertices[current_vertex]->distance + g.get_weight(current_vertex,*it);
    			if(g.vertices[*it]->distance>alt){
    				g.vertices[*it]->prev=current_vertex;
    				g.vertices[*it]->distance = alt;
    				pq.push(std::make_pair(*it,alt));
    			}
    		}
    	}

    }
    return cost;
}

#endif