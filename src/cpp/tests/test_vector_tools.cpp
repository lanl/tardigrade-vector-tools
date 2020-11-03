/**
  * \file test_vector_tools.cpp
  *
  * Tests for vector_tools
  */

#include<vector>
#include<iostream>
#include<fstream>
#include<math.h>
#define USE_EIGEN
#include<vector_tools.h>

#define BOOST_TEST_MODULE test_error_tools
#include <boost/test/included/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

typedef double floatType;
typedef std::vector< floatType > vectorType;
typedef std::vector< vectorType > matrixType;

void print(vectorType a){
    /*!
     * Print the vector to the terminal
     */

    for (unsigned int i=0; i<a.size(); i++){
        std::cout << a[i] << " ";
    }
    std::cout << "\n";
}

void print(matrixType A){
    /*!
     * Print the matrix to the terminal
     */

    for (unsigned int i=0; i<A.size(); i++){
        print(A[i]);
    }
}

BOOST_AUTO_TEST_CASE( test_addition_operators ){
    /*!
     * Test the addition operators
     *
     */

    vectorType a = { 1, 2, 3};
    vectorType b = {-2, 7, 2};
    vectorType c;

    matrixType A = {{1, 2, 3},
                    {4, 5, 6}};
    matrixType B = {{-1, -3, -3},
                    { 2,  5,  6}};
    matrixType C;

    a += b;

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {-1, 9, 5}) );

    c = a + b;

    BOOST_CHECK( vectorTools::fuzzyEquals(c, {-3, 16, 7}) );

    a += 1.;

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {0, 10, 6}) );

    c = a + 2.;
    BOOST_CHECK( vectorTools::fuzzyEquals(c, {2, 12, 8}) && !vectorTools::fuzzyEquals(a, {0, 10, 6}) );

    c = 2. + a;
    BOOST_CHECK( vectorTools::fuzzyEquals(c, {2, 12, 8}) && !vectorTools::fuzzyEquals(a, {0, 10, 6}) );

    A += B;
    BOOST_CHECK( vectorTools::fuzzyEquals(A, {{0,-1, 0},
                                              {6, 10, 12}}) );

    C = A + B;
    BOOST_CHECK( vectorTools::fuzzyEquals(C, {{-1, -4, -3},
                                              { 8, 15, 18}}) );

}

BOOST_AUTO_TEST_CASE( test_subtraction_operators ){
    /*!
     * Test the subtraction operators
     *
     */

    vectorType a = { 1, 2, 3};
    vectorType b = {-2, 7, 2};
    vectorType c;

    matrixType A = {{1, 2, 3},
                    {4, 5, 6}};
    matrixType B = {{-1, -3, -3},
                    { 2,  5,  6}};
    matrixType C;


    BOOST_CHECK( vectorTools::fuzzyEquals(-a, {-1, -2, -3}) );

    a -= b;

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {3, -5, 1}) );

    c = a - b;

    BOOST_CHECK( vectorTools::fuzzyEquals(c, {5,-12, -1}) );

    a -= 1.;

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {2, -6, 0}) );

    c = a - 2.;
    BOOST_CHECK( vectorTools::fuzzyEquals(c, {0, -8, -2}) && !vectorTools::fuzzyEquals(a, {2, -6, 0}) );

    c = 2. - a;
    BOOST_CHECK( vectorTools::fuzzyEquals(c, {0, 8, 2}) && !vectorTools::fuzzyEquals(a, {2, -6, 0}) );

    BOOST_CHECK( vectorTools::fuzzyEquals( -A, {{-1, -2, -3},
                                                {-4, -5, -6}}) );

    A -= B;
    BOOST_CHECK( vectorTools::fuzzyEquals(A, {{2, 5, 6},
                                              {2, 0, 0}}) );

    C = A - B;
    BOOST_CHECK( vectorTools::fuzzyEquals(C, {{ 3, 8,  9},
                                              { 0,-5, -6}}) );

}

BOOST_AUTO_TEST_CASE( test_multiplication_operators ){
    /*!
     * Test the multiplication operators
     *
     */

    vectorType a = { 1, 2, 3};
    vectorType b, c;


    a *= 2;

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {2, 4, 6}) );

    b = 3*a;
    c = a*3;

    BOOST_CHECK( vectorTools::fuzzyEquals(b, c) && !vectorTools::fuzzyEquals(b, {6, 12, 18}) );

}

