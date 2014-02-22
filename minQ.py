#http://www.careercup.com/question?id=7263132
#!usr/bin/env python

import Queue
class minQ:
	def __init__(self):
		self.q = Queue.Queue()
		self.minQ = []

	def getMin(self):
		if self.q.empty():
			print "q is empty"
			return

		return self.minQ[0]

	def push_rear(self, num):
		self.q.put(num, True)
		i = len(self.minQ) - 1
		while i >= 0 and self.minQ[i] > num:
			self.minQ.remove(self.minQ[i])
			i -= 1
			
		self.minQ.append(num)
	
	def pop_front(self):
		ret = self.q.get(0)
		if ret == self.minQ[0]:
			self.minQ.remove(self.minQ[0])
		return ret
			

if __name__ == "__main__":
	q = minQ()
	q.push_rear(1)
	print q.getMin()
	q.push_rear(5)
	print q.getMin()
	q.push_rear(0)
	print q.getMin()
	q.push_rear(3)
	print q.getMin()
	print '--------------------'
	q.pop_front()
	print q.getMin()
	q.pop_front()
	print q.getMin()
	q.pop_front()
	print q.getMin()
	q.pop_front()
