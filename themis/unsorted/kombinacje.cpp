#include <iostream>

void kombinacje(int suma, int prev) {
	for(int i=prev+1; i<=n; ++i) {
		if(suma-i < 0) {
			return;
		}
		if(suma-i == 0) {
			std::cout << i << ' ';
			return;
		}
		kombinacje(suma-i, i);
	}
}

int main() {
	std::cin.tie(0);
	std::ios_base::sync_with_stdio(false);

	int n;
	std::cin >> n;

	kombinacje(n, 0);

	return 0;
}

