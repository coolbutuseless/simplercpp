
<!-- README.md is generated from README.Rmd. Please edit that file -->

# simplercpp

<!-- badges: start -->

![](https://img.shields.io/badge/cool-useless-green.svg)
<!-- badges: end -->

`simplercpp` is a small demo package incorporating C++ code via `Rcpp`

This is one of a series of small demo packages for  
calling other languages from R:

  - [{simplec}](https://github.com/coolbutuseless/simplec) - calling C
    with `.C()`
  - [{simplecall}](https://github.com/coolbutuseless/simplecall) -
    calling C with `.Call()`
  - [{simplercpp}](https://github.com/coolbutuseless/simplercpp) -
    calling C++ with `{Rcpp}`
  - [{simplefortran}](https://github.com/coolbutuseless/simplefortran) -
    calling Fortran with `.Fortran()`

## Rough comparison of `.C()`, `.Call()`, `{Rcpp}` (and `.Fortran()`)

|                | .C()                                                   | .Call()                                                      | Rcpp                                                                                                       |
| -------------- | ------------------------------------------------------ | ------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------- |
| Overview       | No real understanding of R objects                     | Need to understand SEXP macros & internals                   | C++ classes hide the complexity of the SEXP internals                                                      |
| What code?     | Basic C code. Numeric calcs.                           | Complex C code. Can manipulate R objects from C              | Complex C and C++ code involving numerics and R objects                                                    |
| Pros           | Simple to understand and use                           | Simple. No unnecessary copying.                              | Great documentation. Wrapping of R objects very intuitive.                                                 |
| Cons           | Too simple for most interesting things                 | Need to understand SEXP & R internals                        |                                                                                                            |
| Cons           | Performs copying of data to call functions             |                                                              |                                                                                                            |
| Demo R package | [{simplec}](https://github.com/coolbutuseless/simplec) | [{simplecall}](https://github.com/coolbutuseless/simplecall) | [{simplercpp}](https://github.com/coolbutuseless/simplercpp)                                               |
| Compiled size  | 17 kB                                                  | 17 kB                                                        | 92 kB (stripping can bring this down: see [issue1](https://github.com/coolbutuseless/simplercpp/issues/1)) |

|                | .Fortran()                                                         |
| -------------- | ------------------------------------------------------------------ |
| Overview       | No real understanding of R objects                                 |
| What code?     | Basic Fortran code. Numeric calcs.                                 |
| Pros           | Simple to understand and use                                       |
| Cons           | Too simple for most interesting things                             |
| Cons           | Performs copying of data to call functions                         |
| Cons           | Need to know Fortran\!                                             |
| Demo R package | [{simplefortran}](https://github.com/coolbutuseless/simplefortran) |
| Compiled size  | 17 kB                                                              |

## Installation

You can install from
[GitHub](https://github.com/coolbutuseless/simplercpp) with:

``` r
# install.package('remotes')
remotes::install_github('coolbutuseless/simplercpp)
```

## What’s in the box?

Package contains 2 C++ functions, and 2 functions in R (auto-generated
by Rcpp) which call the C functions using Rcpp (which uses `.Call()`).

| C function                                                 | R function       |
| ---------------------------------------------------------- | ---------------- |
| `NumericVector add_rcpp(NumericVector x, NumericVector y)` | `add_rcpp(x, y)` |
| `NumericVector mul_rcpp(NumericVector x, NumericVector y)` | `mul_rcpp(x, y)` |

## What’s in the R functions?

  - The R functions are auto-created by Rcpp into `R/RcppExports.R`
  - C code is called using `.Call()`

<!-- end list -->

``` r
#' Add 2 numeric vectors
#'
#' @param x,y numeric vectors
#'
#' @return numeric vector
#'
add_rcpp <- function(x, y) {
    .Call(`_simplercpp_add_rcpp`, x, y)
}
```

## What’s in the C functions?

  - Numeric vectors in R have a corresponding `NumericVector` class to
    use in C++
  - roxygen docs on the C code get translated to roxygen docs on the
    auto-generated R functions
  - `[[Rcpp::export]]` is used to indicate that this function should be
    made available to the package.

<!-- end list -->

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

## What does the C function look like in R?

  - An object of class `NativeSymbolInfo`
  - Holds an `externalptr` to the loaded function

<!-- end list -->

``` r
simplercpp:::`_simplercpp_add_rcpp`
#> $name
#> [1] "_simplercpp_add_rcpp"
#> 
#> $address
#> <pointer: 0x7f912ed2c220>
#> attr(,"class")
#> [1] "RegisteredNativeSymbol"
#> 
#> $dll
#> DLL name: simplercpp
#> Filename:
#>         /Library/Frameworks/R.framework/Versions/4.0/Resources/library/simplercpp/libs/simplercpp.so
#> Dynamic lookup: FALSE
#> 
#> $numParameters
#> [1] 2
#> 
#> attr(,"class")
#> [1] "CallRoutine"      "NativeSymbolInfo"
```

## Resources

  - [David Vaughan’s post - Now you C
    me](https://blog.davisvaughan.com/2019/03/02/now-you-c-me/)
  - [Peter Dalgaard’s Keynote from
    UseR 2004](http://www.ci.tuwien.ac.at/Conferences/useR-2004/Keynotes/Dalgaard.pdf)
    discusses R’s language interfaces
  - [Using R — Calling C Code ‘Hello
    World’](http://mazamascience.com/WorkingWithData/?p=1067)
  - [Hadley’s Advanced R book chapter - ‘Rs C
    interface’](http://adv-r.had.co.nz/C-interface.html)
  - [Rcpp](https://cran.r-project.org/package=Rcpp)

## Acknowledgements

  - R Core for developing and maintaining such a wonderful language.
  - CRAN maintainers, for patiently shepherding packages onto CRAN and
    maintaining the repository
