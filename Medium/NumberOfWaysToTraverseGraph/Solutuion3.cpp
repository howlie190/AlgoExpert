using namespace std;

int factorial(int n)
{
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int numberOfWaysToTraverseGraph(int width, int height)
{
    // Write your code here.
    return factorial(width + height - 2) /
           (factorial(width - 1) * factorial(height - 1));
}