BOOST_AUTO_TEST_CASE( test_division_operators ){
    /*!
     * Test the division operators
     *
     */

    vectorType a = { 1, 2, 3};
    vectorType b;


    a /= 2;

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {0.5, 1, 1.5}) );

    b = a/2;

    BOOST_CHECK( vectorTools::fuzzyEquals(b, {0.25, 0.5, 0.75}) );

}

BOOST_AUTO_TEST_CASE( test_computeMean ){
    /*!
     * Test the computation of the mean of a vector of vectors
     *
     */

    matrixType A = {{ 1,  2, 3.0, 4},
                    {-4, 13, 0.4, 5},
                    { 2,  6, 1.0, 7}};

    vectorType answer = {-1./3, 7, 8.8/6, 5 + 1/3.};
    vectorType result;
    vectorTools::computeMean(A, result);

    BOOST_CHECK( vectorTools::fuzzyEquals(result, answer) );

    result = vectorTools::computeMean(A);
    BOOST_CHECK( vectorTools::fuzzyEquals(result, answer) );

}

BOOST_AUTO_TEST_CASE( test_cross ){
    /*!
     * Test the computation of the cross product of two vectors
     *
     */

    vectorType a = { 1, 2};
    vectorType b = {-1, 7};
    vectorType c;

    vectorTools::cross(a, b, c);

    BOOST_CHECK( vectorTools::fuzzyEquals(c, {0, 0, 9}) );

    a = {1, 2, 3};
    b = {-1, 7, -3};

    vectorTools::cross(a, b, c);

    BOOST_CHECK( vectorTools::fuzzyEquals(c, {-27, 0, 9}) );

    c = vectorTools::cross(a, b);

    BOOST_CHECK( vectorTools::fuzzyEquals(c, {-27, 0, 9}) );

}

BOOST_AUTO_TEST_CASE( test_dot ){
    /*!
     * Test the computation of the dot product of two vectors
     *
     */

    vectorType a = { 1, 2, 3};
    vectorType b = {-1, 7, 6};
    floatType c;

    vectorTools::dot(a, b, c);

    BOOST_CHECK( vectorTools::fuzzyEquals<floatType>(c, -1 + 14 + 18) );

    c = vectorTools::dot(a, b);
    BOOST_CHECK( vectorTools::fuzzyEquals<floatType>(c, -1 + 14 + 18) );

    matrixType A = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};
    vectorType d;

    d = vectorTools::dot(A, a);

    BOOST_CHECK( vectorTools::fuzzyEquals(d, {14, 32, 50}) );

    matrixType B = {{10, 11, 12},
                    {13, 14, 15},
                    {16, 17, 18}};

    matrixType C = vectorTools::dot(A, B);

    BOOST_CHECK( vectorTools::fuzzyEquals(C, {{ 84,  90,  96},
                                              {201, 216, 231},
                                              {318, 342, 366}}) );

}

BOOST_AUTO_TEST_CASE( test_dotT ){
    /*!
     * Test the computation of the dot product of two matrices
     *
     */

    matrixType A = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

    matrixType B = {{10, 11, 12},
                    {13, 14, 15}};

    matrixType answer = {{ 68,  86},
                         {167, 212},
                         {266, 338}};

    BOOST_CHECK( vectorTools::fuzzyEquals( vectorTools::dotT( A, B ), answer ) );

}

BOOST_AUTO_TEST_CASE( test_Tdot ){
    /*!
     * Test the computation of the dot product of two matrices
     *
     */

    matrixType A = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

    matrixType B = {{10, 11},
                    {12, 13},
                    {14, 15}};

    vectorType b = {4, 5, 6};

    matrixType matrixAnswer = {{156, 168},
                               {192, 207},
                               {228, 246}};

    vectorType vectorAnswer = { 66, 81, 96 };

    BOOST_CHECK( vectorTools::fuzzyEquals( vectorTools::Tdot( A, B ), matrixAnswer ) );

    BOOST_CHECK( vectorTools::fuzzyEquals( vectorTools::Tdot( A, b ), vectorAnswer ) );

}

