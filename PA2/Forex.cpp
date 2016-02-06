// CSE 101 Winter 2016, PA 2
//
// Name: Qian YingDong
// PID: A92501011
// Sources of Help: 
// Due: February 5th, 2016 at 11:59 PM

#ifndef __FOREX_CPP__
#define __FOREX_CPP__

#include <list>

#include "Graph.hpp"
#include "Forex.hpp"
// include more libraries as needed

bool forex(std::list<Ticker> tickers){
	std::map<std::string,float> vertex;
	for (auto it = tickers.begin();it!=tickers.end();it++){
		vertex[it->in]=0;
		vertex[it->out]=0;
	}
	auto it = tickers.begin();
	vertex[it->in]=1;
	for (int i = 0; i<vertex.size();i++){
		for (auto it = tickers.begin();it!=tickers.end();it++){
			if((vertex[it->in]*(it->rate))>vertex[it->out]){
				vertex[it->out] = (vertex[it->in]*(it->rate));
			}
		}
	}
	if (vertex[it->in]>1){
		return true;
	}
    return false; // Replace with correct value
}

#endif