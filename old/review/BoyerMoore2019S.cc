#include <iostream>
#include <cstring>
using namespace std;


const char s[] = "This is a test example string to search inside";
//                     e      e    e   e     e      e     e
const char target[] = "sample";
// this is a ampleample test of sampleampleample"
// "ampleampleample"
const char s2[] = "this is a sample of text sample twice";

void boyerMoore(const char s[], const char target[]) {
	int jump[256];
	int len = strlen(target);
	for (int i = 0; i < 256; i++)
		jump[i] = len;
	for (int i = 0; i < len; i++)
		jump[target[i]] = len - 1 - i;

	const int n = strlen(s); // the number of characters to search
	for (int i = len-1; i < n; ) {
		int offset = jump[s[i]];
		if (offset != 0)
			i += offset;
		else {
			for (int j = i - len + 1, k = 0; j < i; j++, k++)
				if (target[k] != s[j]) {
          goto notFound;
				}
			cout << "Found: " << i - len + 1 << "\n";
		notFound:
			i += len;
		}

	}
}

int main() {
	boyerMoore(s, target);
	boyerMoore(s2, target);

}
