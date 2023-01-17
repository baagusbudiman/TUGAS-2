// nama : Bagus Budiman
// npm : 227064516081


//MINI PROJECT: PROGRAM PEMBELIAN BARANG ONLINE//
#include <iostream>
using namespace std;
string dataUsername = "bagusbudiman", dataPassword = "soeboed28", nama = "Bagus";
string barangBelanja[6] = {"","Baju","Celana","Jaket","Sepatu","Sendal"};
int hargaBarang[6] = {0,50000,35000,100000,75000,20000};
float diskonBarang[6] = {0, 0.2, 0.1, 0.3, 0.15, 0.1};
int syaratDiskonBarang[6] = {0,3, 3, 2, 2, 3};
int tagihanBarang[6] = {0,0,0,0,0,0};
int tagihanHarga[6] = {0,0,0,0,0,0};
int totalTagihanBarang = 0;
int totalTagihanHarga = 0;
void logUser(string &, string &, bool &, bool &, bool &, int &, string &, string &);
void perhitunganBarang(int &, int &, int &, int &, int &, int &, float &,int &);
void mencetakBarangKeranjang(int &, int &, int &);
void charKeInt(char &, int &);
void cetakNamaBarang();
void cetakKodePembayaran();
int main() {
    //deklarasi
    char pilihanMengulang, pilihanLogin, pilihanBarang, pilihanLokasi, pilihanMetodePembayaran, pilihanMenu;
    string barang, usernameLogin, passwordLogin, alamat, metodePembayaran;
    int ongkir, hargaSetelahOngkir, buffer, tagihanBarangSementara, tagihanHargaSementara;
   //inisialisasi
    bool menuJualBeli = false, menuDaftarBarang, menuLogin = true, loginUser = true;
    int jumlahBarang[6] = {0,0,0,0,0,0};
    int totalHargaBarang[6] = {0,0,0,0,0,0};
    int batasCobaLogin;
    //memilih ingin login, atau buat akun
    while (menuLogin){
        batasCobaLogin = 0;
        cout << "=========================================\n";
        cout << "==== Selamat Datang di Tukubarang.com ===\n";
        cout << "========================================= \n1. Login \n2. Register / buat akun\n";
        cout << "Note : Jika belum punya akun silahkan register\n";
        cout << "==============================================\n";
        cout << "Silahkan Tentukan Pilihan : ";
        cin  >> pilihanLogin;
        if(pilihanLogin == '1'){ //login
            while(loginUser){
                system("cls");
                logUser(usernameLogin, passwordLogin,menuJualBeli,menuLogin,loginUser,batasCobaLogin,dataUsername,dataPassword);
                if (batasCobaLogin == 1){
                    break;
                }
            }
        }else if (pilihanLogin == '2'){  //buat
            system("cls");
            cout << "Masukkan nama anda      : ";
            cin >> nama;
            cout << "Buat username akun anda : ";
            cin >> dataUsername;
            cout << "Buat password anda      : ";
            cin >> dataPassword;
            while(loginUser){
                logUser(usernameLogin, passwordLogin,menuJualBeli,menuLogin,loginUser,batasCobaLogin,dataUsername,dataPassword);
                if (batasCobaLogin == 2){
                    cout << "MAAF BATAS PERCOBAAN LOGIN TERLAMPAUI.\n\n";
                    break;
                }
            }
        } else { //jika inputnya salah, user akan diminta menginput ulang
            cout << "Pilihan Salah!\n";
        }
    } //akhir looping menu login
    //menuJualBeli = true;
    while(menuJualBeli){
        cout << "\n=== Menu Tukubarang.com ===\n";
        cout << "1. Belanja \n2. Keranjang ku \n3. Bayar \n4. Keluar \nPilih menu = ";
        cin >> pilihanMenu;
        if(pilihanMenu == '1') {
            menuDaftarBarang = true;
            while(menuDaftarBarang){
                system("cls");
                cout << "\n=== Daftar Barang ===\n";
                cout << "1.) Baju   = Rp. 50000 \n2.) Celana = Rp. 35000 \n3.) Jaket  = Rp. 100000 \n4.) Sepatu = Rp. 75000 \n5.) Sendal = Rp. 20000 \n";
                cout << "Pilih No Barang: ";
                cin >> pilihanBarang;
                charKeInt(pilihanBarang, buffer);
                for(int i = 1; i < 6; i++){
                    if(buffer == i){
                        perhitunganBarang(jumlahBarang[i], tagihanBarang[i], hargaBarang[i], totalHargaBarang[i], tagihanHarga[i], syaratDiskonBarang[i], diskonBarang[i], i);
                    }
                }
                //menambahkan jumlah barang yang dibeli
                tagihanBarangSementara = 0;
                tagihanHargaSementara = 0;
                for(int i = 1; i < 6; i++){
                    tagihanBarangSementara += tagihanBarang[i];
                    tagihanHargaSementara += tagihanHarga[i];
                }
                totalTagihanBarang = tagihanBarangSementara;
                totalTagihanHarga = tagihanHargaSementara;
                // selesai menjumlahkan barang yang dibeli
                cout << "Ingin beli lagi? [Y/N]: ";
                cin >> pilihanMengulang;
                while (pilihanMengulang != 'Y' and pilihanMengulang != 'y'){
                    if (pilihanMengulang == 'N' or pilihanMengulang == 'n'){
                        menuDaftarBarang = false;
                        system("cls");
                        break;    //mengakhiri looping jika user memilih berhenti
                    } else {
                        cout << "Pilihan salah!\n";
                        cout << "Ingin membeli lagi? [Y/N]: ";
                        cin >> pilihanMengulang;
                    }
                } //akhir kode looping pilihan mengulang
            } //akhir menu daftar barang
        }//akhir pilihan if belanja
        else if (pilihanMenu == '2'){ //menu keranjang
            system("cls");
            cout << "\n== Keranjang ==" << endl;
            if (totalTagihanBarang > 0){
                cout << "Daftar barang yang dibeli: " << endl;
                for(int i = 1; i < 6; i++){
                    mencetakBarangKeranjang(tagihanBarang[i], tagihanHarga[i], i);
                }
                cout << "Jumlah total harga: Rp." << totalTagihanHarga <<endl;
            } else {
                cout << "Oops, kamu belum memasukkan apapun ke dalam keranjang" << endl;
            }
        } else if(pilihanMenu == '3'){
            system("cls");
            cout << "== Menu Pembayaraan ==" << endl;
            if (totalTagihanBarang > 0){
                while (true){ //lokasi pengiriman
                    cout << "\nPilih Lokasi anda\n";
                    cout << "1. Pulau Jawa \n2. Luar Pulau Jawa\n";
                    cout << "Pilihan anda: ";
                    cin >> pilihanLokasi;
                    if (pilihanLokasi == '1'){ //lokasi di jawa
                        ongkir = 10000;
                        hargaSetelahOngkir = totalTagihanHarga + ongkir;
                        cout << "Harga Sebelum Ongkir: " << totalTagihanHarga << endl;
                        cout << "Harga Setelah Ongkir: " << hargaSetelahOngkir << endl;
                        break;
                    } else if (pilihanLokasi == '2'){
                        ongkir = 20000;
                        hargaSetelahOngkir = totalTagihanHarga + ongkir;
                        cout << "Harga setelah ongkir: Rp. " << hargaSetelahOngkir << endl;
                        break;
                    } else {
                        cout << "Input salah!\n";
                    }
                } //akhir loop while lokasi
                cout << "Masukkan alamat anda: ";
                cin >> alamat;
                //memilih metode pembayaran
                while (true){
                    cout << "\n== Metode Pembayaraan == \n";
                    cout << "1. M-Banking \n2. Indomaret / Alfamart \n3. GOPAY\n";
                    cout << "Pilihan anda: ";
                    cin >> pilihanMetodePembayaran;
                    if (pilihanMetodePembayaran == '1'){
                        metodePembayaran = "M-Banking";
                        break;
                    } else if (pilihanMetodePembayaran == '2'){
                        metodePembayaran = "Indomaret / Alfamart";
                        break;
                    } else if (pilihanMetodePembayaran == '3'){
                        metodePembayaran = "GOPAY";
                        break;
                    } else {
                        cout << "\nPilihan salah!\n";
                    }
                } //akhir menu pilih metode pembayaran
                //menampilkan riwayat pembelian
                system("cls");
                cout << "\n======================= INVOICE ========================" << endl;
                cout << "Atas nama: " << nama << endl;
                cout << "Barang: "; cetakNamaBarang();
                cout << "Jumlah Barang: " << totalTagihanBarang << endl;
                cout << "Alamat: " << alamat << endl;
                cout << "Metode Pembayaran: " << metodePembayaran << endl;
                cout << "Subtotal Harga Barang: Rp. " << totalTagihanHarga << endl;
                cout << "Ongkir: Rp. " << ongkir << endl;
                cout << "Total Harga: Rp. " << hargaSetelahOngkir << endl;
                cout << "Kode Pembayaraan: "; cetakKodePembayaran(); cout << pilihanLokasi << pilihanMetodePembayaran << endl;
                cout << "\n*GUNAKAN KODE PEMBAYARAN UNTUK MENYELESAIKAN PEMBAYARAN*" << endl;
                cout << "========================================================" << endl;
                cout << "TERIMA KASIH TELAH MEMBELI DI TUKUBARANG.COM" << endl;
                cout << "========================================================" << endl;
                break;
            } else {
                cout << "Oops, Kamu belum Pilih Barang" << endl;
            }
        } //akhir pilihan menu pembayaran
        else if(pilihanMenu == '4'){
            cout << "Program Selesai.";
            menuJualBeli = false;
            break;
        } else
            cout << "Pilihan salah!" << endl;
    }//akhir menu jual beli
    return 0;
}// akhir int main
void logUser(string &usernameLogin, string &passwordLogin, bool &menuJualBeli, bool &menuLogin, bool &loginUser,int &batasCobaLogin, string &dUsername, string &dPassword){
    cout << "-----------------------------\n";
    cout << "Silahkan Login\n";
    cout << "Masukkan username: ";
    cin >> usernameLogin;
    cout << "Masukkan password: ";
    cin >> passwordLogin;
    system("cls");
    if(usernameLogin == dUsername and passwordLogin == dPassword){
        cout << "login berhasil\n";
        menuJualBeli = true;
        menuLogin = false;
        loginUser = false;
    } else {
        batasCobaLogin++;
        cout << "---------------------------------------\n";
        cout << "Username atau Password salah\n";
        cout << "Silahkan register jika belum punya akun\n";
        cout << "---------------------------------------\n\n";
    }
}
void perhitunganBarang(int &jumlahBarang, int &jmlhTotalBarang, int &hargaBarang, int &hargaTotalBarang, int &tagihanHarga, int &syaratDiskonBarang, float &diskonBarang,int &i){
    cout << "\n== BELI " << syaratDiskonBarang << " ATAU LEBIH AKAN MENDAPAT DISKON " << (diskonBarang*100) << "% ==\n";
    cout << "Masukkan jumlah " << barangBelanja[i] << " yang ingin anda beli: ";
    cin >> jumlahBarang;
    jmlhTotalBarang += jumlahBarang;
    if(jumlahBarang >= syaratDiskonBarang){
        hargaTotalBarang = jumlahBarang * hargaBarang;
        hargaTotalBarang = hargaTotalBarang - (hargaTotalBarang*diskonBarang);
        cout << "Total Harga barang: Rp. " << hargaTotalBarang << endl;
    } else {
        hargaTotalBarang = jumlahBarang * hargaBarang;
        cout << "Total Harga barang: Rp. " << hargaTotalBarang << endl;
    } tagihanHarga += hargaTotalBarang;
}
void cetakKodePembayaran(){
    for(int i = 1; i < 6; i++){
        cout << tagihanBarang[i];
    } cout << totalTagihanBarang;
}
void cetakNamaBarang(){
    for(int i = 1; i < 6; i++){
        if (tagihanBarang[i] > 0){
            cout << barangBelanja[i] << " (" << tagihanBarang[i] << "). ";
        }
    } cout << endl;
}
void mencetakBarangKeranjang(int &jmlhTotalBarang, int &jumlahHargaTotalBarang, int &i){
    if(jmlhTotalBarang > 0){
        cout << barangBelanja[i] << ": " << jmlhTotalBarang << " buah" << endl;
        cout << "Total Harga: Rp. " << jumlahHargaTotalBarang << endl << endl;
    }
}
void charKeInt(char &pilihan, int &buffer){
    switch(pilihan){
        case '1': buffer = 1; break;
        case '2': buffer = 2; break;
        case '3': buffer = 3; break;
        case '4': buffer = 4; break;
        case '5': buffer = 5; break;
    }
} 
