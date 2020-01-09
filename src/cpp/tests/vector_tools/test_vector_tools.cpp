#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#define USE_EIGEN
#include<vector_tools.h>

typedef double floatType;
typedef std::vector< floatType > vectorType;
typedef std::vector< vectorType > matrixType;

void print(vectorType a){
    /*!
    Print the vector to the terminal
    */

    for (unsigned int i=0; i<a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void print(matrixType A){
    /*!
    Print the matrix to the terminal
    */

    for (unsigned int i=0; i<A.size(); i++){
        print(A[i]);
    }
}

int test_addition_operators(std::ofstream &results){
    /*!
     * Test the addition operators
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = { 1, 2, 3};
    vectorType b = {-2, 7, 2};
    vectorType c;

    a += b;

    if (!vectorTools::fuzzyEquals(a, {-1, 9, 5})){
        results << "test_addition_operators (test 1) & False\n";
        return 1;
    }

    c = a + b;

    if (!vectorTools::fuzzyEquals(c, {-3, 16, 7})){
        results << "test_addition_operators (test 2) & False\n";
        return 1;
    }

    //All tests passed    
    results << "test_addition_operators & True\n";
    return 0;
}

int test_subtraction_operators(std::ofstream &results){
    /*!
     * Test the subtraction operators
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = { 1, 2, 3};
    vectorType b = {-2, 7, 2};
    vectorType c;

    if (!vectorTools::fuzzyEquals(-a, {-1, -2, -3})){
        results << "test_subtraction_operators (test 1) & False\n";
        return 1;
    }

    a -= b;

    if (!vectorTools::fuzzyEquals(a, {3, -5, 1})){
        results << "test_subtraction_operators (test 2) & False\n";
        return 1;
    }

    c = a - b;

    if (!vectorTools::fuzzyEquals(c, {5,-12, -1})){
        results << "test_subtraction_operators (test 3) & False\n";
        return 1;
    }

    //All tests passed    
    results << "test_subtraction_operators & True\n";
    return 0;
}

int test_multiplication_operators(std::ofstream &results){
    /*!
     * Test the multiplication operators
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = { 1, 2, 3};
    vectorType b, c;


    a *= 2;

    if (!vectorTools::fuzzyEquals(a, {2, 4, 6})){
        results << "test_multiplication_operators (test 1) & False\n";
        return 1;
    }

    b = 3*a;
    c = a*3;

    if (!vectorTools::fuzzyEquals(b, c) && !vectorTools::fuzzyEquals(b, {6, 12, 18})){
        results << "test_multiplication_operators (test 2) & False\n";
        return 1;
    }

    //All tests passed    
    results << "test_multiplication_operators & True\n";
    return 0;
}

int test_division_operators(std::ofstream &results){
    /*!
     * Test the division operators
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = { 1, 2, 3};
    vectorType b;


    a /= 2;

    if (!vectorTools::fuzzyEquals(a, {0.5, 1, 1.5})){
        results << "test_division_operators (test 1) & False\n";
        return 1;
    }

    b = a/2;

    if (!vectorTools::fuzzyEquals(b, {0.25, 0.5, 0.75})){
        results << "test_division_operators (test 2) & False\n";
        return 1;
    }

    //All tests passed    
    results << "test_division_operators & True\n";
    return 0;
}

int test_computeMean(std::ofstream &results){
    /*!
     * Test the computation of the mean of a vector of vectors
     * 
     * :param std::ofstream &results: The output file
     */

    matrixType A = {{ 1,  2, 3.0, 4},
                    {-4, 13, 0.4, 5},
                    { 2,  6, 1.0, 7}};

    vectorType answer = {-1./3, 7, 8.8/6, 5 + 1/3.};
    vectorType result;
    vectorTools::computeMean(A, result);

    if (!vectorTools::fuzzyEquals(result, answer)){
        results << "test_computeMean (test 1) & False\n";
        return 1;
    }

    result = vectorTools::computeMean(A);
    if (!vectorTools::fuzzyEquals(result, answer)){
        results << "test_computeMean (test 2) & False\n";
        return 1;
    }

    results << "test_computeMean & True\n";
    return 0;
}

int test_cross(std::ofstream &results){
    /*!
     * Test the computation of the cross product of two vectors
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = { 1, 2};
    vectorType b = {-1, 7};
    vectorType c;

    vectorTools::cross(a, b, c);

    if (!vectorTools::fuzzyEquals(c, {0, 0, 9})){
        results << "test_cross (test 1) & False\n";
        return 1;
    }

    a = {1, 2, 3};
    b = {-1, 7, -3};

    vectorTools::cross(a, b, c);

    if (!vectorTools::fuzzyEquals(c, {-27, 0, 9})){
        results << "test_cross (test 2) & False\n";
        return 1;
    }

    c = vectorTools::cross(a, b);

    if (!vectorTools::fuzzyEquals(c, {-27, 0, 9})){
        results << "test_cross (test 3) & False\n";
        return 1;
    }

    results << "test_cross & True\n";
    return 0;
}

int test_dot(std::ofstream &results){
    /*!
     * Test the computation of the dot product of two vectors
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = { 1, 2, 3};
    vectorType b = {-1, 7, 6};
    floatType c;
    
    vectorTools::dot(a, b, c);

    if (!vectorTools::fuzzyEquals<floatType>(c, -1 + 14 + 18)){
        results << "test_dot (test 1) & False\n";
        return 1;
    }

    c = vectorTools::dot(a, b);
    if (!vectorTools::fuzzyEquals<floatType>(c, -1 + 14 + 18)){
        results << "test_dot (test 2) & False\n";
        return 1;
    }

    matrixType A = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
    vectorType d;

    d = vectorTools::dot(A, a);

    if (!vectorTools::fuzzyEquals(d, {14, 32, 50})){
        results << "test_dot (test 3) & False\n";
        return 1;
    }

    matrixType B = {{10, 11, 12},
                    {13, 14, 15},
                    {16, 17, 18}};

    matrixType C = vectorTools::dot(A, B);

    if (!vectorTools::fuzzyEquals(C, {{ 84,  90,  96},
                                      {201, 216, 231},
                                      {318, 342, 366}})){
        results << "test_dot (test 4) & False\n";
        return 1;
    }

    results << "test_dot & True\n";
    return 0;
}

int test_inner(std::ofstream &results){

    //Initialize test variables
    vectorType Avec, Bvec ;
    Avec = Bvec = {1., 0., 0., 
                   0., 1., 0.,
                   0., 0., 1.};
    matrixType A, B;
    A = B = {{1., 0., 0.}, 
             {0., 1., 0.},
             {0., 0., 1.}};
    floatType expected = 3.;
    floatType result;
    
    //Test inner product of row major matrices
    result = 0.;
    vectorTools::inner(Avec, Bvec, result);
    if (!vectorTools::fuzzyEquals(result, expected)){
        results << "test_inner (test 1) & False\n";
        return 1;
    }

    result = 0.;
    result = vectorTools::inner(Avec, Bvec);
    if (!vectorTools::fuzzyEquals(result, expected)){
        results << "test_inner (test 2) & False\n";
        return 1;
    }

    //Test inner product of matrices
    result = 0.;
    vectorTools::inner(A, B, result);
    if (!vectorTools::fuzzyEquals(result, expected)){
        results << "test_inner (test 3) & False\n";
        return 1;
    }

    result = 0.;
    result = vectorTools::inner(A, B);
    if (!vectorTools::fuzzyEquals(result, expected)){
        results << "test_inner (test 4) & False\n";
        return 1;
    }

    results << "test_inner & True\n";
    return 0;
}

int test_trace(std::ofstream &results){
    /*!
     * Test the computation of the trace for a square matrix
     *
     * :param std::ofstream &results: The output file
     */

    vectorType a = {1., 0., 0., 
                    0., 1., 0.,
                    0., 0., 1.};
    floatType c;

    vectorTools::trace(a, c);

    if (!vectorTools::fuzzyEquals<floatType>(c, 3.)){
        results << "test_trace (test 1) & False\n";
        return 1;
    }

    //TODO: Refactor with boost or pytest
    vectorType b = {1., 0., 0., 
                    0., 1., 0.,
                    0., 1., 0.,
                    0., 0., 1.};

    try{
        vectorTools::trace(b, c);
    }
    catch( std::length_error ){
    }
    catch(...){
        results << "test_trace (test 2) & False\n";
        return 1;
    }

    c = 0.;
    c = vectorTools::trace(a);
    if (!vectorTools::fuzzyEquals<floatType>(c, 3.)){
        results << "test_trace (test 3) & False\n";
        return 1;
    }

    matrixType A = {{1., 0., 0.},
                    {0., 1., 0.},
                    {0., 0., 1.}};

    c = 0.;
    vectorTools::trace(A, c);
    if (!vectorTools::fuzzyEquals<floatType>(c, 3.)){
        results << "test_trace (test 4) & False\n";
        return 1;
    }

    c = 0.;
    c = vectorTools::trace(A);
    if (!vectorTools::fuzzyEquals<floatType>(c, 3.)){
        results << "test_trace (test 5) & False\n";
        return 1;
    }

    results << "test_trace & True\n";
    return 0;
}

int test_l2norm(std::ofstream &results){
    /*!
     * Test the computation of the l2norm of vectors and matrices
     *
     * :param std::ofstream &results: The output file
     */

    vectorType a = {1, 2, 3};
    matrixType A = {{1, 2, 3, 4},
                    {5, 6, 7, 8}};

    double r = vectorTools::l2norm(a);
    if (!vectorTools::fuzzyEquals(r, 3.7416573867739413)){
        results << "test_l2norm (test 1) & False\n";
        return 1;
    }

    r = vectorTools::l2norm(A);
    if (!vectorTools::fuzzyEquals(r, 14.2828568570857)){
        results << "test_l2norm (test 2) & False\n";
        return 1;
    }

    results << "test_l2norm & True\n";
    return 0;
}

int test_argsort(std::ofstream &results){
    /*!
     * Test the utility that returns the indices required to sort a vector
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType a = {1, -2, 7, 3, 9, 11};
    std::vector< unsigned int > idx = vectorTools::argsort(a);

    if (!vectorTools::equals(idx, {1, 0, 3, 2, 4, 5})){
        results << "test_argsort (test 1) & False\n";
        return 1;
    }

    results << "test_argsort & True\n";
    return 0;
}

int test_fuzzyEquals(std::ofstream &results){
    /*!
     * Test the tolerant compare function
     * 
     * :param std::ofstream &results
     */

    matrixType a = {{1, -2, 3, 2.4, 1e-9, -1e-7},
                    {1.4, 8.5, 1 + 1e-9, 4, -2+1e-3, 100}};

    if(!vectorTools::fuzzyEquals(a, {{1, -2, 3, 2.4, 0, 0},
                                     {1.4, 8.5, 1, 4, -2+1e-3+1e-9, 100+1e-4}})){
        results << "test_fuzzyEquals (test 1) & False\n";
        return 1;
    }

    results << "test_fuzzyEquals & True\n";
    return 0;
}

int test_equals(std::ofstream &results){
    /*!
     * Test the exact equality function
     * 
     * :param std::ofstream &results:
     */

    unsigned int a = 1;
    std::vector< unsigned int > v = {1, 2, 3, 4};
    std::vector< std::vector< unsigned int > > m = {{1, 2, 3},
                                                    {4, 5, 6},
                                                    {7, 8, 9}};

    if (!vectorTools::equals<unsigned int>(a, 1)){
        results << "test_equals (test 1) & False\n";
        return 1;
    }

    if (vectorTools::equals<unsigned int>(a, 2)){
        results << "test_equals (test 2) & False\n";
        return 1;
    }

    if (!vectorTools::equals(v, {1, 2, 3, 4})){
        results << "test_equals (test 3) & False\n";
        return 1;
    }

    if (vectorTools::equals(v, {1, 2, 2, 4})){
        results << "test_equals (test 4) & False\n";
        return 1;
    }

    if (!vectorTools::equals(m, {{1, 2, 3},
                                 {4, 5, 6},
                                 {7, 8, 9}})){
        results << "test_equals (test 5) & False\n";
        return 1;
    }

    if (vectorTools::equals(m, {{1, 2, 3},
                                {4, 5, 4},
                                {7, 8, 9}})){
        results << "test_equals (test 6) & False\n";
        return 1;
    }

    results << "test_equals & True\n";
    return 0;
}

int test_getValuesByIndex(std::ofstream &results){
    /*!
     * Test the retrieval of values of a vector as 
     * indicated by vector of indices.
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType v = {1, 2, 3, 4, 5, 6};
    matrixType m = {{ 1,  2,  3},
                    { 4,  5,  6},
                    { 7,  8,  9},
                    {10, 11, 12},
                    {13, 14, 15}};

    std::vector< vectorTools::size_type > indices = {1, 3, 0};

    vectorType rv;
    vectorTools::getValuesByIndex(v, indices, rv);
    if (!vectorTools::fuzzyEquals(rv, {2, 4, 1})){
        results << "test_getValuesByIndex (test 1) & False\n";
        return 1;
    }

    matrixType rm;
    vectorTools::getValuesByIndex(m, indices, rm);
    if (!vectorTools::fuzzyEquals(rm, {{4, 5, 6},{10, 11, 12},{1, 2, 3}})){
        results << "test_getValuesByIndex (test 2) & False\n";
        return 1;
    }

    results << "test_getValuesByIndex & True\n";
    return 0;
}

int test_appendVectors(std::ofstream &results){
    /*!
     * Test the utility to append a vector of vectors into a row-major vector.
     * 
     * :param const std::ofstream &results: The output file
     */

    matrixType m = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vectorType v = vectorTools::appendVectors(m);
    
    if (!vectorTools::fuzzyEquals(v, {1, 2, 3, 4, 5, 6, 7, 8, 9})){
        results << "test_appendVectors (test 1) & False\n";
        return 1;
    }

    v.clear();
    vectorType v1 = {1, 7, 5};
    vectorType v2 = {4, 6, 2};
    v = vectorTools::appendVectors({v1, v2});

    if (!vectorTools::fuzzyEquals(v, {1, 7, 5, 4, 6, 2})){
        results << "test_appendVectors (test 2) & False\n";
        return 1;
    }

    results << "test_appendVectors & True\n";
    return 0;
}

int test_solveLinearSystem(std::ofstream &results){
    /*!
     * Test the utility to solve a linear system of equations.
     * 
     * :param std::ofstream &results: The output file
     */

    matrixType A = {{0.95617934, 0.41311152, 0.25812163},
                    {0.13346546, 0.12864080, 0.65152997},
                    {0.15425579, 0.35444563, 0.43177476}};

    vectorType b = {0.92263585, 0.96720703, 0.72477723};

    vectorType xSolution = {0.52372037, 0.18327279, 1.34104665};

    unsigned int rank;

    vectorType xAnswer = vectorTools::solveLinearSystem(A, b, rank);

    if (!vectorTools::fuzzyEquals(xSolution, xAnswer)){
        results << "test_solveLinearSystem (test 1) & False\n";
        return 1;
    }

    if (!vectorTools::equals<unsigned int>(rank, 3)){
        results << "test_solveLinearSystem (test 1) & False\n";
        return 1;
    }

    results << "test_solveLinearSystem & True\n";
    return 0;
}

int test_isParallel(std::ofstream &results){
    /*!
     * Test the utility that tests if two vectors are parallel or not
     * 
     * :param std::ofstream &results: The output file
     */

    vectorType v1 = {1, 2, 3};
    vectorType v2 = {2, 4, 6};

    if (!vectorTools::isParallel(v1, v2)){
        results << "test_isParallel (test 1) & False\n";
        return 1;
    }

    v1 = {0, 2, 3};
    if (vectorTools::isParallel(v1, v2)){
        results << "test_isParallel (test 2) & False\n";
        return 1;
    }

    std::vector< int > v3 = {1, 2, 3};
    std::vector< int > v4 = {2, 4, 6};

    if (!vectorTools::isParallel(v3, v4)){
        results << "test_isParallel (test 3) & False\n";
        return 1;
    }

    v3[0] = 0;
    if (vectorTools::isParallel(v3, v4)){
        results << "test_isParallel (test 4) & False\n";
        return 1;
    }

    results << "test_isParallel & True\n";
    return 0;
}

int test_dyadic(std::ofstream &results){
    /*!
     * Test the computation of the dyadic product between two vectors
     * 
     * :param std::ofstream &results:
     */

    vectorType v1 = {1, 2, 3};
    vectorType v2 = {4, 5, 6};
    matrixType A = vectorTools::dyadic(v1, v2);

    if (!vectorTools::fuzzyEquals(A, {{ 4,  5,  6},
                                      { 8, 10, 12},
                                      {12, 15, 18}})){
        results << "test_dyadic (test 1) & False\n";
        return 1;
    }

    results << "test_dyadic & True\n";
    return 0;
}

int test_eye(std::ofstream &results){
    /*!
     * Test the formation of an identity matrix
     * 
     * :param std::ofstream &results:
     */

    std::vector< double > Ivec(9, 1.);
    std::vector< double > IvecExpected = {1., 0., 0.,
                                          0., 1., 0.,
                                          0., 0., 1.};
    int result = vectorTools::eye(Ivec);
    if (!vectorTools::fuzzyEquals(Ivec,IvecExpected)){
        results << "test_eye (test 1) & False\n";
        return 1;
    }

    unsigned int dim = 4;
    std::vector< std::vector< double > > I = vectorTools::eye< double >(dim);
    
    if (!vectorTools::fuzzyEquals(I, {{1, 0, 0, 0},
                                      {0, 1, 0, 0},
                                      {0, 0, 1, 0},
                                      {0, 0, 0, 1}})){
        results << "test_eye (test 2) & False\n";
        return 1;
    }

    I.clear();
    vectorTools::eye(dim, I);

    if (!vectorTools::fuzzyEquals(I, {{1, 0, 0, 0},
                                      {0, 1, 0, 0},
                                      {0, 0, 1, 0},
                                      {0, 0, 0, 1}})){
        results << "test_eye (test 3) & False\n";
        return 1;
    }

    results << "test_eye & True\n";
    return 1;
}

int test_determinant(std::ofstream &results){
    /*!
     * Test the computation of the determinant of a matrix
     * 
     * :param std::ofstream &results: The output file
     */

    std::vector< floatType > Avec = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    if (!vectorTools::fuzzyEquals(vectorTools::determinant(Avec, 3, 3), 1.)){
        results << "test_determinant (test 1) & False\n";
        return 1;
    }

    Avec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    if (!vectorTools::fuzzyEquals(vectorTools::determinant(Avec, 3, 3), 0.)){
        results << "test_determinant (test 2) & False\n";
        return 1;
    }

    Avec = {1, 2, 3, 4};
    if (!vectorTools::fuzzyEquals(vectorTools::determinant(Avec, 2, 2), -2.)){
        results << "test_determinant (test 3) & False\n";
        return 1;
    }

    results << "test_determinant & True\n";
    return 0;
}

int test_inverse(std::ofstream &results){
    /*!
     * Test the computation of the matrix inverse\n";
     *
     * :param std::ofstream &results: The output file
     */

    std::vector< floatType > A = {0.39874077,  0.11561812, -0.75485222,
                                  0.14034205,  0.15851022,  1.29640525,
                                  0.26235075, -0.26051883,  0.45378251};

    std::vector< floatType > Ainv = vectorTools::inverse(A, 3, 3);

    if (!vectorTools::fuzzyEquals(Ainv, {1.6109566 ,  0.56699734,  1.0599259 ,
                                         1.08701345,  1.49027454, -2.44933462,
                                        -0.30730183,  0.52776914,  0.18473576})){
        vectorTools::print(Ainv);
        results << "test_inverse (test 1) & False\n";
        return 1;
    }

    results << "test_inverse & True\n";
    return 0;
}

int test_computeDDetAdJ(std::ofstream &results){
    /*!
     * Test the computation of the derivative of the determinant w.r.t. 
     * the matrix.
     * 
     * :param std::ofstream &results: The output file
     */

    std::vector< floatType > A = {0.39874077,  0.11561812, -0.75485222,
                                  0.14034205,  0.15851022,  1.29640525,
                                  0.26235075, -0.26051883,  0.45378251};

    std::vector< floatType > ddetAdA = vectorTools::computeDDetAdJ(A, 3, 3);

    floatType eps = 1e-6;
    floatType detA0 = vectorTools::determinant(A, 3, 3);
    floatType detA;

    for (unsigned int i=0; i<A.size(); i++){
        std::vector< floatType > delta(A.size(), 0);
        delta[i] = fabs(A[i]*eps);
        detA = vectorTools::determinant(A + delta, 3, 3);

        if (!vectorTools::fuzzyEquals((detA - detA0)/delta[i], ddetAdA[i])){
            results << "test_computeDDetAdJ (test 1) & False\n";
            return 1;
        }

    }

    results << "test_computeDDetAdJ & True\n";
    return 1;
}

int test_matrixMultiply(std::ofstream &results){
    /*!
     * Test the matrix multiplication function.
     * 
     * :param std::ofstream &results: The output file.
     */

    vectorType A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vectorType B = {10, 11, 12, 13, 14, 15, 16, 17, 18};
    vectorType C;

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 0, 0);

    if (!vectorTools::fuzzyEquals(C, {84,  90,  96, 201, 216, 231, 318, 342, 366})){
        results << "testMatrixMultiply (test 1) & False\n";
        return 1;
    }

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 1, 0);

    if (!vectorTools::fuzzyEquals(C, {174, 186, 198, 213, 228, 243, 252, 270, 288})){
        results << "testMatrixMultiply (test 2) & False\n";
        return 1;
    }

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 0, 1);

    if (!vectorTools::fuzzyEquals(C, { 68,  86, 104, 167, 212, 257, 266, 338, 410})){
        results << "testMatrixMultiply (test 3) & False\n";
        return 1;
    }

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 1, 1);

    if (!vectorTools::fuzzyEquals(C, {138, 174, 210, 171, 216, 261, 204, 258, 312})){
        results << "testMatrixMultiply (test 4) & False\n";
        return 1;
    }

    results << "testMatrixMultiply & True\n";
    return 0;
}

