/**
  *****************************************************************************
  * \file vector_tools.cpp
  *****************************************************************************
  * A collection of functions and related utilities intended to help perform
  * vector operations in cpp.
  *****************************************************************************
  */

#include "vector_tools.h"

//Operator overloading
template<typename T>
std::vector<T>& operator+=(std::vector<T> &lhs, const std::vector<T> &rhs){
    /*!
     * Overload the += operator for vectors
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The right-hand side vector
     */

    if (lhs.size() != rhs.size()){
        throw std::length_error("vectors must be the same size to add");
    }

    for (vectorTools::size_type i=0; i<lhs.size(); i++){
        lhs[i] += rhs[i];
    }
    return lhs;
}

template<typename T>
std::vector<T>& operator+=(std::vector<T> &lhs, const T &rhs){
    /*!
     * Overload the += operator for vector scalar addition
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The scalar being added to the vector
     */

    for (vectorTools::size_type i=0; i<lhs.size(); i++){
        lhs[i] += rhs;
    }
    return lhs;
}

template<typename T>
std::vector<T> operator+(std::vector<T> lhs, const std::vector<T> &rhs){
    /*!
     * Overload the + operator for vectors
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The right-hand side vector
     */

    if (lhs.size() != rhs.size()){
        throw std::length_error("vectors must be the same size to add");
    }
    return lhs += rhs;
}

template<typename T>
std::vector<T> operator+(std::vector<T> lhs, const T &rhs){
    /*!
     * Overload the + operator for vector - scalar addition
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The right-hand side vector
     */

    return lhs += rhs;
}

template<typename T>
std::vector<T> operator+(const T &lhs, std::vector<T> rhs){
    /*!
     * Overload the + operator for vectors
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The right-hand side vector
     */

    return rhs += lhs;
}

template<typename T>
std::vector<T> operator-(std::vector<T> v){
    /*!
     * Overload the negative operator for vectors
     *
     * \param &v: The vector in question
     */

    for (vectorTools::size_type i=0; i<v.size(); i++){
        v[i] = -v[i];
    }
    return v;
}

template<typename T>
std::vector<T>& operator-=(std::vector<T> &lhs, const std::vector<T> &rhs){
    /*!
     * Overload the -= operator for vectors
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The right-hand side vector
     */
    return lhs += -rhs;
}

template<typename T>
std::vector<T>& operator-=(std::vector<T> &lhs, const T &rhs){
    /*!
     * Overload the subtraction operator for vector - scalar pairs
     *
     * \param &lhs: The left-hand side vector.
     * \param &rhs: The right-hand side scalar.
     */
    return lhs += -rhs;
}

template<typename T>
std::vector<T> operator-(std::vector<T> lhs, const std::vector<T> &rhs){
    /*!
     * Overload the subtraction operator for vectors
     *
     * \param &lhs: The left-hand side vector
     * \param &rhs: The right-hand side vector
     */

    return lhs -= rhs;
}

template<typename T>
std::vector<T> operator-(std::vector<T> lhs, const T &rhs){
    /*!
     * Overload the subtraction operator for vector - scalar pairs
     *
     * \param lhs: The left-hand side vector
     * \param &rhs: The right-hand side scalar
     */

    return lhs -= rhs;
}

template<typename T>
std::vector<T> operator-(const T &lhs, std::vector<T> rhs){
    /*!
     * Overload the subtraction operator for vector - scalar pairs
     *
     * \param &lhs: The left-hand side scalar
     * \param rhs: The right-hand side vector
     */

    rhs -= lhs;
    return -rhs;
}

template<typename T, typename t>
std::vector<T>& operator*=(std::vector<T> &lhs, const t rhs){
    /*!
     * Overload the *= operator for vectors
     *
     * \param lhs: The left-hand side vector
     * \param rhs: The right-hand side scalar
     */
    for (vectorTools::size_type i=0; i<lhs.size(); i++){
        lhs[i] *= rhs;
    }
    return lhs;
}

template<typename T, typename t>
std::vector<T> operator*(const t lhs, std::vector<T> rhs){
    /*!
     * Overload the / operator for vectors
     *
     * \param lhs: The left-hand side scalar
     * \param rhs: The right-hand side vector
     */
    return rhs*=lhs;
}


template<typename T, typename t>
std::vector<T> operator*(std::vector<T> lhs, const t rhs){
    /*!
     * Overload the / operator for vectors
     *
     * \param lhs: The left-hand side vector
     * \param rhs: The right-hand side scalar
     */
    return lhs*=rhs;
}

template<typename T, typename t>
std::vector<T>& operator/=(std::vector<T> &lhs, const t rhs){
    /*!
     * Overload the /= operator for vectors
     *
     * \param lhs: The left-hand side vector
     * \param rhs: The right-hand side scalar
     */
    return lhs*=(1./rhs);
}

template<typename T, typename t>
std::vector<T> operator/(std::vector<T> lhs, const t rhs){
    /*!
     * Overload the / operator for vectors
     *
     * \param lhs: The left-hand side vector
     * \param rhs: The right-hand side scalar
     */
    return lhs/=rhs;
}

template<typename T>
std::vector< std::vector< T > >& operator+=(std::vector< std::vector< T > > &lhs, const std::vector< std::vector< T > > &rhs){
    /*!
     * Overload the += operator for matrices
     *
     * \param lhs: The left-hand side matrix
     * \param &rhs: The right-hand side matrix
     */

    if (lhs.size() != rhs.size()){
        throw std::length_error("matrices must have the same numbers of rows to add");
    }

    for (unsigned int i=0; i<lhs.size(); i++){
        lhs[i] += rhs[i];
    }
    return lhs;
}

template<typename T>
std::vector< std::vector< T > > operator+(std::vector< std::vector< T > > lhs, const std::vector< std::vector< T > > &rhs){
    /*!
     * Overload the + operator for matrices
     *
     * \param lhs: The left-hand side matrix
     * \param &rhs: The right-hand side matrix
     */

    return lhs += rhs;
}

template<typename T>
std::vector< std::vector< T > > operator-(std::vector< std::vector< T > > v){
    /*!
     * Overload the negation operator for matrices.
     *
     * \param v: The matrix to negate.
     */

    for (unsigned int i=0; i<v.size(); i++){
        v[i] = -v[i];
    }
    return v;
}

