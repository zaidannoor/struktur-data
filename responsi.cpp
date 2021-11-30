#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <fstream>
using namespace std;
fstream myfile; // deklarasi filestream dengan nama myfile

struct typestack{ // deklarasi strcut typestack
	int top;
	int tumpukan[50];
};

struct typequeue{ //deklarasi struct typequeque
	int belakang;
	int antrian[50]; 
};

// stack digunakan untuk menyimpan data stok buku
// sedangkan queque untuk menyimpan data peminjaman buku
typestack stack; // deklarasi variabel stack bertipe typestack
typequeue queue; // deklarasi variabel queque bertipe typequeque


// void void untk stack buku
void buatstack(); // membuat stack
int stackkosong(); // mengecek apakah stack kosong atau tidak
int stackpenuh(); // mengecek apakah stack penuah atau tidak
void push(int IB); // untuk memasukkan data ke dalam stack
int pop(); // untuk mengambil data paling atas dari stack
void cetakstack(); // untuk mencetak isi stack yang berisi data no buku

// void void untuk queque peminjaman
void buatqueue(); // membuat queue
int queuekosong(); // mwngecek apakah queue kosong atau tidak
int queuepenuh(); // untuk mengecek queue penuh tidak
void enqueue(int IB); // untuk memasukkan data ke dalam queue
int dequeue(); // untuk mengambil data paling depan dari queue
void cetakqueue(); // untuk mencetak isi queue

// void void untuk kendali file eksternal
void import_buku(); // untuk mengambil data dari file eksternal 'buku.txt' kemudian dimasukkan kedalam stack
void import_pinjam(); // untuk mengambil data dari file eksternal 'pinjam.txt' kemudian dimasukkan kedalam queue
void update_data(); // untuk mengupdate file buku.txt dan pinjam.txt saat ada peminjaman dan pengembalian buku

void kembali_ke_menu(); // untuk tampilan kembali ke menu utama



int main(){

	
	int menu; // digunakan untuk memilih menu utama
	int no_buku; // untuk menyimpan no buku sementara untuk disimpan ke dalam file eksternal pada menu 1
	int jumlah; // untuk memilih jumlah buku yang ingin diinput pada menu 1
	int ambil; // untuk mengambil no buku yang di pop atau di enqueue pada menu 2 atau 4
	buatstack(); // menjalankan void buatstack
	buatqueue(); // menjalankan void buatqueue
	
	import_buku(); // menjalankan void import_data
	
	import_pinjam(); // menjalankan void import_pinjam
	
	
	
	while(true){
		cout<<"========Menu======="<<endl;
		cout<<" 1. Tambah Stok Buku"<<endl;
		cout<<" 2. Pinjam Buku"<<endl;
		cout<<" 3. Lihat Daftar Stok Buku"<<endl;
		cout<<" 4. Kembalikan Buku"<<endl;
		cout<<" 5. Lihat Daftar Buku yang dipinjam"<<endl;
		cout<<" 6. Exit"<<endl;
		cout<<" Pilih Menu : ";
		cin>>menu;
		
		if(menu == 1){
			cout<<" Jumlah Buku yang ingin diinput : ";
			cin>>jumlah;
			for(int i=0;i<jumlah;i++){
				cout<<" Nomor Buku "<<i+1<<" : ";
				cin>>no_buku;
				push(no_buku);
			}
			
			// memasukkan data buku dari stack ke file eksternal
			myfile.open("buku.txt" , ios::out);
				for(int i=0;i <= stack.top;i++){
					myfile<<stack.tumpukan[i]<<endl<<endl;
				}
			myfile.close();
			
			kembali_ke_menu();	
		}
		
		else if(menu == 2){
			if(stackkosong()){
				cout<<" Stock buku masih kosong"<<endl;
			}
			else{
				ambil = pop();
				enqueue(ambil);
				update_data();
				cout<<"======Buku Berhasil Dipinjam======"<<endl;
				
				
			}
			kembali_ke_menu();
		}
		
		
		else if(menu == 3){
			if(stackkosong()){
				cout<<" Stok buku masih kosong "<<endl;
			}
			else{
				cout<<"=====Daftar Stok Buku====="<<endl;
				cetakstack();
			}
			
			kembali_ke_menu();
		}
		
		else if(menu == 4){
			if(queuekosong()){
				cout<<" Tidak ada buku yang dipinjam"<<endl;
			}
			else{
				ambil = dequeue();
				push(ambil);
				update_data();
				cout<<"=====Buku Berhasil Dikembalikan====="<<endl;	
			}
			
			kembali_ke_menu();
		}
		
		else if(menu == 5){
			if(queuekosong()){
				cout<<" Tidak ada buku yang dipinjam"<<endl;
			}
			else{
				cout<<"====Daftar Buku yang Dipinjam===="<<endl;
				cetakqueue();
			}
			
			kembali_ke_menu();
			
		}
		
		else if(menu == 6){
			break;
		}
		
		else{
			cout<<" Masukkan angka 1,2,3,4,5,atau 6 saja !!!"<<endl;
			kembali_ke_menu();
		}
	}
	
	
	return 0;
}


