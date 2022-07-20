#include <vector>
#include <algorithm>

using namespace std;

bool classPhotos(vector<int> redShirtHeights, vector<int> blueShirtHeights)
{
    sort(redShirtHeights.begin(), redShirtHeights.end());
    sort(blueShirtHeights.begin(), blueShirtHeights.end());
    bool backRowRed = redShirtHeights.back() > blueShirtHeights.back()
                          ? true
                          : false;
    for (int i = 0; i < blueShirtHeights.size(); i++)
    {
        if (backRowRed)
        {
            if (redShirtHeights[i] <= blueShirtHeights[i])
                return false;
        }
        else if (blueShirtHeights[i] <= redShirtHeights[i])
            return false;
    }
    return true;
}
