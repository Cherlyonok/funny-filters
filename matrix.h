//
// Created by Timofey Cherlenok on 09.03.2023.
//

#pragma once
#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include "utility"
struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
template <typename T>
class Matrix {
public:
    class Row {
        friend class Matrix<T>;

    public:
        T& operator[](size_t col_num) {
            return (*matrix_)(num_, col_num);
        }
        size_t Size() const {
            return matrix_->GetColsNum();
        }

    private:
        Row(Matrix<T>* m, size_t num) : num_(num), matrix_(m) {
        }

    private:
        size_t num_;
        Matrix<T>* matrix_;
    };
    class ConstRow {
        friend class Matrix<T>;

    public:
        T operator[](size_t col_num) const {
            return matrix_->operator()(num_, col_num);
        }
        size_t Size() const {
            return matrix_->GetColsNum();
        }

    private:
        ConstRow(const Matrix<T>* m, size_t num) : num_(num), matrix_(m) {
        }

    private:
        size_t num_;
        const Matrix<T>* matrix_;
    };
    class Col {
        friend class Matrix<T>;

    public:
        T& operator[](size_t row_num) {
            return (*matrix_)(row_num, num_);
        }
        size_t Size() const {
            return matrix_->GetRowsNum();
        }

    private:
        Col(Matrix<T>* m, size_t num) : num_(num), matrix_(m) {
        }

    private:
        size_t num_;
        Matrix<T>* matrix_;
    };
    class ConstCol {
        friend class Matrix<T>;

    public:
        T operator[](size_t row_num) const {
            return (*matrix_)(row_num, num_);
        }
        size_t Size() const {
            return matrix_->GetRowsNum();
        }

    private:
        ConstCol(const Matrix<T>* m, size_t num) : num_(num), matrix_(m) {
        }

    private:
        size_t num_;
        const Matrix* matrix_;
    };

public:
    Matrix(size_t rows_num, size_t cols_num, T def) {
        if (rows_num == 0 && cols_num == 0) {
            rows_num_ = 0;
            cols_num_ = 0;
            table_ = nullptr;
            return;
        }
        if (rows_num == 0 || cols_num == 0) {
            throw std::invalid_argument("no 0 rows or columns pls");
        }
        rows_num_ = rows_num;
        cols_num_ = cols_num;
        table_ = AllocateMatrix(rows_num_, cols_num_);
        for (size_t i = 0; i < rows_num; ++i) {
            for (size_t j = 0; j < cols_num; ++j) {
                this->operator()(i, j) = def;
            }
        }
    }

    ~Matrix() {
        Clear();
    }
    Matrix(const Matrix<T>& other) {  // other
        rows_num_ = other.GetRowsNum();
        cols_num_ = other.GetColsNum();
        table_ = AllocateMatrix(rows_num_, cols_num_);
        for (size_t i = 0; i < rows_num_; ++i) {
            for (size_t j = 0; j < cols_num_; ++j) {
                this->operator()(i, j) = other[i][j];
            }
        }
    }
    Matrix<T>& operator=(const Matrix<T>& rhv) {  // copy and swap - проверка что они не одинаковые - rhv
        if (this == &rhv) {
            return *this;
        }
        Matrix<T> tmp(rhv);
        this->Swap(tmp);
        return *this;
    }
    T operator()(size_t i, size_t j) const {
        return GetIJEl(table_, i, j, cols_num_);
    }

    T& operator()(size_t i, size_t j) {
        return GetIJEl(table_, i, j, cols_num_);
    }

    Row operator[](size_t i) {
        return {this, i};
    }
    ConstRow operator[](size_t i) const {
        return ConstRow(this, i);
    }
    T At(size_t i, size_t j) const {
        if (i < rows_num_ && j < cols_num_) {
            return this->operator()(i, j);
        }
        throw std::out_of_range("invalid matrix index IOJ");
    }
    T& At(size_t i, size_t j) {
        if (i < rows_num_ && j < cols_num_) {
            return this->operator()(i, j);
        }
        throw std::out_of_range("invalid matrix index IOJ");
    }
    void Swap(Matrix<T>& tmp) {
        std::swap(rows_num_, tmp.rows_num_);
        std::swap(cols_num_, tmp.cols_num_);
        std::swap(table_, tmp.table_);
    }

public:
    void Clear() {
        if (!table_) {
            return;
        }
        delete[] table_;
        rows_num_ = 0;
        cols_num_ = 0;
    }
    void Resize(size_t new_rows_num, size_t new_cols_num, T def) {

        if (new_cols_num == 0 && new_rows_num == 0) {
            Clear();
            return;
        }

        if (new_rows_num == 0 || new_cols_num == 0) {
            throw std::invalid_argument("no 0 rows or columns pls");
        }

        T* new_table = AllocateMatrix(new_rows_num, new_cols_num);
        for (size_t i = 0; i < new_rows_num; ++i) {
            for (size_t j = 0; j < new_cols_num; ++j) {
                if (i < std::min(rows_num_, new_rows_num) && j < std::min(cols_num_, new_cols_num)) {
                    GetIJEl(new_table, i, j, new_cols_num) = GetIJEl(table_, i, j, cols_num_);
                } else {
                    GetIJEl(new_table, i, j, new_cols_num) = def;
                }
            }
        }
        delete[] table_;
        table_ = new_table;
        rows_num_ = new_rows_num;
        cols_num_ = new_cols_num;
    }

    static T& GetIJEl(T* arr, size_t i, size_t j, size_t cols_num) {
        return arr[i * cols_num + j];
    }
    size_t GetColsNum() const {
        return cols_num_;
    }

    size_t GetRowsNum() const {
        return rows_num_;
    }

    T* GetPtr() {
        return table_;
    }

    const T* GetPtr() const {
        return table_;
    }

private:
    static T* AllocateMatrix(size_t rows_n, size_t cols_n) {
        T* ans = new T[rows_n * cols_n];
        return ans;
    }

private:
    T* table_;
    size_t rows_num_;
    size_t cols_num_;
};