BOOST_AUTO_TEST_CASE( test_TdotT ){
    /*!
     * Test the computation of the dot product of two matrices
     *
     */

    matrixType A = {{1, 2, 3},
                    {4, 5, 6},
                    {7, 8, 9}};

    matrixType B = {{10, 11, 12},
                    {13, 14, 15}};

    matrixType answer = {{138, 174},
                         {171, 216},
                         {204, 258}};

    BOOST_CHECK( vectorTools::fuzzyEquals( vectorTools::TdotT( A, B ), answer ) );

}

BOOST_AUTO_TEST_CASE( test_inner ){

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
    BOOST_CHECK( vectorTools::fuzzyEquals(result, expected) );

    result = 0.;
    result = vectorTools::inner(Avec, Bvec);
    BOOST_CHECK( vectorTools::fuzzyEquals(result, expected) );

    //Test inner product of matrices
    result = 0.;
    vectorTools::inner(A, B, result);
    BOOST_CHECK( vectorTools::fuzzyEquals(result, expected) );

    result = 0.;
    result = vectorTools::inner(A, B);
    BOOST_CHECK( vectorTools::fuzzyEquals(result, expected) );

}

BOOST_AUTO_TEST_CASE( test_trace ){
    /*!
     * Test the computation of the trace for a square matrix
     *
     */

    vectorType a = {1., 0., 0.,
                    0., 1., 0.,
                    0., 0., 1.};
    floatType c;

    vectorTools::trace(a, c);

    BOOST_CHECK( vectorTools::fuzzyEquals<floatType>(c, 3.) );

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
        return 1;
    }

    c = 0.;
    c = vectorTools::trace(a);
    BOOST_CHECK( vectorTools::fuzzyEquals<floatType>(c, 3.) );

    matrixType A = {{1., 0., 0.},
                    {0., 1., 0.},
                    {0., 0., 1.}};

    c = 0.;
    vectorTools::trace(A, c);
    BOOST_CHECK( vectorTools::fuzzyEquals<floatType>(c, 3.) );

    c = 0.;
    c = vectorTools::trace(A);
    BOOST_CHECK( vectorTools::fuzzyEquals<floatType>(c, 3.) );

}

BOOST_AUTO_TEST_CASE( test_l ){
    /*!
     * Test the computation of the l2norm of vectors and matrices
     *
     */

    vectorType a = {1, 2, 3};
    matrixType A = {{1, 2, 3, 4},
                    {5, 6, 7, 8}};

    double r = vectorTools::l2norm(a);
    BOOST_CHECK( vectorTools::fuzzyEquals(r, 3.7416573867739413) );

    r = vectorTools::l2norm(A);
    BOOST_CHECK( vectorTools::fuzzyEquals(r, 14.2828568570857) );

}

BOOST_AUTO_TEST_CASE( test_argsort ){
    /*!
     * Test the utility that returns the indices required to sort a vector
     *
     */

    vectorType a = {1, -2, 7, 3, 9, 11};
    std::vector< unsigned int > idx = vectorTools::argsort(a);

    BOOST_CHECK( vectorTools::equals(idx, {1, 0, 3, 2, 4, 5}) );

}

BOOST_AUTO_TEST_CASE( test_fuzzyEquals ){
    /*!
     * Test the tolerant compare function
     *
     */

    matrixType a = {{1, -2, 3, 2.4, 1e-9, -1e-7},
                    {1.4, 8.5, 1 + 1e-9, 4, -2+1e-3, 100}};

    BOOST_CHECK( vectorTools::fuzzyEquals(a, {{1, -2, 3, 2.4, 0, 0},
                                              {1.4, 8.5, 1, 4, -2+1e-3+1e-9, 100+1e-4}}) );

}

BOOST_AUTO_TEST_CASE( test_equals ){
    /*!
     * Test the exact equality function
     *
     */

    unsigned int a = 1;
    std::vector< unsigned int > v = {1, 2, 3, 4};
    std::vector< std::vector< unsigned int > > m = {{1, 2, 3},
                                                    {4, 5, 6},
                                                    {7, 8, 9}};

    BOOST_CHECK( vectorTools::equals<unsigned int>(a, 1) );

    BOOST_CHECK( !vectorTools::equals<unsigned int>(a, 2) );

    BOOST_CHECK( vectorTools::equals(v, {1, 2, 3, 4}) );

    BOOST_CHECK( !vectorTools::equals(v, {1, 2, 2, 4}) );

    BOOST_CHECK( vectorTools::equals(m, {{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}}) );

    BOOST_CHECK( !vectorTools::equals(m, {{1, 2, 3},
                                          {4, 5, 4},
                                          {7, 8, 9}}) );

}

