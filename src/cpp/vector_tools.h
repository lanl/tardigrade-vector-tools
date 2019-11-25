/******************************************************************************
*                              vector_tools.h                                 *
===============================================================================
* A collection of functions and related utilities intended to help perform    *
* vector operations in cpp.                                                   *
*******************************************************************************
*/

#ifndef VECTOR_TOOLS_H
#define VECTOR_TOOLS_H

#include<stdio.h>
#include<iostream>
#include<exception>
#include<fstream>
#include<vector>
#include<map>
#include<math.h>
#include<assert.h>
#include<string.h>
#include<numeric>
#include<algorithm>

#ifdef USE_EIGEN
    #include<Eigen/Dense>
#endif

//Operator overloading
template<typename T>
std::vector<T>& operator+=(std::vector<T> &lhs, const std::vector<T> &rhs);

template<typename T>
std::vector<T> operator+(std::vector<T> lhs, const std::vector<T> &rhs);

template<typename T>
std::vector<T> operator-(std::vector<T> v);

template<typename T>
std::vector<T>& operator-=(std::vector<T> &lhs, const std::vector<T> &rhs);

template<typename T>
std::vector<T> operator-(std::vector<T> lhs, const std::vector<T> &rhs);

template<typename T, typename t>
std::vector<T>& operator*=(std::vector<T> &lhs, const t rhs);

template<typename T, typename t>
std::vector<T> operator*(const t lhs, std::vector<T> rhs);

template<typename T, typename t>
std::vector<T> operator*(std::vector<T> lhs, const t rhs);

template<typename T, typename t>
std::vector<T>& operator/=(std::vector<T> &lhs, const t rhs);

template<typename T, typename t>
std::vector<T> operator/(std::vector<T> lhs, const t rhs);

namespace vectorTools{
    //Type definitions
    typedef unsigned int size_type;

    //Computation Utilities
    template<typename T>
    int computeMean(const std::vector<std::vector< T > > &A, std::vector< T > &v);

    template<typename T>
    std::vector< T > computeMean(const std::vector< std::vector< T > > &A);

    template<typename T>
    int cross(const std::vector< T > &a, const std::vector< T > &b, std::vector< T > &c);

    template<typename T>
    std::vector< T > cross(const std::vector< T > &a, const std::vector< T > &b);

    template<typename T>
    int dot(const std::vector< T > &a, const std::vector< T > &b, T &c);

    template<typename T>
    T dot(const std::vector< T > &a, const std::vector< T > &b);

    template<typename T>
    std::vector< T > dot(const std::vector< std::vector< T > > &A, const std::vector< T > &b);

    template<typename T>
    double l2norm(const std::vector< T > &v);

    template<typename T>
    double l2norm(const std::vector< std::vector< T > > &A);

    template<typename T>
    std::vector< std::vector< T > > dyadic(const std::vector< T > &a, const std::vector< T > &b);

    template<typename T>
    int dyadic(const std::vector< T > &a, const std::vector< T > &b, std::vector< std::vector< T > > &A);

    //Comparison Tools
    template<typename T>
    bool fuzzyEquals(const T &a, const T &b, double tolr=1e-6, double tola=1e-6);

    template<typename T>
    bool fuzzyEquals(const std::vector< T > &a, const std::vector< T > &b, double tolr=1e-6, double tola=1e-6);

    template<typename T>
    bool fuzzyEquals(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B,
        double tolr=1e-6, double tola=1e-6);

    template<typename T>
    bool equals(const T &a, const T &b);

    template<typename T>
    bool equals(const std::vector< T > &a, const std::vector< T > &b);

    template<typename T>
    bool equals(const std::vector< std::vector< T > > &a, const std::vector< std::vector< T > > &b);

    template<typename T>
    bool isParallel(const std::vector< T > &v1, const std::vector< T > &v2);

    //Access Utilities
    template <typename T>
    int getValuesByIndex(const std::vector< T > &v, const std::vector< size_type > &indices,
        std::vector< T > &subv);

    //Appending utilities
    template<typename T>
    std::vector< T > appendVectors(const std::vector< std::vector< T > > &A);

    //Sorting utilities
    template <typename T>
    std::vector< size_type > argsort(const std::vector< T > &v);

    //Printing Utilities
    template<typename T>
    int print(const std::vector< T > &v);

    template<typename T>
    int print(const std::vector< std::vector< T > > &A);

    //Utilities which require Eigen
    #ifdef USE_EIGEN
        template<typename T>
        std::vector< double > solveLinearSystem(const std::vector< std::vector< T > > &A, const std::vector< T > &b, unsigned int &rank);

        template<typename T>
        std::vector< double > solveLinearSystem(const std::vector< T > &A, const std::vector< T > &b, 
            const unsigned int nrows, const unsigned int ncols, unsigned int &rank);

    #endif

}

#include "vector_tools.cpp"
#endif
