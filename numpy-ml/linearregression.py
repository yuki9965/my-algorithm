import numpy as np
from ..utils.testing import is_symmetric_positive_definite, is_number


class LinearRegression:
    def __init__(self, fit_intercept=True):
        """
        An ordinary least squares regression model fit via the normal equation.
        Parameters
        ----------
        fit_intercept : bool
            Whether to fit an additional intercept term in addition to the
            model coefficients. Default is True.
        """
        self.beta = None
        self.fit_intercept = fit_intercept # 是否有偏置

    def fit(self, X, y):
        """
        Fit the regression coefficients via maximum likelihood.
        Parameters
        ----------
        X : :py:class:`ndarray <numpy.ndarray>` of shape `(N, M)`
            A dataset consisting of `N` examples, each of dimension `M`.
        y : :py:class:`ndarray <numpy.ndarray>` of shape `(N, K)`
            The targets for each of the `N` examples in `X`, where each target
            has dimension `K`.
        """
        # convert X to a design matrix if we're fitting an intercept
        if self.fit_intercept:
            #加上偏置 (N, M+1)
            X = np.c_[np.ones(X.shape[0]), X]   #按列叠加两个矩阵的意思，也可以说是按行连接两个矩阵，就是把两矩阵左右相加，要求行数相等

        pseudo_inverse = np.dot(np.linalg.inv(np.dot(X.T, X)), X.T)  #伪逆
        self.beta = np.dot(pseudo_inverse, y)

    def predict(self, X):
        """
        Used the trained model to generate predictions on a new collection of
        data points.
        Parameters
        ----------
        X : :py:class:`ndarray <numpy.ndarray>` of shape `(Z, M)`
            A dataset consisting of `Z` new examples, each of dimension `M`.
        Returns
        -------
        y_pred : :py:class:`ndarray <numpy.ndarray>` of shape `(Z, K)`
            The model predictions for the items in `X`.
        """
        # convert X to a design matrix if we're fitting an intercept
        if self.fit_intercept:
            X = np.c_[np.ones(X.shape[0]), X]
        return np.dot(X, self.beta)