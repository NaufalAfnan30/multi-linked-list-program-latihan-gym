#include "gym.h"
#include <string>
#include <iostream>
using namespace std;

void createListTrainer(ListTrainer &LT){
    LT.first = nullptr;
}

void createListKlien(ListKlien &LK){
    LK.first = nullptr;
}

adrTrainer createElemenTrainer(string id, string nama, int pengalaman, string spesialisasi){
    adrTrainer T;

    T = new Trainer;
    T->IDTrainer = id;
    T->namaTrainer = nama;
    T->pengalaman = pengalaman;
    T->spesialisasi = spesialisasi;
    T->firstRelasi;
    T->next = nullptr;
    T->prev = nullptr;

    return T;
}
adrKlien createElemenKlien(string nama, int usia, string membership, string tujuan, string idKlien){
    adrKlien C;

    C = new Klien;
    C->IDKlien = id;
    C->namaKlien = nama;
    C->usia = usia;
    C->Membership = membership;
    C->Tujuan = tujuan;
    C->next = nullptr;

    return C;
}
adrLatihan createElemenLatihan(adrKlien K, string jadwal, int durasi){
    adrLatihan L;

    L = new Latihan;
    L->durasi = durasi;
    L->jadwal = jadwal;
    L->Toklien = K;

    L->next = nullptr;

    return L;
}

void insertTrainer(ListTrainer &LT, adrTrainer T){
    adrTrainer Q;

    if (LT.first == nullptr){
        LT.first = T;
    } else {
        Q = LT.first;

        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = T;
        T->prev = Q;
    }
}
void insertKlien(ListKlien &LK, adrKlien K){
    adrKlien Q;

    if (LK.first != nullptr){
        LK.first = K;
    } else {
        Q = LK.first;

        while (Q->next != nullptr){
            Q = Q->next;
        }
        Q->next = k;
    }
}
void insertLatihan(ListTrainer &LT, ListKlien &LK, string idTrainer, string idKlien, string jadwal, int durasi){
    adrTrainer T = findTrainerByID(LT, idTrainer);
    adrKlien K = findKlien(LK, idKlien);

    if (T == nullptr){
        cout << "Trainer tidak ditemukan!" << endl;
        return;
    }

    if (K == nullptr){
        cout << "Klien tidak ditemukan!" << endl;
        return;
    }

    adrLatihan exist = findLatihan(LT, idKlien);
    if (exist != nullptr){
        cout << "Klien sudah punya trainer" << endl;
        return;
    }

    adrLatihan L = createElemenLatihan(K, jadwal, durasi);
    L->next = T->firstRelasi;
    T->firstRelasi = L;

    cout << "Latihan berhasil ditambahkan!" << endl;
}

void deleteTrainer(ListTrainer &LT, string idTrainer){
    adrTrainer p;
    p = LT.first;

    if (LT.first == nullptr){
        cout << "List trainer kosong" << endl;
    }

    while (p->next != nullptr && p->IDTrainer != idTrainer){
        p = p->next;
    }

    if (p == nullptr){
        cout << "Trainer tidak ditemukan" << endl;
        return;
    }

    adrLatihan L;
    L = p->firstRelasi;
    while (L != nullptr){
        adrLatihan temp = L;
        L = L->next;
        delete temp;
    }

    if (p->prev == nullptr){
        LT.first = p->next;
        if (LT.first != nullptr){
            LT.first->prev = nullptr;
        }
    } else {
        if (p->next != nullptr){
            p->next->prev = p->prev;
        }
        p->prev->next = p->next;
    }
    delete p;
    cout << "Trainer berhasil dihapus" << endl;
}
void deleteKlien(ListKlien &LK, ListTrainer &LT, string idKlien){
    if (LK.first == nullptr){
        cout << "List klien kosong" << endl;
        return;
    }

    adrKlien p = LK.first;
    adrKlien Q = nullptr;

    while (p != nullptr && p->IDKlien != idKlien){
        Q = p;
        p = p->next;
    }
    if (p == nullptr){
        cout << "Klien tidak ditemukan!" << endl;
        return;
    }
    if (Q == nullptr){
        LK.first = p->next;
    }else {
        Q->next = p->next;
    }

    delete p;
    cout << "Klien berhasil dihapus!" << endl;
}
void deleteLatihan(ListTrainer &LT, string idTrainer, string idKlien){
    adrTrainer T = findTrainerByID(LT, idTrainer);

    if (T == nullptr){
        cout << "Trainer tidak ditemukan!" << endl;
        return;
    }

    adrLatihan L = T->firstRelasi;
    adrLatihan Q = nullptr;

    while (L != nullptr && L->Toklien->IDKlien != idKlien){
        Q = L;
        L = L->next;
    }

    if (L == nullptr){
        cout << "Jadwal latihan tidak ditemukan!" << endl;
        return;
    }

    if (Q == nullptr){
        T->firstRelasi = L->next;
    }else {
        Q->next = L->next;
    }
    delete L;
    cout << "Jadwal latihan berhasil dihapus!" << endl;
}

