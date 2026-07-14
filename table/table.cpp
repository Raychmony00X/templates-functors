#include "table.h"

template<class T>
Table<T>::Table(int r, int c) : rows(r), cols(c) {
    data = new T[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = T();
    }
}

template<class T>
Table<T>::~Table() {
    delete[] data;
}

template<class T>
std::pair<int, int> Table<T>::Size() const {
    return { rows, cols };
}

template<class T>
Table<T>::RowProxy::RowProxy(T* new_row_data, int c)
    : row_data(new_row_data), cols(c) {
}

template<class T>
T& Table<T>::RowProxy::operator[](int col) {
    return row_data[col];
}

template<class T>
const T& Table<T>::RowProxy::operator[](int col) const {
    return row_data[col];
}

template<class T>
Table<T>::ConstRowProxy::ConstRowProxy(const T* new_row_data, int c)
    : row_data(new_row_data), cols(c) {
}

template<class T>
const T& Table<T>::ConstRowProxy::operator[](int col) const {
    return row_data[col];
}

template<class T>
typename Table<T>::RowProxy Table<T>::operator[](int row) {
    return RowProxy(data + row * cols, cols);
}

template<class T>
typename Table<T>::ConstRowProxy Table<T>::operator[](int row) const {
    return ConstRowProxy(data + row * cols, cols);
}

template class Table<int>;