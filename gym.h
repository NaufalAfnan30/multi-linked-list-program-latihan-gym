#ifndef GYM_H_INCLUDED
#define GYM_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct Trainer *adrTrainer;
typedef struct Klien *adrKlien;           //membuat pointer
typedef struct Latihan *adrLatihan;

//deklarasi struct
struct Trainer{ //membuat struct Trainer
    string IDTrainer;
    string namaTrainer;
    int pengalaman;
    string spesialisasi;

    adrLatihan firstRelasi;
    adrTrainer next;
    adrTrainer prev;
};

struct Klien{   //membuat struct klien
    string namaKlien;
    int usia;
    string Membership;
    string Tujuan;
    string IDKlien;

    adrKlien next;
};

struct Latihan{ //membuat struct Latihan
    adrKlien Toklien;
    string jadwal;
    int durasi;

    adrLatihan next;
};

struct ListTrainer{ //membuat struct list trainer
    adrTrainer first;
};

struct ListKlien{   //membuat struct list klien
    adrKlien first;
};

//deklarasi fungsi
void createListTrainer(ListTrainer &LT);    //membuat create list trainer
void createListKlien(ListKlien &LK);    //membuat create list klien

adrTrainer createElemenTrainer(string id, string nama, int pengalaman, string spesialisasi);  //membuat elemen trainer
adrKlien createElemenKlien(string nama, int usia, string membership, string tujuan);  //membuat elemen klien
adrLatihan createElemenLatihan(adrKlien K, string jadwal, int durasi);    //membuat elemen latihan

void insertTrainer(ListTrainer &LT, adrTrainer T);  //membuat prosedur insert trainer
void insertKlien(ListKlien &LK, adrKlien K);    //membuat prosedur insert klien
void insertLatihan(ListTrainer &LT, ListKlien &LK, string idTrainer, string idKlien, string jadwal, int durasi); //membuat prosedur insert latihan

void deleteTrainer(ListTrainer &LT, string idTrainer);  //membuat prosedur delete trainer by id
void deleteKlien(ListKlien &LK, ListTrainer &LT, string idKlien);   //membuat prosedur delete klien by id
void deleteLatihan(ListTrainer &LT, string idTrainer);  //membuat prosedur delete latihan by id klien

adrTrainer findTrainerByID(ListTrainer LT, string idTrainer);   //membuat function find trainer by id
adrKlien findKlien(ListKlien LK, string idKlien);   //membuat function find klien by id untuk proses pengoperasian
adrKlien findKlienByMembership(ListKlien LK, string membership);   //membuat function find klien by membership untuk tampilan display
adrLatihan findLatihan(ListTrainer LT, string idKlien);    //membuat function find latihan by id untuk proses pengoperasian
adrLatihan findLatihanByJadwal(ListTrainer LT, string jadwal); //membuat function find latihan by jadwal untuk tampilan display

void showAllTrainer(ListTrainer LT);    //membuat prosedur show seluruh trainer
void showAllKlien(ListKlien LK);    //membuat prosedur show seluruh klien
void showKlienDariTrainer(ListTrainer, string idTrainer);   //membuat prosedur show klien dari trainer tertentu
void showSemuaTrainerdanKlien(ListTrainer LT);  //membuat prosedur show semua trainer dan klien
void showKlienDenganTrainer(ListTrainer LT, ListKlien LK);  //membuat prosedur show klien dengan trainer
void showTrainerDariKlien(ListTrainer LT, string idKlien);  // membuat prosedur show trainer dari klien tertentu

void countRelasiSetiapTrainer(ListTrainer LT);  //membuat prosedur count relasi dari tiap trainer
void countRelasiKlienTertentu(ListTrainer LT, string idKlien);  //membuat prosedur count dari relasi klien tertentu
void countKlienTanpaRelasi(ListTrainer LT, ListKlien LK);   //membuat prosedur count klien tanpa relasi
void editLatihan(ListTrainer LT, string idTrainer, string idKLien, string jadwalBaru, int durasiBaru);  //membuat prosedur edit latihan

#endif // GYM_H_INCLUDED
