//1220505011 AY�E G�L DAL
// PRE-ORDER GE����YLE A�A� OLU�TURMA VE K�K D�ND�RME


#include <stdio.h>
#include <stdlib.h>

typedef struct Node {     //D���m olu�turuluyor.
    int data;   //Veri tan�mland�.
    struct Node* left;    //D���m�n solu.
    struct Node* right;   //D���m�n sa��.
} Node;

Node* dugumOlustur(int data) {    //Yeni d���m olu�turuluyor.
    Node* newNode = (Node*)malloc(sizeof(Node));  //Yeni d���m i�in alan ay�r�ld�.
    newNode->data = data;  //Girilen data yeni d���m�n datas�na tan�mland�.
    newNode->left = NULL;   //Yeni d���m�n solu NULL.
    newNode->right = NULL;  //Yeni d���m�n sa�� NULL.
    return newNode;           //Yeni d���m d�nd�r�l�r.
}

Node* solaDondur(Node* node) {   //Sola d�nd�rme fonksiyonu.
    Node* newRoot = node->right;   //K�k�n sa��n� yeni k�ke ata.
    node->right = newRoot->left;   //Yeni k�k�n solunu k�k�n sa��na ata.
    newRoot->left = node;          //K�k� yeni k�k�n soluna ata.
    return newRoot;            //Yeni k�k� d�nd�r.
}

Node* sagaDondur(Node* node) {        //Sa�a d�nd�rme fonksiyonu.
    Node* newRoot = node->left;    //K�k�n solunu yeni k�ke ata.
    node->left = newRoot->right;   //Yeni k�k�n sa��n� k�k�n soluna ata.
    newRoot->right = node;        //K�k� yeni k�k�n sa��na ata.
    return newRoot;               //Yeni k�k� d�nd�r.
}

void preorderDonus(Node* root) {      //Preoreder tipiyle ge�i�.
    if (root == NULL) {       //K�k bo� ise d�ng� sonlan�r.
        return;
    }
    printf("%d ", root->data);    //K�k�n verisini yazd�r.
    preorderDonus(root->left);    //K�k�n solunu tekrar preorderDonus fonksiyonuna sok.
    preorderDonus(root->right);    //K�k�n sa��n� tekrar preorderDonus fonksiyonuna sok.
}

int main() {
	//D�nd�r�lecek de�erler girilir.
    Node* root = dugumOlustur(4);   
    root->left = dugumOlustur(2);
    root->right = dugumOlustur(6);
    root->left->left = dugumOlustur(1);
    root->left->right = dugumOlustur(3);
    root->right->left = dugumOlustur(5);
    root->right->right = dugumOlustur(7);

    printf("Sola Dondurmeden once:");
    preorderDonus(root);        //�lk haliyle yazd�rma.

    root = solaDondur(root);    //Sola d�nd�rme i�lemi.

    printf("\nSola Dondurmeden Sonra: ");
    preorderDonus(root);        //Sola d�nd�rerek yazd�rma.

    printf("\nSaga Dondurmeden Once: ");
    preorderDonus(root);        //Bir �nceki hali.

    root = sagaDondur(root);    //Sa�a d�nd�rme i�lemi.

    printf("\nSaga Dondurdukten Sonra: ");
    preorderDonus(root);        //Sa�a d�nd�rd�kten sonra yazd�rma.

    return 0;
}






















