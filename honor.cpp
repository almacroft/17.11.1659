#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

namespace hdr{
	void garis(){
		cout<<"=========================="<<endl;
	}
	void header(){
		garis();
		cout<<"SISTEM PENGGAJIAN KARYAWAN"<<endl;
		garis();
	}
}

class Employee{
public:
	Employee(int nomor, string nama){
		this->nomor=nomor;
		this->nama=nama;
	}
protected:
	int nomor;
	string nama;
};

class Gaji: public Employee{
public:
	Gaji(int gajipokok, int nomor, int asuransi, string nama):Employee(nomor, nama){
		this->gajipokok = gajipokok;
		this->nomor = nomor;
		this->nama = nama;
		this->asuransi = asuransi;
	}
	int getGaji(int jabatan, int transport){
		kotor = (gajipokok + jabatan + transport);
		return kotor;
	}
	int getGaji(int pph){
		bersih = kotor - (pph + asuransi);
		return bersih;
	}
	int getGaji(){
		return gajipokok;
	}
	string getNama(){
		return nama;
	}
	int getNomor(){
		return nomor;
	}
protected:
	int bersih;
	int kotor;
	int gajipokok;
	int asuransi;
};

void tampil(Gaji g, int jabatan, int transport, int pph){
	system("cls");
	hdr::header();
	cout<<"Nama : "<<g.getNama()<<endl;
	cout<<"Nama : "<<g.getNomor()<<endl;
	cout<<"Gaji Pokok : "<<g.getGaji()<<endl;
	cout<<"Gaji Kotor : "<<g.getGaji(jabatan, transport)<<endl;
	cout<<"Gaji Bersih : "<<g.getGaji(pph)<<endl;
	getch();
}

void menu(Gaji g, string nama, int nomor, int gajipokok, int jabatan, int transport){
	int pil;
	int jbt;
	int trns;
	int pph;

	do{
		system("cls");
		hdr::header();
		cout<<"Nama : "<<nama<<endl;
		cout<<"Nomor : "<<nomor<<endl;
		cout<<"Gaji Pokok : "<<gajipokok<<endl;
		cout<<"Jabatan : ";
		if (jabatan == 1){
			cout<<"Ketua"<<endl;
			jbt = 1000000;
		}else if (jabatan == 2){
			cout<<"Wakil"<<endl;
			jbt = 750000;
		}else{
			cout<<"Seksi"<<endl;
			jbt = 500000;
		}
		cout<<"Transportasi : ";
		if (transport == 1){
			cout<<"Pribadi"<<endl;
			trns = 250000;
		}else{
			cout<<"Umum"<<endl;
			transport = 500000;
		}

		if (gajipokok>1500000)
		{
			pph = gajipokok * 0.025;
		}else{
			pph = gajipokok * 0.01;
		}
		hdr::garis();
		cout<<"[1. Tampilkan Gaji | 2. Keluar]"<<endl;
		hdr::garis();
		cout<<"Pilihan : ";cin>>pil;
		if (pil == 1){
			tampil(g, jbt, trns, pph);
		}else{
			system("exit");
		}
	}while(pil != 2);
}

int main(void){
	string nama;
	int gajipokok, nomor, jabatan, transport;
	system("cls");
	hdr::header();
	cout<<"Nama : ";
	cin>>nama;
	cout<<"Nomor : ";
	cin>>nomor;
	cout<<"Gaji Pokok : ";
	cin>>gajipokok;
	cout<<"Jabatan [1. Ketua |2. Wakil |3. Seksi] : ";
	cin>>jabatan;
	cout<<"Transportasi [1. Pribadi |2. Umum] : ";
	cin>>transport;
	Gaji g(gajipokok, nomor, 100000, nama);
	menu(g, nama, nomor, gajipokok, jabatan, transport);
	return 0;
}
