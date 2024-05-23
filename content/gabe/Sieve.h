/**
 * Author: Gabe Wu
 * Date: 2022-04-29
 * Source: me
 * Description: Prime sieve. Put at top of main(). $sieve[i]$ is smallest
    factor of $i$ greater than $1$.
 * Status: Used, works well
 */

const int MAX_PRIME = 1000005;  //edit
vector<int> sieve(MAX_PRIME);
vector<int> primes; // list of primes up to MAX_PRIME

for(int i=2; i<MAX_PRIME; i++) {
		if(!sieve[i]) {
				primes.push_back(i);
				for(int x=i; x<MAX_PRIME; x+=i) {
						if(sieve[x] == 0) {
								sieve[x] = i;
						}
				}
		}
}