BOOST_AUTO_TEST_CASE( test_getValuesByIndex ){
    /*!
     * Test the retrieval of values of a vector as
     * indicated by vector of indices.
     *
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
    BOOST_CHECK( vectorTools::fuzzyEquals(rv, {2, 4, 1}) );

    matrixType rm;
    vectorTools::getValuesByIndex(m, indices, rm);
    BOOST_CHECK( vectorTools::fuzzyEquals(rm, {{4, 5, 6},{10, 11, 12},{1, 2, 3}}) );

}

BOOST_AUTO_TEST_CASE( test_appendVectors ){
    /*!
     * Test the utility to append a vector of vectors into a row-major vector.
     *
     */

    matrixType m = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    vectorType v = vectorTools::appendVectors(m);

    BOOST_CHECK( vectorTools::fuzzyEquals(v, {1, 2, 3, 4, 5, 6, 7, 8, 9}) );

    v.clear();
    vectorType v1 = {1, 7, 5};
    vectorType v2 = {4, 6, 2};
    v = vectorTools::appendVectors({v1, v2});

    BOOST_CHECK( vectorTools::fuzzyEquals(v, {1, 7, 5, 4, 6, 2}) );

}

BOOST_AUTO_TEST_CASE( test_solveLinearSystem ){
    /*!
     * Test the utility to solve a linear system of equations.
     *
     */

    matrixType A = {{0.95617934, 0.41311152, 0.25812163},
                    {0.13346546, 0.12864080, 0.65152997},
                    {0.15425579, 0.35444563, 0.43177476}};

    vectorType b = {0.92263585, 0.96720703, 0.72477723};

    vectorType xSolution = {0.52372037, 0.18327279, 1.34104665};

    unsigned int rank;

    vectorType xAnswer = vectorTools::solveLinearSystem(A, b, rank);

    BOOST_CHECK( vectorTools::fuzzyEquals(xSolution, xAnswer) );

    BOOST_CHECK( vectorTools::equals<unsigned int>(rank, 3) );

    vectorTools::solverType< floatType > linearSolver;
    xAnswer = vectorTools::solveLinearSystem( A, b, rank, linearSolver );

    BOOST_CHECK(  !vectorTools::fuzzyEquals( xSolution, xAnswer )  );

    BOOST_CHECK(  !vectorTools::equals< unsigned int >( rank, 3 )  );

    xAnswer = vectorType( 3, 0 );
    Eigen::Map< Eigen::MatrixXd > xmat( xAnswer.data( ), 3, 1 );
    Eigen::Map< const Eigen::MatrixXd > bmat( b.data( ), 3, 1 );
    xmat = linearSolver.solve( bmat );

    BOOST_CHECK(  !vectorTools::fuzzyEquals( xSolution, xAnswer )  );

    A = { { 2 } };
    b = { 7 };

    xSolution = { 3.5 };

    xAnswer = vectorTools::solveLinearSystem( A, b, rank );

    BOOST_CHECK(  !vectorTools::fuzzyEquals( xAnswer, xSolution )  );

}

BOOST_AUTO_TEST_CASE( test_isParallel ){
    /*!
     * Test the utility that tests if two vectors are parallel or not
     *
     */

    vectorType v1 = {1, 2, 3};
    vectorType v2 = {2, 4, 6};

    BOOST_CHECK( vectorTools::isParallel(v1, v2) );

    v1 = {0, 2, 3};
    BOOST_CHECK( !vectorTools::isParallel(v1, v2) );

    std::vector< int > v3 = {1, 2, 3};
    std::vector< int > v4 = {2, 4, 6};

    BOOST_CHECK( vectorTools::isParallel(v3, v4) );

    v3[0] = 0;
    BOOST_CHECK( vectorTools::isParallel(v3, v4) );

}

