#include <iostream>
#include <vector>
#include <sstream>
#include <string>  // using istringstream
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	cin.ignore();
	vector<string> b;
	for (int i = 1; i <= n; i++) {
		string line, word;
		getline(cin, line);
		istringstream wordStream(line);
		while (wordStream >> word) {
			b.push_back(word);
		}
		vector<string>::iterator iter = b.end() - 1;
		cout <<"Case #"<< i << ": ";  
		for (; iter != b.begin(); iter--)
			cout << *iter << " ";
		cout << *iter << endl;
		b.clear();
	}
	return 0;
}
