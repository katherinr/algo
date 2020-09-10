#include <ctime>
#include <cmath>

int Eucleudus(int a, int b) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return b;
}

int EucleudusDelimeter(int a, int b) {
	while (a != 0 && b != 0) {
		if (a > b) {
			a %= b;
		}
		else
		{
			b %= a;
		}
	}
	return a;
}

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}

	return gcd(b, a % b);
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

long long int Fibbonacci(long long int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	return Fibbonacci(n - 1) + Fibbonacci(n - 2);
}

long long FibbonacciIterative(long long int n) {
	if (n == 0 || n == 1) {
		return 1;
	}
	long long fibN = 0;
	long long prev = 1, prevprev = 0;

	for (int i = 0; i < n; ++i) {
		fibN = prev + prevprev;
		prevprev = prev;
		prev = fibN;
	}
	return fibN;
}

long long int FibbonacciGold(long long int n) {
	double fi1 = (1 + sqrt(5)) / 2;
	long long FibNum = round((pow(fi1, n + 1)) / sqrt(5));
	return FibNum;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void multiply(std::vector <vector <long long>> &matrixF, std::vector <vector <long long>> &matrixM)
{
	int x = matrixF[0][0] * matrixM[0][0] + matrixF[0][1] * matrixM[1][0];
	int y = matrixF[0][0] * matrixM[0][1] + matrixF[0][1] * matrixM[1][1];
	int z = matrixF[1][0] * matrixM[0][0] + matrixF[1][1] * matrixM[1][0];
	int w = matrixF[1][0] * matrixM[0][1] + matrixF[1][1] * matrixM[1][1];

	matrixF[0][0] = x;
	matrixF[0][1] = y;
	matrixF[1][0] = z;
	matrixF[1][1] = w;
}

void Power(std::vector <vector <long long>>& matrixF, long long n)
{
	std::vector <vector <long long>> matrixM{ {1,1},{1,0} };
	for (int i = 0; i < n; i++)
		multiply(matrixF, matrixM);
}

long long int FibbonacciMatrix(long long n) {
	std::vector <vector <long long>> matrixF{ {1,1},{1,0} };
	if (n == 0)
		return 0;
	Power(matrixF, n - 1);
	return matrixF[0][0];
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	const auto start_time1 = clock();
	cout << Eucleudus(1000, 116) << " " << endl;
	const auto end_time1 = clock();
	cout << "Wasted time by sub " << (end_time1 - start_timeS1) << " seconds " << endl;

	const auto start_time2 = clock();
	cout << gcd(1000, 116) << " " << endl;
	const auto end_time2 = clock();
	cout << "Wasted time " << (end_time1 - start_time1) << " seconds " << endl;

	//cout << Fibbonacci(1200) << endl;
	cout << FibbonacciGold(1200) << endl;
	cout << FibbonacciIterative(1200) << endl;
	cout << FibbonacciMatrix(1200) << endl;

	system("pause");
	return 0;
}
