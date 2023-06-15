#include "PriorityQueue.h"

void PriorityQueue::push(const Dog& t)
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
/// 
/// </summary>
/// <returns></returns>
Dog PriorityQueue::poll() {
	if (_queue.empty()) {
		std::exception e("PriorityQueue empty !");
		throw e;
	}

	Dog ret = _queue.front();
	_queue.pop_front();
	return ret;
}
