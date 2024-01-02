#include <iostream>

using namespace std;
#include "mahasiswa.h"
#include "matakuliah.h"
#include "relasi.h"
#include "menu.h"
int main()
{
    List_mhs Lm;
    createListMhs(Lm);
    adr_mhs P;
    infotype_mhs data_mahasiswa;
    int nomor;

    List_mk Lmk;
    createListMk(Lmk);
    adr_mk Q;
    infotype_mk data_mataKuliah;

    List_r Lr;
    createList(Lr);

    string n;

    data_mahasiswa.NIM = "1234567890";
    data_mahasiswa.nama = "Clara";
    data_mahasiswa.tahun = 21;
    data_mahasiswa.SKS = 0;
    P = alokasiMhs(data_mahasiswa);
    insertFirstMhs(Lm, P);

    data_mahasiswa.NIM = "1234567891";
    data_mahasiswa.nama = "Gyanendra";
    data_mahasiswa.tahun = 21;
    data_mahasiswa.SKS = 23;
    P = alokasiMhs(data_mahasiswa);
    insertFirstMhs(Lm, P);

    data_mahasiswa.NIM = "1234567892";
    data_mahasiswa.nama = "Gyaneka";
    data_mahasiswa.tahun = 23;
    data_mahasiswa.SKS = 0;
    P = alokasiMhs(data_mahasiswa);
    insertFirstMhs(Lm, P);

    data_mataKuliah.kode = "C2211";
    data_mataKuliah.nama = "Kalkulus";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 23;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C1402";
    data_mataKuliah.nama = "Statistika";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 23;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C2309";
    data_mataKuliah.nama = "Kewirausahaan";
    data_mataKuliah.SKS = 2;
    data_mataKuliah.tahun = 22;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C0404";
    data_mataKuliah.nama = "Agama";
    data_mataKuliah.SKS = 2;
    data_mataKuliah.tahun = 23;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C2011";
    data_mataKuliah.nama = "TeoriPeluang";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 22;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C2004";
    data_mataKuliah.nama = "Pancasila";
    data_mataKuliah.SKS = 2;
    data_mataKuliah.tahun = 23;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C2244";
    data_mataKuliah.nama = "StrukturData";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 22;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C2345";
    data_mataKuliah.nama = "Logmat";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 23;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C8527";
    data_mataKuliah.nama = "Alpro";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 23;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    data_mataKuliah.kode = "C4235";
    data_mataKuliah.nama = "RPL";
    data_mataKuliah.SKS = 3;
    data_mataKuliah.tahun = 21;
    Q = alokasiMk(data_mataKuliah);
    insertFirstMk(Lmk,Q);

    connect(Lr,Lm,Lmk,"Gyaneka","Alpro");
    connect(Lr,Lm,Lmk,"Gyaneka","Agama");
    connect(Lr,Lm,Lmk,"Gyaneka","Kalkulus");
    connect(Lr,Lm,Lmk,"Gyaneka","Logmat");
    printListMhs(Lm);
    printListMk(Lmk);

    do{
        nomor = menu();
        switch (nomor){
        case 1: //DONE
            inputData(Lm,Lmk);
            break;
        case 2: //DONE
            printListMhs(Lm);
            break;
        case 3: //DONE
            deleteDataMahasiswa(Lm,Lr);
            break;
        case 4://DONE
            cariDataMhs(Lm);
            break;
        case 5://DONE
            cariDataMk(Lmk);
            break;
        case 6://DONE
            menghubungkanData(Lm,Lmk,Lr);
            break;
        case 7: //DONE
            printRelasi(Lr,Lm);
            break;
        case 8: //DONE
            cout << "Masukan nama mahasiswa : ";
            cin >> n;
            showMkBasedMhs(Lr,n);
            break;
        case 9: //DONE
            deleteChild(Lr);
            break;
        case 10: //DONE
            sumMk(Lmk);

        }
    }while(nomor != 0);
    return 0;
}