template<typename T>
std::vector< std::vector < T > >& operator-=(std::vector< std::vector< T > > &lhs, const std::vector< std::vector< T > > &rhs){
    /*!
     * Overload the -= operator for matrices
     *
     * \param lhs: The left-hand side matrix
     * \param &rhs: The right-hand side matrix
     */

    if (lhs.size() != rhs.size()){
        throw std::length_error("matrices must have the same numbers of rows to add");
    }

    for (unsigned int i=0; i<lhs.size(); i++){
        lhs[i] += -rhs[i];
    }

    return lhs;
}

template<typename T>
std::vector< std::vector< T > > operator-(std::vector< std::vector< T > > lhs, const std::vector< std::vector< T > > &rhs){
    /*!
     * Overload the - operator for matrices
     *
     * \param lhs: The left-hand side matrix
     * \param &rhs: The right-hand side matrix
     */
    return lhs -= rhs;
}

namespace vectorTools{

    //Computation Utilities
    template<typename T>
    int computeMean(const std::vector< std::vector< T > > &A, std::vector< T > &v){
        /*!
         * Compute the column-wise mean of A
         *
         * \param &A: The matrix of vectors
         * \param &v: The resulting mean
         */

        if (A.size() == 0){
            std::cerr << "Error: Matrix must have a size greater than zero\n";
            return 1;
        }

        //Size the output vector
        v = std::vector<T>(A[0].size(), 0);

        //Compute the mean
        for (auto it = A.begin(); it!=A.end(); it++){
            v += *it/A.size();
        }
        return 0;
    }

    template<typename T>
    std::vector< T > computeMean(const std::vector< std::vector< T > > &A){
        /*!
         * Compute the column-wise mean of A
         *
         * \param &A: The matrix of vectors
         */

        std::vector< T > v;
        computeMean(A, v);
        return v;
    }

    template<typename T>
    int cross(const std::vector< T > &a, const std::vector< T > &b, std::vector< T > &c){
        /*!
         * Compute the cross product of two vectors i.e. a x b
         * Note that if a and b are 2D vectors a 3D vector for c will be returned.
         *
         * TODO: Generalize this to n dimensions.
         *
         * \param &a: The first vector
         * \param &b: The second vector
         * \param &c: The resulting vector
         */

        size_type size = a.size();
        c = std::vector< T >(size, 0);

        if (size == 2){
            c.resize(3);
            c[2] =  a[0]*b[1] - a[1]*b[0];
        }
        else if (size == 3){
            c[0] =  a[1]*b[2] - a[2]*b[1];
            c[1] = -a[0]*b[2] + a[2]*b[0];
            c[2] =  a[0]*b[1] - a[1]*b[0];
        }
        else{
            throw std::length_error("Only 2D and 3D vectors are accepted");
        }

        return 0;
    }

    template<typename T>
    std::vector< T > cross(const std::vector< T > &a, const std::vector< T > &b){
        /*!
         * Compute the cross product of two vectors i.e. a x b
         * Note that if a and b are 2D vectors a 3D vector for c will be returned
         *
         * TODO: Generalize this to n dimensions
         *
         * \param &a: The first vector
         * \param &b: The second vector
         */

         std::vector< T > c;
         cross(a, b, c);
         return c;
    }

    template<typename T>
    int dot(const std::vector< T > &a, const std::vector< T > &b, T &v){
        /*!
         * Compute the dot product of two vectors i.e. v = a_i b_i
         *
         * \param &a: The first vector
         * \param &b: The second vector
         * \param &v: The output quantity
         */

        //Get the size and perform error handling
        size_type size = a.size();
        if (size != b.size()){
            throw std::length_error("vectors must be the same size to add");
        }

        //Set v to zero
        v = 0;

        for (size_type i=0; i<size; i++){
            v += a[i]*b[i];
        }
        return 0;
    }

    template<typename T>
    T dot(const std::vector< T > &a, const std::vector< T > &b){
        /*!
         * Compute the dot product of two vectors i.e. v = a_i b_i
         *
         * \param &a: The first vector
         * \param &b: The second vector
         */

        T v;
        dot(a, b, v);
        return v;
    }

    template<typename T>
    std::vector< T > dot(const std::vector< std::vector< T > > &A, const std::vector< T > &b){
        /*!
         * Compute the dot product between a matrix and a vector resulting i.e. c_i = A_ij b_j
         *
         * \param &A: The matrix
         * \param &b: The vector
         */

        size_type size = A.size();

        std::vector< T > c(size);

        unsigned int i=0;
        for (auto A_i=A.begin(); A_i!=A.end(); A_i++, i++){
            c[i] = dot(*A_i, b);
        }
        return c;
    }

    template<typename T>
    std::vector< T > Tdot(const std::vector< std::vector< T > > &A, const std::vector< T > &b){
        /*!
         * Compute the dot product between a matrix and a vector resulting i.e. c_i = A_ji b_j
         *
         * \param &A: The matrix
         * \param &b: The vector
         */

        size_type size = A.size();

        if ( size == 0 ){
            throw std::length_error("A has no rows");
        }

        if ( size != b.size() ){
            throw std::length_error("A and b are incompatible shapes");
        }

        std::vector< T > c(A[0].size(), 0);

        for ( unsigned int i = 0; i < A[0].size(); i++ ){
            for ( unsigned int j = 0; j < size; j++ ){
                c[i] += A[j][i] * b[j];
            }
        }
        return c;
    }

    template<typename T>
    std::vector< std::vector< T > > dot(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B){
        /*!
         * Compute the dot product between two matrices i.e. C_{ij} = A_{ik} B_{kj}
         *
         * \param &A: The first matrix
         * \param &B: The second matrix
         */

        size_type rows = A.size();

        if (B.size() == 0){
            throw std::length_error("B has no rows");
        }

        size_type inner = B.size();
        size_type cols = B[0].size();

        //Error handling
        for (unsigned int I=0; I<rows; I++){
            if (A[I].size() != inner){
                throw std::length_error("A and B have incompatible shapes");
            }
        }

        for (unsigned int I=0; I<inner; I++){
            if (B[I].size() != cols){
                throw std::length_error("B is not a regular matrix");
            }
        }

        //Perform the matrix multiplication
        std::vector< std::vector< T > > C(rows, std::vector< T >(cols, 0));

        for (unsigned int I=0; I<rows; I++){

            for (unsigned int J=0; J<cols; J++){

                for (unsigned int K=0; K<inner; K++){

                    C[I][J] += A[I][K] * B[K][J];
                }
            }
        }
        return C;
    }

