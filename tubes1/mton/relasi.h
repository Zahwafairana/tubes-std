#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "mahasiswa.h"
#include "matakuliah.h"
#include <iostream>
using namespace std;

#define first(L) L.first
#define next(P) P->next
#define prev(P) P->prev
#define mahasiswa(P) P->mahasiswa
#define matakuliah(P) P->matakuliah

typedef struct elm_r *adr_r;

struct elm_r{
    adr_mhs mahasiswa;
    adr_mk matakuliah;
    adr_r next,prev;
};

struct List_r{
    adr_r first;
};

void createList(List_r &L);
adr_r alokasi(adr_mhs M, adr_mk MK);
void insertFirst(List_r &L, adr_r P);
void deleteElement(List_r &L, adr_r &P);

adr_r findElm(List_r L, adr_mhs M, adr_mk MK);
adr_r findElmByinfo(List_r L, string M, string MK);

void connect(List_r &L, List_mhs Lm, List_mk Lmk, string M, string MK);
bool isDuplikat(List_r L, string namaMhs, string namaMk);

void printRelasi(List_r L, List_mhs Lm);
#endif // RELASI_H_INCLUDED
