#pragma once

#include <utility>

template<class T>
class Table {
private:
    T* data;
    int rows;
    int cols;

public:
    Table(int r, int c);
    ~Table();
    std::pair<int, int> Size() const;

    class RowProxy {
    private:
        T* row_data;
        int cols;
    public:
        RowProxy(T* new_row_data, int c);
        T& operator[](int col);
        const T& operator[](int col) const;
    };

    class ConstRowProxy {
    private:
        const T* row_data;
        int cols;
    public:
        ConstRowProxy(const T* new_row_data, int c);
        const T& operator[](int col) const;
    };

    RowProxy operator[](int row);
    ConstRowProxy operator[](int row) const;
};