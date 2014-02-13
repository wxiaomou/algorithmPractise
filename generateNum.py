#http://www.careercup.com/question?id=23823662
#!usr/bin/env python

import Queue
from sets import Set

class Solution:
	def __init__(self):
		pass

	def generate(self, equation, N):
		ret = []
		if len(equation) == 0:
			return ret
	
		ref = Set() 
		e = equation.split('* ');
		q = Queue.PriorityQueue()
		q.put(1)
		begin = False
		k = -1
		while len(ret) < N:
			_min = q.get(True)
			for j in xrange(k, len(e)):
				q.put(int(e[j][0]) * _min)
			
			if begin and _min not in ref:
				ref.add(_min)
				ret.append(_min)
			else:
				begin = True

		return ret

if __name__ == '__main__':
	sol = Solution()
	equ = "2^i * 3^j * 5^k * 7^l"
	print sol.generate(equ, 8)
