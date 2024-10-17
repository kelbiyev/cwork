#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <iostream>
#include <stdexcept>
template <typename T>
class Matrix {
private:
	void MakeRectangle();
	std::vector<std::vector<T>> data;
public:
	size_t GetRows() const;
	size_t GetColumns() const;
	Matrix(const std::vector<std::vector<T>>& d);
	Matrix(size_t rows, size_t columns){
		data.resize(rows);
		for (auto& row:data){
			row.resize(columns);
		}
	}
	/*
	const std::vector<T>& operator[] (size_t i) const{
		return data[i];
	}
	std::vector<T>& operator[] (size_t i) {
		return data[i];
	}
	*/
	T& operator() (size_t i , size_t j){
		return data[i][j];
	}
	const T& operator() (size_t i , size_t j) const{
		return data[i][j];
	}
};
template <typename T>
std::ostream& operator<< (std::ostream& out , const Matrix<T>& matrix){
	const size_t rows = matrix.GetRows();
	const size_t columns = matrix.GetColumns();
	for(size_t i = 0; i != rows; ++i){
		for(size_t j = 0; j != columns; ++j){
			if(j>0){
				out<<"\t";
			}
			out<<matrix(i,j);
		}
		out<<"\n";
	}
	return out;
}
template <typename T>
std::istream& operator>> (std::istream& in , const Matrix<T>& matrix){
	const size_t rows = matrix.GetRows();
	const size_t columns = matrix.GetColumns();
	for(size_t i = 0; i != rows; ++i){
		for(size_t j = 0; j != columns; ++j){
			in >> matrix(i,j);
		}
	}
	return in;
}

#include "matrix.hpp"
#endif //MATRIX_H

