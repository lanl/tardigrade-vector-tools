/******************************************************************************
*                               vector_tools.cpp                              *
===============================================================================
* A collection of functions and related utilities intended to help perform    *
* vector operations in cpp.                                                   *
*******************************************************************************
*/

#include "vector_tools.h"


//Operator overloading
template<typename T>
std::vector<T>& operator+=(std::vector<T> &lhs, const std::vector<T> &rhs){
    /*!
     * Overload the += operator for vectors
     * 
     * :param std::vector<T> &lhs: The left-hand side vector
     * :param std::vector<T> &rhs: The right-hand side vector
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
std::vector<T> operator+(std::vector<T> lhs, const std::vector<T> &rhs){
    /*!
     * Overload the + operator for vectors
     * 
     * :param std::vector<T> &lhs: The left-hand side vector
     * :param std::vector<T> &rhs: The right-hand side vector
     */

    if (lhs.size() != rhs.size()){
        throw std::length_error("vectors must be the same size to add");
    }
    return lhs += rhs;
}

template<typename T>
std::vector<T> operator-(std::vector<T> v){
    /*!
     * Overload the negative operator for vectors
     * 
     * :param std::vector<T> &v: The vector in question
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
     * :param std::vector<T> &lhs: The left-hand side vector
     * :param std::vector<T> &rhs: The right-hand side vector
     */
    return lhs += -rhs;
}

template<typename T>
std::vector<T> operator-(std::vector<T> lhs, const std::vector<T> &rhs){
    /*!
     * Overload the subtraction operator for vectors
     * 
     * :param std::vector<T> &lhs: The left-hand side vector
     * :param std::vector<T> &rhs: The right-hand side vector
     */
    
    return lhs -= rhs;
}


template<typename T, typename t>
std::vector<T>& operator*=(std::vector<T> &lhs, const t rhs){
    /*!
     * Overload the *= operator for vectors
     * 
     * :param std::vector<T> lhs: The left-hand side vector
     * :param const t rhs: The right-hand side scalar
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
     * :param const t lhs: The left-hand side scalar
     * :param std::vector<T> rhs: The right-hand side vector
     */
    return rhs*=lhs;
}


template<typename T, typename t>
std::vector<T> operator*(std::vector<T> lhs, const t rhs){
    /*!
     * Overload the / operator for vectors
     * 
     * :param std::vector<T> lhs: The left-hand side vector
     * :param const t rhs: The right-hand side scalar
     */
    return lhs*=rhs;
}

template<typename T, typename t>
std::vector<T>& operator/=(std::vector<T> &lhs, const t rhs){
    /*!
     * Overload the /= operator for vectors
     * 
     * :param std::vector<T> lhs: The left-hand side vector
     * :param const t rhs: The right-hand side scalar
     */
    return lhs*=(1./rhs);
}

template<typename T, typename t>
std::vector<T> operator/(std::vector<T> lhs, const t rhs){
    /*!
     * Overload the / operator for vectors
     * 
     * :param std::vector<T> lhs: The left-hand side vector
     * :param const t rhs: The right-hand side scalar
     */
    return lhs/=rhs;
}

namespace vectorTools{