int test_matrixSqrt(std::ofstream &results){
    /*!
     * Test the computation of the square root of a matrix.
     * 
     * :param std::ofstream &results: The output file.
     * 
     */

    vectorType A = {3.,  3.,  5.,  3.,  7.,  7.,  5.,  7., 11.};
    unsigned int dim = 3;

    vectorType X = vectorTools::matrixSqrt(A, 3);

    if (!vectorTools::fuzzyEquals(A, vectorTools::matrixMultiply(X, X, dim, dim, dim, dim, 0, 0)  )){
        results << "testMatrixSqrt (test 1) & False\n";
        return 1;
    }

    results << "testMatrixSqrt & True\n";
    return 0;
}

int main(){
    /*!
    The main loop which runs the tests defined in the 
    accompanying functions. Each function should output
    the function name followed by & followed by True or False 
    if the test passes or fails respectively.
    */

    //Open the results file
    std::ofstream results;
    results.open("results.tex");

    //Test the operator overloading
    test_addition_operators(results);
    test_subtraction_operators(results);
    test_multiplication_operators(results);
    test_division_operators(results);

    //Test the utility functions
    test_computeMean(results);
    test_cross(results);
    test_dot(results);
    test_inner(results);
    test_trace(results);
    test_l2norm(results);
    test_argsort(results);
    test_fuzzyEquals(results);
    test_equals(results);
    test_getValuesByIndex(results);
    test_appendVectors(results);
    test_solveLinearSystem(results);
    test_isParallel(results);
    test_dyadic(results);
    test_eye(results);
    test_determinant(results);
    test_inverse(results);
    test_computeDDetAdJ(results);
    test_matrixMultiply(results);
    test_matrixSqrt(results);

    //Close the results file
    results.close();

    return 0;

}