    template<typename T>
    std::vector< std::vector< T > > dotT(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B){
        /*!
         * Compute the dot product between two matrices where the second is transposed i.e. C_{ij} = A_{ik} B_{jk}
         *
         * \param &A: The first matrix
         * \param &B: The second matrix
         */

        size_type Arows = A.size();

        if (B.size() == 0){
            throw std::length_error("B has no rows");
        }

        size_type Brows = B.size();
        size_type Bcols = B[0].size();

        //Error handling
        for (unsigned int I=0; I<Arows; I++){
            if (A[I].size() != Bcols){
                throw std::length_error("A and B have incompatible shapes");
            }
        }

        for (unsigned int I=0; I<Brows; I++){
            if (B[I].size() != Bcols){
                throw std::length_error("B is not a regular matrix");
            }
        }

        //Perform the matrix multiplication
        std::vector< std::vector< T > > C(Arows, std::vector< T >(Brows, 0));

        for (unsigned int I=0; I<Arows; I++){

            for (unsigned int J=0; J<Brows; J++){

                for (unsigned int K=0; K<Bcols; K++){

                    C[I][J] += A[I][K] * B[J][K];
                }
            }
        }
        return C;
    }

    template<typename T>
    std::vector< std::vector< T > > Tdot(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B){
        /*!
         * Compute the dot product between two matrices where the first is transposed i.e. C_{ij} = A_{ki} B_{kj}
         *
         * \param &A: The first matrix
         * \param &B: The second matrix
         */

        size_type Arows = A.size();

        if (Arows == 0){
            throw std::length_error("A has no rows");
        }

        size_type Acols = A[0].size();

        if (B.size() == 0){
            throw std::length_error("B has no rows");
        }

        size_type Brows = B.size();
        size_type Bcols = B[0].size();

        //Error handling
        if (Arows != Brows){
            throw std::length_error("A and B have incompatible shapes");
        }

        for (unsigned int I=0; I<Arows; I++){
            if (A[I].size() != Acols){
                throw std::length_error("A is not a regular matrix");
            }
        }

        for (unsigned int I=0; I<Brows; I++){
            if (B[I].size() != Bcols){
                throw std::length_error("B is not a regular matrix");
            }
        }

        //Perform the matrix multiplication
        std::vector< std::vector< T > > C(Acols, std::vector< T >(Bcols, 0));

        for (unsigned int I=0; I<Acols; I++){

            for (unsigned int J=0; J<Bcols; J++){

                for (unsigned int K=0; K<Brows; K++){

                    C[I][J] += A[K][I] * B[K][J];
                }
            }
        }
        return C;
    }

    template<typename T>
    std::vector< std::vector< T > > TdotT(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B){
        /*!
         * Compute the dot product between two matrices where both are transposed i.e. C_{ij} = A_{ki} B_{jk}
         *
         * \param &A: The first matrix
         * \param &B: The second matrix
         */

        std::vector< std::vector< T > > CT = dot(B, A);

        std::vector< std::vector< T > > C(CT[0].size(), std::vector< T > (CT.size()));

        for (unsigned int i=0; i<C.size(); i++){
            for (unsigned int j=0; j<C[i].size(); j++){
                C[i][j] = CT[j][i];
            }
        }
        return C;
    }

    template<typename T>
    int inner(const std::vector< T > &A, const std::vector< T > &B, T &result){
        /*!
         * Compute the inner product between two matrices stored in row major format
         * 
         * \f$result = \sum{A_{ij}*B_{ij}}\f$
         *
         * \param &A: The first matrix in row major format
         * \param &B: The second matrix in row major format
         * \param &result: The inner product scalar
         */

        result = 0.;
        dot(A, B, result);

        return 0;
    }

    template<typename T>
    T inner(const std::vector< T > &A, const std::vector< T > &B){
        /*!
         * Compute the inner product between two matrices stored in row major format
         * 
         * \f$result = \sum{A_{ij}*B_{ij}}\f$
         *
         * \param &A: The first matrix in row major format
         * \param &B: The second matrix in row major format
         * :return: The inner product scalar
         * :rtype: T result
         */

        T result = 0.;
        inner(A, B, result);

        return result;
    }

    template<typename T>
    int inner(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B, T &result){
        /*!
         * Compute the inner product between two matrices stored in matrix format
         * 
         * \f$result = \sum{A_{ij}*B_{ij}}\f$
         *
         * \param &A: The first matrix
         * \param &B: The second matrix
         * \param &result: The inner product scalar
         */

        //Get the size and perform error handling
        unsigned int Arows = A.size();
        unsigned int Acols = A[0].size();
        if (Arows != B.size() || Acols != B[0].size()){
            throw std::length_error("Matrices must have the same dimensions to add.");
        }

        //Convert to row major matrices
        std::vector< T > Avec = appendVectors(A);
        std::vector< T > Bvec = appendVectors(B);

        result = 0.;
        inner(Avec, Bvec, result);

        return 0;
    }

    template<typename T>
    T inner(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B){
        /*!
         * Compute the inner product between two matrices stored in matrix format
         * 
         * \f$result = \sum{A_{ij}*B_{ij}}\f$
         *
         * \param &A: The first matrix
         * \param &B: The second matrix
         * :return: The inner product scalar
         * :rtype: T result
         */

        T result = 0.;
        inner(A, B, result);

        return result;
    }


    template<typename T>
    int trace(const std::vector< T > &A, T &v){
        /*!
         * Compute the trace of a square matrix ( \f$A\f$ ) in row major format:
         * 
         * \f$v = A_{ii}\f$
         *
         * \param &A: The matrix in row major format ( \f$A\f$ )
         * \param &v: The scalar output quantity ( \f$v\f$ )
         */

        //Get the size and perform error handling
        unsigned int length = A.size();
        unsigned int dimension = std::round(std::sqrt(length));
        if (dimension*dimension != length){
            throw std::length_error("The trace can only be computed for square matrices.");
        }

        //Set v to zero
        v = 0;

        //Compute the trace
        for (size_type i=0; i<dimension; i++){
            v += A[dimension*i + i];
        }

        return 0;
    }

