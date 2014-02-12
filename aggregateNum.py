#http://www.careercup.com/question?id=14948278
#!usr/bin/env python

class Solution:
	def __init__(self):
		pass

	def Match(self, l1, l2, text):
		pos1 = 0
		pos2 = l1 
		pos4 = l1 + l2
		num1 = int(text[:pos2])
		num2 = int(text[pos2:pos4])
		#print num1
		#print pos2, pos4
		#print num2
		start = pos4
		while start < len(text):
			ref = start
			for l in xrange(start + 1, len(text) + 1):
				num3 = int(text[start: l])
				if num3 == (num1 + num2) and l == len(text):
					return True
				elif num3 == (num1 + num2):
					num1 = num3
					start = l 
			if ref == start:
				return False

	def check(self, text):
		n = len(text)
		for i in xrange(1, n / 3):
			for j in xrange(1, n / 3):
				if self.Match(i, j, text):
					return True
		
		return False

if __name__ == "__main__":
	sol = Solution()
	text = "1299111210"
	print sol.check(text)

