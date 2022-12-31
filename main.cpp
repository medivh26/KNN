#include <iostream>
#include "KNN.h"
#include <iomanip>
using namespace std;

ostream& operator <<(ostream& output, const KNN& knn)
{
    output << "Training Data" << endl;
    output << "Index" << setw(15) << "Features" << setw(15) << "Category" << endl;
    for (int i = 0; i < knn.getSamplePoints().size(); i++)
    {
        output << knn.getSamplePoints()[i].getIndex() << setw(15) << "X = " << setw(2) << knn.getSamplePoints()[i].getCoordinate(0)
            << " Y = " << setw(2) << knn.getSamplePoints()[i].getCoordinate(1) << setw(15) << knn.getSamplePoints()[i].getCategoryID() << endl;
    }
    output << endl << "Testing Data" << endl;
    output << "Index" << setw(15) << "Features" << endl;

    for (int i = 0; i < knn.getTestingPoints().size(); i++)
    {
        output << knn.getTestingPoints()[i].getIndex() << setw(15) << "X = " << setw(2) << knn.getTestingPoints()[i].getCoordinate(0)
            << " Y = " << setw(2) << knn.getTestingPoints()[i].getCoordinate(1) << endl;
    }
    cout << endl << endl << endl;

    return output;
}
int main()
{
    int k;
    cout << "Enter the value of K: ";
    cin >> k;
    KNN knn(k);
    cout << knn;
    knn.KNNRun();
    knn.printData();
    knn.showGraph();

    return 0;
}