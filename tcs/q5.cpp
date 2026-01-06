#include <bits/stdc++.h>
using namespace std;

// Seven-segment display representations for digits (0-9) and operators
unordered_map<int, char> seg_mapping = {
    {0b1111110, '0'},
    {0b0110000, '1'},
    {0b1101101, '2'},
    {0b1111001, '3'},
    {0b0110011, '4'},
    {0b1011011, '5'},
    {0b1011111, '6'},
    {0b1110000, '7'},
    {0b1111111, '8'},
    {0b1111011, '9'},
    {0b0100000, '('},
    {0b0001000, ')'},
    {0b0101100, '+'},
    {0b0101110, '*'},
    {0b0011110, '-'},
    {0b0001110, '/'},
    {0b0000000, '='}  // Use this for '=' symbol
};

// Function to map the 7-segment bitmask to a character
char get_char_from_bitmask(int bitmask) {
    if (seg_mapping.find(bitmask) != seg_mapping.end()) {
        return seg_mapping[bitmask];
    }
    return '?';  // Return '?' for unrecognized bitmask
}

int find_faulty_index(int N, vector<string> &matrix) {
    vector<char> characters(N);
    vector<int> bitmasks(N);
    
    // Convert matrix into the list of bitmasks
    for (int i = 0; i < N; i++) {
        // Extract the 3x3 segments for each character and calculate the bitmask
        int bitmask = 0;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (matrix[j][i * 3 + k] == '|') {
                    bitmask |= (1 << (3 * j + k));  // Set the corresponding bit
                }
            }
        }
        bitmasks[i] = bitmask;
        characters[i] = get_char_from_bitmask(bitmask);
    }

    // Form the equation string (LHS + "=" + RHS)
    string equation = "";
    for (char c : characters) {
        equation += c;
    }

    // Ensure the equation contains '='
    size_t eq_pos = equation.find('=');
    if (eq_pos == string::npos) {
        cerr << "Equation is invalid: '=' symbol not found." << endl;
        return -1;
    }

    string lhs = equation.substr(0, eq_pos);
    string rhs = equation.substr(eq_pos + 1);

    // Check if the current equation evaluates correctly
    try {
        int lhs_value = stoi(lhs);
        int rhs_value = stoi(rhs);
        if (lhs_value == rhs_value) {
            return -1;  // No error, no faulty character
        }
    } catch (...) {
        // If conversion to int fails, handle it here
    }

    // Try toggling each character and see if the equation balances
    for (int i = 0; i < N; i++) {
        int original_bitmask = bitmasks[i];
        for (auto &entry : seg_mapping) {
            if (original_bitmask != entry.first) {
                bitmasks[i] = entry.first;
                string new_eq = "";
                for (int j = 0; j < N; j++) {
                    new_eq += get_char_from_bitmask(bitmasks[j]);
                }

                eq_pos = new_eq.find('=');
                lhs = new_eq.substr(0, eq_pos);
                rhs = new_eq.substr(eq_pos + 1);

                try {
                    int lhs_value = stoi(lhs);
                    int rhs_value = stoi(rhs);
                    if (lhs_value == rhs_value) {
                        return i;  // The faulty index is found
                    }
                } catch (...) {
                    // If conversion to int fails, handle it here
                }
            }
        }
        bitmasks[i] = original_bitmask;  // Revert to original bitmask
    }

    return -1;  // This line should never be reached due to problem constraints
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int N;
    inputFile >> N;
    inputFile.ignore();  // Ignore newline after N

    vector<string> matrix(3);
    for (int i = 0; i < 3; i++) {
        getline(inputFile, matrix[i]);
    }

    // Output the index of the faulty character
    int faulty_index = find_faulty_index(N, matrix);
    outputFile << faulty_index << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
