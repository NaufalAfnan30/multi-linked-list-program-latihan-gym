#include "gym.h"
#include <string>
using namespace std;

void createListTrainer(ListTrainer &LT){
    LT.first = nullptr;
}

void createListKlien(ListKlien &LK){
    LK.first = nullptr;
}

adrTrainer createListTrainer(string id, string nama, int pengalaman, string spesialisasi);  //membuat elemen trainer
adrKlien createListKlien(string nama, int usia, string membership, string tujuan);  //membuat elemen klien
adrLatihan createListLatihan(adrKlien K, string jadwal, int durasi);    //membuat elemen latihan

void insertTrainer(ListTrainer &LT, adrTrainer T);  //membuat prosedur insert trainer
void insertKlien(ListKlien &LK, adrKlien K);    //membuat prosedur insert klien
void insertLatihan(ListTrainer &LT, ListKlien &LK, string idTrainer, string idKlien, string jadwal, int durasi); //membuat prosedur insert latihan

void deleteTrainer(ListTrainer &LT, string idTrainer);  //membuat prosedur delete trainer by id
void deleteKlien(ListKlien &LK, ListTrainer &LT, string idKlien);   //membuat prosedur delete klien by id
void deleteLatihan(ListTrainer &LT, string idTrainer);  //membuat prosedur delete latihan by id klien

adrTrainer findTrainer(ListTrainer LT, string idTrainer);   //membuat function find trainer by id
adrKlien findKlien(ListKlien LK, string idKlien);   //membuat function find klien by id untuk proses pengoperasian
adrKlien findKlienByMembership(ListKlien, string membership);   //membuat function find klien by membership untuk tampilan display
adrLatihan findLatihan(ListTrainer, string idKlien);    //membuat function find latihan by id untuk proses pengoperasian
adrLatihan findLatihanByJadwal(ListTrainer, string jadwal); //membuat function find latihan by jadwal untuk tampilan display

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
