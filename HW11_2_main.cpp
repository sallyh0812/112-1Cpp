#include <bits/stdc++.h>
#include "concatenate.cpp"

using namespace std;

//===================================//
//         GLOBAL PARAMETER          //
//===================================//
int file_num = 2;

//===================================//
//           SUB FUNCTION            //
//===================================//
int* concatenate(int* array_1, int* array_2, int size_1, int size_2);

//===================================//
//           MAIN FUNCTION           //
//===================================//
int main(){
	for(int i_file = 1; i_file <= file_num; i_file++){
		// I/O FILE //
		string input_file_name  = "input2_"  + to_string(i_file) + ".txt";
		string output_file_name = "output2_" + to_string(i_file) + ".txt";
		ifstream input_file (input_file_name);
		ofstream output_file(output_file_name, ios::out);
		
		int size_1, size_2;
		// READ ARRAY 1 //
		input_file >> size_1;
		int array_1[size_1];
		for(int i = 0; i < size_1; i++){
			input_file >> array_1[i];
		}
		
		// READ ARRAY 2	//
		input_file >> size_2;
		int array_2[size_2];
		for(int i = 0; i < size_2; i++){
			input_file >> array_2[i];
		}
		
		// CONCATENATE ARRAY 1 & ARRAY 2 //
		int* array_3 = concatenate(array_1, array_2, size_1, size_2);
		for(int i = 0; i < size_1 + size_2; i++){
			output_file << *(array_3 + i) << endl;
		}		
	}
	
	return 0;
}