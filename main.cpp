#include <iostream>
#include <string>
#include <vector>
#include <fstream>
class Urun {
public:
    int id;
    string ad;
    float fiyat;
    Urun* next;
    Urun(int id=0, string ad="", float fiyat=0.0f) : id(id), ad(ad), fiyat(fiyat), next(nullptr) {}
    // Ekrana veya dosyaya yazdırma operatörü
friend ostream& operator<<(ostream& os, const Urun& u) {
    os << u.id << " " << u.ad << " " << u.fiyat;
    return os;
}

// Dosyadan okuma operatörü
friend istream& operator>>(istream& is, Urun& u) {
    is >> u.id >> u.ad >> u.fiyat;
    return is;
}
};

#include <iomanip>
#include <algorithm>

using namespace std;

class VeritabaniModern {
private:
    vector<Urun> urunler; 

public:

    void kaydet() {
    ofstream dosya("veritabani.txt"); 
    for (const auto& u : urunler) {
        dosya << u.id << " " << u.ad << " " << u.fiyat << endl;
    }
    dosya.close();
    cout << ">> Veriler metin formatinda kaydedildi." << endl;
    }

    void ekle(int id, string ad, float fiyat) {
        for (const auto& u : urunler) {
            if (u.id == id) {
                cout << "Hata: ID zaten mevcut!" << endl;
                return;
            }
        }
        urunler.push_back(Urun(id, ad, fiyat));
        cout << "Basarili: " << ad << " eklendi." << endl;
    }
    
    void listele() {
        if (urunler.empty()) {
            cout << "Liste bos!" << endl;
            return;
        }
        for (const auto& u : urunler) {
            cout << "ID: " << u.id << " | Ad: " << u.ad << " | Fiyat: " << u.fiyat << endl;
        }
    }

    void sil(int id) {
        auto before = urunler.size();
        urunler.erase(std::remove_if(urunler.begin(), urunler.end(),
            [id](const Urun& u){ return u.id == id; }), urunler.end());
        if (urunler.size() < before) cout << "Basarili: Urun silindi." << endl;
        else cout << "Urun bulunamadi!" << endl;
    }
    };

class Veritabani {
private:
    Urun* head; 
public:
    Veritabani() { head = nullptr; } 

    void ekle(int id, string ad, float fiyat);
    void listele();
        ~Veritabani() {
        Urun* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp; 
        }
        cout << "Sistem: Bellek otomatik temizlendi." << endl;
    }
    void Veritabani::ekle(int id, string ad, float fiyat) {
    Urun* temp = head;
    while (temp != nullptr) {
        if (temp->id == id) {
            cout << "Hata: ID zaten mevcut!" << endl;
            return;
        }
        temp = temp->next;
    }

    Urun* yeni = new Urun(id, ad, fiyat);

    if (head == nullptr) {
        head = yeni;
    } else {
        Urun* son = head;
        while (son->next != nullptr) son = son->next;
        son->next = yeni;
    }
    cout << "Basarili: " << ad << " eklendi." << endl;
}
};

void Veritabani::listele() {
    Urun* temp = head;
    if (temp == nullptr) {
        cout << "\nListe su an bos!" << endl;
        return;
    }
    cout << "\n--- GUNCEL STOK LISTESI ---" << endl;
    while (temp != nullptr) {
        cout << "ID: " << temp->id
             << " | Ad: " << temp->ad
             << " | Fiyat: " << fixed << setprecision(2) << temp->fiyat << " TL" << endl;
        temp = temp->next;
    }
}
int main() {
    Veritabani db; 
    
    db.ekle(1, "SSD", 1200.50);
    db.ekle(2, "RAM", 800.00);
    db.listele(); 

    return 0; 
}