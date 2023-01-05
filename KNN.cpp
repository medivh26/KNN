#include "KNN.h" /// include the KNN class


/// constructor set k values , create samples and testing point.
KNN::KNN(int k)
{
	setK(k); /// set the K
	createSamplePoints(); /// create sample points
	createTestingPoints(); /// create testing points
}

/// destructor
KNN::~KNN()
{
}

/// Used to sort an vector of points' distance  
bool comparison(Point x, Point y)
{
	return (x.getDistance() < y.getDistance());
}

/// Used in the count_if function that count the category IDs in the specified range to store
bool IsCat0(Point cat) 
{ 
	return (cat.getCategoryID() == 0);
}
bool IsCat1(Point cat)
{
	return (cat.getCategoryID() == 1);
}
bool IsCat2(Point cat)
{
	return (cat.getCategoryID() == 2);
}

/// Function to set the K 
void KNN::setK(int k)
{
    if (k < 0) {
        throw invalid_argument("K must be greater than 0");
    } 
	else {
        K = k;
    }
}

/// Create Sample Points 
void KNN::createSamplePoints()
{
	///create samples point 
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		Point samplepoint(i, (rand() % 11 - 5), (rand() % 11 - 5));
		if (i < 10) {
			samplepoint.setCategoryID(0);
		}
		else if (10 <= i && i < 20) {
			samplepoint.setCategoryID(1);
		}
		else {
			samplepoint.setCategoryID(2);
		}
		samples.push_back(samplepoint);
	}

}

/// Create Testing Point
void KNN::createTestingPoints()
{
	for (int i = 30; i < 40; i++)
	{
		Point testpoint(i, (rand() % 11 - 5), (rand() % 11 - 5));
		testing_points.push_back(testpoint);
	}
}

/// Function to retrieve K
int KNN::getK() const
{
	return K;
}

/// function to retrieve samples vector
vector<Point> KNN::getSamplePoints() const
{
	return samples;
}

/// function to retrieve testing_points vector
vector<Point> KNN::getTestingPoints() const
{
	return testing_points;
}

/// Print Samples Point and testing point
void KNN::printData()
{
	cout << "After the k-NN algorithm" << endl<< endl;
	cout << "Training Data";
	cout << "Index\t\t" << " Coordinates:\t\t" << "Category" << endl;
	for (int i = 0; i < getSamplePoints().size(); i++)
	{
		cout << getSamplePoints()[i].getIndex() << "\t\t\t\t" << " X = " << setw(2) << getSamplePoints()[i].getCoordinates(0)
			<< " Y = " <<setw(2) << getSamplePoints()[i].getCoordinates(1) << "\t\t   " << getSamplePoints()[i].getCategoryID() << endl;
	}
	cout << "\n";
	for (int i = 0; i < getTestingPoints().size(); i++)
	{
		cout << getTestingPoints()[i].getIndex() << "\t\t\t\t" << " X = " <<setw(2) << getTestingPoints()[i].getCoordinates(0)
			<< " Y = " <<setw(2) << getTestingPoints()[i].getCoordinates(1) << "\t\t   " << getTestingPoints()[i].getCategoryID() << endl;
	}
}
///  Run the KNN algorithm
void KNN::RunKNN()
{
	classifyPoint(getSamplePoints(), getTestingPoints());
}
/// show the Graph
void KNN::showGraph()
{
	Graph g;
	g.printGraph(getSamplePoints(), getTestingPoints());
}
/// This function finds classification of points using  k nearest neighbour algorithm.
/// It assumes only two features and three category
void KNN::classifyPoint(vector<Point> x, vector<Point> y)
{
	double m=0;
	vector<int> freq;
	for(int i= 0;  i< y.size(); i++)
	{
		freq.clear();
		for (int j = 0; j < x.size(); j++)
		{
			m = pow(((x[j].getCoordinates(0)) - (y[i].getCoordinates(0))), 2) +
				 pow(((x[j].getCoordinates(1)) - (y[i].getCoordinates(1))), 2);
			m = sqrt(m);
			x[j].setDistance(m);
		}
		sort(x.begin(), x.end(), comparison);

		freq.push_back(count_if(x.begin(), x.begin() + getK(), IsCat0));
		freq.push_back(count_if(x.begin(), x.begin() + getK(), IsCat1));
		freq.push_back(count_if(x.begin(), x.begin() + getK(), IsCat2));
		if (!(freq[0] == freq[1] && freq[0] == freq[2])) {
			testing_points[i].setCategoryID(max_element(freq.begin(), freq.end()) - freq.begin());
		}
		else {
			testing_points[0].setCategoryID(x[0].getCategoryID());
		}
	}
}


/// Overload the << operator to print the training and testing data
ostream& operator <<(ostream& output, const KNN& knn)
{
    output<< endl;
    output << "Training Data" << endl << endl<< "Index" << "\t\t\t\t" << "Coordinates" << "\t\t" << "Category" << endl;
    
    for (int i = 0; i < knn.getSamplePoints().size(); i++)
    {
        output << knn.getSamplePoints()[i].getIndex() << "\t\t\t\t" << "X = " << setw(2) << knn.getSamplePoints()[i].getCoordinates(0)
            << " Y = " << setw(2) << knn.getSamplePoints()[i].getCoordinates(1) << setw(15) << knn.getSamplePoints()[i].getCategoryID() << endl;
    }
    output << endl << "Testing Data" << endl<< endl<< "Index" << "\t\t\t\t" << "Coordinates" << endl;

    for (int i = 0; i < knn.getTestingPoints().size(); i++)
    {
        output << knn.getTestingPoints()[i].getIndex() << "\t\t\t\t" << "X = " << setw(2) << knn.getTestingPoints()[i].getCoordinates(0)
            << " Y = " << setw(2) << knn.getTestingPoints()[i].getCoordinates(1) << endl;
    }

    cout << endl << endl << endl;

    return output;
}
