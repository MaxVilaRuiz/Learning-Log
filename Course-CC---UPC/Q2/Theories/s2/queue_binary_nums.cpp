#include <iostream>
#include <queue>

using namespace std;

void generateBinaryNumbers(int N) {
  queue<string> q;
  q.push("1");
  for (int i = 0; i < N; i++) {
    string front = q.front();
    q.pop();
    cout << front << " ";
    q.push(front + "0");
    q.push(front + "1");
  }
  cout << endl;
}

/*
 * Generate Binary Numbers Using a Queue
 *
 *   Given a number N, generate the first N binary numbers in sequence.
 * 
 *   Input: N = 5
 *   Output: 1, 10, 11, 100, 101
 */
int main() {
    int N = 10;
    cout << "First " << N << " binary numbers: ";
    generateBinaryNumbers(N);
    return 0;
}
