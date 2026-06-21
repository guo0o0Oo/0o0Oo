#include<bits/stdc++.h>
using namespace std;
int main(){
	int t=0;
	while(1&&t<100){
		t++;
		system("makerands.exe > test.txt");
		system("1249D2ok.exe < test.txt > ans.txt");
		system("1249D2.exe < test.txt > out.txt");
		if(system("fc ans.txt out.txt"))break;
	}
	return 0;
}
