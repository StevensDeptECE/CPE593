#include <iostream>
#include <cstring>

using namespace std;

const char s[] = "this is a test example of the ample";
const char s2[] = "this is a test example of the sample";
//                     esa   e     e   e
const char target[] = "sample";
//const char s[] = "this is a xmpleampleampleample not yet ampleampleample";
//const char target[] = "ampleampleample";

void boyerMoore(const char s[], const char target[]) {
	int jump[256];
	int n = strlen(s);
	int len = strlen(target);
	for (int i = 0; i < 256; i++)
		jump[i] = len;
	for (int i = 0; i < len; i++)
		jump[ target[i] ] = len - 1 - i;

	for (int i = len-1; i < n; ) {
		int offset = jump[ s[i] ];
		if (offset > 0)
			i += offset;
		else {
			for (int j = i - len + 1, k = 0; j < i; j++, k++)
				if (target[k] != s[j ])
					goto notFound;
			cout << "Found: " << i - len + 1 << '\n';
		notFound:
			i += len;
			;
		}
	}
}

int main() {
	boyerMoore(s, target);
	boyerMoore(s2, target);
}
