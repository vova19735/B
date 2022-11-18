#include<iostream>
#include <fstream>
using namespace std;
int main() {
	ifstream ifs;
	ifs.open("input.txt");
	int value;
	int N, Q;
	ifs >> N;
	int y = 0, n = 0;
	int** client1 = new int *[N];
	for (int i = 0;i < N;i++) {
		client1[i] = new int [3];
	}
	int start, end, cost, type;
	for (int i = 0;i < N;i++) {
		ifs>>client1[i][0];
		ifs >> client1[i][1];
		ifs >> client1[i][2];
	}

	ofstream ofs;
	ofs.open("output.txt");
	ifs >> Q;
	for (int i = 0;i < Q;i++) {
		ifs >> start;
		ifs >> end;
		ifs >> type;
		int all_cost = 0;
		int all_time = 0;
		switch (type) {
		case 1:
			all_cost = 0;
			for (int i = 0;i < N;i++) {
				if (client1[i][0] >= start && client1[i][0] <= end) {
					all_cost += client1[i][2];
				}
			}
			ofs << all_cost << " ";
			break;
		case 2:
			all_time = 0;
			for (int i = 0;i < N;i++) {
				if (client1[i][1] >= start && client1[i][1] <= end) {
					all_time += (client1[i][1] - client1[i][0]);
				}
			}
			ofs << all_time << " ";
			break;
		}
	}
	ofs.close();
	ifs.close();

	for (int i = 0;i < N;i++) {
		delete [] client1[i];
	}
	delete[]client1;
	return 0;
}