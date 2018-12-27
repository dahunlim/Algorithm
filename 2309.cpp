#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int input;
	int sum = 0;
	vector<int> v1;

	for (int i = 0; i < 9; i++) {
		cin >> input;
		v1.push_back(input);
	}

	sort(v1.begin(), v1.end());

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 9; k++) {
				if ((k != i) && (k != j)) {
					sum += v1[k];
				}
			}
			if (sum == 100) {
				for (int g = 0; g < 9; g++) {
					if ((g != i) && (g != j)) {
						cout << v1[g] << "\n";
					}
					if (g == 8) {
						return 0;
					}
				}
			}
			sum = 0;
		}
	}
    return 0;
}