    template<typename T>
    T trace(const std::vector< T > &A){
        /*!
         * Compute the trace of a square matrix in row major format
         * 
         * \f$v = A_{ii}\f$
         *
         * \param &A: The matrix in row major format ( \f$A\f$ )
         */

        T v;
        trace(A, v);
        return v;
    }

    template<typename T>
    int trace(const std::vector< std::vector< T > > &A, T &v){
        /*!
         * Compute the trace of a square matrix
         * 
         * \f$v = A_{ii}\f$
         *
         * \param &A: The matrix
         * \param &v: The scalar output quantity
         */

        //Convert matrix to row major vector format
        std::vector< T > Avec = appendVectors(A);

        trace(Avec, v);
        return 0;
    }

    template<typename T>
    T trace(const std::vector< std::vector< T > > &A){
        /*!
         * Compute the trace of a square matrix
         * 
         * \f$v = A_{ii}\f$
         *
         * \param &A: The matrix
         */

        T v;
        trace(A, v);
        return v;
    }

    template<typename T>
    double l2norm(const std::vector< T > &v){
        /*!
         * Compute the l2 norm of the vector v i.e. (v_i v_i)^(0.5)
         *
         * \param &v: The vector to compute the norm of
         */

        return std::sqrt(dot(v, v));
    }

    template<typename T>
    double l2norm(const std::vector< std::vector < T > > &A){
        /*!
         * Compute the l2 norm of the matrix A i.e. (A_ij A_ij)^(0.5)
         *
         * \param &A: The matrix to compute the norm of
         */

        double v=0;
        for (auto it=A.begin(); it!=A.end(); it++){
            v += dot(*it, *it);
        }
        return std::sqrt(v);
    }

    template<typename T>
    std::vector< std::vector< T > > dyadic(const std::vector< T > &a, const std::vector< T > &b){
        /*!
         * Compute the dyadic product between two vectors returning a matrix i.e. A_ij = a_i b_j;
         */

        std::vector< std::vector< T > > A;
        dyadic(a, b, A);
        return A;
    }

    template<typename T>
    int dyadic(const std::vector< T > &a, const std::vector< T > &b, std::vector< std::vector< T > > &A){
        /*!
         * Compute the dyadic product between two vectors return a matrix i.e. A_ij = a_i b_j
         *
         * \param &a: The first vector
         * \param &b: The second vector
         * \param &A: The returned matrix
         */

        A.resize(a.size());
        unsigned int i=0;
        for (auto ai=a.begin(); ai!=a.end(); ai++, i++){
            A[i].resize(b.size());
            unsigned int j=0;
            for (auto bj=b.begin(); bj!=b.end(); bj++, j++){
                A[i][j] = (*ai)*(*bj);
            }
        }
        return 0;
    }

    template<typename T>
    int eye(std::vector< T > &I){
        /*!
         * Construct an identity tensor in row major format
         *
         * \param &I: The identity matrix
         */

        //Get the size and perform error handling
        unsigned int length = I.size();
        unsigned int dimension = std::round(std::sqrt(length));
        if (dimension*dimension != length){
            throw std::length_error("The identity tensor can only be constructed for square matrices.");
        }

        //Construct the identity matrix
        I = std::vector< T >(I.size(), 0);
        for (size_type i=0; i<dimension; i++){
            I[dimension*i + i] = 1;
        }

        return 0;
    }

    template<typename T>
    std::vector< std::vector< T > > eye(const unsigned int dim){
        /*!
         * Construct an identity tensor of the size indicated by dim
         *
         * \param dim: The dimension of the matrix
         */

        std::vector< std::vector< T > > I(dim, std::vector< T >(dim, 0));
        for (unsigned int i=0; i<dim; i++){
            I[i][i] = 1;
        }
        return I;
    }

    template<typename T>
    int eye(const unsigned int dim, std::vector< std::vector< T > > &I){
        /*!
         * Construct an identity tensor of the size indicated by dim
         *
         * \param dim: The dimension of the matrix
         * \param &I: The resulting identity matrix
         */

        I = eye<T>(dim);

        return 0;
    }

    template< typename T >
    T median(const std::vector< T > &x){
        /*!
         * Compute the median of a vector x
         *
         * \param &x: The vector to compute the median of.
         */

        unsigned int n = x.size();
        std::vector< T > xcopy = x;
        std::sort(xcopy.begin(), xcopy.end());

        if ( (n & 2) == 0){
            return xcopy[n / 2];
        }
        else{
            return 0.5*( xcopy[(n - 1)/2] + xcopy[n / 2] );
        }
    }

    template< typename T >
    std::vector< T > abs(const std::vector< T > &x){
        /*!
         * Compute the absolute value of every component of a vector.
         *
         * \param &x: The vector to compute the absolute value of.
         */

        std::vector< T > xcopy = x;
        for (unsigned int i=0; i<xcopy.size(); i++){
            xcopy[i] = std::abs(xcopy[i]);
        }
        return xcopy;
    }

    //Comparison Utilities
    template< typename T >
    bool fuzzyEquals(const T &a, const T &b, double tolr, double tola){
        /*!
         * Compare two values to determine if they are equal within a
         * tolerance.
         *
         * \param &a: The first value to compare
         * \param &b: The second value to compare
         * \param tolr: The relative tolerance
         * \param tola: The absolute tolerance
         */

        double tol = fmin(tolr*fabs(a) + tola, tolr*fabs(b) + tola);
        return fabs(a-b)<tol;
    }

    template< typename T >
    bool fuzzyEquals(const std::vector< T > &a, const std::vector< T > &b, double tolr, double tola){
        /*!
         * Compare two vectors to determine if they are equal within a
         * tolerance.
         *
         * \param &a: The first vector to compare
         * \param &b: The second vector to compare
         * \param tolr: The relative tolerance
         * \param tola: The absolute tolerance
         */

        if (a.size() != b.size()){
            return false;
        }

        for (unsigned int i=0; i<a.size(); i++){
            if (!fuzzyEquals(a[i], b[i], tolr, tola)){
                return false;
            }
        }
        return true;
    }

    template< typename T >
    bool fuzzyEquals(const std::vector< std::vector< T > > &A, const std::vector< std::vector< T > > &B, double tolr, double tola){
        /*!
         * Compare two matrices to determine if they are equal within a
         * tolerance.
         *
         * \param &A: The first matrix to compare
         * \param &B: The second matrix to compare
         * \param tolr: The relative tolerance
         * \param tola: The absolute tolerance
         */

        if (A.size() != B.size()){
            return false;
        }

        for (unsigned int i=0; i<A.size(); i++){
            if (!fuzzyEquals(A[i], B[i], tolr, tola)){
                return false;
            }
        }
        return true;
    }

