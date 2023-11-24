#include <iostream>
#include <locale>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cmath>
#include <cstring>
#include <sstream>

using namespace std;

int NOD_Del(int a,int b){
	if (b == 0) {return a;} else { return NOD_Del(b, a % b);}
}
int NOD_Vich(int a, int b) {
	if (b == 0) { return a; }
	else if (a > b){ return NOD_Vich(b, a - b); }else { return NOD_Vich(a, b - a); }
}
void EvCh() {
	cout << "Введите 0 для нахождения делением, 1 для нахождения вычитанием.\n";
	bool alg;
	cin >> alg;
	cout << "Введите два числа.\n";
	int a, b;
	cin >> a >> b;
	if (alg) { cout << NOD_Vich(a, b); }
	else { cout << NOD_Del(a, b); }
}


bool Prov(int chisl) {
	bool final = true;
	for (int i = chisl - 1; i > 1; i--) { 
		if ( chisl % i == 0) { final = false; } 
	}
	return final;
}
void ReshEr() {
	int kon, nach = 1;
	cout << "Введите число.\n";
	cin >> kon;
	while (kon > nach) {
		if (Prov(nach)){cout << nach << endl;}
		nach++;
	}
}


string PoiskMin(string s) {
	string buff, minWord;
	int minLen = pow(100, 8);
	istringstream iss(s);
	while (iss >> buff) {
		if (buff.length() < minLen) {
			minLen = buff.length();
			minWord = buff;
		}
	}
	return minWord;
}
void OTF_6() {
	setlocale(LC_ALL, "en_US.utf8");
	ifstream file("C:OTF.txt");
	string line;
	while (getline(file, line)) {
		if (file.is_open()) {
			cout << PoiskMin(line);
			file.close();
		}
	}
}


void OTF_12() {
	setlocale(LC_ALL, "en_US.utf8");
	ifstream file("C:OTF.txt");
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			cout << line << endl;}
		file.close();} else {cout << "Не удалось открыть файл!" <<endl;}
}


float abs(float a, float b) {
	if (a >= b) { return a - b; } else { return b - a; }
}
void Ri_6() {
	float  a[10000], x, Ep;
	cout << "Введите два числа.\n";
	cin >> x >> Ep;
	a[0] = 0; a[1] = 1; a[2] = x;
	for (int n = 3; n <= 10000; n++) {
		a[n] = 3 + (1 / pow(2, n)) * pow(cos(pow(a[n - 1], 2) - x * pow(a[n - 2], 2) - (a[n - 1]) / x), 2);
		if (abs(a[n], a[n - 1]) < Ep) { cout << a[n]; n=10000;}
	}
}


void Ri_12() {
	int n;
	float Sig = 0, del = 0, fact = 1;
	cout << "Введите числоа.\n";
	cin >> n;
	for (float k = 1; k <= n; k++) {
		del += 1 / k;
		Sig = sig + (fact * k);
	}
	cout << Sig/ del;
}


int NOD_all(int arr[], int n){
	int result = arr[0];
	for (int i = 1; i < n; i++){ result = NOD_Del(result, arr[i]); }
	return result;
}
void Fi_6() {
	int mass[150], res, chisl, kol = 1;
	srand(time(NULL));

	ofstream fout("fi_6_cpp.txt");
	for (int i = 0; i < 150; i++) {fout << rand() << "\n";}
	fout.close();

	ifstream fin("fi_6_cpp.txt");
	for (int i = 0; i < 150; i++) {
		fin >> chisl;
		mass[i] = chisl;
	}
	fin.close();

	res = NOD_all(mass, sizeof(mass));
	cout <<endl << "Наибольший общий делитель -->  " << res << endl << endl << "Простые числа:\n";

	for (int i = 0; i<150; i++ ){
		if (Prov(mass[i])) { cout << mass[i] << endl; kol++; }
	}
	cout <<endl << "Количество простых чисел -->  " << kol << endl;
}
	
int maxLeng(int a, int b) {
	if (a < b) { return b; } else { return a; }
}
void Fi_12(){
	int m, leng = 1, maxL=0;
	float chisl, buff, ost;
	bool flag = false, povt = true;
	cout << "Введите кол - во создаваемых чисел     ";
	cin >> m;

	ofstream fout("fi_12_cpp.txt");
	ost = rand() / 1000;
	for (int i = 0; i < m; i++) { fout << rand() + ost << "\n"; }
	fout.close();

	ifstream fin("fi_12_cpp.txt");
	fin >> chisl;
	buff = chisl;
	for (int i = 1; i < m; i++) {
		fin >> chisl;
		if (buff < chisl && povt) { cout << buff << "  " << chisl << "  "; buff = chisl; flag = true; povt = false; leng += 1; }
		else if (buff < chisl && !povt) {cout << chisl << "  "; buff = chisl; flag = true; leng += 1;}
		else  if (flag && buff > chisl) { cout << endl << endl; flag = false; povt = true; maxL = maxLeng(maxL, leng); leng = 1; }
		}
	fin.close();
	cout << maxL;
}


int main() {
	setlocale(LC_ALL, "Rus");
	//EvCh();
	//ReshEr();
	OTF_6();
	//OTF_12();
	//Ri_6();
	//Ri_12();
	//Fi_6();
	//Fi_12();
}