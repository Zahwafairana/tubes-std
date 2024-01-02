#ifndef MAHASISWA_H_INCLUDED
#define MAHASISWA_H_INCLUDED
#include <iostream>
using namespace std;

#define firstMhs(L) L.first
#define nextMhs(P) P->next
#define infoMhs(P) P->info

struct mahasiswa {
    string NIM,nama;
    int tahun, SKS;
};
typedef mahasiswa infotype_mhs;
typedef struct elmlist_mhs *adr_mhs;

struct elmlist_mhs {
    infotype_mhs info;
    adr_mhs next;
};

struct List_mhs {
    adr_mhs first;
};


/** TIDAK PERLU MODIFIKASI */
void createListMhs(List_mhs &L);
void insertFirstMhs(List_mhs &L, adr_mhs P);
void deleteElmByInfoMhs(List_mhs &L, string nama);


/** PERLU MODIFIKASI */
adr_mhs alokasiMhs(infotype_mhs x);
adr_mhs findElmMhs(List_mhs L, string x);
void printInfoMhs(List_mhs L, string nama);
void printListMhs(List_mhs L);

#endif // MAHASISWA_H_INCLUDED
