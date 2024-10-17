#ifndef MATRIX_HPP
#define MATRIX_HPP
#include "matrix.h"
#include <stdexcept>

template <typename T>
size_t Matrix<T>::GetRows() const{
	return data.size();
}

template <typename T>
size_t Matrix<T>::GetColumns() const{
	if (data.empty())
		return 0;
	
	return data[0].size();
}
template <typename T>
void Matrix<T>::MakeRectangle(){
	size_t maxSize = 0;
	for (const auto& row: data){
		if(row.size() > maxSize){
			maxSize = row.size();
		}
	}
	
	for(auto& row:data){
		row.resize(maxSize);
	}
}

template <typename T>
Matrix<T>::Matrix(const std::vector<std::vector<T>>& d): data {d} {
	MakeRectangle();

}


/*
template <typename T>
Matrix<T>::Matrix(size_t rows, size_t columns){
	data.resize(rows);
	for (auto& row:data){
		row.resize(data);
	}
}
*/
template <typename T>
Matrix<T>& operator+=(const Matrix<T>& other){
	const size_t rows = GetRows();
	const size_t columns = GetColumns();
	if(rows != other.GetRows() || columns != other.GetColumns()){
		throw std::invalid_argument("Different sizes");
	}
	for(size_t i = 0; i!= rows; ++i){
		for(size_t i = 0; i!= rows; ++i){
			data(i,j) += other.data(i,j);
		}
	}
	return *this;
} 

template <typename T>
Matrix<T> operator+ (const Matrix<T>& m1 , const Matrix<T>& m2){
	auto tmp {m1};
	tmp += m2;
	return tmp;
}

template <typename T1>
bool operator== (const Matrix<T1>& other) const {
	const size_t rows = GetRows();
	const size_t columns = GetColumns();
	if(rows != other.GetRows() || columns != other.GetColumns()){
		return false;
	}
	for (size_t i = 0; i != rows; ++i){
		for(size_t j = 0; j != columns; ++j){
			if(!((*this)(i,j) == other(i,j))){
				return false;
			}
		}
	}
	return true;
}

template <typename T1>
template <typename T2>
bool operator!= (const Matrix<T1>& m1, const Matrix<T2>& m2){
	return !(m1 == m2);
}

#endif //MATRIX_HPP

