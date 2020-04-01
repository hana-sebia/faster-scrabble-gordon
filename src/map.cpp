#include <cstring>
#include "map.hpp"
#include <iostream>


Node::Node() {
  this->is_final = false;
  for (unsigned int i = 0; i < 27; i++) {
    this->tab[i] = nullptr;
  }
}


Node::~Node() {
  Node * temp = this;
  for(unsigned int i = 0; i < 27; i++) {
    delete temp->tab[i];
    temp->tab[i] = nullptr;
  }
}



Node* Node::getNode(const unsigned short int & i) const {
  if (i < 27)
    return tab[i];
  if (i == static_cast<unsigned int>('+'))
    return tab[26];
  if (i - 'A' < 26)
    return tab[i - 'A'];

  return nullptr;
}


bool Node::isFinal() const {
  return is_final;
}


Node* Node::addNode(const bool & b) {
  Node * ptr = new Node();
  ptr->is_final = b;
  for (unsigned int i = 0 ; i < 27; i++) {
      ptr->tab[i] = nullptr;
  }
  return ptr;
}


void Node::addNode(const std::string & s) {
  unsigned int i = 0, size = s.size();
  unsigned short int c;
  Node * tmp = this;

  for (i = 0; i < size; i++) {
    if (s[i] > 'Z' || s[i] < 'A')
      c = 'Z' - 'A' + 1;
    else
      c = s[i] - 'A';
    if (tmp->tab[c] == nullptr)
      tmp->tab[c] = addNode( (i == size - 1) );

    tmp = tmp->tab[c];
  }
}
