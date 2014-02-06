#!usr/bin/env python
class Solution:
	def __init__(self):
		pass

	def find(self, a, b):
		i = 0
		j = 0
		diff = 100000
		while i < len(a) and j < len(b):
			if a[i] < b[j]:
				diff = min(diff, b[j] - a[i])
				i += 1
			else:
				diff = min(diff, a[i] - b[j])
				j += 1

		return diff

if __name__ == '__main__':
	sol = Solution()
	a = [0, 1, 2, 3, 4]
	b = [5, 6, 7, 8, 9]
	print sol.find(a, b)
