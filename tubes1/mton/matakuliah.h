#ifndef MATAKULIAH_H_INCLUDED
#define MATAKULIAH_H_INCLUDED

#include <iostream>
using namespace std;

#define nextMk(P) P->next
#define prevMk(P) P->prev
#define firstMk(L) L.first
#define lastMk(L) L.last
#define infoMk(P) P->info
struct mataKuliah{
    string kode, nama;
    int SKS,tahun;
};
typedef mataKuliah infotype_mk;
typedef struct elmlist_mk *adr_mk;

struct elmlist_mk{
    infotype_mk info;
    adr_mk next;
    adr_mk prev;
};

struct List_mk{
    adr_mk first;
    adr_mk last;
};

/** TIDAK PERLU MODIFIKASI */
void createListMk(List_mk &L);
void insertFirstMk(List_mk &L, adr_mk P);
void deleteElmByInfoMk(List_mk &L, string nama);


/** PERLU MODIFIKASI */
adr_mk alokasiMk(infotype_mk x);
adr_mk findElmMk(List_mk L, string x);
void printInfoMk(List_mk L, string nama);
void printListMk(List_mk K);
#endif // MATAKULIAH_H_INCLUDED
