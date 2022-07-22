#include <algorithm>
#include <vector>

using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds,
                  vector<int> blueShirtSpeeds,
                  bool        fastest)
{
    if (fastest) {
        sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
        sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end(),
             [](int a, int b) { return a > b; });
    }
    else {
        sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
        sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    }
    int ans = 0;
    for (int i = 0; i < redShirtSpeeds.size(); i++) {
        if (redShirtSpeeds[i] > blueShirtSpeeds[i])
            ans += redShirtSpeeds[i];
        else
            ans += blueShirtSpeeds[i];
    }
    return ans;
}