adrTrainer findTrainerByID(ListTrainer LT, string idTrainer){
    adrLatihan p;
    p = LT.first;

    while (p != nullptr){
        if (p->IDtrainer == idTrainer){
            return p;
        }
        p = p->next;
    }
    return nullptr
}
adrKlien findKlien(ListKlien LK, string idKlien){
    adrKlien p = LK.first;

    while (p != nullptr){
        if (p->IDKlien == idKlien){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
adrKlien findKlienByMembership(ListKlien LK, string membership){
    adrKlien p = LK.first;

    while (p != nullptr){
        if (p->Membership == membership){
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
adrLatihan findLatihan(ListTrainer LT, string idKlien){
    adrTrainer T = LT.first;

    while (T != nullptr){
        adrLatihan L = T->firstRelasi;

        while (L != nullptr){
            if (L->Toklien->IDKlien == idKlien){
                return L;
            }
            L = L->next;
        }
        T = T->next;
    }
    return nullptr;
}
adrLatihan findLatihanByJadwal(ListTrainer LT, string jadwal){
    adrTrainer T = LT.first;

    while (T != nullptr){
        adrLatihan L = T->firstRelasi;


        while (L != nullptr){
            if (L->jadwal == jadwal){
                return L;
            }
            L = L->next;
        }
        T = T->next;
    }
    return nullptr;
}

void showAllTrainer(ListTrainer LT){
    adrTrainer T = LT.first;

    if (T == nullptr){
        cout << "Tidak ada data trainer tersebut!" << endl;
        return;
    }

    cout << "====== DAFTAR TRAINER ======" << endl;

    while (T != nullptr){
        cout << "ID Trainer   : " << T->IDTrainer << endl;
        cout << "Nama Trainer : " << T->namaTrainer << endl;
        cout << "Pengalaman   : " << T->pengalaman << " tahun" <<  endl;
        cout << "Spesialisasi : " << T->spesialisasi << endl;
        cout << "------------------------" << endl;

        T= T->next;
    }
}
void showAllKlien(ListKlien LK){
    adrKlien K = LK.first;

    if (K == nullptr){
        cout << "Tidak ada data klien tersebut!" << endl;
        return
    }
    cout << "====== DAFTAR KLIEN ======" << endl;
    while (K != nullptr){
        cout << "ID Klien          : " << K->IDKlien << endl;
        cout << "Nama Klien        : " << K->namaKlien << endl;
        cout << "Usia              : " << K->usia << endl;
        cout << "Level Membership  : " << K->Membership << endl;
        cout << "Tujuan            : " << K->Tujuan << endl;
        cout << "----------------------" << endl;

        K = K->next;
    }
}
void showKlienDariTrainer(ListTrainer LT, string idTrainer){
    adrTrainer T = findTrainerByID(LT, idTrainer);

    if (T == nullptr){
        cout << "Trainer dengan ID: " << T->IDTrainer << "tidak dapat ditemukan!" << endl;
        return;
    cout << "Nama Trainer: " << T->namaTrainer << endl;
    cout << "Pengalaman: " << T->pengalaman << " tahun" << endl;
    cout << "Spesialisasi: " << T->spesialisasi << endl;
    cout << "====== DAFTAR KLIEN ======" << endl;

    adrLatihan L = T->firstRelasi;

    if (L == nullptr){
        cout << "Trainer ini belum memiliki klien." << endl;
        return;
    }

    while (L != nullptr){
        cout << "ID Klien         : " << L->Toklien->IDKlien << endl;
        cout << "Nama Klien       : " << L->Toklien->namaKlien << endl;
        cout << "Usia             : " << L->Toklien->usia << endl;
        cout << "Level Membership : " << L->Toklien->Membership << endl;
        cout << "Tujuan           : " << L->Toklien->Tujuan << endl;
        cout << "Jadwal Latihan   : " << L->jadwal << endl;
        cout << "Durasi Latihan   : " << L->durasi << endl;
        cout << "-------------------------------" << endl;

        L = L->next;
    }
}

void showSemuaTrainerdanKlien(ListTrainer LT){
    adrTrainer T = LT.first;

    if (T == nullptr){
        cout << "Tidak ada data trainer tersebut." << endl;
        return
    }

    cout << "======= DAFTAR TRAINER DAN KLIEN =======" << endl;

    while (T != nullptr){
        cout << "Trainer: " << T->namaTrainer << " (" << ")" << endl;
        cout << "Pengalaman: " << T->pengalaman << " tahun" endl;
        cout << "Spesialisasi: " << T->spesialisasi << endl;
        cout << endl;

        adrLatihan L = T->firstRelasi;
        int no = 1;

        if (L == nullptr){
            cout << "   Tidak memiliki klien." << endl;
        }else {
            while (L != nullptr){
                cout << "   Klien " << no++ << endl;
                cout << "   ID               : " << L->Toklien->IDKlien << endl;
                cout << "   Nama             : " << L->Toklien->namaKlien << endl;
                cout << "   Level Membership : " << L->Toklien->Membership << endl;
                cout << "   Jadwal Latihan   : " << L->jadwal << endl;
                cout << "   Durasi           : " << L->durasi << " menit" << endl;
                cout << endl;

                L = L->next;
            }
        }
        cout << "------------------------------------" << endl;
        cout << endl;
        T = T->next;
    }
}
void showKlienDenganTrainer(ListTrainer LT, ListKlien LK){
    adrKlien K = LK.first;

    if (K == nullptr){
        cout << "Tidak ada data klien." << endl;
        return;
    }

    cout << "======= DAFTAR KLIEN DAN TRAINER =======" << endl;
    cout << endl;

    while (K != nullptr){
        cout << "Klien: " << K->namaKlien << " (" << K->IDKlien <<  ")" << endl;

        adrTrainer T = LT.first;
        bool found = false;

        while (T != nullptr && !found){
            adrLatihan L = T->firstRelasi;

            while (L != nullptr){
                if (L->Toklien->IDKlien == K->IDKlien){
                    cout << "Dilatih oleh:" << endl;
                    cout << "   Trainer : " << T->namaTrainer << endl;
                    cout << "   Jadwal  : " << L->jadwal << endl;
                    cout << "   Durasi  : " << L->durasi << " menit" << endl;
                    found = true;
                    break;
                }
                L = L->next;
            }
            T = T->next;
        }
        if (!found){
            cout << "   Belum memiliki trainer." << endl;
        }
        cout << "---------------------------------------" << endl;
        cout << endl;
        K = K->next;
    }
}
void showTrainerDariKlien(ListTrainer LT, string idKlien){
    adrTrainer T = LT.first;
    bool found = false;

    cout << "====== TRAINER DARI KLIEN ======" << endl;
    cout << endl;

    while (T != nullptr && !found){
        adrLatihan L = T->firstRelasi;

        while (L != nullptr){
            if (L->Toklien->IDKlien == idKlien){
                cout << "Trainer : " << T->namaTrainer << endl;
                cout << "Jadwal  : " << L->jadwal << endl;
                cout << "Durasi  : " << L->durasi << " menit" << endl;
                found = true;
                break;
            }
            L = L->next;
        }
        T = T->next;
    }
    if (!found){
        cout << "Klien dengan ID" << idKlien << " belum memiliki trainer atau tidak ditemukan." << endl;
    }
}

void countRelasiSetiapTrainer(ListTrainer LT);  //membuat prosedur count relasi dari tiap trainer
void countRelasiKlienTertentu(ListTrainer LT, string idKlien);  //membuat prosedur count dari relasi klien tertentu
void countKlienTanpaRelasi(ListTrainer LT, ListKlien LK);   //membuat prosedur count klien tanpa relasi
void editLatihan(ListTrainer LT, string idTrainer, string idKLien, string jadwalBaru, int durasiBaru);  //membuat prosedur edit latihan
