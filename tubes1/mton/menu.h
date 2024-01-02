#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "mahasiswa.h"
#include "matakuliah.h"
#include "relasi.h"
#include <iostream>
using namespace std;

int menu();
void inputData(List_mhs &Lm, List_mk &Lmk);
infotype_mhs inputDataMahasiswa();
infotype_mk inputDataMataKuliah();
void deleteDataMahasiswa(List_mhs &L, List_r &Lr);
void cariDataMhs(List_mhs L);
void cariDataMk(List_mk L);
void menghubungkanData(List_mhs L, List_mk Lmk, List_r &Lr);
void showMkBasedMhs(List_r L, string nama);
void deleteChild(List_r &Lr);
void sumMk(List_mk L);
#endif // MENU_H_INCLUDED
