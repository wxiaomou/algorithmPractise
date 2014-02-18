#http://www.careercup.com/question?id=4699414551592960
#!usr/bin/env python

class Node:
	def __init__(self, name, h, numofHihgerBefore):
		self.name = name
		self.h = h
		self.numofHihgerBefore = numofHihgerBefore
		
	def __repr__(self):
		return repr((self.name, self.h, self.numofHihgerBefore))
	
	def __str__(self):
		return self.name

class Solution:
	def __init__(self):
		pass

	def _sort(self, q):
		ret = []
		q = sorted(q, key=lambda node: node.numofHihgerBefore)
		print q

		ret.append(q[0])
		for i in xrange(1, len(q)):
			for j in xrange(0, len(ret) + 1):
					if q[i].numofHihgerBefore == 0:
						if j == len(ret):
							ret.append(q[i])
						elif ret[j].h > q[i].h:
							ret.insert(j, q[i])
							break
					else:
						if ret[j].h > q[i].h:
							q[i].numofHihgerBefore -= 1

		return ret
						
if __name__ == "__main__":
	sol = Solution()
#	<6,2,"A">,<1,4,"B">,<11,0,"C">,<5,1,"D">,<10,0,"E">,<4,0,"F"> 
	A = Node('A', 6, 2)
	B = Node('B', 1, 4)
	C = Node('C', 11, 0)
	D = Node('D', 5, 1)
	E = Node('E', 10, 0)
	F = Node('F', 4, 0)
	q = [A, B, C, D, E, F]
	
	#print sorted(q, key=lambda node: node.numofHihgerBefore)
	print sol._sort(q)


