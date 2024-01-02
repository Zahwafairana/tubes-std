#include "matakuliah.h"
void createListMk(List_mk &L){
    firstMk(L) = NULL;
}
void insertFirstMk(List_mk &L, adr_mk P){
    if(firstMk(L) != NULL){
        nextMk(P) = firstMk(L);
        firstMk(L) = P;
    }else{
        firstMk(L) = P;
    }
}
void deleteElmByInfoMk(List_mk &L, string nama){
    adr_mk P = firstMk(L);
    adr_mk Q = NULL;
    if(nextMk(firstMk(L)) == NULL){
        firstMk(L) = NULL;
    }else if(infoMk(P).nama == nama){
        firstMk(L) = nextMk(firstMk(L));
        nextMk(P) = NULL;
    }else{
        while(P != NULL && infoMk(nextMk(P)).nama == nama){
            P = nextMk(P);
        }
        Q = P;
        nextMk(P) = nextMk(Q);
        nextMk(Q) = NULL;
        if(P == NULL){
            cout << "Mata Kuliah tidak ada" << endl;
        }
    }
}


/** PERLU MODIFIKASI */
adr_mk alokasiMk(infotype_mk x){
    adr_mk P = new elmlist_mk;
    infoMk(P).kode = x.kode;
    infoMk(P).nama = x.nama;
    infoMk(P).SKS = x.SKS;
    infoMk(P).tahun = x.tahun;
    nextMk(P) = NULL;
    prevMk(P) = NULL;
    return P;
}
adr_mk findElmMk(List_mk L, string x){
     adr_mk P = firstMk(L);
    while(P != NULL) {
        if(infoMk(P).kode == x || infoMk(P).nama == x) {
            return P;
        }
        P = nextMk(P);
    }
    return NULL;
}
void printInfoMk(List_mk L, string nama){
    adr_mk P = findElmMk(L,nama);
    cout << "======INFO MATA KULIAH: ======" << endl;
    if(P != NULL){
        cout << "Kode: " << infoMk(P).kode << endl;
        cout << "Nama: " << infoMk(P).nama << endl;
        cout << "SKS: " << infoMk(P).SKS << endl;
        cout << "Tahun: " << infoMk(P).tahun<< endl;
        cout << "========================" << endl;
    }else{
        cout << "Matakuliah tidak tersedia" << endl;
    }
    cout << endl;
}
void printListMk(List_mk L){
    adr_mk P = firstMk(L);
    int i = 1;
    cout << "======LIST MATA KULIAH: ======" << endl;
    if(firstMk(L) != NULL){
        while(P != NULL){
            if(i < 10){
                cout << i << ". Nama: " << infoMk(P).nama << endl;
            }else{
                cout << i << ".Nama: " << infoMk(P).nama << endl;
            }
            i++;
            P = nextMk(P);
        }
    }else{
        cout << "KOSONG" << endl;
    }
    cout << endl;
}