    template<typename T>
    bool equals(const T &a, const T &b){
        /*!
         * Compare two values for exact equality
         * \param &a: The first value to compare
         * \param &b: The second value to compare
         */
         return a == b;
    }

    template<typename T>
    bool equals(const std::vector< T > &a, const std::vector< T > &b){
        /*!
         * Compare two vectors for exact equality
         *
         * \param &a: The first vector to compare
         * \param &b: The second vector to compare
         */
        unsigned int size = a.size();
        if (size != b.size()){
            return false;
        }
        for (unsigned int i=0; i<size; i++){
            if (!equals(a[i], b[i])){
                return false;
            }
        }
        return true;
    }

    template<typename T>
    bool equals(const std::vector< std::vector< T > > &a, const std::vector< std::vector< T > > &b){
        /*!
         * Compare two matrices for exact equality
         *
         * \param &a: The first matrix to compare
         * \param &b: The second matrix to compare
         */

        unsigned int size = a.size();
        if (size != b.size()){
            return false;
        }
        for (unsigned int i=0; i<size; i++){
            if (!equals(a[i], b[i])){
                return false;
            }
        }
        return true;
    }

    template<typename T>
    bool isParallel(const std::vector< T > &v1, const std::vector< T > &v2){
        /*!
         * Compare two vectors and determine if they are parallel
         *
         * \param &v1: The first vector
         * \param &v2: The second vector
         */

        //Recast the incoming vectors as double
        std::vector< double > v1d(v1.begin(), v1.end());
        std::vector< double > v2d(v2.begin(), v2.end());

        //Compute the unit vector for each
        std::vector< double > nv1 = v1d/l2norm(v1d);
        std::vector< double > nv2 = v2d/l2norm(v2d);

        //Compute the distance
        double d = std::abs(dot(nv1, nv2));

        return fuzzyEquals(d, 1.);
    }

    //Access Utilities
    template <typename T>
    int getValuesByIndex(const std::vector< T > &v, const std::vector< size_type > &indices,
        std::vector< T > &subv){
        /*!
         * Get the values of a vector referenced by index
         *
         * \param &v: The vector from which to retrieve get a sub-vector
         * \param &indices: The indices to retrieve
         * \param &subv: The subvector of values
         */

        //Resize subv
        subv.resize(indices.size());

        unsigned int i=0;
        for (auto it=indices.begin(); it!=indices.end(); it++, i++){
            subv[i] = v[*it];
        }
        return 0;
    }

    //Appending Utilities
    template<typename T>
    std::vector< T > appendVectors(const std::vector< std::vector< T > > &A){
        /*!
         * Append a matrix into a row-major vector.
         *
         * \param &A: The matrix to be appended
         */

        std::vector< T > Avec;

        for (auto Ai=A.begin(); Ai!=A.end(); Ai++){
            Avec.insert(Avec.end(), (*Ai).begin(), (*Ai).end());
        }
        return Avec;
    }

    template<typename T>
    std::vector< T > appendVectors(const std::initializer_list< std::vector< T > > &list){
        /*!
         * Append a brace-enclosed initializer list to a row-major vector
         *
         * \param list: The list of vectors to append
         */

        std::vector< T > Avec;
        for (auto li=list.begin(); li!=list.end(); li++){
            Avec.insert(Avec.end(), (*li).begin(), (*li).end());
        }
        return Avec;
    }

    template< typename T >
    std::vector< std::vector< T > > inflate( const std::vector< T > &Avec, const unsigned int &nrows, const unsigned int &ncols ){
        /*!
         * Inflate the provided row-major vector into a 2D matrix.
         *
         * \param &Avec: The matrix in row-major form.
         * \param &nrows: The number of rows in the matrix.
         * \param &ncols: The number of columns in the matrix.
         */

        if ( Avec.size() != nrows * ncols ){
            throw std::length_error("Avec is not a consistent size with the desired dimensions of the matrix");
        }

        std::vector< std::vector< T > > A( nrows, std::vector< T >( ncols ) );

        for ( unsigned int i = 0; i < nrows; i++ ){
            for ( unsigned int j = 0; j < ncols; j++ ){
                A[i][j] = Avec[ i * ncols + j ];
            }
        }
        return A;
    }

    //Sorting Utilities
    template<typename T>
    std::vector< size_type > argsort(const std::vector< T > &v){
        /*!
         * Find the indices required to sort a vector
         * Code from: https://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes
         *
         * \param &v: The vector to get the index sorted properties.
         */

        // initialize original index locations
        std::vector< size_type > idx(v.size());
        std::iota(idx.begin(), idx.end(), 0);

        // sort indices based on comparing values in v
        std::sort(idx.begin(), idx.end(),
                  [&v](size_type i1, size_type i2) {return v[i1] < v[i2];});

        return idx;
    }

    //Printing Utilities
    template<typename T>
    int print(const std::vector< T > &v){
        /*!
         * Print the contents of the vector to the terminal assuming << has been defined for each component
         *
         * \param &v: The vector to be displayed
         */

        for (auto it = v.begin(); it!=v.end(); it++){
            std::cout << *it << " ";
        }
        std::cout << "\n";
        return 0;
    }

    template<typename T>
    int print(const std::vector< std::vector< T > > &A){
        /*!
         * Print the contents of the matrix to the terminal assuming << has been defined for each component
         *
         * \param &A: The matrix to be displayed
         */

        for (auto it = A.begin(); it!=A.end(); it++){
            print(*it);
        }
        return 0;
    }

    #ifdef USE_EIGEN
        template< typename T >
        std::vector< double > solveLinearSystem( const std::vector< std::vector< T > > &A, const std::vector< T > &b,
            unsigned int &rank ){
            /*!
             * Solve a linear system of equations using Eigen. Note this uses a dense solver.
             * 
             * \f$Ax = b\f$
             *
             * \param &A: The \f$A\f$ matrix
             * \param &b: The \f$b\f$ vector
             * \param &rank: The rank of \f$A\f$
             */

            //Get the number of rows in A
            unsigned int nrows = A.size( );

            //Append all of the vectors into one long vector
            const std::vector< T > Avec = appendVectors( A );

            unsigned int ncols = Avec.size( ) / nrows;
            if ( ( Avec.size( ) % nrows ) > 0 ){
                throw std::length_error( "A is not a regular matrix" );
            }
            return solveLinearSystem( Avec, b, nrows, ncols, rank );

        }

