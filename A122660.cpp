#include <chrono>
#include <iostream>
#include <unordered_map>
#define M (1 << 16)

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::unordered_map;

const int mask = M - 1;
int c[M], cc[M], cnt, n;

template <typename T>
constexpr T getbyte() {
  char c;
  std::cin.get(c);
  return (T)c;
}

int main() {
  auto start = high_resolution_clock::now();
  std::ios::sync_with_stdio(0);
  std::cout.tie(0);
  std::cin.ignore(15);
  cnt = 0;
  while (n = getbyte<int>()) {
    int firstEdge;
    for (int i = 0; i < n; ++i) {
      int first = getbyte<int>();
      --first;
      int prev = first, curr;
      if (!i) firstEdge = prev << 8;
      while (curr = getbyte<int>()) {
        --curr;
        c[(prev << 8) | i] = curr;
        cc[(curr << 8) | i] = prev;
        prev = curr;
      }
      c[(prev << 8) | i] = first;
      cc[(first << 8) | i] = prev;
    }
    int currEdge = firstEdge, pos = 0;
    do {
      currEdge = ((currEdge << 8) | (pos & 1 ? c : cc)[currEdge]) & mask;
      ++pos;
    } while (pos & 1 || currEdge != firstEdge);
    if (pos == 6 * n - 12) ++cnt;
  }
  auto end = high_resolution_clock::now();
  duration<double> sec = end - start;
  std::cout << cnt << " petrie-complete graphs found in " << sec.count() << "s\n";
}