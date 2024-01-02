#include "relasi.h"
void createList(List_r &L){
    first(L) = NULL;
}
adr_r alokasi(adr_mhs M, adr_mk MK){
    adr_r P = new elm_r;
    mahasiswa(P) = M;
    matakuliah(P) = MK;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}
void insertFirst(List_r &L, adr_r P){
    if(first(L) == NULL){
        first(L) = P;
    }else{
        next(P) = first(L);
        first(L) = P;
    }
}
void deleteElement(List_r &L, adr_r &P){
    adr_r Q;
    if(first(L) == P){
        if(next(P) == P){
            first(L) = NULL;
        }else{
            first(L) = next(P);
            next(P) = NULL;
            prev(P) = NULL;
        }
    }else if(P != NULL){
        Q = first(L);
        while(next(Q) != P){
            Q = next(Q);
        }
        next(Q) = next(P);
        next(P) = NULL;
        prev(P) = NULL;
    }else{
        cout << "Mata kuliah tidak ada" << endl;
    }
}

adr_r findElm(List_r L, adr_mhs M, adr_mk MK){
    adr_r P = first(L);
    if(P != NULL){
        while(P != NULL){
            if(mahasiswa(P) == M && matakuliah(P) == MK){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}
adr_r findElmByinfo(List_r L, string M, string MK){
    adr_r P = first(L);
    int i = 1;
    if(P != NULL){
        while(P != NULL){
            if(P->mahasiswa->info.nama == M && P->matakuliah->info.nama == MK){
                return P;
            }
            P = next(P);
        }
    }
    return NULL;
}

void connect(List_r &L, List_mhs Lm, List_mk Lmk, string M, string MK){
    adr_mhs P = findElmMhs(Lm, M);
    adr_mk Q = findElmMk(Lmk, MK);
    if(P != NULL && Q != NULL){
        adr_r R = alokasi(P,Q);
        insertFirst(L,R);
        P->info.SKS = P->info.SKS + Q->info.SKS;
    }

}

bool isDuplikat(List_r L, string namaMhs, string namaMk){
    adr_r P = first(L);
    while(P != NULL){
        if(P->mahasiswa->info.nama == namaMhs && P->matakuliah->info.nama == namaMk){
            return true;
        }
        P = P->next;
    }
    return false;
}

void printRelasi(List_r L, List_mhs Lm){
    adr_mhs  P = first(Lm);
    cout << "Print Relasi" << endl;
    while(P != NULL){
        cout << infoMhs(P).nama << " - ";
        adr_r R = first(L);
        if(R != NULL){
            do{
                if(mahasiswa(R) == P){
                    cout << infoMk(matakuliah(R)).nama << ", ";
                }
                R = next(R);
            }while(R != first(L));
        }
        cout << endl;
        P = next(P);
    }
    cout << endl;
}
