#include <Rcpp.h>
using namespace Rcpp;


//' Add 2 numeric vectors
//'
//' @param x,y numeric vectors
//'
//' @return numeric vector
//'
// [[Rcpp::export]]
NumericVector add_rcpp(NumericVector x, NumericVector y) {
  return(x + y);
}



//' Multiply 2 numeric vectors
//'
//' @param x,y numeric vectors
//'
//' @return numeric vector
//'
// [[Rcpp::export]]
NumericVector mul_rcpp(NumericVector x, NumericVector y) {
  return(x * y);
}
