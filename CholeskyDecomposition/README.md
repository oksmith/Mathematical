When we simulate random uncorrelated random variables (for example, X_1, X_2, ..., X_n iid N(0,1)) we can generate equivalent correlated random variables by multiplying the 
random vector X by the Cholesky decomposition of the covariance matrix containing the correlations. 

See this page for more detail: https://math.stackexchange.com/questions/163470/generating-correlated-random-numbers-why-does-cholesky-decomposition-work 

Based off of the Cholesky–Banachiewicz algorithm, this VBA program computes the Cholesky decomposition of a positive definite symmetric matrix. 
