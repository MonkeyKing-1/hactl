/**
 * Author: Timothy Qian??
 * Date: 2022-04-29
 * Source: me
 * Description: Iterative segment tree (currently range sums)
 * Status: Used, works well
 */

template <class T> struct SegmentTree {
	int n;
	std::vector<T> seg;

	const T ID = 0;		//Null value

	T comb(T a, T b) {
		return a + b;	//Edit operation here
	}

	SegmentTree() {}
	SegmentTree(int _n) { init(_n);	}
	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	void add(int p, T val) {
		seg[p += n] += val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};