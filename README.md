# Migration of a Database Engine: From C to C++ 

Bu proje, C dilinde **Linked List**  ve **Binary File I/O** kullanılarak geliştirilmiş, dinamik bir stok yönetim veritabanı motorudur.

##  Özellikler
- **Dinamik Bellek Yönetimi:** `malloc` ve `free` ile çalışma anında bellek tahsisi.
- **Kalıcı Depolama:** Verileri ikili (binary) formatta `.bin` dosyasına kaydeder ve geri yükler.
- **Güvenli Giriş Sistemi:** `fgets` ve `strtol` ile buffer overflow hataları engellenmiştir.
- **CRUD Operasyonları:** Veri ekleme, silme, listeleme ve dosya yönetimi.
