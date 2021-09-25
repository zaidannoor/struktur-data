#include <iostream>
#include <string>
#include <string.h>
#include <malloc.h>
using namespace std;
typedef string info;
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
	cout<<sizeof(node);
	sisipnode("zaidan" , "buku" , 4);
	while(true){
		cout<<" 1. Input Node "<<endl;
		cout<<" 2. Lihat List"<<endl;
		cout<<" 3. Hapus Node"<<endl;
		cout<<" 4. Exit"<<endl;
		cout<<" Pilih : ";
		cin>>pilih;
		if(pilih == 1){
			cout<<" Input Data"<<endl;
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
			
		}
		else if(pilih == 2){
			cout<<" Data peminjaman buku "<<endl;
			cetaklist();
		}
		else if(pilih == 4){
			break;
		}
	}
	
	cetaklist();
	
	
	
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
	NB = (node *)malloc(sizeof(node));
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
				break;
			}
			bantu = bantu->next;
		}
		
		if(bantu->next == kepala){ // data tak ditemukan dalam list
			cout<<" Data tidak ditemukan "<<endl;
		}
	}
}

void cetaklist(){
	typeptr bantu;
	bantu = kepala->next;
	while(bantu != kepala){
		cout<<" Peminjam    : "<<bantu->peminjam<<endl;
		cout<<" Judul       : "<<bantu->judul<<endl;
		cout<<" Lama pinjam : "<<bantu->waktu<<endl<<endl;
		bantu = bantu->next;
	}
	
}
