#ifndef NODE_H
#define NODE_H

using namespace std;

template <class T>
class Node {

  int x, y;

  public:
    Node* next=nullptr;
    Node* down=nullptr;

    T data;

    Node(int _x, int _y, T _data):x(_x),y(_y),data(_data){}
    Node(int _x): x(_x){}

    int getXData(){
      return x;
    }

    int getYData(){
      return y;
    }

    T getData(){
      return data;
    }

};

#endif
