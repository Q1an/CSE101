// DO NOT MODIFY
//
// CSE 101 Winter 2016, PA 1

#ifndef __SCC_HPP__
#define __SCC_HPP__

#include <list>

#include "DFS.hpp"

template <class T>
std::list<std::set<T>> scc(Graph<T>& g);

#include "SCC.cpp"
#endif