        template< typename T >
        std::vector< double > solveLinearSystem(const std::vector< std::vector< T > > &A, const std::vector< T > &b,
            unsigned int &rank, solverType< T > &linearSolver ){
            /*!
             * Solve a linear system of equations using Eigen. Note this uses a dense solver.
             * 
             * \f$Ax = b\f$
             *
             * \param &A: The \f$A\f$ matrix
             * \param &b: The \f$b\f$ vector
             * \param &rank: The rank of \f$A\f$
             * \param &linearSolver: The linear solver which contains the decomposed
             *     A matrix ( after the solve ). This is useful for when further
             *     non-linear solves are required such as in the construction
             *     of Jacobians of non-linear equaquations which were solved
             *     using Newton methods.
             */

            //Get the number of rows in A
            unsigned int nrows = A.size( );

            //Append all of the vectors into one long vector
            const std::vector< T > Avec = appendVectors( A );

            unsigned int ncols = Avec.size( ) / nrows;
            if ( ( Avec.size( ) % nrows ) > 0 ){
                throw std::length_error( "A is not a regular matrix" );
            }
            return solveLinearSystem( Avec, b, nrows, ncols, rank, linearSolver );

        }

        template< typename T >
        std::vector< double > solveLinearSystem( const std::vector< T > &Avec, const std::vector< T > &b,
            const unsigned int nrows, const unsigned int ncols, unsigned int &rank ){
            /*!
             * Solve a linear system of equations using Eigen. Note this uses a dense solver.
             * 
             * \f$Ax = b\f$
             *
             * \param &Avec: The vector form of the \f$A\f$ matrix ( row major )
             * \param &b: The \f$b\f$ vector
             * \param nrows: The number of rows of \f$A\f$
             * \param ncols: The number of columns of \f$A\f$
             * \param &rank: The rank of \f$A\f$
             */

            solverType< T > linearSolver;
            return solveLinearSystem( Avec, b, nrows, ncols, rank, linearSolver );
        }

        template< typename T >
        std::vector< double > solveLinearSystem( const std::vector< T > &Avec, const std::vector< T > &b,
            const unsigned int nrows, const unsigned int ncols, unsigned int &rank,
            solverType< T > &linearSolver ){
            /*!
             * Solve a linear system of equations using Eigen. Note this uses a dense solver.
             * 
             * \f$Ax = b\f$
             *
             * \param &Avec: The vector form of the \f$A\f$ matrix ( row major )
             * \param &b: The \f$b\f$ vector
             * \param nrows: The number of rows of \f$A\f$
             * \param ncols: The number of columns of \f$A\f$
             * \param &rank: The rank of \f$A\f$
             * \param &linearSolver: The linear solver which contains the decomposed
             *     A matrix ( after the solve ). This is useful for when further
             *     non-linear solves are required such as in the construction
             *     of Jacobians of non-linear equaquations which were solved
             *     using Newton methods.
             */

            if ( Avec.size( ) != ( nrows * ncols ) ){
                throw std::length_error( "The size of Avec and the dimensions nrows and ncols do not align." );
            }

            if ( b.size( ) != ncols ){
                throw std::length_error( "The b vector's size is not consistent with A's dimension" );
            }

            //Set up the Eigen maps for A and b
            Eigen::Map< const Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Amat( Avec.data( ), nrows, ncols );
            Eigen::Map< const Eigen::Matrix< T, -1,  1 > > bmat( b.data( ), nrows, 1 );

            //Set up the Eigen maps for the solution vector
            std::vector< double > x( nrows );
            Eigen::Map< Eigen::MatrixXd > xmat( x.data( ), nrows, 1 );

            //Perform the decomposition
            linearSolver = solverType< T >( Amat );

            rank = linearSolver.rank( );

            xmat = linearSolver.solve( bmat );
            return x;
        }

        template<typename T>
        T determinant(const std::vector< T > &Avec, const unsigned int nrows, const unsigned int ncols){
            /*!
             * Compute the determinant of the matrix A
             *
             * \param &Avec: The vector form of the A matrix (row major)
             * \param nrows: The number of rows
             * \param ncols: The number of columns
             */

            if (Avec.size() != (nrows*ncols)){
                std::cerr << "Error: The size of Avec and the dimensions nrows and ncols do not align.\n";
                assert(1==0);
            }

            //Set up the Eigen map for A
            Eigen::Map < const Eigen::Matrix<T, -1, -1, Eigen::RowMajor> > Amat(Avec.data(), nrows, ncols);
            return Amat.determinant();
        }

        template<typename T>
        std::vector< double > inverse(const std::vector< T > &Avec, const unsigned int nrows, const unsigned int ncols){
            /*!
             * Compute the inverse of a matrix in row-major format
             *
             * \param &Avec: The vector form of the A matrix (row major)
             * \param nrows: The number of rows
             * \param ncols: The number of columns
             */

            if (Avec.size() != (nrows*ncols)){
                std::cerr << "Error: The size of Avec and the dimensions nrows and ncols do not align.\n";
                assert(1==0);
            }

            if (nrows != ncols){
                std::cerr << "Error: The number of rows must equal the number of columns.\n";
                assert(1==0);
            }

            //Set up the Eigen map for A
            Eigen::Map < const Eigen::Matrix<T, -1, -1, Eigen::RowMajor> > Amat(Avec.data(), nrows, ncols);

            //Set up the Eigen map for the inverse
            std::vector< double > AinvVec(nrows*ncols);
            Eigen::Map< Eigen::MatrixXd > Ainv(AinvVec.data(), ncols, nrows);

            //Compute the inverse
            Ainv = Amat.inverse().transpose(); //Note transpose because of how Eigen works

            return AinvVec;
        }

