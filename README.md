# Pre-order-tipi-gecisiyle-Ikili-Arama-Agaci-Olusturma.-BST-
BST'nin (yani ikili arama ağacının) ön sıralı geçişini temsil eden bir dizi tamsayı verildiğinde, ağacı oluşturma ve kökünü döndürme işlemi yapar.

# PROJENİN AMACI VE NASIL KULLANILDIĞI
Bu algoritmada verilen sayıları pre-order geçiş tipiyle ağacı oluşturma ve bu ağacın kökünü döndürme gösterilmiştir.
İlk önce struct düğüm oluşturulur.Düğümün verisi,sağı,solu tanımlanır.Dugum olusturmak için fonksiyon tanımlanır. 

Bu fonksiyon içinde:Yeni düğüme alan tanımlanır, parametre olarak alınan veri yeni düğümün datasına atanır ve yeni düğümün sağı ve solu NULL'a eşitlenir.

Daha sonra sağa ve sola döndürme fonksiyonları ayrı ayrı tanımlanır.
Preorder geçiş tipiyle oluşturcağımız için preorderDonus fonksiyonu oluşturulur.Ve kökler preorder tipiyle yazdırılır.

Son olarak main fonksiyonu içerisinde kökü döndürülecek sayılar yazılır.


# KULLANILAN FONKSİYONLAR
**typedef struct Node**:Düğüm oluşturma yapısıdır.

**Node dugumOlustur**: Düğüm oluşturma fonksiyonudur.
**Node solaDondur**:Sola döndürme fonksiyonudur.
**Node sagaDondur**:Sağa döndürme fonksiyonudur.

Kullanılan structların dışında:

**void preorderDonus**: Ağacı pre-order tipi geçişiyle oluşturmayı sağlar.Eğer kök NULL ise return 0 döndürür. Ve kökün solunu,sağını tekrar preorderDonus fonksiyonuna gönderir.

# NASIL TEST EDİLİR?
Bu algoritma girilen sayılarla pre orde geçiş tipiyle ağacı oluşturur ve kökünü döndürür.

Örnek: 4 2 1 3 6 5 7 sayıları gerekli yerlere yazılırsa,

Sola Dondurmeden Sonra: 6 4 2 1 3 5 7

Saga Dondurmeden Once: 6 4 2 1 3 5 7

Saga Dondurdukten Sonra: 4 2 1 3 6 5 7

  Şeklinde ekrana yazılır. 



