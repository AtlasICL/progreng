#include <iostream>

class intvector {

public:
  intvector() {
    m_size = 0;
    m_capacity = 1;
    p = new int[m_capacity];
  }

  void push_back(int n) {

    if (m_capacity <= m_size) {
      m_capacity = m_capacity * 2;

      int *tmp_p;
      tmp_p = new int[m_capacity];

      for (int i = 0; i < m_size; i++) {
        tmp_p[i] = p[i];
      }

      delete p;
      p = tmp_p;
    }

    p[m_size] = n;
    m_size++;
  }

  int size() const { return m_size; }

  int capacity() const { return m_capacity; }

  int at(int i) const { return p[i]; }

  ~intvector() { delete[] p; }

  intvector(const intvector &v) {
    m_capacity = v.m_capacity;
    m_size = v.m_size;

    p = new int[m_capacity];

    for (int i = 0; i < m_size; i++) {
      p[i] = v.p[i];
    }

    std::cout << "--copy constructor called--" << std::endl;
  }

  // assignment operator
  // (see explanation in exercise below)

  intvector &operator=(const intvector &v) {

    // first of all we check whether this is being called
    // during a reflexive assignment
    // that is something such as a = a;

    // if yes we don't do anything
    // otherwise we enter the if statement

    if (this == &v) {
      return *this;
    }

    if (this != &v) {

      delete[] p;

      m_capacity = v.m_capacity;
      m_size = v.m_size;

      p = new int[m_capacity];

      for (int i = 0; i < m_size; i++) {
        p[i] = v.p[i];
      }
    }
    return *this;
  }

private:
  int *p;
  int m_size;
  int m_capacity;
};

int main() {
  intvector iv1;

  for (int i = 0; i < 9; i++) {
    iv1.push_back(i);
    std::cout << i << " was added" << std::endl;
    std::cout << "size: " << iv1.size() << std::endl;
    std::cout << "capacity: " << iv1.capacity() << std::endl;
  }

  std::cout << std::endl << "printing iv1: " << std::endl;

  for (int i = 0; i < iv1.size(); i++) {
    std::cout << iv1.at(i) << std::endl;
  }

  std::cout << std::endl;

  // calling the copy constructor
  intvector iv2(iv1);

  // calling the assignment operator
  intvector iv3;
  iv3.operator=(iv1);

  iv1.push_back(9);

  std::cout << "printing iv1:" << std::endl;

  for (int i = 0; i < iv1.size(); i++) {
    std::cout << iv1.at(i) << std::endl;
  }

  std::cout << std::endl;

  std::cout << "printing iv2:" << std::endl;

  for (int i = 0; i < iv2.size(); i++) {
    std::cout << iv2.at(i) << std::endl;
  }

  std::cout << std::endl;

  std::cout << "printing iv3:" << std::endl;

  for (int i = 0; i < iv3.size(); i++) {
    std::cout << iv3.at(i) << std::endl;
  }

  std::cout << std::endl;
}