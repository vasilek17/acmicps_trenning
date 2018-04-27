#include <iostream> 
#include <vector>
#include <deque>



struct vertex {

	std::vector<vertex* > friends;

	bool us = false;
	int value;

	vertex(int value_) : value(value_) {}

	vertex() {}

	int* bfs(std::deque<vertex*> *deq, int n) {
		int* dist = new int[n];
		deq->push_front(this);
		while (!deq->empty()) {
			std::cout << deq->size() << " ";
			vertex* frontvert = deq->front(); deq->pop_front();
			for (auto v : frontvert->friends) {
				if (!v->us) {
					v->us = false;
					if (value != v->value)
						dist[v->value] = dist[frontvert->value] + 1;
					deq->push_front(v);
				}
			}
		}
		for (int o = 0; o < n; o++)
			std::cout << dist[o] << " ";
		return dist;
	}

	void push(vertex* f) {
		friends.push_back(f);
		//	f->friends.push_back(this);
	}
};


void main() {
	int n, i, a, b;
	std::vector<vertex* > all;
	std::cin >> n >> i;
	for (int k = 0; k < n; k++) {
		vertex* ex = new vertex(k);
		all.push_back(ex);
	}

	//for (auto o : all)
	//std::cout << o->value << std::endl;
	for (int k = 0; k < i; k++) {
		std::cin >> a >> b;
		all.at(a)->push(all.at(b)); all.at(b)->push(all.at(a));
	}

	std::vector<int*> dist;

	std::deque<vertex* > *deq = new std::deque<vertex* >;

	std::cin >> i;
	for (int k = 0; k < i; k++) {
		std::cin >> a;
		dist.push_back(all.at(a)->bfs(deq, n));
		for (auto p : all)
			p->us = false;
	}

	for (auto k : dist) {
		for (int l = 0; l < n; l++)
			std::cout << k[l] << std::endl;
	}

	std::cin >> a;


}