        template<typename T>
        std::vector< std::vector< double > > inverse( const std::vector< std::vector< T > > &A ){
            /*!
             * Compute the inverse of a matrix
             *
             * \param &A: The vector form of the A matrix
             */

            unsigned int nrows = A.size();
            unsigned int ncols;

            if ( nrows > 0 ){
                ncols = A[0].size();
            }
            else{
                throw std::length_error("A has no size");
            }

            if ( ncols == 0 ){
                throw std::length_error("A has no columns");
            }

            std::vector< T > Avec = appendVectors( A );
            std::vector< double > Ainvvec = inverse( Avec, nrows, ncols );

            return inflate( Ainvvec, nrows, ncols );
        }

        template<typename T>
        std::vector< double > computeDDetAdJ(const std::vector< T > &Avec, const unsigned int nrows, const unsigned int ncols){
            /*!
             * Compute the derivative of the determinant of a matrix w.r.t. the matrix
             *
             * \param &Avec: The matrix in vector form.
             * \param nrows: The number of rows in A
             * \param ncols: The number of columns in A
             */

            //Set up the Eigen map for A
            Eigen::Map < const Eigen::Matrix<T, -1, -1, Eigen::RowMajor> > Amat(Avec.data(), nrows, ncols);

            T detA = Amat.determinant();

            //Set up the Eigen map for the inverse
            std::vector< double > ddetAdA(nrows*ncols);
            Eigen::Map< Eigen::MatrixXd > ddetAdAmat(ddetAdA.data(), ncols, nrows);

            //Compute the derivative
            ddetAdAmat = detA * Amat.inverse(); //Note lack of transpose because of how Eigen works

            return ddetAdA;

        }

        template< typename T >
        std::vector< T > matrixMultiply(const std::vector< T > &A, const std::vector< T > &B,
                                        const unsigned int Arows, const unsigned int Acols,
                                        const unsigned int Brows, const unsigned int Bcols,
                                        const bool Atranspose, const bool Btranspose){
            /*!
             * Perform a matrix multiplication between two matrices stored in row-major format
             * $C_{ij} = A_{ik} B_{kj}$ if Atranspose = Btranspose = false
             * $C_{ij} = A_{ki} B_{kj}$ if Atranspose = true, Btranspose = false
             * $C_{ij} = A_{ik} B_{jk}$ if Atranspose = false, Btranspose = true
             * $C_{ij} = A_{ki} B_{jk}$ if Atranspose = true, Btranspose = true
             *
             * NOTE: The shape of B will be determined from the shape of A.
             *
             * \param &A: The A matrix in row-major format
             * \param &B: The B matrix in row-major format
             * \param Arows: The number of rows in A
             * \param Acols: The number of columns in A
             * \param Brows: The number of rows in B
             * \param Bcols: The number of columns in B
             * \param Atranspose: Boolean to indicate whether A should be transposed.
             * \param Btranspose: Boolean to indicate whether B should be transposed.
             */

            //Error handling
            if (A.size() != Arows*Acols){
                throw std::length_error("A has an incompatible shape");
            }

            if (B.size() != Brows*Bcols){
                throw std::length_error("B has an incompatible shape");
            }

            //Map A and B to Eigen matrices
            Eigen::Map < const Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Amat(A.data(), Arows, Acols);
            Eigen::Map < const Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Bmat(B.data(), Brows, Bcols);
            std::vector< T > C;

            //Perform the multiplication
            if ( Atranspose && Btranspose){
                C = std::vector< T >( Acols * Brows, 0);
                Eigen::Map < Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Cmat(C.data(), Acols, Brows);

                Cmat = Amat.transpose();
                Cmat *= Bmat.transpose();
            }
            else if ( Atranspose && !Btranspose){
                C = std::vector< T >( Acols * Bcols, 0);
                Eigen::Map < Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Cmat(C.data(), Acols, Bcols);

                Cmat = Amat.transpose() * Bmat;
            }
            else if ( !Atranspose && Btranspose){
                C = std::vector< T >( Arows * Brows, 0);
                Eigen::Map < Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Cmat(C.data(), Arows, Brows);

                Cmat = Amat * Bmat.transpose();
            }
            else{
                C  = std::vector< T >( Arows * Bcols, 0);
                Eigen::Map < Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Cmat(C.data(), Arows, Bcols);

                Cmat = Amat * Bmat;
            }

            return C;
        }

        template< typename T >
        int __matrixSqrtResidual(const std::vector< T > &A, const unsigned int Arows,
                                 const std::vector< T > &X,
                                 std::vector< double > &R, std::vector< std::vector< double > > &J){
            /*!
             * Compute the residual equation for the square root of a matrix.
             * This function is not intended to be accessed by the user.
             *
             * \param &A: The matrix A in row major form.
             * \param Arows: The number of rows in A.
             * \param &X: The estimate of the square root of A
             * \param &R: The value of the residual.
             * \param &J: The value of the jacobian.
             */

            Eigen::Map < const Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Amat(A.data(), Arows, Arows);
            Eigen::Map < const Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > Xmat(X.data(), Arows, Arows);

            R = std::vector< double >(Arows*Arows, 0);
            Eigen::Map < Eigen::Matrix< double, -1, -1, Eigen::RowMajor > > Rmat(R.data(), Arows, Arows);

            Eigen::Matrix< double, -1, -1 > temp;

            std::vector< double > eyeVec(Arows*Arows);
            eye(eyeVec);

            J = std::vector< std::vector< double > >(Arows*Arows, std::vector< double >(Arows*Arows, 0 ) );
            temp = Xmat;
            temp *= Xmat;
            Rmat = Amat - temp;

            for (unsigned int i=0; i<Arows; i++){
                for (unsigned int j=0; j<Arows; j++){
                    for (unsigned int k=0; k<Arows; k++){
                         for (unsigned int l=0; l<Arows; l++){
                             J[Arows*i + j][Arows*k + l] = -eyeVec[Arows*i + k]*X[Arows*l + j]
                                                           -X[Arows*i + k]*eyeVec[Arows*j + l];
                         }
                    }
                }
            }
            return 0;
        }

        template< typename T >
        std::vector< double > matrixSqrt(const std::vector< T > &A, const unsigned int Arows,
                                    const double tolr, const double tola, const unsigned int maxIter,
                                    const unsigned int maxLS){
            /*!
             * Solve for the square root of the square matrix A.
             *
             * \param &A: The matrix A in row major form.
             * \param Arows: The number of rows in A.
             * \param &dAdX: The gradient of A w.r.t. X
             * \param tolr: The relative tolerance.
             * \param tola: The absolute tolerance.
             * \param maxIter: The maximum number of iterations
             * \param maxLS: The maximum number of line search iterations.
             */

            std::vector< std::vector< double > > dAdX;
            return matrixSqrt(A, Arows, dAdX, tolr, tola, maxIter);
        }

