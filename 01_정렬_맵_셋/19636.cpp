#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int W, I0, T, D, I, A;

	cin >> W >> I0 >> T;
	cin >> D >> I >> A;

	int w1 = W;
	int w2 = W;
	int i2 = I0;

	for (int i = 0; i < D; i++)
	{
		w1 += I - (I0 + A);
		w2 += I - (i2 + A);

		if (abs(I - (i2 + A)) > T)
			i2 += floor((I - (i2 + A)) / 2.0);
	}
	if (w1 <= 0)
		cout << "Danger Diet\n";
	else
		cout << w1 << " " << I0 << "\n";
	
	if (w2 <= 0 || i2 <= 0)
		cout << "Danger Diet\n";
	else
	{
		cout << w2 << " " << i2 << " ";
		if (I0 > i2)
			cout << "YOYO";
		else
			cout << "NO"; 
	}	
	
	return 0;
}