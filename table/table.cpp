#include "table.h"

template<class T>
Table<T>::Table(int r, int c) : rows(r), cols(c) {
    int size = rows * cols;
    
    if (size == 0) {
        data = nullptr;
    } else {
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = T();
        }

    }

}

template<class T>
Table<T>::Table(const Table& other) : rows(other.rows), cols(other.cols) {
    int size = rows * cols;
    
    if (size == 0) {
        data = nullptr;
    } else {
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

    }

}

template<class T>
Table<T>& Table<T>::operator=(const Table& other) {
    if (this == &other) return *this;
    
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    int size = rows * cols;
    if (size == 0) {
        data = nullptr;
    } else {
        data = new T[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }

    }

    return *this;
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
    if (col < 0 || col >= cols) {
        throw std::out_of_range("Index out of array");
    }

    return row_data[col];
}

template<class T>
const T& Table<T>::RowProxy::operator[](int col) const {
    if (col < 0 || col >= cols) {
        throw std::out_of_range("Index out of array");
    }

    return row_data[col];
}

template<class T>
Table<T>::ConstRowProxy::ConstRowProxy(const T* new_row_data)
    : row_data(new_row_data){}

template<class T>
const T& Table<T>::ConstRowProxy::operator[](int col) const {
    return row_data[col];
}

template<class T>
typename Table<T>::RowProxy Table<T>::operator[](int row) {
    if (row < 0 || row >= rows) {
        throw std::out_of_range("Index out of array");
    }

    return RowProxy(data + row * cols, cols);
}

template<class T>
typename Table<T>::ConstRowProxy Table<T>::operator[](int row) const {
    if (row < 0 || row >= rows) {
        throw std::out_of_range("Index out of array");
    }

    return ConstRowProxy(data + row * cols);
}

template class Table<int>;