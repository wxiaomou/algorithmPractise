#Q: Given a sorted array of integers, write a function that will return the number with the biggest number of repetitions. 
#(Asked to refine the solution to be more efficient) http://www.careercup.com/question?id=5104572540387328
import math
class Solution:
	def __init__(self):
		pass

	def find(self, array):
		cnt = 0
		ret = 0
		i = 0
		while i < len(array):
			ref = array[i]
			tmp_cnt = 0
			while  i < len(array) and array[i] == ref:
				tmp_cnt += 1
				i += 1
			if tmp_cnt > cnt:
				cnt = tmp_cnt
				ret = ref
		return ret

	def find2(self, array, start, end):
		if start == end:
			return [start, 1]
		elif start > end:
			return [0, 0]
		cnt = 1
		mid = (start + end) / 2
		ret = array[mid]
		i = mid - 1 
		j = mid + 1
		while i >= start and array[i] == array[mid]:
			i -= 1
			cnt += 1

		while j <= end and array[j] == array[mid]:
			j += 1
			cnt += 1
		left = [0, 0]
		right = [0, 0]
		if (i - start + 1) > cnt:
			left = self.find2(array, start, i)
		if (end - j + 1) > cnt:
			right = self.find2(array, j, end)
		_max = 0
		if left[1] > right[1]:
			ret = left[0]
			_max = left[1]
		else:
			ret = right[0]
			_max = right[1]

		if _max < cnt:
			ret = array[mid]
			_max = cnt

		return [ret, _max]


		
		

if __name__ == '__main__':
	sol = Solution()
	array = [1,1,1,2,3,4,4,4,4,5,5]
#	array = [1,1,2,3,4,5]
	print sol.find2(array, 0, len(array) - 1)[0], sol.find2(array, 0, len(array) - 1)[1]



