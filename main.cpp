#include <iostream> /// include the iostream library
#include "KNN.h" /// include the KNN class
#include <iomanip> /// include the iomanip library
using namespace std; /// use the standard namespace

/// Main function
int main()
{
    int k; /// variable to store the K value
    cout << "Enter the value of K: "; /// prompt the user to enter the K value
    cin >> k; /// read the K value
    KNN knn(k);  /// create a KNN object
    cout << knn; /// print the KNN object
    knn.RunKNN(); /// run the KNN algorithm
    knn.printData(); /// print the data
    knn.showGraph(); /// show the graph

    return 0;
}