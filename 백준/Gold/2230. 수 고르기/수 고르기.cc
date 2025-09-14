#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>
#include <cstring>
#include <string>
#include <cstdlib>
#include <random>
using namespace std;

int N, M;
int arr[100000];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    int j = 0;
    int mn = 0x3f3f3f3f;

    for(int i = 0; i < N; i++) {
        while((j < N) && (arr[j] - arr[i] < M)) {
            j++;
        }
        if(j == N) {
            break;
        }
        mn = min(mn, arr[j] - arr[i]);
    }

    cout << mn;
}




