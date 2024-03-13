#include <iostream>
#include <stack>
#include<chrono>
using namespace std::chrono;
using namespace std;

struct HanoiState {
	int disks;
	int source;
	int destination;
	int auxiliary;

	HanoiState(int d, int src, int dest, int aux)	: disks(d), source(src), destination(dest), auxiliary(aux) {}
};

void tohIterative(int disks, int source, int destination, int auxiliary) {
	stack<HanoiState> stack;
	stack.push(HanoiState(disks, source, destination, auxiliary));

	while (!stack.empty()) {
    	HanoiState currentState = stack.top();
    	stack.pop();

    	if (currentState.disks == 1) {
        	cout << "Move disk 1 from rod " << currentState.source << " to rod " << currentState.destination << std::endl;
    	} else {
        	stack.push(HanoiState(currentState.disks - 1, currentState.auxiliary, currentState.destination, currentState.source));
        	stack.push(HanoiState(1, currentState.source, currentState.destination, currentState.auxiliary));
        	stack.push(HanoiState(currentState.disks - 1, currentState.source, currentState.auxiliary, currentState.destination));
    	}
	}
}

int main() {
	int disks = 3;
	int source = 1;
	int destination = 3;
	int auxiliary = 2;
    auto start=high_resolution_clock::now();
	tohIterative(disks, source, destination, auxiliary);
    auto stop=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(stop-start);
    cout<<endl;
    cout<<duration.count()<<"millisecond"<<endl;
	return 0;
}