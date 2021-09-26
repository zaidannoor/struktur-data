#include <iostream>
#include <iomanip>
#include <cstring>
#include <malloc.h>
using namespace std;

typedef struct node *typeptr;
struct node {
	string judul; // judul buku
	string peminjam;// nama peminjam
	int waktu; // lama waktu meminjam buku
	typeptr next; // next dari node
	
};
typeptr kepala;
int jmlnode = 0;
void buatlist();
int listkosong();
void sisipnode(string peminjam, string buku, int lama_pinjam);
void cetaklist();
void hapusnode(string peminjam , string judul);

int main(){
	int pilih; // memilih pada menu
	int waktu; // menampung inputan lama peminjaman buku
	string nama,judul; // menampung inputan nama dan judul buku
	cout<<" Peminjaman buku menggunakan Linked List melingkar"<<endl;
	buatlist();
	sisipnode("zaidan" , "buku" , 4);
	sisipnode("noor" , "lari" , 9);
	sisipnode("irfan" , "palu" , 6);
	while(true){
		cout<<" 1. Input Node "<<endl;
		cout<<" 2. Lihat List"<<endl;
		cout<<" 3. Hapus Node"<<endl;
		cout<<" 4. Exit"<<endl;
		cout<<" Pilih : ";
		cin>>pilih;
		if(pilih == 1){
			cout<<"\n Input Data"<<endl;
			cin.ignore();
			cout<<" Nama peminjam : ";
			getline(cin,nama);
			cout<<" Judul buku : ";
			getline(cin,judul);
			cout<<" lama meminjam : ";
			cin>>waktu;
			sisipnode(nama ,judul, waktu);
			cout<<endl;
			system("pause");
			system("cls");
			
			
		}
		else if(pilih == 2){
			cout<<"\n Data peminjaman buku "<<endl<<endl;
			cetaklist();
			cout<<endl<<endl;
			system("pause");
			system("cls");
		}
		else if(pilih == 3){
			cout<<"\n Menghapus data "<<endl;
			cin.ignore();
			cout<<" Nama peminjam : ";
			getline(cin,nama);
			cout<<" Judul buku : ";
			getline(cin,judul);
			hapusnode(nama,judul);
			system("pause");
			system("cls");
		}
		else if(pilih == 4){
			break;
		}
		else{
			cout<<" Masukkan angka 1,2,3, atau 4 saja"<<endl;
			system("pause");
			system("cls");
		}
	}
	
	
	
	
	
	return 0;
}

void buatlist(){
	kepala = (node *)malloc(sizeof(node));
	kepala->next = kepala;
	
}

int listkosong(){
	if(kepala->next == kepala){
		return true;
	}
	else{
		return false;
	}
		
}

void sisipnode(string peminjam, string buku, int lama_pinjam ){
	typeptr NB,bantu;
	NB = new node();
	NB->peminjam = peminjam;
	NB->judul = buku;
	NB->waktu = lama_pinjam;
	
	if(listkosong()){
		kepala->next = NB;
		NB->next = kepala;
	}
	
	else{
		bantu = kepala;
		while(lama_pinjam > bantu->next->waktu && bantu->next != kepala){
			bantu = bantu->next;
		}
		if(bantu->next == kepala){ // bantu berada di akhir
			bantu->next = NB;
			NB->next = kepala;
		}
		else{ // bantu berada di tengah tengah
			NB->next = bantu->next;
			bantu->next = NB;
		}
	}
	//kepala->info = jmlnode;
	
}


void hapusnode(string peminjam , string judul){
	typeptr hapus,bantu;
	bool found = false;
	if(listkosong()){
		cout<<" List ini masih kosong "<<endl;
	}
	else{
		bantu = kepala;
		while(bantu->next != kepala){
			// data ditemukan dalam list
			if(bantu->next->peminjam == peminjam && bantu->next->judul == judul){
				hapus = bantu->next;
				bantu->next = hapus->next;
				free(hapus);
				found = true;
				break;
			}
			bantu = bantu->next;
		}
		
		if(found == false){ // data tak ditemukan dalam list
			cout<<" Data tidak ditemukan "<<endl;
		}
	}
}

void cetaklist(){
	typeptr bantu;
	bantu = kepala->next;
	cout<<setw(64)<<setfill('-')<<'-'<<endl;
	cout<<setfill(' ');
	cout<<'|'<<setw(20)<<left<<"Peminjam"<<'|'<<setw(20)<<left;
	cout<<"Judul"<<'|'<<setw(20)<<left<<"Lama pinjam (hari)"<<'|'<<endl;
	cout<<setw(64)<<setfill('-')<<'-'<<endl;
	cout<<setfill(' ');
	while(bantu != kepala){
		cout<<'|'<<setw(20)<<left<<bantu->peminjam;
		cout<<'|'<<setw(20)<<left<<bantu->judul;
		cout<<'|'<<setw(20)<<left<<bantu->waktu<<"|\n";
		bantu = bantu->next;
	}
	cout<<setw(64)<<setfill('-')<<'-'<<endl;
	
}

