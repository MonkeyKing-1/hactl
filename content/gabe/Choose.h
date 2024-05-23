/**
 * Author: Gabe Wu
 * Date: 2022-04-29
 * Source: me
 * Description: Put at top of main().
 * Status: Used, works well
 */
const int MAX_FAC = 1000005;    //edit

vector<mi> fac(MAX_FAC + 1, 1), ifac(MAX_FAC + 1);
for(int i=1; i<=MAX_FAC; i++) fac[i] = fac[i-1] * i;
ifac[MAX_FAC] = inv(fac[MAX_FAC]);
for(int i=MAX_FAC-1; i>=0; i--) ifac[i] = ifac[i+1] * (i+1);

function<mi(int, int)> choose = [&](int a, int b) {
	assert(a >= 0 && b >= 0 && a <= MAX_FAC);
	return a >= b ? fac[a]*ifac[a-b]*ifac[b] : 0;
};