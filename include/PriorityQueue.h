#pragma once

#include <iostream>
#include <list>
#include <exception>

struct MyComparator;

/// <summary>
/// Priority Queue
/// </summary>
/// <typeparam name="T"></typeparam>
template <class T>
class PriorityQueue {
private:
	std::list<T> _queue;
public:
	// You need to complete the implement : 
	void push(const T& t);
	T poll();
};

/// <summary>
/// Insert a new element to the wanted place considering priority in complexity of O(n)
/// </summary>
/// <typeparam name="T">Type of the inserted element</typeparam>
/// <param name="t">An element to insert</param>
template <class T>
inline void PriorityQueue<T>::push(const T& t)
{
	if (_queue.empty()) {
		_queue.push_front(t);
	}
	else {
		bool isAdded = false;
		for (auto it = _queue.begin(); it != _queue.end() && !isAdded; ++it) {
			if (!(MyComparator()(*it, t) < 0)) {
				_queue.insert(it, t);
				isAdded = true;
			}
		}
		if (!isAdded)
			_queue.push_back(t);
	}
}

/// <summary>
/// Pulls out the highest priority element in the queue 
/// which is located in the front of the queue
/// </summary>
/// <typeparam name="T">Type of the elements in the queue</typeparam>
/// <returns>Highest priority element in the queue</returns>
template <class T>
inline T PriorityQueue<T>::poll() {
	if (_queue.empty()) {
		std::exception e("PriorityQueue empty !");
		throw e;
	}

	T ret = _queue.front();
	_queue.pop_front();
	return ret;
}

/// <summary>
/// comparison struct
/// </summary>
struct MyComparator {
	/// <summary>
	/// Compare between 2 element of type T using operator minus-
	/// </summary>
	/// <typeparam name="T">Type of elemets</typeparam>
	/// <param name="a">First element to compare</param>
	/// <param name="b">Second element to compare</param>
	/// <returns>Positive element type T if a > b
	///			 Negative element of type T if a < b 
	///			 "0" element of type T if a == b</returns>
	template <class T>
	T operator()(T a, T b) const {
		return a - b;
	}
};