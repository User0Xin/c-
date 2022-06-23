#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

class DXS {
protected:
	int* coe;
	int* exp;
	int n;
public:
	DXS() {
		coe = new int[20];
		exp = new int[20];
		n = 20;
		for (int i = 0; i < n; i++) {
			exp[i] = -1;
		}
	}
	DXS(const DXS& c) {
		coe = new int[20];
		exp = new int[20];
		n = 20;
		if (c.n != 0) {
			n = c.n;
			for (int i = 0; i < n; i++) {
				coe[i] = c.coe[i];
				exp[i] = c.exp[i];
			}
		}
	}
	~DXS() {
		if (coe != NULL && exp != NULL) {
			delete[]coe;
			delete[]exp;
			coe = NULL;
			exp = NULL;
		}
	}
	DXS operator=(DXS& c) {
		n = c.n;
		if (n != 0) {
			for (int i = 0; i < n; i++) {
				coe[i] = c.coe[i];
				exp[i] = c.exp[i];
			}
			return *this;
		}
	}
	friend DXS operator+(const DXS& c1, const DXS& c2);
	friend DXS operator-(const DXS& c1, const DXS& c2);
	friend DXS operator*(const DXS& c1, const DXS& c2);
	friend istream& operator>>(istream& cin, DXS& p);
	friend ostream& operator<<(ostream& cout, DXS& p);
};
istream& operator>>(istream& cin, DXS& p) {
	int n;
	cin >> n;
	p.n = n;
	for (int i = 0; i < n; i++) {
		cin >> p.coe[i] >> p.exp[i];
	}
	return cin;
}
ostream& operator<<(ostream& cout, DXS& p) {
	int flag = 0;
	char F = '\0';
	for (int i = 0; i < p.n; i++) {
		if (p.coe[i] == 0 && p.n == 1) {
			cout << "0";
			break;
		}
		else if (p.coe[i] != 0) {
			if (p.exp[i] == 0) {
				cout << p.coe[i];
			}
			else {
				if (p.coe[i] > 0) {
					if (flag == 0)
					{
						F = '\0';
					}
					else
					{
						F = '+';
					}
					if (p.exp[i] != 1 && p.coe[i] != 1) {
						cout << F << p.coe[i] << "x^" << p.exp[i];
					}
					else if (p.exp[i] == 1 && p.coe[i] != 1) {
						cout << F << p.coe[i] << "x";
					}
					else if (p.exp[i] == 1 && p.coe[i] == 1) {
						cout << F << "x";
					}
					else if (p.exp[i] != 1 && p.coe[i] == 1) {
						cout << F << "x^" << p.exp[i];
					}
				}
				else {
					F = '-';
					if (p.exp[i] != 1 && p.coe[i] != -1) {
						cout << p.coe[i] << "x^" << p.exp[i];
					}
					else if (p.exp[i] == 1 && p.coe[i] == -1) {
						cout << F << "x";
					}
					else if (p.exp[i] == 1 && p.coe[i] != -1) {
						cout << p.coe[i] << "x";
					}
					else if (p.exp[i] != 1 && p.coe[i] == -1) {
						cout << F << "x^" << p.exp[i];
					}
					else {
						cout << p.coe[i] << "x^" << p.exp[i];
					}
				}
			}
			flag = 1;
		}
	}
	return cout;
}
DXS operator+(const DXS& c1, const DXS& c2) {
	DXS temp;
	for (int i = 0; i < temp.n; i++) {
		temp.coe[i] = 0;
	}
	int i = 0, j = 0, k = 0;
	while (c1.exp[i] >= 0 || c2.exp[j] >= 0) {
		if (c1.exp[i] == c2.exp[j]) {
			temp.exp[k] = c1.exp[i];
			temp.coe[k] = c1.coe[i] + c2.coe[j];
			i++;
			j++;
			k++;
		}
		else if (c1.exp[i] < 0) {
			temp.exp[k] = c2.exp[j];
			temp.coe[k] = c2.coe[j];
			j++;
			k++;
		}

		else if (c2.exp[j] < 0) {
			temp.exp[k] = c1.exp[i];
			temp.coe[k] = c1.coe[i];
			i++;
			k++;
		}
		else if (c1.exp[i] > c2.exp[j]) {
			temp.exp[k] = c2.exp[j];
			temp.coe[k] = c2.coe[j];
			j++;
			k++;
		}
		else if (c1.exp[i] < c2.exp[j]) {
			temp.exp[k] = c1.exp[i];
			temp.coe[k] = c1.coe[i];
			i++;
			k++;
		}
	}
	temp.n = k;
	return temp;

}
DXS operator-(const DXS& c1, const DXS& c2) {
	DXS temp;
	for (int i = 0; i < temp.n; i++) {
		temp.coe[i] = 0;
	}
	int i = 0, j = 0, k = 0;
	for (int i = 0; i < temp.n; i++) {
		temp.coe[i] = 0;
	}
	while (c1.exp[i] >= 0 || c2.exp[j] >= 0) {
		if (c1.exp[i] == c2.exp[j]) {
			temp.exp[k] = c1.exp[i];
			temp.coe[k] = c1.coe[i] - c2.coe[j];
			i++;
			j++;
			k++;
		}
		else if (c1.exp[i] < 0) {
			temp.exp[k] = c2.exp[j];
			temp.coe[k] = 0 - c2.coe[j];
			j++;
			k++;
		}

		else if (c2.exp[j] < 0) {
			temp.exp[k] = c1.exp[i];
			temp.coe[k] = c1.coe[i];
			i++;
			k++;
		}
		else if (c1.exp[i] > c2.exp[j]) {
			temp.exp[k] = c2.exp[j];
			temp.coe[k] = 0 - c2.coe[j];
			j++;
			k++;
		}
		else if (c1.exp[i] < c2.exp[j]) {
			temp.exp[k] = c1.exp[i];
			temp.coe[k] = c1.coe[i];
			i++;
			k++;
		}
	}
	temp.n = k;
	return temp;

}
DXS operator*(const DXS& c1, const DXS& c2) {
	DXS temp;
	for (int i = 0; i < c1.n + c2.n; i++) {
		temp.coe[i] = 0;
	}
	int k = 0;
	for (int i = 0; i < c1.n; i++) {
		for (int j = 0; j < c2.n; j++) {
			temp.coe[k] = c1.coe[i] * c2.coe[j];
			temp.exp[k] = c1.exp[i] + c2.exp[j];
			k++;
		}
	}

	for (int i = 0; i < k; i++) {
		int min = i;
		for (int j = i + 1; j < k; j++) {
			if (temp.exp[min] > temp.exp[j]) {
				min = j;
			}
		}

		int tmp1 = temp.exp[i];
		temp.exp[i] = temp.exp[min];
		temp.exp[min] = tmp1;

		int tmp2 = temp.coe[i];
		temp.coe[i] = temp.coe[min];
		temp.coe[min] = tmp2;
	}

	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < k; j++) {
			if (temp.exp[i] == temp.exp[j]) {
				temp.coe[i] += temp.coe[j];
				temp.coe[j] = 0;
			}
		}

	}

	temp.n = k;
	return temp;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		DXS d1, d2;
		cin >> d1 >> d2;
		DXS d3 = d1 + d2;
		cout << d3 << endl;
		DXS d4 = d1 - d2;
		cout << d4 << endl;
		DXS d5 = d1 * d2;
		cout << d5;
		if (t != 0)
			cout << endl;
	}


	return 0;
}