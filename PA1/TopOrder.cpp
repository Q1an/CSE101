// CSE 101 Winter 2016, PA 1
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help: 
// Due: 1/22/2016 at 11:59 PM

#ifndef __TOP_ORDER_CPP__
#define __TOP_ORDER_CPP__

#include "Graph.hpp"
#include <list>
// include more libraries as needed

template <class T>
std::list<T> top_order(Graph<T>& g) {
    std::list<T> topOrder;
    bool dag = true;
    for (typename std::map<T, Vertex<T> *>::iterator it=g.vertices.begin(); it!=g.vertices.end(); ++it){
        it->second->pre = -1;
        it->second->post = -1;
    }
    for (typename std::map<T, Vertex<T> *>::iterator it=g.vertices.begin(); it!=g.vertices.end(); ++it){
    	explore(g,it->first,0,topOrder,dag);
    }
    if(dag){
        topOrder.reverse();
    }else{
        topOrder.clear();
    }
    return topOrder;
}

template <class T>
void explore(Graph<T>& g, T t,int c,std::list<T>& topOrder,bool& dag){
    if(g.vertices[t]->visited==false){
    	g.vertices[t]->visited=true;
    	g.vertices[t]->pre=c;
    	c++;
    	for (typename std::list<T>::iterator it=(g.vertices[t])->edges.begin(); it!=(g.vertices[t])->edges.end(); ++it){
    		explore(g,*it,c,topOrder,dag);
    	}
    	g.vertices[t]->post=c;
    	c++;
    	topOrder.push_back(t);
    }else{
        if(g.vertices[t]->post==-1){
            dag = false;
        }
    }
}

#endif
