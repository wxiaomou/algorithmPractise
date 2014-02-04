#!usr/bin/env python

class Solution:
	def __init__(self):
		self.ret = ''

	def reverse(self, _str, i):
		if i == len(_str):
			return
		self.reverse(_str, i + 1)
		self.ret += _str[i]
		return

	def get_ret(self):
		return self.ret

if __name__ == '__main__':
	sol = Solution()
	_str = "This is a test"
	sol.reverse(_str, 0)
	print sol.get_ret()
