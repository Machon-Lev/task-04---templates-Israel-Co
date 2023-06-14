#include "PriorityQueue.h"

PriorityQueue::PriorityQueue() :_queue() {}

PriorityQueue::~PriorityQueue() { _queue.clear(); }

void PriorityQueue::push(const int& t)
{
	if (_queue.empty()) {
		_queue.push_front(t);
	}
	else {
		bool isAdded = false;
		for (auto it = _queue.begin(); it != _queue.end() && !isAdded; ++it) {
			if (MyComparator()(*it, t) > 0) {
				if (it == _queue.begin())
					_queue.push_front(t);
				else 
					_queue.insert(--it, t);
				isAdded = true;
			}
		}
		if (!isAdded)
			_queue.push_back(t);
	}
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int PriorityQueue::poll() {
	if (_queue.empty()) {
		std::exception e("PriorityQueue empty !");
		throw e;
	}

	int ret = _queue.front();
	_queue.pop_front();
	return ret;
}
