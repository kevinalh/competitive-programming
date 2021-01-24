"""Troynacci Query
https://codeforces.com/gym/100571/problem/B

The trick in this problem is to build an array p that can be summed over with the
recursive formula p[i] = a * p[i - 2] + b * p[i - 1] and gives us the actual addition
for x.

This can be accomplished by adding f[0] to p[l] and then writing down the recursive
formulas and noting what substractions we need to make to stop the long sum.

For example:
	If we keep summing from p[l] to p[r], next value will be according to our formula:
	p[r + 1] == a * p[r - 1] + b * p[r] == f[r - l + 1] (by definition)
	but we want this to be zero, so we take p[r + 1] -= f[r - l + 1]
"""
import sys
import io
import os


mod = (10**9) + 7
# This fast I/O is required for submission acceptance
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline


if __name__ == '__main__':
	# Input reading
	n, q = map(int, input().split())
	f1, f2 = map(int, input().split())
	a, b = map(int, input().split())
	x = list(map(int, input().split()))

	# First we pre-compute the Troynacci list following the given formula
	troy = [0] * (n + 5)
	troy[0] = f1
	troy[1] = f2
	for i in range(2, n):
		troy[i] = (a * troy[i - 2] + b * troy[i - 1]) % mod

	# p is going to store values to be used in the recursion
	p = [0] * (n + 2)

	for _ in range(q):
		l, r = map(int, input().split())
		l -= 1
		r -= 1
		# First we do the obvious first update
		p[l] = (p[l] + troy[0]) % mod
		# Next, we update according to whether we are updating a single field or not
		# The mods everywhere are required for avoiding high memory usage
		if r > l:
			p[l + 1] = (
				(p[l + 1] + troy[1]) % mod -
				(b * troy[0]) % mod
			) % mod
			p[r + 1] = (p[r + 1] - troy[r - l + 1]) % mod
			p[r + 2] = (p[r + 2] - (a * troy[r - l]) % mod) % mod
		else:
			p[r + 1] = (p[r + 1] - (b * troy[0]) % mod) % mod
			p[r + 2] = (p[r + 2] - (a * troy[0]) % mod) % mod

	# Finally we apply the recursive formula for p and add them to x
	x[0] = (x[0] + p[0]) % mod
	if n > 1:
		p[1] = (p[1] + (b * p[0]) % mod) % mod
		x[1] = (x[1] + p[1]) % mod
	for i in range(2, n):
		p[i] = (p[i] + (
			a * p[i - 2]
		) % mod + (
			b * p[i - 1]
		) % mod) % mod
		x[i] = (x[i] + p[i]) % mod

	sys.stdout.write(' '.join(map(str, x[:n])))