        template< typename T >
        std::vector< double > matrixSqrt(const std::vector< T > &A, const unsigned int Arows,
                                    std::vector< std::vector< double > > &dAdX,
                                    const double tolr, const double tola, const unsigned int maxIter,
                                    const unsigned int maxLS){
            /*!
             * Solve for the square root of the square matrix A.
             *
             * \param &A: The matrix A in row major form.
             * \param Arows: The number of rows in A.
             * \param &dAdX: The gradient of A w.r.t. X
             * \param tolr: The relative tolerance.
             * \param tola: The absolute tolerance.
             * \param maxIter: The maximum number of iterations
             * \param maxLS: The maximum number of line search iterations.
             */

            if (A.size() != Arows * Arows){
                throw std::length_error("A has an incompatible shape");
            }

            //Initialize the output
            std::vector< double > X(Arows*Arows);
            eye(X);

            //Compute the first residual and jacobian
            std::vector< double > R;
            std::vector< std::vector< double > > J;

            __matrixSqrtResidual(A, Arows, X, R, J);

            double Rp = sqrt(dot(R, R));
            double Rnorm = Rp;
            double tol = tolr * Rp + tola;

            //Begin the Newton-Raphson loop
            unsigned int niter = 0;
            unsigned int rank;
            unsigned int nlsiter = 0;
            double lambda = 1.;
            std::vector< double > dX(Arows*Arows, 0);
            while ((Rp > tol) && (niter < maxIter)){
                dX = -solveLinearSystem(J, R, rank);
                if (rank < dX.size()){
                    std::cout << "niter: " << niter << "\n";
                    vectorTools::print(J);
                    throw std::invalid_argument("J is rank defficent");
                }

                X += dX;

                __matrixSqrtResidual(A, Arows, X, R, J);

                Rnorm = sqrt(dot(R, R));

                lambda = 1;
                nlsiter = 0;
                while ((Rnorm > (1 - 1e-4)*Rp) && (nlsiter < maxLS)){

                    X -= lambda * dX;
                    lambda *= 0.5;
                    X += lambda * dX;

                    __matrixSqrtResidual(A, Arows, X, R, J);
                    Rnorm = sqrt(dot(R, R));

                    nlsiter++;

                }

                if (Rnorm > (1 - 1e-4)*Rp){
                    throw std::invalid_argument("Failure in line search");
                }
                else{
                    Rp = Rnorm;
                }

                niter++;

            }

            if (Rp > tol){
                throw std::invalid_argument("Matrix square root did not converge");
            }

            //Set the jacobian
            dAdX = -J;

            return X;
        }

        template< typename T >
        void svd( const std::vector< T > &A, const unsigned int nrows, const unsigned int ncols,
                  std::vector< double > &U, std::vector< double > &Sigma,
                  std::vector< double > &V ){
            /*!
             * Compute the singular value decomposition of a real valued matrix A where A is of the form
             * A = U Sigma VT
             * where VT indicates the transpose.
             * 
             * \param &A: The matrix in row-major format
             * \param nrows: The number of rows in A
             * \param ncols: The number of columns in A
             * \param &U: The returned left-hand side unitary matrix in row-major format
             * \param &Sigma: The singular values
             * \param &V: The returned right-hand side unitary matrix in row-major format
             */

            if ( A.size( ) != nrows * ncols ){

                throw std::invalid_argument( "A's size is not consistent with the indicated number of rows and columns" );

            }

            // Clear and Re-size the output vectors
            U.clear( );
            U.resize( nrows * nrows );

            Sigma.clear( );
            Sigma.resize( std::min( nrows, ncols ) );

            V.clear( );
            V.resize( ncols * ncols );

            // Construct the Eigen Maps
            Eigen::Map< const Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > _A( A.data(), nrows, ncols );

            Eigen::Map< Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > _U( U.data(), nrows, nrows );

            Eigen::Map< Eigen::Matrix< T, -1,  -1, Eigen::RowMajor > > _Sigma( Sigma.data(), Sigma.size( ), 1 );

            Eigen::Map< Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > _V( V.data(), ncols, ncols );

            // Perform the singular value decomposition
            Eigen::JacobiSVD< Eigen::Matrix< T, -1, -1, Eigen::RowMajor > > _svd( _A, Eigen::ComputeFullU | Eigen::ComputeFullV );

            _U = _svd.matrixU( );

            _Sigma = _svd.singularValues( );

            _V = _svd.matrixV( );

            return;

        }

        template< typename T >
        void polar_decomposition( const std::vector< T > &A, const unsigned int nrows, const unsigned int ncols,
                                  std::vector< double > &R, std::vector< double > &U, const bool left ){
            /*!
             * Perform the polar decomposition of the matrix A. If left is false the decomposition will be:
             * 
             * A = R U
             * 
             * If left is true the decomposition will be:
             * A = U R
             * 
             * /param &A: The matrix to be decomposed
             * /param &nrows: The number of rows in A
             * /param &ncols: The number of columns in A
             * /param &R: The rotation tensor
             * /param &U: The stretch tensor. Left or right stretch is determined by the parameter `left`
             * /param &left: The flag indicating of the right decomposition (A = RU) or the left decomposition
             *     (A = UR) is to be performed.
             */

            // Compute Usqrd
            std::vector< double > Usqrd;
            unsigned int Urows;

            if ( left ){

                Usqrd = vectorTools::matrixMultiply( A, A, nrows, ncols, ncols, nrows, 0, 1 );
                Urows = nrows;

            }
            else{

                Usqrd = vectorTools::matrixMultiply( A, A, ncols, nrows, nrows, ncols, 1, 0 );
                Urows = ncols;

            }

            // Perform the matrix square root of Usqrd
            U = matrixSqrt( Usqrd, Urows );

            // Compute the rotation matrix
            std::vector< double > Uinv = vectorTools::inverse( U, nrows, ncols );

            if ( left ){

                R = vectorTools::matrixMultiply( Uinv, A, nrows, nrows, nrows, ncols, 0, 0 );

            }
            else{

                R = vectorTools::matrixMultiply( A, Uinv, nrows, ncols, ncols, ncols, 0, 0 );

            }

            return;
        }

    #endif
}
