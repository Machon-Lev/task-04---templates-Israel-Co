#pragma once

#include <iostream>
#include <list>
#include <exception>

class PriorityQueue {
private:
	std::list<float> _queue;
public:
	// You need to complete the implement : 
	void push(const float& t);
	float poll();
};

struct MyComparator {
	float operator()(float a, float b) const {
		return a - b;
	}
};

//template <class T>
//struct MyComparator;
//
//// any templates?
//template<class T>
//class PriorityQueue{
//private:
//	std::list<T> _head();
//public:
//	// You need to complete the implement : 
//	PriorityQueue<T>() {};
//	~PriorityQueue<T>() {};
//
//	void push(const T& t);
//	T poll();
//
//private:
//	// add relevant data members
//};
//
//template<class T>
//inline void PriorityQueue<T>::push(const T& t) {
//	if (_head == nullptr)
//		this._head.push_front(t);
//	else {
//		bool isAdded = false;
//		auto current = _head.begin();
//		auto it = _head.begin();
//		for (; it != _head.end() && !isAdded; it++)
//		{
//			/*if (*it > t) {
//				_head.insert(current, 1, t);
//				isAdded = true;
//			}
//			else
//				currenr = it;*/
//			if (MyComparator(*it, t) < 0) {
//				_head.insert(current, 1, t);
//				isAdded = true;
//			}
//			else
//				current = it;
//		}
//		if (!isAdded)
//			_head.push_back();
//	}
//}
//
//template<class T>
//inline T PriorityQueue<T>::poll()
//{
//	return _head.pop_front();
//}
//
//template<class T>
//struct MyComparator {
//	template <class T>
//	int operator()(T a, T b) const {
//		return a - b;
//	}
//};