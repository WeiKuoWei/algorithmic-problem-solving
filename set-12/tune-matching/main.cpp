// https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
// KMP part is from geeksforgeeks.org

#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>

using namespace std;

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of pat[] in txt[]
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			// printf("Found pattern at index %d ", i - j);
            cout << "S";
            return;
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters, they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
    cout << "N";
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example. AAACAAAA and i = 7. The
			// idea is similar to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main(){
    // create a map of notes to frequencies
    unordered_map<string, int> notes;
	notes["Ab"] = 11;
    notes["A"] = 0;
    notes["A#"] = 1;
    notes["Bb"] = 1;
    notes["B"] = 2;
	notes["B#"] = 3;
	notes["Cb"] = 2;
    notes["C"] = 3;
    notes["C#"] = 4;
    notes["Db"] = 4;
    notes["D"] = 5;
    notes["D#"] = 6;
    notes["Eb"] = 6;
    notes["E"] = 7;
	notes["E#"] = 8;
	notes["Fb"] = 7;
    notes["F"] = 8;
    notes["F#"] = 9;
    notes["Gb"] = 9;
    notes["G"] = 10;
    notes["G#"] = 11;

    // input the first tune
    int M, T;
    cin >> M >> T;

    int first[M], second[T];
    for(int i = 0; i < M; i++){
        string temp;
        cin >> temp;
        first[i] = notes[temp];
    }
    for(int i = 0; i < T; i++){
        string temp;
        cin >> temp;
        second[i] = notes[temp];
    }

    // create a map for integers to char
	unordered_map<int, char> reverse_notes;
	for(int i = 0; i < 12; i++){
		reverse_notes[i] = 'A' + i;
	}


	if(T == 1){
		// scan through each character in first
		for(int i = 0; i < M; i++){
			if(first[i] == second[0]){
				cout << "S";
				return 0;
			}
		}
		cout << "N";
		return 0;
	}
	else{
		char diff_first[M-1], diff_second[T-1];
		for(int i = 0; i < M - 1; i++){
			diff_first[i] = reverse_notes[(first[i + 1] - first[i] + 12) % 12];
			// diff_first[i] = (first[i + 1] - first[i] + 12) % 12;
		}
		for(int i = 0; i < T - 1; i++){
			diff_second[i] = reverse_notes[(second[i + 1] - second[i] + 12) % 12];
			// diff_second[i] = (second[i + 1] - second[i] + 12) % 12;
		}

		KMPSearch(diff_second, diff_first);
	}

    

    return 0;
}

/*

Input The first line consists of two integers M and T (1<=M<=10ˆ5, 1<=T<=10ˆ4, T<=M). M and T represents
number of notes present in the first and second tune respectively. The next two lines contain M and T notes
respectively, indicating the notes of the tunes.
Notes in each line are separated by one space and each one is from English alphabet from A to G and possibly
followed by a ‘#’ or ‘b’ accidental sign.
Output Print a single line containing one character ‘S’ or ‘N’ indicating if the two tunes are similar or not.
Example 1
Input:
16 4
D G A B C D G G G C D E F# G C C
G G C D
Output:
S
Example 2
Input:
12 2
C C# D D# E F F# G G# A A# B
C D
Output:
N

Example 3
Input:
3 1
C B A
C

Output:
S

Example 4
Input:
3 2
B B B
C B 

Output:
N

Example 5
Input:
18 5
A A A A A A A A A A A A A A A A A B
A A A A B 

Output:
S

Example 6
Input:
21 6
A B A B A B C A B A B A B C A B A B A B C
A B A B A C

Output:
N

Example 7
Input:
2 1
B C#
Db

Output:
S

Example 8
Input:
2 2
B C
A B

Output:
N

Example 9 
Input:
2 2
A B
G Ab

Output:
S

Exmample 10
3 3 
B B B
Ab G# Ab


*/