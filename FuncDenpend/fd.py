#/usr/bin python

"The cluster of functional dependency on attributes X."

U = ['A', 'B', 'C', 'D', 'E']
X = ['A', 'B']
F = {'AB':'C', 'B':'D', 'C':'E', 'EC':'B', 'AC':'B'}

def extend(X):
	Y= []
	lenX = len(X)
	for i in range(lenX):
		Y.append(X[i])

	lenY = len(Y)
	for i in range(lenY):
		temp1 = Y[i]
		Y.remove(temp1)
		lenY2 = len(Y)
		for j in range(lenY2):
			temp2 = temp1
			temp3 = Y[j]
			temp1 = temp1 + temp3
			X.append(temp1)
			Y.remove(temp3)
			for W in Y:
				temp1 = temp1 + W
				X.append(temp1)
			Y.insert(j, temp3)
			temp1 = temp2
		Y.insert(i, temp1)
	return X

def cluster(X, F):
	extend(X)
	Y = []
	Z = []
	for V in X:
		if len(V) == 1:
			Y.append(V)
	
	i = 0
	while len(Y) != len(U):
		j = i
		for V in X:
			if V in F.keys():
				Y.append(F[V])
				X.append(F[V])
				i = i + 1
		if j == i: break
		else: continue
	
	print Y
				
if __name__ == '__main__':
	cluster(X, F)
