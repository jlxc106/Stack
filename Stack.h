//Stack.h
//Written by Jay Lim
//September 16, 2016

#pragma once

template <typename T> struct node{
	node<T> *back;
	node<T> *front;
	T nodeData;

};