    //Computation Utilities
    template<typename T>
    int computeMean(const std::vector< std::vector< T > > &A, std::vector< T > &v){
        /*!
         * Compute the column-wise mean of A
         * 
         * :param matrixType &A: The matrix of vectors
         * :param vectorType &v: The resulting mean
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
         * :param matrixType &A: The matrix of vectors
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
         * :param std::vector< T > &a: The first vector
         * :param std::vector< T > &b: The second vector
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
         * :param std::vector< T > &a: The first vector
         * :param std::vector< T > &b: The second vector
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
         * :param std::vector< T > &a: The first vector
         * :param std::vector< T > &b: The second vector
         * :param T &v: The output quantity
         */

        //Get the size and perform error handing
        size_type size = a.size();
        if (size != b.size()){
            throw std::length_error("vectors must be the same size to add");
        }

        //Set v to null
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
         * :param std::vector< T > &a: The first vector
         * :param std::vector< T > &b: The second vector
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
         * :param std::vector< std::vector< T > > &A: The matrix
         * :param std::vector< T > &b: The vector
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
    double l2norm(const std::vector< T > &v){
        /*!
         * Compute the l2 norm of the vector v i.e. (v_i v_i)^(0.5)
         * 
         * :param const std::vector< T > &v: The vector to compute the norm of
         */

        return std::sqrt(dot(v, v));
    }

    template<typename T>
    double l2norm(const std::vector< std::vector < T > > &A){
        /*!
         * Compute the l2 norm of the matrix A i.e. (A_ij A_ij)^(0.5)
         * 
         * :param const std::vector< std::vector< T > > &A: The matrix to compute the norm of
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
         * :param const std::vector< T > &a: The first vector
         * :param const std::vector< T > &b: The second vector
         * :param std::vector< std::vector< T > > &A: The returned matrix
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

    //Comparison Utilities
    template< typename T >
    bool fuzzyEquals(const T &a, const T &b, double tolr, double tola){
        /*!
         * Compare two values to determine if they are equal within a 
         * tolerance.
         * 
         * :param const T &a: The first value to compare
         * :param const T &b: The second value to compare
         * :param double tolr: The relative tolerance
         * :param double tola: The absolute tolerance
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
         * :param const std::vector< T > &a: The first vector to compare
         * :param const std::vector< T > &b: The second vector to compare
         * :param double tolr: The relative tolerance
         * :param double tola: The absolute tolerance
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
         * :param const std::vector< std::vector< T > > &a: The first matrix to compare
         * :param const std::vector< std::vector< T > > &b: The second matrix to compare
         * :param double tolr: The relative tolerance
         * :param double tola: The absolute tolerance
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
         * :param const T &a: The first value to compare
         * :param const T &b: The second value to compare
         */
         return a == b;
    }
    
    template<typename T>
    bool equals(const std::vector< T > &a, const std::vector< T > &b){
        /*!
         * Compare two vectors for exact equality
         * 
         * :param const std::vector< T > &a: The first vector to compare
         * :param const std::vector< T > &b: The second vector to compare
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
         * :param const std::vector< T > &a: The first matrix to compare
         * :param const std::vector< T > &b: The second matrix to compare
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
         * :param std::vector< T > &v1: The first vector
         * :param std::vector< T > &v2: The second vector
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
         * :param const std::vector< T > &v: The vector from which to retrieve get a sub-vector
         * :param const std::vector< size_type > &indices: The indices to retrieve
         * :param std::vector< T > &subv: The subvector of values
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
         * :param const std::vector< std::vector< T > > &A: The matrix to be appended
         */

        std::vector< T > Avec;
        
        for (auto Ai=A.begin(); Ai!=A.end(); Ai++){
            Avec.insert(Avec.end(), (*Ai).begin(), (*Ai).end());
        }
        return Avec;
    }

    //Sorting Utilities
    template<typename T>
    std::vector< size_type > argsort(const std::vector< T > &v){
        /*!
         * Find the indices required to sort a vector
         * Code from: https://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes
         * 
         * :param const std::vector< T > &v: The vector to get the index sorted properties.
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
         * :param std::vector< T > &v: The vector to be displayed
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
         * :param std::vector< std::vector< T > > &A: The matrix to be displayed
         */

        for (auto it = A.begin(); it!=A.end(); it++){
            print(*it);
        }
        return 0;
    }

    #ifdef USE_EIGEN
        template<typename T>
        std::vector< double > solveLinearSystem(const std::vector< std::vector< T > > &A, const std::vector< T > &b,
            unsigned int &rank){
            /*!
             * Solve a linear system of equations using Eigen. Note this uses a dense solver.
             * 
             * :param const std::vector< std::vector< T > > &A: The A matrix
             * :param const std::vector< T > &b: The b vector
             * :param unsigned int &rank: The rank of A
             */

            //Get the number of rows in A
            unsigned int nrows = A.size();

            //Append all of the vectors into one long vector
            const std::vector< T > Avec = appendVectors( A );

            unsigned int ncols = Avec.size()/nrows;
            if ((Avec.size() % nrows) > 0){
                std::cerr << "Error: A is not a regular matrix.";
                assert(1==0);
            }
            return solveLinearSystem( Avec, b, nrows, ncols, rank);

        }

        template<typename T>
        std::vector< double > solveLinearSystem(const std::vector< T > &Avec, const std::vector< T > &b,
            const unsigned int nrows, const unsigned int ncols, unsigned int &rank){
            /*!
             * Solve a linear system of equations using Eigen.
             * 
             * :param const std::vector< T > &Avec: The vector form of the A matrix (row major)
             * :param const std::vector< T > &b: The b vector
             * :param const unsigned int nrows: The number of rows of A
             * :param const unsigned int ncols: The number of columns of A
             * :param unsigned int &rank: The rank of A
             */

            if (Avec.size() != (nrows*ncols)){
                std::cerr << "Error: The size of Avec and the dimensions nrows and ncols do not align.\n";
                assert(1==0);
            }

            //Set up the Eigen maps for A and b
            Eigen::Map< const Eigen::Matrix<T, -1, -1, Eigen::RowMajor> > Amat(Avec.data(), nrows, ncols);
            Eigen::Map< const Eigen::Matrix<T, -1,  1> > bmat(b.data(), nrows, 1);

            //Set up the Eigen maps for the solution vector
            std::vector< double > x(nrows);
            Eigen::Map< Eigen::MatrixXd > xmat(x.data(), nrows, 1);

            //Perform the decomposition
            Eigen::ColPivHouseholderQR<Eigen::Matrix<T, -1, -1, Eigen::RowMajor>> qrSolver(Amat);

            rank = qrSolver.rank();

            xmat = qrSolver.solve(bmat);
            return x;
        }

    #endif
}
