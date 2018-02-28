#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;
struct listnode {
	int address, data, next;
};
int find(const vector<listnode>& thelist, int address) {
	int size = thelist.size();
	for (int i = 0; i<size; i++) {
		if (thelist[i].address == address) { return i; }
	}
	return -1;
}
int main() {
	int first, n, k;
	cin >> first >> n >> k;
	vector<listnode> thelist(n);
	for (int i = 0; i<n; i++) {
		cin >> thelist[i].address >> thelist[i].data >> thelist[i].next;
	}
	int count = 0;
	vector<int> addr(n, -1);
	addr[0] = find(thelist, first);
	while (addr[count] != -1) {
		count++;
		addr[count] = find(thelist, thelist[addr[count - 1]].next);
		if (thelist[addr[count]].next == -1) { count++; break; }
	}
	for (int i = 0; i + k<count; i += k) {
		reverse(addr.begin() + i, addr.begin() + i + k);
	}
	for (int i = 0; i<count - 1; i++) {
		thelist[addr[i]].next = thelist[addr[i + 1]].address;
		printf("%05d %d %05d\n", thelist[addr[i]].address, thelist[addr[i]].data, thelist[addr[i]].next);
	}
	thelist[addr[count - 1]].next = -1;
	printf("%05d %d -1", thelist[addr[count - 1]].address, thelist[count - 1].data);
}