BOOST_AUTO_TEST_CASE( test_dyadic ){
    /*!
     * Test the computation of the dyadic product between two vectors
     *
     */

    vectorType v1 = {1, 2, 3};
    vectorType v2 = {4, 5, 6};
    matrixType A = vectorTools::dyadic(v1, v2);

    BOOST_CHECK( vectorTools::fuzzyEquals(A, {{ 4,  5,  6},
                                              { 8, 10, 12},
                                              {12, 15, 18}}) );

}

BOOST_AUTO_TEST_CASE( test_eye ){
    /*!
     * Test the formation of an identity matrix
     *
     */

    std::vector< double > Ivec(9, 1.);
    std::vector< double > IvecExpected = {1., 0., 0.,
                                          0., 1., 0.,
                                          0., 0., 1.};
    vectorTools::eye(Ivec);
    BOOST_CHECK( vectorTools::fuzzyEquals(Ivec,IvecExpected) );

    unsigned int dim = 4;
    std::vector< std::vector< double > > I = vectorTools::eye< double >(dim);

    BOOST_CHECK( vectorTools::fuzzyEquals(I, {{1, 0, 0, 0},
                                              {0, 1, 0, 0},
                                              {0, 0, 1, 0},
                                              {0, 0, 0, 1}}) );

    I.clear();
    vectorTools::eye(dim, I);

    BOOST_CHECK( vectorTools::fuzzyEquals(I, {{1, 0, 0, 0},
                                              {0, 1, 0, 0},
                                              {0, 0, 1, 0},
                                              {0, 0, 0, 1}}) );

}

BOOST_AUTO_TEST_CASE( test_determinant ){
    /*!
     * Test the computation of the determinant of a matrix
     *
     */

    std::vector< floatType > Avec = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::determinant(Avec, 3, 3), 1.) );

    Avec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::determinant(Avec, 3, 3), 0.) );

    Avec = {1, 2, 3, 4};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::determinant(Avec, 2, 2), -2.) );

}

BOOST_AUTO_TEST_CASE( test_inverse ){
    /*!
     * Test the computation of the matrix inverse;
     *
     */

    std::vector< floatType > Avec = { 0.39874077,  0.11561812, -0.75485222,
                                      0.14034205,  0.15851022,  1.29640525,
                                      0.26235075, -0.26051883,  0.45378251 };

    std::vector< floatType > answer = { 1.6109566 ,  0.56699734,  1.0599259 ,
                                        1.08701345,  1.49027454, -2.44933462,
                                       -0.30730183,  0.52776914,  0.18473576 };

    std::vector< floatType > Avecinv = vectorTools::inverse( Avec, 3, 3 );

    BOOST_CHECK( vectorTools::fuzzyEquals( Avecinv, answer ) );

    std::vector< std::vector< floatType > > A = vectorTools::inflate( Avec, 3, 3 );
    std::vector< std::vector< double > > Ainv = vectorTools::inverse( A );

    BOOST_CHECK(  !vectorTools::fuzzyEquals( vectorTools::appendVectors( Ainv ), answer )  );

}

BOOST_AUTO_TEST_CASE( test_inflate ){
    /*!
     * Test the inflate command in vector_tools
     *
     */

    std::vector< floatType > Avec = { 1, 2, 3, 4,  5,
                                      6, 7, 8, 9, 10 };

    unsigned int nrows = 2;
    unsigned int ncols = 5;

    std::vector< std::vector< floatType > > answer = { { 1, 2, 3, 4,  5},
                                                       { 6, 7, 8, 9, 10} };

    std::vector< std::vector< floatType > > result = vectorTools::inflate( Avec, nrows, ncols );

    BOOST_CHECK(  !vectorTools::fuzzyEquals( answer, result )  );

}

