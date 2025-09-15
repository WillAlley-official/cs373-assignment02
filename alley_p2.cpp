#include <vector>
#include <iostream>
// #include <sstream>
// #include <fstream>
#include <string>
using namespace std;

//@-------------------------------------------@
// MAIN FUNCTION
//@-------------------------------------------@

int main(int argc, char* argv[]) {

	// Input Validation
	if(argc != 3) {
		cout << "ERR: Proper usage is ./program <gate_start_positions> <marble_sequence>" << endl;
		return 0;
	}

	string gates = argv[1];
	string inputSeq = argv[2];
	int inputSize = inputSeq.size();

	if(gates.size() != 5) {
		cout << "ERR: <gate_start_positions> only accepts five L's or R's total" << endl;
		return 0;
	}
	
	// Type Converts and Stores CLI Arguments
	vector<int> marbles;
	for(int i=0; i<inputSize; i++) {
		int inputNum = inputSeq[i] - '0';
		marbles.push_back(inputNum);
	}

	// Initial Print of Gates
	cout << gates;

	// Main Loop for Marble Traversal
	char exitChute = 'A';
	for(int i=0; i<inputSize; i++) {

		// Print Arrow
		cout << "->";

		// Read Input
		int currGate = 0;
	
		// Go to Gate
		if(!marbles[i]) currGate = 0;
		else currGate = 1;

		// Read Gate, Swap Gate and Move
		if(gates[currGate] == 'L') {
			gates[currGate] = 'R';
			currGate += 2;
		} else { 
			gates[currGate] = 'L';
			currGate += 3;
		}

		// Read Gate, Swap Gate and Move
		if(gates[currGate] == 'L') {
			gates[currGate] = 'R';
			if(currGate == 2) exitChute = 'C';
			else if(currGate == 3) exitChute = 'D';
			else exitChute = 'E';
		} else { 
			gates[currGate] = 'L';
			if(currGate == 2) exitChute = 'D';
			else if(currGate == 3) exitChute = 'E';
			else exitChute = 'F';
		}

		// Print Gates
		cout << gates;
	}
		
	// Print Exit Chute
	cout << " " << exitChute << endl; 

	return 0;
}
