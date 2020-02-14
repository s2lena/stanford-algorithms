#include <algorithm> 
#include <fstream>
#include <iostream>
#include <vector>

#ifdef NDEBUG
#define NUM_OF_NODES 9
#else
#define NUM_OF_NODES 875714
#endif 

using namespace std;

enum class Flags
{
	UNCHECK = 0,
	CHECK = 1,
	DONE = 2
};

int main() {
	vector<vector<int>> map(NUM_OF_NODES);
	vector<vector<int>> reversed_map(NUM_OF_NODES);
	vector<Flags> flags;
	vector<int> orders;

	ifstream fin;
	int num_of_edges = 0;
#ifdef NDEBUG
	fin.open("C:/Users/Selena/Documents/SCC_debug.txt");
#else
	fin.open("C:/Users/Selena/Documents/SCC.txt");
#endif
	while (!fin.eof()) {
		int x, y;
		x = y = -1;
		fin >> x >> y;
		if (x == y)
			continue;
		num_of_edges++;
		map[x - 1].push_back(y - 1);
		reversed_map[y - 1].push_back(x - 1);
	}
	fin.close();
	cout << "Edges: " << num_of_edges << endl;

	flags.assign(NUM_OF_NODES, Flags::UNCHECK);
	for (int node = 0; node < NUM_OF_NODES; node++) {
		if (flags[node] == Flags::DONE)
			continue;

		vector<int> nodes;
		nodes.push_back(node);

		while (!nodes.empty())
		{
			int current_node = nodes.back();

			if (flags[current_node] != Flags::DONE) {
				flags[current_node] = Flags::CHECK;

				int next_node = -1;
				for (int child_node : map[current_node]) {
					if (flags[child_node] == Flags::UNCHECK) {
						next_node = child_node;
						break;
					}
				}

				if (next_node != -1) {
					nodes.push_back(next_node);
				}
				else {
					flags[current_node] = Flags::DONE;
				}
			}

			if (flags[current_node] == Flags::DONE) {
				orders.push_back(current_node);
				nodes.pop_back();
			}
		}
	}
	vector<int> size;
	reverse(orders.begin(), orders.end());
	flags.assign(NUM_OF_NODES, Flags::UNCHECK);
	for (int node : orders) {
		if (flags[node] == Flags::DONE)
			continue;

		vector<int> components;
		vector<int> nodes;
		nodes.push_back(node);

		while (!nodes.empty())
		{
			int current_node = nodes.back();

			if (flags[current_node] != Flags::DONE) {
				flags[current_node] = Flags::CHECK;

				int next_node = -1;
				for (int child_node : reversed_map[current_node]) {
					if (flags[child_node] == Flags::UNCHECK) {
						next_node = child_node;
						break;
					}
				}

				if (next_node != -1) {
					nodes.push_back(next_node);
				}
				else {
					flags[current_node] = Flags::DONE;
				}
			}

			if (flags[current_node] == Flags::DONE) {
				components.push_back(current_node);
				nodes.pop_back();
			}
		}
		size.push_back(components.size());
		components.clear();
	}
	vector<int> max;
	max.assign(5, 0);
	int i = 0;
	while (i != 5) {
		for (int j : size) {
			if (j > max[i]) {
				bool sure = true;
				for (int t = 0; t < 5; t++) {
					if (j == max[t]) {
						sure = false;
						break;
					}
				}
				if (sure == true)
					max[i] = j;
			}
		}
		i++;
	}

	for (int e : max) {
		cout << e << endl;
	}

	return 0;
}