#include "mahasiswa.h"
void createListMhs(List_mhs &L){
    firstMhs(L) = NULL;
}
void insertFirstMhs(List_mhs &L, adr_mhs P){
    if(firstMhs(L) != NULL){
        nextMhs(P) = firstMhs(L);
        firstMhs(L) = P;
    }else{
        firstMhs(L) = P;
    }
}
void deleteElmByInfoMhs(List_mhs &L, string flag){ // betulin
    adr_mhs P = findElmMhs(L,flag);
    adr_mhs Q = NULL;
    if(firstMhs(L) == P){
        if(nextMhs(P) == NULL){
            firstMhs(L) = NULL;
        }else{
            firstMhs(L) = nextMhs(P);
            nextMhs(P) = NULL;
        }
    }else if(P != NULL){
        Q = firstMhs(L);
        while(nextMhs(Q) != P){
            Q = nextMhs(Q);
        }
        nextMhs(Q) = nextMhs(P);
        nextMhs(P) = NULL;
    }else{
        cout << "Mahasiswa tidak ada" << endl;
    }
}


/** PERLU MODIFIKASI */
adr_mhs alokasiMhs(infotype_mhs x){
    adr_mhs P = new elmlist_mhs;
    infoMhs(P).NIM = x.NIM;
    infoMhs(P).nama = x.nama;
    infoMhs(P).tahun = x.tahun;
    infoMhs(P).SKS = x.SKS;
    nextMhs(P) = NULL;
    return P;
}
adr_mhs findElmMhs(List_mhs L, string x){
    adr_mhs P = firstMhs(L);
    while(P != NULL){
        if(infoMhs(P).NIM == x || infoMhs(P).nama == x) {
            return P;
        }
        P = nextMhs(P);
    }
    return NULL;
}
void printInfoMhs(List_mhs L, string nama){
    adr_mhs P = findElmMhs(L,nama);
    cout << "======INFO MAHASISWA: ======" << endl;
    if(P != NULL){
        cout << "Nim: " << infoMhs(P).NIM << endl;
        cout << "Nama: " << infoMhs(P).nama << endl;
        cout << "SKS: " << infoMhs(P).SKS << endl;
        cout << "Tahun: " << infoMhs(P).tahun<< endl;
        cout << "========================" << endl;
    }else{
        cout << "Mahasiswa tidak tersedia" << endl;
    }
    cout << endl;
}
void printListMhs(List_mhs L){
    int i = 1;
    adr_mhs P = firstMhs(L);
    cout << "======LIST MAHASISWA: ======" << endl;
    if(firstMhs(L) != NULL){
        while(P != NULL){
            cout << i << ". Nama: " << infoMhs(P).nama << endl;
            P = nextMhs(P);
            i++;
        }
    }else{
        cout << "KOSONG" << endl;
    }
}