BOOST_AUTO_TEST_CASE( test_computeDDetAdJ ){
    /*!
     * Test the computation of the derivative of the determinant w.r.t.
     * the matrix.
     *
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

        BOOST_CHECK( vectorTools::fuzzyEquals((detA - detA0)/delta[i], ddetAdA[i]) );

    }

}

BOOST_AUTO_TEST_CASE( test_matrixMultiply ){
    /*!
     * Test the matrix multiplication function.
     *
     */

    vectorType A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vectorType B = {10, 11, 12, 13, 14, 15, 16, 17, 18};
    vectorType C;

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 0, 0);

    BOOST_CHECK( vectorTools::fuzzyEquals(C, {84,  90,  96, 201, 216, 231, 318, 342, 366}) );

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 1, 0);

    BOOST_CHECK( vectorTools::fuzzyEquals(C, {174, 186, 198, 213, 228, 243, 252, 270, 288}) );

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 0, 1);

    BOOST_CHECK( vectorTools::fuzzyEquals(C, { 68,  86, 104, 167, 212, 257, 266, 338, 410}) );

    C = vectorTools::matrixMultiply(A, B, 3, 3, 3, 3, 1, 1);

    BOOST_CHECK( vectorTools::fuzzyEquals(C, {138, 174, 210, 171, 216, 261, 204, 258, 312}) );

}

BOOST_AUTO_TEST_CASE( test_matrixSqrtResidual ){
    /*!
     * Test the computation of the residual used in solving for
     * the square root of a matrix.
     *
     */

    vectorType A = {3., 3., 5., 3., 7., 7., 5., 7., 11.};
    vectorType X = {1., 2., 3., 4., 5., 6., 7., 8.,  9.};

    vectorType R, RJ;
    matrixType J, JJ;
    vectorTools::__matrixSqrtResidual(A, 3, X, R, J);

    //Check that the Jacobian is consistent with the residual
    floatType eps = 1e-6;
    for (unsigned int i=0; i<X.size(); i++){
        vectorType delta(X.size(), 0);
        delta[i] = eps*fabs(X[i]) + eps;

        vectorTools::__matrixSqrtResidual(A, 3, X + delta, RJ, JJ);

        vectorType gradCol = (RJ - R)/delta[i];

        for (unsigned int j=0; j<A.size(); j++){
            BOOST_CHECK( vectorTools::fuzzyEquals(gradCol[j], J[j][i]) );
        }
    }

}

BOOST_AUTO_TEST_CASE( test_matrixSqrt ){
    /*!
     * Test the computation of the square root of a matrix.
     *
     *
     */

    vectorType A = {3.,  3.,  5.,  3.,  7.,  7.,  5.,  7., 11.};
    unsigned int dim = 3;
    floatType eps = 1e-6;
    vectorType gradCol;

    vectorType X = vectorTools::matrixSqrt(A, 3);

    BOOST_CHECK( vectorTools::fuzzyEquals(A, vectorTools::matrixMultiply(X, X, dim, dim, dim, dim, 0, 0)  ) );

    //Test the jacobian
    matrixType dAdX;
    vectorType XJ = vectorTools::matrixSqrt(A, 3, dAdX);

    BOOST_CHECK( vectorTools::fuzzyEquals(XJ, X) );

    vectorType dXdA = vectorTools::inverse(vectorTools::appendVectors(dAdX), A.size(), A.size());

    for (unsigned int i=0; i<A.size(); i++){
        vectorType delta(A.size(), 0);
        delta[i] = eps*A[i] + eps;

        XJ = vectorTools::matrixSqrt(A + delta, 3);

        gradCol = (XJ - X)/delta[i];

        for (unsigned int j=0; j<gradCol.size(); j++){
            BOOST_CHECK( vectorTools::fuzzyEquals(gradCol[j], dXdA[A.size()*j + i]) );
        }
    }

}

BOOST_AUTO_TEST_CASE( test_median ){
    /*!
     * Test the computation of the median of a vector
     *
     */

    vectorType x = {0.65353053, 0.97839806, 0.32387778, 0.13137077, 0.17253149, 0.03216338};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::median(x), 0.24820463352966032) );

    x = {0.82387829, 0.07615528, 0.89366009, 0.04843728, 0.81331188, 0.19575555, 0.02308312};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::median(x), .19575554955487007) );

}

BOOST_AUTO_TEST_CASE( test_abs ){
    /*!
     * Test the computation of the absolute value of a vector.
     *
     */

    std::vector< double > x = {-1, 2, 3, 4, -5, 6};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::abs(x), {1., 2., 3., 4., 5., 6.}) );

    std::vector< int > y = {-1, 2, 3, 4, -5, 6};
    BOOST_CHECK( vectorTools::fuzzyEquals(vectorTools::abs(y), {1, 2, 3, 4, 5, 6}) );

}
