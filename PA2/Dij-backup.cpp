// CSE 101 Winter 2016, PA 2
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help: 
// Due: February 5th, 2016 at 11:59 PM

#ifndef __DIJKSTRA_CPP__
#define __DIJKSTRA_CPP__

#include "Graph.hpp"
#include <vector>
#include <algorithm>
// include more libraries as needed

template <class T>
struct compare  
{  
  bool operator()(const std::pair<Vertex<T>*, float>& l, const std::pair<Vertex<T>*, float>& r)  
  {  
      return l.second > r.second;  
  }  
};  

template <class T>
float dijkstra(Graph<T>& g, T src) {
    float cost = 0.0;
    std::vector<std::pair<Vertex<T>*, float> > pq;  
    for (auto it=g.vertices.begin(); it!=g.vertices.end(); ++it){
    		pq.push_back(std::make_pair(it->second,it->second->distance));
    	}
    std::make_heap (pq.begin(),pq.end(),compare<T>());
    while (!pq.empty())  
    { 
    	printf("%f",pq.back().second);
    	pq.pop_back();
    }
    return cost;
}

#endif