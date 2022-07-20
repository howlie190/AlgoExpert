#include <vector>
#include <algorithm>

using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights)
{
    int red = 0;
    int blue = 0;
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort(blueShirtHeights.begin(), blueShirtHeights.end());
    for (int i = 0; i < redShirtHeights.size(); i++)
    {
        if (redShirtHeights[i] < blueShirtHeights[i])
            blue++;
        else if (redShirtHeights[i] > blueShirtHeights[i])
            red++;
    }
    return red == redShirtHeights.size() || blue == redShirtHeights.size();
}
