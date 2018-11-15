#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix {
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;

    public:
        Matrix();
        Matrix(int sizeX, int sizeY){
          columns=sizeX;
          rows=sizeY;

          hRows = new Node<T>(0);
          hColumns = new Node<T>(0);
          Node<T>* TmpR=hRows;
          Node<T>* TmpC=hColumns;

          for(int i=1; i<sizeX; i++){
            Node<T>* TmpX = new Node<T>(i);
            TmpC->next = TmpX;
            TmpC = TmpX;
          }

          for(int i=1; i<sizeY; i++){
            Node<T>* TmpY = new Node<T>(i);
            TmpR->down = TmpY;
            TmpR = TmpY;
          }
        };

        void set(int x, int y, T data){ //crear, modificar, si data 0 se borra
          Node<T>* TmpR=hRows;
          Node<T>* TmpC=hColumns;
          Node<T>* newNode = new Node<T>(x, y, data);

          for(int i=0; i<columns; i++){
            if(x==i){
              while(TmpC->down && y > TmpC->down->getYData()){
                TmpC=TmpC->down;
              }
              if(TmpC->down){newNode->down = TmpC->down;}
              TmpC->down = newNode;
              break;
            }
            else{TmpC=TmpC->next;}
          }

          for(int j=0; j<rows; j++){
            if(y==j){
              while( TmpR->next && x > TmpR->next->getXData() ){
                TmpR=TmpR->next;
              }
              if(TmpR->next){newNode->next = TmpR->next;}
              TmpR->next = newNode;
              break;
            }
            else{TmpR=TmpR->down;}
          }

        };

        T operator()(int x, int y){
          Node<T>* TmpC=hColumns;

          if(x<=columns && x>= 0 && y<=rows && y>=0){

            for(int i=0; i<columns; i++){
              if(x==i){
                while(TmpC->down && y>TmpC->down->getYData()){
                  TmpC=TmpC->down;
                }
                cout << TmpC->down->getXData() << " " << TmpC->down->getYData() << endl;
                if(TmpC->down->getXData()==x && TmpC->down->getYData()==y){
                  cout << "wo";
                  return TmpC->down->getData();
                  break;
                }
                else{cout << "hi";}
              }
              else{TmpC=TmpC->next;}
            }

          }
          else{throw "error";}
        };

        Matrix<T> operator*(Matrix<T> other); //multiplica dos matrices
        Matrix<T> operator*(T scalar); //multiplca la matriz por un escalar
        Matrix<T> operator+(Matrix<T> other); //suma
        Matrix<T> operator-(Matrix<T> other); //resta
        Matrix<T> transposed(); //transposed

        Matrix<T> operator=(Matrix<T> other){
          Node<T>* tempY = hRows;

          if(columns==other.columns && rows==other.rows){
          }
          else{throw "error";}
        }; //igualar una matriz a otra

        void print() {
         Node<T>* tempY = hRows;
         while (tempY) {
             Node<T>* tempX = tempY;
             while (tempX->next) {
                 tempX = tempX->next;
                 cout << tempX->getXData() << "," << tempX->getYData() << "," << tempX->getData() << " ";
             }
             tempY = tempY->down;
             cout << endl;
         }
         Node<T>* temp = hColumns->down;
         cout << "value of X: " << temp->down->getXData() << " value of Y: " << temp->down->getYData();
       }

        //~Matrix();
};

#endif
