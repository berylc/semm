% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/extract_fit_params.R
\name{extract_fit_params}
\alias{extract_fit_params}
\title{Returns the fitted parameters for a model 1 or model 2 object.}
\usage{
extract_fit_params(fit, dat, ndim = 2)
}
\arguments{
\item{fit}{fitted rstan model from model1 or model2 fit}

\item{dat}{a list with B and SE elements, variant IDs; from prep_gwas_input()}

\item{ndim}{optional parameter to specify number of categories (e.g. male, female), defaults to 2}
}
\value{
named list of fit parameters
}
\description{
Note that in all cases these return the median value from the post-warmup draws.
}
