import numpy as np
import time
import matplotlib.pyplot as plt

class K_means:
    def __init__(self, k):
        
        self.k = k
    
    def ecludist(self, x, y):
        return np.sqrt(np.square(x - y).sum())

    def clusterMean(self, data):
        return np.mean(data, axis = 0)
    
    def randinitcenter(self, data):
        # data : (N, M)
        N, M = data.shape
        centers = np.zeros((self.k, M))

        for i in range(self.k):
            index = int(np.random.uniform(0, N))
            centers[i,:] = data[index,:]
        return centers

    def kmeas(self, data , maxitera):
        N, M = data.shape
        clusterAssment = np.zeros((N, 2))
        clusterChanged = True

        #获取初始聚类中心
        centroids = self.randinitcenter(data)

        while clusterChanged:
            clusterChanged = False
            for i in range(N):
                mindist = np.inf
                minindex = 0
                for j in range(k):
                    distance = self.ecludist(centroids[j,:], data[i,:])
                    
                    if distance < mindist:
                        mindist = distance
                        minindex = j
                
                if clusterAssment[i, 0] != minindex:
                    clusterChanged = True
                    clusterAssment[i,:] = minindex, mindist ** 2
            
            #更新聚类中心
            for j in range(k):
                pointsInCluster = data[np.nonzero(clusterAssment[:, 0] == j)[0]]
                centroids[j, :] = self.clusterMean(pointsInCluster)

        print('聚类完毕')
        return centroids, clusterAssment

    def showCluster(self, dataSet, k, centroids, clusterAssment):
        numSamples, dim = dataSet.shape
        if dim != 2:
            print("Sorry! I can not draw because the dimension of your data is not 2!")
            return 1

        mark = ['or', 'ob', 'og', 'ok', '^r', '+r', 'sr', 'dr', '<r', 'pr']
        if k > len(mark):
            print("Sorry! Your k is too large! please contact Zouxy")
            return 1

        # draw all samples
        for i in range(numSamples):
            markIndex = int(clusterAssment[i, 0])
            plt.plot(dataSet[i, 0], dataSet[i, 1], mark[markIndex])

        mark = ['Dr', 'Db', 'Dg', 'Dk', '^b', '+b', 'sb', 'db', '<b', 'pb']
        # draw the centroids
        for i in range(k):
            plt.plot(centroids[i, 0], centroids[i, 1], mark[i], markersize=12)

        plt.show()
     

if __name__ == "__main__":
    dataSet = np.random.rand(100, 2)
    k = 5
    kmean = K_means(k)

    centroids, clusterAssment = kmean.kmeas(dataSet, k)
    print(centroids)
    print("显示数据")
    kmean.showCluster(dataSet, k, centroids, clusterAssment)