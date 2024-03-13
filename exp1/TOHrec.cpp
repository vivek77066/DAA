#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
class Solution {
public:
	long toh(int disks, int source, int destination, int auxiliary) {
    	if (disks == 1) {
        	cout << "move disk 1 from rod " << source << " to rod " << destination << std::endl;
        	return 1;
    	}

    	long count1 = toh(disks - 1, source, auxiliary, destination);
    	cout << "move disk " << disks << " from rod " << source << " to rod " << destination << std::endl;
    	long count2 = toh(disks - 1, auxiliary, destination, source);

    	return count1 + count2 + 1;
	}
};

int main() {
	Solution solution;
	int N = 3; // Change N to the number of disks you want to use
	auto start = high_resolution_clock::now();
	long total_moves = solution.toh(N, 1, 3, 2);
	cout << "Total moves: " << total_moves << std::endl;
	  auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<endl;
    cout << duration.count()<<"micosecond" << endl;
	return 0;
}