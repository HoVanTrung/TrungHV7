/*input dd/mm/yy:16/4/2022.
-------Menu-------------
1.Find the number of month
2.Show next day (dd/mm/yyyy)
3.Show previous day (dd/mm/yyyy)
*/

#include <iostream>

using namespace std;
int dd,mm,yyyy;
int n;
int status=0;
bool status4=false;


//kiem tra xem co phai nam nhuan hay khong?
void check_4(int yyyy){
	if(yyyy%4==0)
		status4=true;
	else 
		status4=false;
}

bool check_dd(){
	if(dd<0) return 0;
	if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12){
		if(dd > 32) 
			return 0;
	}
	else if(mm==2){
		if(status4==true){
			if(dd>30) return 0;
		}
		else {
			if(dd>29) return 0;
		}
	}
	else {
		if(dd>31) return 0;
	}
	return 1;
}
void Func_One(){
	cout <<"\nFind the number of month: "<<mm;
}
//int dd, int mm, int yyyy
void Func_Two(){
	check_4(yyyy);
	if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10) {
		if(dd==31) {
			dd=1;
			mm++;
		}
		else
			dd++;
	}
	else if(mm==2) {
		if(status4==true) {
			if(dd==29) {
				dd=1;
				mm++;
			}
			else
				dd++;
		}
		else {
			if(dd==28){
				dd=1;
				mm++;
			}
			else 
				dd++;
		}
	}
	else if(mm==12){
		if(dd==31){
			dd=1;
			mm=1;
			yyyy++;
		}
		else 
			dd++;
	}
	else {
		if(dd==30) {
			dd=1;
			mm++;
		}
		else
			dd++;	
	}
	cout << "\nShow next day(dd/mm/yyyy): "<<dd<<"/"<<mm<<"/"<<yyyy;
}
//int dd, int mm,int yyyy
void Func_Three(){
	check_4(yyyy);
	if(dd==1){
		if(mm!=1)
			mm--;
		else {
			dd=31;
			mm=12;
			yyyy--;
		}
		
		if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12) dd=31;
		else if(mm==2){
			if(status4==true)
				dd=29;
			else 
				dd=28;
		}
		else
			dd=30;
	}
	else {
		dd--;
	}
	cout << "\nShow previous day(dd/mm/yyyy): "<<dd<<"/"<<mm<<"/"<<yyyy;
}

void action(){
	
	while(1){
	do {
		cout <<"Enter Year(dd): ";
		cin >> yyyy;
	}while(yyyy<1900 || yyyy>3000);
	do {
		cout <<"Enter Month(dd): ";
		cin >> mm;		
	} while (mm<0 || mm>12);

	do {
		cout <<"Enter Date(dd): ";
		cin >> dd;
	} while(check_dd()!=1);
	
	cout << "\nDate is: "<< dd <<"/" << mm << "/" << yyyy;
		while(1){
			cout << "\n\nPlease, choose number in Menu: ";
			cin >> n;
			switch(n){
				case 1:
					Func_One();
					status=0;
					break;
				case 2:
					Func_Two();
					status=0;
					break;
				case 3:
					Func_Three();
					status=0;
					break;
				case 4:
					status=1;
					break;
				default:
					cout << "\nInvalid number";
					status=0;
					break;
			}
			if(status == 1){
				break;
			}				
		}		
	}
	
}

void menu(){
	cout << "============== Menu =============="<<endl;
	cout << "1. Find the number of month"<<endl;
	cout << "2. Show next day (dd/mm/yyyy)"<<endl;
	cout << "3. Show previous day (dd/mm/yyyy)"<<endl;
	cout << "4. Stop\n"<<endl;
}

int main(){
	menu();
	action();
}
