#http://www.careercup.com/question?id=5074387359236096
#!usr/bin/env python
class Solution:
	def __init__(delf):
		pass

	def printTree(self, rs):
		_map = {}
		un_root_node = set()
		for it in rs:
			if it[0] in _map:
				_map[it[0]].append(it[1])
			else:
				_map[it[0]] = [it[1]]
			
			un_root_node.add(it[1])

		for key in _map.keys():
			if key not in un_root_node:
				root = key
				break

		self.printNode(root, _map)

	def printNode(self, root, _map):
		if root == None:
			return

		print root
		if root not in _map:
			return

		for it in _map[root]:
			self.printNode(it, _map)

		return

if __name__ == "__main__":
	sol = Solution()
	rs = [["animal", "mammal"]]
	rs.append(["animal", "bird"])
	rs.append(["lifeform", "animal"])
	rs.append(["cat", "lion"])
	rs.append(["mammal", "cat"])
	rs.append(["animal", "fish"])
	sol.printTree(rs)

