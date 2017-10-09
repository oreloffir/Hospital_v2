#include "LinkedList.h"

LinkedList<class T>::Node::Node(T& data, Node* next) : data(data), next(next) {}
LinkedList<class T>::Node::~Node() {}