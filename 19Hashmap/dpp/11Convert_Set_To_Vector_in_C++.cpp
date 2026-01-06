// C++ program to Convert Set To Vector
// Using range constructor
#include <bits/stdc++.h>
using namespace std;

int main(){
	// Set declared
	unordered_set<int> st = { 1, 2, 10, 7, 9, 5 };
	cout << "Original Set elements\n";
	for (int i : st)
		cout << i << " ";
	cout << endl;

	// range constructor from
	// st.begin() to st.end()
	// Vector declared with values
	vector<int> vc(st.begin(), st.end());

	cout << "Printing Vector after conversion\n";
	for (int i : vc)
		cout << i << " ";
	cout << endl;

	return 0;
}

// C++ program to Convert Set To Vector
// using push_back()
#include <bits/stdc++.h>
using namespace std;

int main(){
	// Set declared
	set<int> st = { 1, 2, 3, 7, 9, 5 };

	cout << "Original Set elements\n";
	for (int i : st)cout << i << " ";
	cout << endl;

	// vector declared
	vector<int> vc;

	// Inserting elements into vector using
	// push_back function
	for (auto& it : st) {
		vc.push_back(it);
	}

	cout << "Printing Vector after conversion\n";
	for (int i : vc) cout << i << " ";
	cout << endl;

	return 0;
}

// C++ program to Convert Set
// To Vector using
// std:: copy function
#include <bits/stdc++.h>
using namespace std;

int main()
{
	set<int> st = { 1, 2, 3, 7, 9, 5 };

	cout << "Original Set elements\n";
	for (int i : st)
		cout << i << " ";
	cout << endl;

	vector<int> vc(st.size());
	copy(st.begin(), st.end(), vc.begin());

	cout << "Printing Vector after conversion\n";
	for (int i : vc)
		cout << i << " ";
	cout << endl;

	return 0;
}

// C++ program to Convert Set To Vector
// Using copy function back_inserter()
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Set declared
	set<int> st = { 1, 2, 3, 7, 9, 5 };

	cout << "Original Set elements\n";
	for (int i : st)
		cout << i << " ";
	cout << endl;

	// Vector declared
	vector<int> vc;

	// Using copy
	std::copy(st.begin(), st.end(), back_inserter(vc));

	cout << "Printing Vector after conversion\n";
	for (int i : vc)
		cout << i << " ";
	cout << endl;

	return 0;
}

// C++ program to Convert Set To Vector
// Using vector::assign
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// Using Set
	set<int> st = { 1, 2, 3, 7, 9, 5 };

	cout << "Original Set elements\n";
	for (int i : st)
		cout << i << " ";
	cout << endl;

	// Vector declared
	vector<int> vc;

	// Using vector::assign
	vc.assign(st.begin(), st.end());

	cout << "Printing Vector after conversion\n";
	for (int i : vc)
		cout << i << " ";
	cout << endl;

	return 0;
}
