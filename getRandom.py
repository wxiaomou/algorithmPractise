#http://www.careercup.com/question?id=6065702117048320
#!usr/bin/env python

class Solution:
	def __inti__(self):
		pass

	def get_random(self, N, K, num):
		if num >= N - len(K):
			print 'wrong input'
			return

		for i in K:
			if num >= i:
				num += 1
			else:
				return num
		return num

if __name__ == '__main__':
	sol = Solution()
	print sol.get_random(10, [2, 6], 0)
	print sol.get_random(10, [2, 6], 1)
	print sol.get_random(10, [2, 6], 2)
	print sol.get_random(10, [2, 6], 3)
	print sol.get_random(10, [2, 6], 4)
	print sol.get_random(10, [2, 6], 5)
	print sol.get_random(10, [2, 6], 6)
	print sol.get_random(10, [2, 6], 7)
