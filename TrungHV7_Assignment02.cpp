// Viet chuong trinh in ra noi dung console sau:
//    *
//   ***
//  *****
// *******
//*********
// *******
//  *****
//   ***
//    *
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	while(1){
		char space=' ',sao='*';
		int n,dem=0,k,m=0;
		cout <<"\nNhap so sao n: ";
		cin >>n;
		while(dem < n){
			k=dem;
			if(dem<n/2+1){
				while(k <= n/2){
					if(k!=n/2)
						cout <<space;
					else{
						m = (n-n/2) - n/2 + (dem*2);
						for(int i=0; i < m; i++){
							cout <<sao;	
						}
					}
					k++;			
				}
				cout<<endl;	
			}
			else {
				m=n-(dem-n/2);
				for(int i=0;i<m;i++){
					if(i<dem-n/2){
						cout<<space;
					}
					else{
						cout <<sao;
					}
				}	
				cout<<endl;	
			}
	
		dem++;	
		}
	}
}


