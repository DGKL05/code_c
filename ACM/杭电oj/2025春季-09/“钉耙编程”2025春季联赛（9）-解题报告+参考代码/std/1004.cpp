#include <iostream>
#define MULTI int _T; cin >> _T; while(_T--)
using namespace std;

int main() {
	MULTI {
		int V, W;
		cin >> V >> W;
		int k = (W + 2) / 2;
		int isEven = (W % 2 == 0);
		cout << max(1, (V + isEven) / k) << "\n";
	}
}