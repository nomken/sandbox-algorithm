#include <iostream>

using namespace std;

/*
 * Jump Consistent Hash
 * http://fj.hatenablog.jp/entry/2015/12/18/224645
 */
int32_t JumpConsistentHash(uint64_t key, int32_t num_buckets) {
  int64_t b = -1, j = 0;
  while (j < num_buckets) {
    b = j;
    key = key * 2862933555777941757ULL + 1;
    j = (b + 1) * (double(1LL << 31) / double((key >> 33) + 1));
  }
  return b;
}


int main(int argc, char *argv[]) {
  cout << argc << endl;
  for(int i=0; i<argc; i++) {
    cout << i << ")" << argv[i] << endl;
  }
  cout << "-----" << endl;

  uint64_t key = 10;
  int32_t num_buckets = 100;
  if(argc >= 3) {
    key = atoi(argv[1]);
    num_buckets = atoi(argv[2]);
  }

  int32_t b = JumpConsistentHash(key, num_buckets);

  cout << "key : " << key << endl;
  cout << "num : " << num_buckets << endl;
  cout << "b   : " << b << endl;

  return 0;
}

