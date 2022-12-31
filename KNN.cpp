#include "KNN.h" // include the KNN class


// constructor set k values , create samples and testing point.
KNN::KNN(int k)
{
	setK(k); // set the K
	createSamplePoints(); // create sample points
	createTestingPoints(); // create testing points
}

// destructor
KNN::~KNN()
{
}

// Used to sort an vector of points' distance  
bool comparison(Point a, Point b)
{
	return (a.getDistance() < b.getDistance());
}

// Used in the count_if function that count the category IDs in the specified range to store
bool catIs_1(Point c) 
{ 
	return (c.getCategoryID() == 0);
}
bool catIs_2(Point c)
{
	return (c.getCategoryID() == 1);
}
bool catIs_3(Point c)
{
	return (c.getCategoryID() == 2);
}

// Function to set the K 
void KNN::setK(int k)
{
	string message = "ERROR ! K can not be negative";
	try
	{
		K = k;
		if (K<0)
		{
			throw message;
		}

	}
	catch (string x)
	{

		cout << x << endl;
		cout << " K = 3 " << endl;
		K = 3;
	}

}

// Create Sample Points 
void KNN::createSamplePoints()
{
	//create samples point 
	srand(time(NULL));
	for (int i = 0; i < 30; i++)
	{
		Point point(i, (rand() % 11 - 5), (rand() % 11 - 5));
		if (i < 10) {
			point.setCategoryID(0);
		}
		else if (10 <= i && i < 20) {
			point.setCategoryID(1);
		}
		else {
			point.setCategoryID(2);
		}
		samples.push_back(point);
	}

}

// Create Testing Point
void KNN::createTestingPoints()
{
	for (int i = 30; i < 40; i++)
	{
		Point point(i, (rand() % 11 - 5), (rand() % 11 - 5));
		testing_points.push_back(point);
	}
}

// Function to retrieve K
int KNN::getK() const
{
	return K;
}

// function to retrieve samples vector
vector<Point> KNN::getSamplePoints() const
{
	return samples;
}

// function to retrieve testing_points vector
vector<Point> KNN::getTestingPoints() const
{
	return testing_points;
}

// Print Samples Point and testing point
void KNN::printData()
{
	cout << "After the k-NN algorithm" << endl;
	cout << "Training Data";
	cout << "Index\t\t" << " Features:\t\t" << "Catagory" << endl;
	for (int i = 0; i < getSamplePoints().size(); i++)
	{
		cout << getSamplePoints()[i].getIndex() << "\t\t\t\t" << " X = " << setw(2) << getSamplePoints()[i].getCoordinate(0)
			<< " Y = " <<setw(2) << getSamplePoints()[i].getCoordinate(1) << "\t\t   " << getSamplePoints()[i].getCategoryID() << endl;
	}
	cout << "\n";
	for (int i = 0; i < getTestingPoints().size(); i++)
	{
		cout << getTestingPoints()[i].getIndex() << "\t\t\t\t" << " X = " <<setw(2) << getTestingPoints()[i].getCoordinate(0)
			<< " Y = " <<setw(2) << getTestingPoints()[i].getCoordinate(1) << "\t\t   " << getTestingPoints()[i].getCategoryID() << endl;
	}
}
//  Run the KNN algorithm
void KNN::KNNRun()
{
	classifyPoint(getSamplePoints(), getTestingPoints());
}
// show the Graph
void KNN::showGraph()
{
	Graph g1;
	g1.printGraph(getSamplePoints(), getTestingPoints());
}
// This function finds classification of points using  k nearest neighbour algorithm.
// It assumes only two features and three category
void KNN::classifyPoint(vector<Point> a, vector<Point> b)
{
	double d=0;
	vector<int> freq;
	for(int i= 0;  i< b.size(); i++)
	{
		freq.clear();
		for (int j = 0; j < a.size(); j++)
		{
			d = pow(((a[j].getCoordinate(0)) - (b[i].getCoordinate(0))), 2) +
				pow(((a[j].getCoordinate(1)) - (b[i].getCoordinate(1))), 2);
			d = sqrt(d);
			a[j].setDistance(d);
		}
		sort(a.begin(), a.end(), comparison);

		freq.push_back(count_if(a.begin(), a.begin() + getK(), catIs_1));
		freq.push_back(count_if(a.begin(), a.begin() + getK(), catIs_2));
		freq.push_back(count_if(a.begin(), a.begin() + getK(), catIs_3));
		if (!(freq[0] == freq[1] && freq[0] == freq[2])) {
			testing_points[i].setCategoryID(max_element(freq.begin(), freq.end()) - freq.begin());
		}
		else {
			testing_points[0].setCategoryID(a[0].getCategoryID());
		}
	}
}
