#include <iostream>
#include <iomanip>
using namespace std;

int z;
char kosong, isi;
int x[30], y[30];
int isibaris[30],isikolom[30];
char terisi[30][30][30];
string kendaraan[100][100][100], namaKendaraan;
void menu ();
void input ();
void sewa();
void daftar();
void outputterisi();

void login ()
{
	char pilih;
	string username, pass;	
	do{	
		cout <<"\n\t\tLOGIN";
		cout <<"\nUSERNAME\t: ";cin>>username;
		cout <<"PASSWORD\t: ";cin>>pass;
		if(username == "susahsekali" && pass == "DUHapaya")
		{
			cout <<"LOGIN BERHASIL !!";
			system("clear");
			menu ();
		}
		else
		{	
			cout <<"LOGIN SALAH !!";
			system("clear");
			cout<<"\nIngin login kembali <y/n>";
			cin>>pilih;
			system("cls||clear");
		}
      }while(pilih == 'y' || pilih == 'Y');
}
void menu ()
{
		int pilih;
		char yn;
	do
	{
		cout <<"\n1. INPUT MASTER TEMPAT PARKIR";
		cout <<"\n2. SEWA PARKIR";
		cout <<"\n3. DAFTAR SEWA PARKIR";
		cout <<"\n4. EXIT";
		cout <<"\nInput Pilihan : "; cin >>pilih;
		switch(pilih)
		{
			case 1 :
				input ();
				break;
			case 2 :
				sewa ();
				break;
			case 3 :
				daftar ();
				break ;
			case 4 :
				exit (0);
		}
		cout<<"Kembali Ke Menu? <Y/N> \t: "; cin>>yn;
	}
	while(yn == 'y' || yn == 'Y');
}
void input ()
{
	cout <<"\nINPUT MASTER TEMPAT PARKIR";
	cout <<"\n\nJumlah SLOT	: "; cin>>z;
	if (z > 0)
	{
	cout <<"Tanda Kosong\t: "; cin>>kosong;
	cout <<"Tanda Isi\t: "; cin >>isi;
		for (int a = 1; a <= z; a++)
		{
			
			cout <<"\nSlot Ke		: "<<a<<endl;
			cout <<"Jumlah baris	: ";cin >>x[a];
			cout <<"Jumlah kolom	: ";cin >>y[a];
		}
		
	}
	
	
	for(int a = 1; a <= z; a++)
	{
		for(int i = 1; i <= x[a]; i++)
		{
			for(int j=1; j<=y[a]; j++)
			{
				terisi[a][i][j] = kosong;
			}
		}	
	}
	
	
	menu ();
}
void sewa()
{
	int slotke,a;
	char yn;
	a=0;
	cout<<"SEWA PARKIR\n";
	
	outputterisi();
	do{
			
		cout<<"Sewa SLot Ke\t: "; cin>>slotke;
		cout<<"Sewa Baris Ke\t: "; cin>>isibaris[a];
		cout<<"Sewa Kolom Ke\t: "; cin>>isikolom[a]; cin.ignore();
		cout<<"masukan NO.kendaraan :"; getline(cin, namaKendaraan);
		terisi[slotke][isibaris[a]][isikolom[a]] = isi;
		kendaraan[slotke][isibaris[a]][isikolom[a]] = namaKendaraan;
		cout<<"\n\nSewa Lagi <Y/N> \t: "; cin>>yn;
		a++;
	}while(yn == 'y' || yn == 'Y');
	
}

void outputterisi()
{
	cout<<"SLOT PARKIR\n\n";
	
	for(int a=1; a<=z; a++)
	{
		cout<<"SLOT KE-"<<a<<endl;
		for(int i=1; i<=x[a]; i++)
		{
			for(int j=1; j<=y[a]; j++)
			{
				cout<<terisi[a][i][j] << " " ;
			}
			cout<<endl;
		}	
		cout<<endl;
	}
} 


void daftar()
{
	cout <<"DAFTAR SEWA PARKIR";
	cout <<"\nDAFTAR";
	cout <<"\n----------------------------------------------------------------"<<endl;
	cout <<"|"<< setfill('*') <<setw(15)<<"NO.KENDARAAN"<< setfill('*') << setw(5) << "|" << setfill(' ') << setw(10)<<"SLOT" << setfill(' ') << setw(10)<<"|"<<setfill(' ') << setw(15)<<"[baris,kolom]"<< setfill(' ') << setw(10)<<"|";
	cout <<"\n----------------------------------------------------------------\n";
	for(int a=1; a<=z; a++)
	{
		for(int i=1; i<=x[a]; i++)
		{
			for(int j=1; j<=y[a]; j++)
			{
				if(terisi[a][i][j] == 'X')
				{
					cout <<"|"<< setfill(' ') <<setw(15)<<kendaraan[a][i][j]<< setfill(' ') << setw(5) << "|" << setfill(' ') << setw(10)<< a << setfill(' ') << setw(10)<<"|"<<setfill(' ') << setw(5)<<"[" << i << "," << j << "]"<< setfill(' ') << setw(15)<<"|\n";
				}
			}
		}	
	}
	
	outputterisi();
}
int main ()
{
	login ();
}
