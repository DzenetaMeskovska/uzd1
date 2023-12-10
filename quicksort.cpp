#include<iostream>
#include<cstdlib>
#define N 100

using namespace std;

//ievads
void mas_ievads(int mas[],int n){
    int i;
    for(i=0;i<n;i++){
	  cout<<"mas["<<i<<"]= ";
	  cin>>mas[i];
   }
}
//izvads
void mas_izvads(int mas[],int n){
    int i;
	cout<<"\nMasiivs:\n";
    for(i=0;i<n;i++){
	  cout<<mas[i]<<" ";
   }
}
//---------------------------------------------------
void atra(int mas[], int n, int kreisa, int laba){
	int i=kreisa,j=laba,x,apm=1;
	int vid=(laba+kreisa)/2;
	cout<<"\nvid= "<<mas[vid];
	while(i<j && apm==1){
		apm=0;
		while(mas[i]<mas[vid]){i++;}
		while(mas[j]>mas[vid]){j--;}
		cout<<"\nkreisais= "<<mas[i];
		cout<<"\nlabais= "<<mas[j];
		if(mas[i]>mas[j]){
			x=mas[i];
			mas[i]=mas[j];
			mas[j]=x;
			apm=1;
		}
		if(i==vid || j==vid){i=kreisa;j=laba;}
		cout<<"\n";
		mas_izvads(mas,n);
	}
    if(i<j){
		atra(mas,n,i,vid-1);
		atra(mas,n,vid+1,j);
    }
}
//-------------------------------------
int main() {
	int mas[N]={12,8,14,6,4,9,1};
	int n=7;
	mas_izvads(mas,n);
	atra(mas,n,0,n-1);
	
	system("pause>nul");
	return 0;
}