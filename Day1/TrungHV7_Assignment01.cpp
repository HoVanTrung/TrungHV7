#include <iostream>
#include <string.h>

using namespace std;
//Kiem tra so doi xung. 
//VD:123321, 11, 121 la doi xung
//VD: 10521 khong la so doi xung.
bool Isnumber(string s,int k)
{
	if(k==0) return 0;
	if(k=s.length()==1) return 0;
	if(s[0]=='0') return 0;
	for(int i=0; i<k; i++)
	{
		if(s[i]<'0' || s[i]>'9') return 0;
	}
	return 1;
}
int main(){
//Neu la so le
	while(1){
		int k=0,m;
		string s;
		cout <<"\nNhap so nguyen n: ";
		cin >> s;
		while( Isnumber(s,k=s.length()) != 1)
		{
			cout <<"So ban nhap sai, moi nhap lai: ";
			cin >> s;
		}
		k=s.length();
		if(k%2 != 0){
			for(int i=0; i<(k-1)/2; i++){
				if (s[i]==s[k-i-1]) {
					m=1;
				}else {
					m=0;
				}
				if(m==0) {
					cout <<"So " <<s << " khong phai so doi xung."<<endl;
					break;
				}
			}
		}
		else 
		{
			for(int i=0; i<(k)/2; i++){
				if (s[i]==s[k-i-1]) {
					m=1;
				}else {
					m=0;
				}
				if(m==0) {
					cout <<"So " <<s << " khong phai so doi xung."<<endl;
					break;
				}
			}
		}
		if(m==1) {
			cout <<"So " <<s << " la so doi xung."<<endl;
		}
	}
	return 0;
}
	
