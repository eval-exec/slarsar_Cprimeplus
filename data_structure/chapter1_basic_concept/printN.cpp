#include <iostream>
#include <ctime>
using namespace std;
void printN(int i){
	while( i != 1){
        cout<<i<<endl;
		return printN(i-1);

	}




}

int main(){
using namespace std;
double starttime ,endtime,ttime;
	starttime = clock();
	int n;
	cout<<"please input a int number";
	cin >> n;
	printN(n);
	endtime = clock();
	ttime=(endtime - starttime)/CLOCKS_PER_SEC;
	while(1){
		
		n++;
		n--;
	}
	cout<<ttime;
	return 0;
}