void buatstack(){
	stack.top=-1; 
}

int stackkosong(){
	if (stack.top==-1){
		return true;
	}else{
		return false;
	}	
}

int stackpenuh(){
	if (stack.top == 50){
		return true;
	}else{
		return false; 
	}
}

void push(int IB){
	if(stackpenuh()){
		cout << "stack overflow\n";
	}else{
		stack.top++;
		stack.tumpukan[stack.top]=IB;;
	}
}

int pop(){
	int IP;
	if(stackkosong()){
		cout << "stack underflow\n";
	}else{
		IP=stack.tumpukan[stack.top];
		stack.top--;
	}
	return IP;
}

void cetakstack(){
	int i=stack.top;
	
	while (i >= 0){
		cout << " " << stack.tumpukan[i] << endl;
		i--;
	}
}

void buatqueue(){
	queue.belakang=0; 
}


int queuekosong(){
	if(queue.belakang==0)
		return true;
	else
		return false; 
}


int queuepenuh(){
	if(queue.belakang==50)
		return true;
	else
		return false; 
}


void enqueue(int IB){
	if(queuepenuh())
		cout << "queue overflow\n";
	else{
		queue.belakang++;
		queue.antrian[queue.belakang]=IB; 
	}
}

int dequeue(){
	int ID, i;
	if(queuekosong())
		cout << "queue underflow\n";
	else{
		ID=queue.antrian[1];
		for (i=1; i<queue.belakang; i++){
			queue.antrian[i]=queue.antrian[i+1];
		}
		queue.belakang--; 
	}
	return ID;
}

void cetakqueue(){
	int i=1;
	while(i<=queue.belakang){
		cout << "  " << queue.antrian[i];
		i++; 
	}
	cout<<"\n";
}

void import_buku(){
	string tampil; // untuk menampung data sementara dari file eksternal
	
	myfile.open("buku.txt" , ios::in);
	if(myfile.is_open()){
		// mengambil data baris per baris dari file eksternal
		while(getline(myfile, tampil)){
			/// jika baris yang diambil tidak kosong maka ambil datanya ke queue
			if(tampil != ""){
				push(stoi(tampil)); // memasukkan data dari file eksternal ke dalam stack
			}	
		}	
	}
	
	myfile.close();
}

void import_pinjam(){
	string tampil; // untuk menampung data sementara dari file eksternal
	
	myfile.open("pinjam.txt" , ios::in);
	if(myfile.is_open()){
		// mengambil data baris per baris dari file eksternal
		while(getline(myfile, tampil)){
			/// jika baris yang diambil tidak kosong maka ambil datanya ke queue
			if(tampil != ""){
				// function stoi digunakan untuk mengkonversi string ke int
				enqueue(stoi(tampil)); // memasukkan data dari file eksternal ke dalam stack
			}
		}
	}
	
	myfile.close();
}

void kembali_ke_menu(){
	string kembali; // untuk menginput apakah ingin kembali ke menu atau tidak
	cout<<"\n";
	// terus mengulang sampai yang diinput adalah huruf y
	do{
		cout<<" Kembali ke menu utama ? ";
		cin>>kembali;
	}while(kembali != "y" && kembali != "Y"); 
	system("CLS");
}

void update_data(){
	// mengupdate data stock buku
	myfile.open("buku.txt" , ios::out);
		for(int i=0;i <= stack.top;i++){
			myfile<<stack.tumpukan[i]<<endl<<endl;
		}
	myfile.close();
				
	// mengupdate data peminjaman buku
	myfile.open("pinjam.txt" , ios::out);
		for(int i=1;i <= queue.belakang;i++){
			myfile<<queue.antrian[i]<<endl<<endl;
		}
	myfile.close();
}
