#include <algorithm> 
#include <vector>
#include <list>
#include <array> 
#include <stack>
#include <queue> 
#include <iostream> 
#include <iterator> 
#include <string> 
#include <chrono>
#define N 2000
using namespace std;

int Nb_Prem(int n) {
	bool premier=true;
	if (n == 0) return 0; 

	else {
		for (int i = 2; i < n; i++) {
			if (n % i != 0) premier = true;
			else if (n % i == 0) premier = false;
			if (premier == false) {
				cout << "X" << endl;
			}
		}
		if (premier == true){
			cout << n << " est premier" << endl;
			return premier;
		}
	}
	
}

array<int, N / 5> tabPremiers;
int nbNbPremiers = 0;

int GenPrem() {
	int j = 0;
	for (int i = 1; i <= N; i++) {
		if (Nb_Prem(i)) {
			tabPremiers[j]=i;
			nbNbPremiers++;
			j++;
		}
	}
	cout << "nombre de nb premiers de 1 a " << N << " : " << nbNbPremiers << endl;
	return nbNbPremiers;
}

void PartTrois() {
	vector<int> Vec;
	list<int> :: iterator it;
	list<int> List;
	stack<int> Pile;
	queue<int> file;

	cout << nbNbPremiers << endl;
	cout << "==> Array to vector" << endl;
	cout << "Vecteur : " << endl;
	for (int i = 0; i < nbNbPremiers; i++) {
		Vec.push_back(tabPremiers[i]);
		cout << Vec[i] << " ";
	}
	cout << endl;

	cout << "==> Vector to list" << endl;
	cout << "List :" << endl;
	for (int i = 0; i < nbNbPremiers; i++) {
		List.push_back(Vec[i]);
	}
	for (it = List.begin(); it != List.end(); ++it)
		cout << '\t' << *it;

	auto iter = List.begin();

	cout << "==> List to stack" << endl;
	cout << "Stack :" << endl;
	for (int i = 0; i < nbNbPremiers; i++) {
		advance(iter, 1);
		Pile.push(iter);
	}

	auto iter1 = Pile.top();
	cout << "==> Stack to queue" << endl;
	cout << "Queue :" << endl;
	for (int i = 0; i < nbNbPremiers; i++) {
		advance(iter1, -1);
		file.push(iter1);
	}
}

int main() {
	//Nb_Prem(4);
	nbNbPremiers=GenPrem();
	PartTrois();
}