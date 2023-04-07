//1220505011 AYÞE GÜL DAL
// PRE-ORDER GEÇÝÞÝYLE AÐAÇ OLUÞTURMA VE KÖK DÖNDÜRME


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {     //Düðüm oluþturuluyor.
    int data;   //Veri tanýmlandý.
    struct Node* left;    //Düðümün solu.
    struct Node* right;   //Düðümün saðý.
} Node;

Node* dugumOlustur(int data) {    //Yeni düðüm oluþturuluyor.
    Node* newNode = (Node*)malloc(sizeof(Node));  //Yeni düðüm için alan ayýrýldý.
    newNode->data = data;  //Girilen data yeni düðümün datasýna tanýmlandý.
    newNode->left = NULL;   //Yeni düðümün solu NULL.
    newNode->right = NULL;  //Yeni düðümün saðý NULL.
    return newNode;           //Yeni düðüm döndürülür.
}

Node* solaDondur(Node* node) {   //Sola döndürme fonksiyonu.
    Node* newRoot = node->right;   //Kökün saðýný yeni köke ata.
    node->right = newRoot->left;   //Yeni kökün solunu kökün saðýna ata.
    newRoot->left = node;          //Kökü yeni kökün soluna ata.
    return newRoot;            //Yeni kökü döndür.
}

Node* sagaDondur(Node* node) {        //Saða döndürme fonksiyonu.
    Node* newRoot = node->left;    //Kökün solunu yeni köke ata.
    node->left = newRoot->right;   //Yeni kökün saðýný kökün soluna ata.
    newRoot->right = node;        //Kökü yeni kökün saðýna ata.
    return newRoot;               //Yeni kökü döndür.
}

void preorderDonus(Node* root) {      //Preoreder tipiyle geçiþ.
    if (root == NULL) {       //Kök boþ ise döngü sonlanýr.
        return;
    }
    printf("%d ", root->data);    //Kökün verisini yazdýr.
    preorderDonus(root->left);    //Kökün solunu tekrar preorderDonus fonksiyonuna sok.
    preorderDonus(root->right);    //Kökün saðýný tekrar preorderDonus fonksiyonuna sok.
}

int main() {
	//Döndürülecek deðerler girilir.
    Node* root = dugumOlustur(4);   
    root->left = dugumOlustur(2);
    root->right = dugumOlustur(6);
    root->left->left = dugumOlustur(1);
    root->left->right = dugumOlustur(3);
    root->right->left = dugumOlustur(5);
    root->right->right = dugumOlustur(7);

    printf("Sola Dondurmeden once:");
    preorderDonus(root);        //Ýlk haliyle yazdýrma.

    root = solaDondur(root);    //Sola döndürme iþlemi.

    printf("\nSola Dondurmeden Sonra: ");
    preorderDonus(root);        //Sola döndürerek yazdýrma.

    printf("\nSaga Dondurmeden Once: ");
    preorderDonus(root);        //Bir önceki hali.

    root = sagaDondur(root);    //Saða döndürme iþlemi.

    printf("\nSaga Dondurdukten Sonra: ");
    preorderDonus(root);        //Saða döndürdükten sonra yazdýrma.

    return 0;
}






















