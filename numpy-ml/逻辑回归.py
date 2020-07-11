import numpy as np


def sigmoid(z):
    return 1 / (1 + np.exp(-z))


class LogisiticRegression(object):
    def __init__(self,lamda, regular="l2",fit_bias=True):
        self.regular = regular
        self.lamda = lamda  # l2正则化系数
        self.W = None  # 参数
        self.fit_bias = fit_bias

    def fit(self, X, y, lr, tol=1e-7, itermax=1e5):

        if self.fit_bias:
            X = np.c_(np.ones(X.shape[0]), X)

        self.W = np.random.rand(X.shape[1])

        prev_loss = np.inf

        for _ in range(itermax):
            y_pred = sigmoid(np.dot(self.W, X))
            loss = self._lossfun(X, y, y_pred)
            if prev_loss - loss < tol:
                return
            prev_loss = loss
            self.W -= lr * self._grad(X, y, y_pred)

    def lossfun(self, X, y, y_pred):
        loss = -np.log(y_pred[y == 1]).sum() - np.log(1 - y_pred[y == 0]).sum()
        regular = 0.5 * self.lamda * np.linalg.norm(self.W, 2) ** 2
        return loss + regular

    def grad(self, X, y, y_pred):

        regular_grad = self.lamda * self.W
        return - (np.dot(y - y_pred, X) + regular_grad)

    def predict(self, X):
        if self.fit_bias:
            X = np.c_(np.ones(X.shape[0]), X)
        return sigmoid(np.dot(self.W.T, X))
