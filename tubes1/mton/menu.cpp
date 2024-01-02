#include "mahasiswa.h"
#include "matakuliah.h"
#include "relasi.h"

int menu(){
    cout << "=========================MENU========================" << endl;
    cout << "Selamat datang di aplikasi registrasi mahasiswa" << endl;
    cout << "1. Input data mahasiswa/mata kuliah" << endl;
    cout << "2. Menampilkan data mahasiswa"  << endl;
    cout << "3. Menghapus data mahasiswa" << endl;
    cout << "4. Mencari data mahasiswa" << endl;
    cout << "5. Mencari data mata kuliah" << endl;
    cout << "6. Menghubungkan mahasiswa dan mata kuliah" << endl;
    cout << "7. Menampilkan data mahasiswa beserta mata kuliahnya" << endl;
    cout << "8. Mencari mata kuliah pada mahasiswa" << endl;
    cout << "9. Menghapus mata kuliah pada mahasiswa" << endl;
    cout << "10.Menghitung jumlah mata kuliah " << endl;
    cout << "0. Keluar" << endl;
    cout << "=====================================================" << endl;
    cout << "Ketik angka dari menu yang akan dijalankan: ";
    int nomor;
    cin >> nomor;
    return nomor;
}
infotype_mhs inputDataMahasiswa(){
    infotype_mhs mahasiswa;
    cout << "Masukan data : " << endl;
    printf("NIM\t : ");
    cin >> mahasiswa.NIM;
    printf("Nama\t : ");
    cin >> mahasiswa.nama;
    printf("Tahun\t : ");
    cin >> mahasiswa.tahun;
    return mahasiswa;
}
infotype_mk inputDataMataKuliah(){
    infotype_mk mataKuliah;
    cout << "Masukan data : " << endl;
    printf("Kode\t : ");
    cin >> mataKuliah.kode;
    printf("Nama\t : ");
    cin >> mataKuliah.nama;
    printf("Tahun\t : ");
    cin >> mataKuliah.tahun;
    printf("SKS\t : ");
    cin >> mataKuliah.SKS;
    return mataKuliah;
}
void inputData(List_mhs &Lm, List_mk &Lmk){
    adr_mhs P,duplikat;
    adr_mk Q,duplikat2;
    infotype_mhs data_mahasiswa;
    infotype_mk data_mataKuliah;
    string status;
    cout << "Data apa yang ingin anda masukan?(mahasiswa/matakuliah)" << endl;
    cin >> status;
    if(status == "mahasiswa"){
        data_mahasiswa = inputDataMahasiswa();
        P = alokasiMhs(data_mahasiswa);
        duplikat = findElmMhs(Lm,P->info.NIM);
        if(duplikat == NULL){
            insertFirstMhs(Lm,P);
        }else{
            cout << "terjadi duplikat pada NIM" << endl;
        }
    }else if(status == "matakuliah"){
        data_mataKuliah = inputDataMataKuliah();
        Q = alokasiMk(data_mataKuliah);
        duplikat2 = findElmMk(Lmk,Q->info.kode);
        if(duplikat2 == NULL){
            insertFirstMk(Lmk,Q);
        }else{
            cout << "terjadi duplikat pada KODE" << endl;
        }
        }else{
            cout << "Inputan tidak valid" << endl;
        }
}
void deleteDataMahasiswa(List_mhs &L, List_r &Lr){
    string nim;
    cout << "Masukan Nim/Nama Mahasiswa yang akan dihapus : ";
    cin >> nim;
    adr_mhs P = findElmMhs(L,nim);
    adr_r Q,K;
    Q = first(Lr);
    while(Q != first(Lr)){
        if(Q->mahasiswa == P){
            deleteElement(Lr,K);
        }
        Q = Q->next;
    }
    deleteElmByInfoMhs(L,nim);
}
void cariDataMhs(List_mhs L){
    string nama;
    cout << "Masukan Nama Mahasiswa : ";
    cin >> nama;
    printInfoMhs(L,nama);
}
void cariDataMk(List_mk L){
    string nama;
    cout << "Masukan Nama Mata Kuliah : ";
    cin >> nama;
    printInfoMk(L,nama);
}
void menghubungkanData(List_mhs L, List_mk Lmk, List_r &Lr){
    string namaMhs, namaMk;
    bool statusTahun,StatusSKS;
    statusTahun = StatusSKS = false;
    cout << "Masukan nama Mahasiswa : ";
    cin >> namaMhs;
    cout << "Masukan nama Mata Kuliah : ";
    cin >> namaMk;
    adr_mhs P = findElmMhs(L,namaMhs);
    adr_mk Q = findElmMk(Lmk,namaMk);
    if(P != NULL && Q != NULL){
        if(P->info.tahun == Q->info.tahun){
            statusTahun = true;
        }
        if(P->info.SKS + Q->info.SKS <= 24){
            StatusSKS = true;
        }
        if(statusTahun && StatusSKS && !isDuplikat(Lr,namaMhs,namaMk)){
            cout << isDuplikat(Lr,namaMhs,namaMk) << endl;
            connect(Lr,L,Lmk,namaMhs,namaMk);
        }else{
            cout << "Status tidak valid" << endl;
        }
    }else{
        cout << "Mahasiswa atau Mata kuliah tidak tersedia" << endl;
    }
}
void showMkBasedMhs(List_r L, string nama){
    cout << nama << " - ";
    adr_r R = first(L);
    if(R != NULL){
        do{
            if(infoMhs(mahasiswa(R)).nama == nama){
                cout << infoMk(matakuliah(R)).nama << ", ";
            }
            R = next(R);
        }while(R != first(L));
    }
    cout << endl;

}
void deleteChild(List_r &Lr){
    string namaMhs,namaMk;
    cout << "Masukan nama Mahasiswa : ";
    cin >> namaMhs;
    showMkBasedMhs(Lr,namaMhs);
    cout << "Masukan nama Mata Kuliah yang ingin dihapus : ";
    cin >> namaMk;
    adr_r P = findElmByinfo(Lr,namaMhs,namaMk);
    if(P!= NULL){
        deleteElement(Lr,P);
    }

}

void sumMk(List_mk L){
    adr_mk P = firstMk(L);
    int sum = 0;
    while(P != NULL){
        sum++;
        P = P->next;
    }
    cout << "Jumlah Mata Kuliah : " << sum << endl;
}
