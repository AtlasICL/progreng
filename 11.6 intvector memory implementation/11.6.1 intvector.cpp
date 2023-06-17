#include <iostream>

typedef int vector_type;

class vector
{

public:
  vector()
  {
    m_size = 0;
    m_capacity = 1;
    p = new vector_type[m_capacity];
  }

  void push_back(vector_type n)
  {
    if (m_capacity <= m_size)
    {
      m_capacity = 2 * m_capacity;
      vector_type* tmp = new vector_type[m_capacity];

      for (int i = 0; i < m_size; ++i)
      {
        tmp[i] = p[i];
      }

      delete[] p;
      p = tmp;
    }

    p[m_size] = n;
    m_size++;
  }

  int size() const { return m_size; }

  int capacity() const { return m_capacity; }

  vector_type at(int i) const { return p[i]; }

  ~vector() { delete[] p; }

  vector(const vector& vin)
  {
    m_capacity = vin.capacity();
    m_size = vin.size();
    p = new int[m_capacity];
    for (int i = 0; i<m_size; i++)
    {
      p[i] = vin.p[i];
    }
  }

  vector &operator=(const vector& vin)
  {
    if (this == &vin)
    {
      return *this;
    }

    else
    {
      delete[] p;
      m_capacity = vin.capacity();
      m_size = vin.size();

      p = new int[m_capacity];
      for (int i = 0; i<m_size; i++){
        p[i] = vin.p[i];
      } 
    }
    return *this;
  }

private:
  int m_size;
  int m_capacity;
  vector_type* p;
};

int main() {
  vector iv1;

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
  vector iv2(iv1);

  // calling the assignment operator
  vector iv3;
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