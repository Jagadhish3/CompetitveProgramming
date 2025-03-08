#include<iostream>
using namespace std;

void sieveofatkins(int num){
	bool sieve[num+1];
	
	for(int i=0;i<=num;i++){
		sieve[i]=false;
	}

	if(num>2){
		sieve[2]=true;
	}
	if(num>3){
		sieve[3]=true;
	}


	for(int x=1;x*x<=num;x++){
		for(int y=1;y*y<=num;y++){
			int n=(4*x*x)+(y*y);

			if(n<=num && n%12==1||n%12==5){
				sieve[n]=true;
			}

			n=(3*x*x)+(y*y);
			if(n<=num && n%12==7){
				sieve[n]=true;
			}

			n=(3*x*x)-(y*y);
			if(x<y && n<=num && n%12==11){
				sieve[n]=true;
			}
		}
	}

	for(int i=5;i*i<=num;i++){
		if(sieve[i]){
			for(int j=i*i;j<=num;j+=i*i){
				sieve[j]=false;
			}
		}
	}
	for(int i=1;i<=num;i++){
		if(sieve[i]){
			cout<<i<<" ";
		}
	}
}

int main(){
	int n;
	cin>>n;

	sieveofatkins(n);
}