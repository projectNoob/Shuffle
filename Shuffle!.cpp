#include <algorithm>
#include <cstdio>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;
int poker[53];
int N[13], E[13], S[13], W[13];
int pn[4][14], pe[4][14], ps[4][14], pw[4][14];
bool cmp(int a, int b){
	return a > b;
}
void print(int num){
	if (num == 0)
		return;
	putchar(' ');
	cerr << ' ';
	switch(num){
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9: putchar(num + '0'); cerr << char(num + '0'); break;
		case 10: putchar('T'); cerr << 'T'; break;
		case 11: putchar('J'); cerr << 'J'; break;
		case 12: putchar('Q'); cerr << 'Q'; break;
		case 13: putchar('K'); cerr << 'K'; break;
		case 14: putchar('A'); cerr << 'A'; break;
		default: cout << "Unknown Error"; 1 / poker[52];
	}
}
int RAND(int L = -2147483648, int R = 2147483647){
	if (L == R)
		return L;
	if (rand() % 2)
		return RAND((L + R) / 2 + 1, R);
	return RAND(L, (L + R) / 2);
}
int main(){
	for (int i = 0; i <= 51; ++i)
		poker[i] = i;
	char ch;
	int seed;
	cerr << "Welcome to use this program.\n";
x:	cerr << "Using selected seed? Y/N\n";
	ch = getche();
	if (ch == 'N'){
		srand(time(0));
		cerr << "\nseed:" << (seed = RAND()) << endl;
	}
	else if (ch == 'Y'){
		cerr << "\nPlease input seed:";
		cin >> seed;
	}
	else if (ch == 'y' || ch == 'n'){
		cerr << "\nUppercase, please.\n";
		goto x;
	}
	else{
		cerr << "\nUnknown command.\n";
		goto x;
	}
	freopen("poker_seed.txt", "w", stdout);
	cout << "seed:" << seed << endl;
	srand(seed);
	random_shuffle(poker, poker + 51);
	while (RAND() % 9)
		random_shuffle(poker, poker + 51);
	for (int i = 0; i <= 51; ++i)
		switch (i % 4){
			case 0: N[i / 4] = poker[i]; break;
			case 1: E[i / 4] = poker[i]; break;
			case 2: S[i / 4] = poker[i]; break;
			case 3: W[i / 4] = poker[i]; break;
			default: cout << "Unknown Error"; 1 / poker[52];
		}
	for (int i = 0; i <= 12; ++i)
		pn[N[i] / 13][++pn[N[i] / 13][0]] = N[i] % 13 + 2;
	for (int i = 0; i <= 12; ++i)
		pe[E[i] / 13][++pe[E[i] / 13][0]] = E[i] % 13 + 2;
	for (int i = 0; i <= 12; ++i)
		ps[S[i] / 13][++ps[S[i] / 13][0]] = S[i] % 13 + 2;
	for (int i = 0; i <= 12; ++i)
		pw[W[i] / 13][++pw[W[i] / 13][0]] = W[i] % 13 + 2;
	sort(pn[0] + 1, pn[0] + pn[0][0] + 1, cmp);
	sort(pn[1] + 1, pn[1] + pn[1][0] + 1, cmp);
	sort(pn[2] + 1, pn[2] + pn[2][0] + 1, cmp);
	sort(pn[3] + 1, pn[3] + pn[3][0] + 1, cmp);
	sort(pe[0] + 1, pe[0] + pe[0][0] + 1, cmp);
	sort(pe[1] + 1, pe[1] + pe[1][0] + 1, cmp);
	sort(pe[2] + 1, pe[2] + pe[2][0] + 1, cmp);
	sort(pe[3] + 1, pe[3] + pe[3][0] + 1, cmp);
	sort(ps[0] + 1, ps[0] + ps[0][0] + 1, cmp);
	sort(ps[1] + 1, ps[1] + ps[1][0] + 1, cmp);
	sort(ps[2] + 1, ps[2] + ps[2][0] + 1, cmp);
	sort(ps[3] + 1, ps[3] + ps[3][0] + 1, cmp);
	sort(pw[0] + 1, pw[0] + pw[0][0] + 1, cmp);
	sort(pw[1] + 1, pw[1] + pw[1][0] + 1, cmp);
	sort(pw[2] + 1, pw[2] + pw[2][0] + 1, cmp);
	sort(pw[3] + 1, pw[3] + pw[3][0] + 1, cmp);
	fclose(stdout);
	freopen("poker_north.txt", "w", stdout);
	cout << "S";
	cerr << "N:\nS";
	if (pn[0][0])
		for (int i = 1; i <= 13; ++i)
			print(pn[0][i]);
	cout << "\nH";
	cerr << "\nH";
	if (pn[1][0])
		for (int i = 1; i <= 13; ++i)
			print(pn[1][i]);
	cout << "\nD";
	cerr << "\nD";
	if (pn[2][0])
		for (int i = 1; i <= 13; ++i)
			print(pn[2][i]);
	cout << "\nC";
	cerr << "\nC";
	if (pn[3][0])
		for (int i = 1; i <= 13; ++i)
			print(pn[3][i]);
	freopen("poker_east.txt", "w", stdout);
	cout << "S";
	cerr << "\nE:\nS";
	if (pe[0][0])
		for (int i = 1; i <= 13; ++i)
			print(pe[0][i]);
	cout << "\nH";
	cerr << "\nH";
	if (pe[1][0])
		for (int i = 1; i <= 13; ++i)
			print(pe[1][i]);
	cout << "\nD";
	cerr << "\nD";
	if (pe[2][0])
		for (int i = 1; i <= 13; ++i)
			print(pe[2][i]);
	cout << "\nC";
	cerr << "\nC";
	if (pe[3][0])
		for (int i = 1; i <= 13; ++i)
			print(pe[3][i]);
	freopen("poker_south.txt", "w", stdout);
	cout << "S";
	cerr << "\nS:\nS";
	if (ps[0][0])
		for (int i = 1; i <= 13; ++i)
			print(ps[0][i]);
	cout << "\nH";
	cerr << "\nH";
	if (ps[1][0])
		for (int i = 1; i <= 13; ++i)
			print(ps[1][i]);
	cout << "\nD";
	cerr << "\nD";
	if (ps[2][0])
		for (int i = 1; i <= 13; ++i)
			print(ps[2][i]);
	cout << "\nC";
	cerr << "\nC";
	if (ps[3][0])
		for (int i = 1; i <= 13; ++i)
			print(ps[3][i]);
	freopen("poker_west.txt", "w", stdout);
	cout << "S";
	cerr << "\nW:\nS";
	if (pw[0][0])
		for (int i = 1; i <= 13; ++i)
			print(pw[0][i]);
	cout << "\nH";
	cerr << "\nH";
	if (pw[1][0])
		for (int i = 1; i <= 13; ++i)
			print(pw[1][i]);
	cout << "\nD";
	cerr << "\nD";
	if (pw[2][0])
		for (int i = 1; i <= 13; ++i)
			print(pw[2][i]);
	cout << "\nC";
	cerr << "\nC";
	if (pw[3][0])
		for (int i = 1; i <= 13; ++i)
			print(pw[3][i]);
	cerr << "\nPress any key to continue...";
	getch();
	return 0;
}
