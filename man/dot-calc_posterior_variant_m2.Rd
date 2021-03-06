% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/calc_posteriors.R
\name{.calc_posterior_variant_m2}
\alias{.calc_posterior_variant_m2}
\title{Calculate the posterior probability for an m2 variant}
\usage{
.calc_posterior_variant_m2(B, SE, p, sigmasq)
}
\arguments{
\item{B}{betas from the dat object}

\item{SE}{ses from the dat object}

\item{p}{proportion vector from the m2 fit}

\item{sigmasq}{variances from the m2 fit}
}
\value{
a vector with the posterior probability of belonging to each component
}
\description{
Calculate the posterior probability for an m2 variant
}
