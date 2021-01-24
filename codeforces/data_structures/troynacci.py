"""Troynacci Query
https://codeforces.com/gym/100571/problem/B
"""
from typing import List


class Solution:

	def __init__(self, a: int, b: int, x: List[int], troy: List[int], n: int) -> None:
		self.a = a
		self.b = b
		self.troy = troy
		self.x = x
		self.n = n
		self.mod = (10**9) + 7
		self.p = [0] * (self.n + 5)

	def update_from_bounds(self, l: int, r: int) -> None:
		l -= 1
		r -= 1
		# First we do the obvious first update
		self.p[l] += self.troy[0]
		# Next, we update according to whether we are updating a single field or not
		if r > l:
			self.p[l + 1] += self.troy[1] - (self.b * self.troy[0])
			self.p[r + 1] -= self.troy[r - l + 1]
			self.p[r + 2] -= self.a * self.troy[r - l]
		elif r == l:
			self.p[r + 1] -= self.b * self.troy[0]
			self.p[r + 2] -= self.a * self.troy[0]

	def sum_all(self) -> None:
		if self.n > 1:
			self.p[1] += (self.b * self.p[0])
		for i in range(2, self.n):
			self.p[i] += (self.a * self.p[i - 2]) + (self.b * self.p[i - 1])
		for i in range(0, self.n):
			self.x[i] = (self.x[i] + self.p[i]) % self.mod


def compute_troynacci(f1: int, f2: int, a: int, b: int, n: int) -> List[int]:
	troy = [0] * (n + 5)
	troy[0] = f1
	troy[1] = f2
	for i in range(2, n):
		troy[i] = a * troy[i - 2] + b * troy[i - 1]
	return troy


if __name__ == '__main__':
	# Input reading
	n, q = map(int, input().split())
	f1, f2 = map(int, input().split())
	a, b = map(int, input().split())
	x = list(map(int, input().split()))
	# Array of zeroes for keeping track of changes
	troy = compute_troynacci(f1, f2, a, b, n + 2)
	sol = Solution(a, b, x, troy, n)
	for _ in range(q):
		sol.update_from_bounds(*(map(int, input().split())))
	sol.sum_all()
	print(' '.join(map(str, sol.x[:n])))
