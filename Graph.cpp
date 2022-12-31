#include "Graph.h" // include the Graph class

// constructor
Graph::Graph()
{
}

// destructor
Graph::~Graph()
{
}

// visualizes categories separated by their features
void Graph::printGraph(vector<Point> samples, vector<Point> testingPoint)
{
	char atom_window[] = "KNN-Samples_Point"; // window name
	char atom_window_1[] = "KNN-Result"; // window name

	cv::Mat atom_image_1 = cv::Mat::zeros(650, 650, CV_8UC3); // create a black image
	cv::Mat atom_image_2 = cv::Mat::zeros(650, 650, CV_8UC3); // create a black image

	// draw white line at each position in the atom_image_1 and atom_image_2 matrices
	for (int i = 0; i < atom_image_1.rows; i++) {  
		for (int j = 0; j < atom_image_1.cols; j++) {
			line(atom_image_1, cv::Point(i, j), cv::Point(i, j), cv::Scalar(255, 255, 255), 1, 8);
			line(atom_image_2, cv::Point(i, j), cv::Point(i, j), cv::Scalar(255, 255, 255), 1, 8);
		}
	}
	// RANDOM SAMPLE POINTS
	line(atom_image_1, cv::Point(20, 300), cv::Point(580, 300), cv::Scalar(0, 0, 0), 6, 8);
	line(atom_image_1, cv::Point(300, 20), cv::Point(300, 580), cv::Scalar(0, 0, 0), 6, 8);
	line(atom_image_1, cv::Point(290, 50), cv::Point(310, 50), cv::Scalar(0, 0, 0), 3, 8);
	line(atom_image_1, cv::Point(290, 550), cv::Point(310, 550), cv::Scalar(0, 0, 0), 3, 8);
	line(atom_image_1, cv::Point(50, 290), cv::Point(50, 310), cv::Scalar(0, 0, 0), 3, 8);
	line(atom_image_1, cv::Point(550, 290), cv::Point(550, 310), cv::Scalar(0, 0, 0), 3, 8);
	putText(atom_image_1, "Y", cv::Point(310, 30), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_1, "X", cv::Point(550, 280), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_1, "5", cv::Point(312, 50), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_1, "-5", cv::Point(312, 550), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_1, "-5", cv::Point(40, 320), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_1, "5", cv::Point(540, 320), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	circle(atom_image_1, cv::Point(50, 620), 4, cv::Scalar(255, 0, 0), 2, cv::LINE_8);
	putText(atom_image_1, "Category-0", cv::Point(58, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(255, 0, 0), 1, false);
	circle(atom_image_1, cv::Point(150, 620), 6, cv::Scalar(0, 255, 0), 2, cv::LINE_8);
	putText(atom_image_1, "Category-1", cv::Point(158, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 255, 0), 1, false);
	circle(atom_image_1, cv::Point(250, 620), 8, cv::Scalar(0, 0, 255), 2, cv::LINE_8);
	putText(atom_image_1, "Category-2", cv::Point(258, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 255), 1, false);
	cv::rectangle(atom_image_1, cv::Point(345, 615), cv::Point(355, 625), cv::Scalar(255, 0, 255), 2);
	putText(atom_image_1, "Testing Samples", cv::Point(358, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(255, 0, 255), 1, false);


	// AFTER KNN OPERATİONS
	line(atom_image_2, cv::Point(20, 300), cv::Point(580, 300), cv::Scalar(0, 0, 0), 6, 8);
	line(atom_image_2, cv::Point(300, 20), cv::Point(300, 580), cv::Scalar(0, 0, 0), 6, 8);
	line(atom_image_2, cv::Point(290, 50), cv::Point(310, 50), cv::Scalar(0, 0, 0), 3, 8);
	line(atom_image_2, cv::Point(290, 550), cv::Point(310, 550), cv::Scalar(0, 0, 0), 3, 8);
	line(atom_image_2, cv::Point(50, 290), cv::Point(50, 310), cv::Scalar(0, 0, 0), 3, 8);
	line(atom_image_2, cv::Point(550, 290), cv::Point(550, 310), cv::Scalar(0, 0, 0), 3, 8);
	putText(atom_image_2, "Y", cv::Point(310, 30), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_2, "X", cv::Point(550, 280), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_2, "5", cv::Point(312, 50), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_2, "-5", cv::Point(312, 550), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_2, "-5", cv::Point(40, 320), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	putText(atom_image_2, "5", cv::Point(540, 320), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 0), 1, false);
	circle(atom_image_2, cv::Point(50, 620), 4, cv::Scalar(255, 0, 0), 2, cv::LINE_8);
	putText(atom_image_2, "Category-0", cv::Point(58, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(255, 0, 0), 1, false);
	circle(atom_image_2, cv::Point(150, 620), 6, cv::Scalar(0, 255, 0), 2, cv::LINE_8);
	putText(atom_image_2, "Category-1", cv::Point(158, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 255, 0), 1, false);
	circle(atom_image_2, cv::Point(250, 620), 8, cv::Scalar(0, 0, 255), 2, cv::LINE_8);
	putText(atom_image_2, "Category-2", cv::Point(258, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(0, 0, 255), 1, false);
	cv::rectangle(atom_image_2, cv::Point(345,615), cv::Point(355,625),cv::Scalar(255, 0, 255),2);
	putText(atom_image_2, "Testing Samples", cv::Point(358, 623), cv::FONT_HERSHEY_DUPLEX, 0.4, cv::Scalar(255, 0, 255), 1, false);


	/*drawing a filled circle on two images at a position specified by the 
	object's coordinates and with a color specified by the object's category ID.*/
	for (int i = 0; i < 30; i++)
	{
		
		MyFilledCircle(atom_image_1, cv::Point(samples[i].getCoordinate(0), samples[i].getCoordinate(1)), samples[i].getCategoryID());
		MyFilledCircle(atom_image_2, cv::Point(samples[i].getCoordinate(0), samples[i].getCoordinate(1)), samples[i].getCategoryID());
	}

	/*	*/
	for (int i = 0; i < 10; i++)
	{
		MyFilledCircle(atom_image_2, cv::Point(testingPoint[i].getCoordinate(0), testingPoint[i].getCoordinate(1)), testingPoint[i].getCategoryID());
	}
	
	imshow(atom_window, atom_image_1);
	imshow(atom_window_1, atom_image_2);
	cv::waitKey(0);
}

// Function to draw circles with opencv
void Graph::MyFilledCircle(cv::Mat img, cv::Point center, int i)
{
	if (center.x >= 0 && center.y > 0) { // if the coordinates are positive and positive
		center.x = 300 + 50 * center.x;
		center.y = 300 - 50 * center.y;
	}
	else if (center.x < 0 && center.y >= 0) { // if the coordinates are negative and positive
		center.x = 300 - 50 * abs(center.x);
		center.y = 300 - 50 * center.y;
	}
	else if (center.x <= 0 && center.y < 0) { // if the coordinates are negative and negative
		center.x = 300 - 50 * abs(center.x);
		center.y = 300 + 50 * abs(center.y);
	}
	else if (center.x > 0 && center.y <= 0) { // if the coordinates are positive and negative
		center.x = 300 + 50 * abs(center.x);
		center.y = 300 + 50 * abs(center.y);
	}
	else if (center.x == 0 && center.y == 0) // if the coordinates are zero
	{
		center.x = 300;
		center.y = 300;
	}

	if (i == 0) { // if the category is 0
		circle(img, center, 4, cv::Scalar(255, 0, 0), 2, cv::LINE_8);
	}
	else if (i == 1) { // if the category is 1 
		circle(img, center, 6, cv::Scalar(0, 255, 0), 2, cv::LINE_8);
	}
	else if (i == 2) { // if the category is 2
		circle(img, center, 8, cv::Scalar(0, 0, 255), 2, cv::LINE_8);
	}
	else if (i == 3) { // if the category is 3
		circle(img, center, 7, cv::Scalar(255, 0, 255), 2, cv::LINE_8);
	}
}
// Function  to draw rectangle with opencv
void Graph::MyFilledRectangle(cv::Mat img, cv::Point center, int i)
{
	if (center.x >= 0 && center.y > 0) { // if the coordinates are positive and positive
		center.x = 300 + 50 * center.x;
		center.y = 300 - 50 * center.y;
	}
	else if (center.x < 0 && center.y >= 0) { // if the coordinates are negative and positive
		center.x = 300 - 50 * abs(center.x);
		center.y = 300 - 50 * center.y;
	}
	else if (center.x <= 0 && center.y < 0) { // if the coordinates are negative and negative
		center.x = 300 - 50 * abs(center.x);
		center.y = 300 + 50 * abs(center.y);
	}
	else if (center.x > 0 && center.y <= 0) { // if the coordinates are positive and negative
		center.x = 300 + 50 * abs(center.x);
		center.y = 300 + 50 * abs(center.y);
	}
	else if (center.x == 0 && center.y == 0) // if the coordinates are zero
	{
		center.x = 300; 
		center.y = 300;
	}

	cv::Point pt1; // create a point p1
	pt1.x = center.x-10; // set the x coordinate of p1
	pt1.y = center.y-10; // set the y coordinate of p1
	cv::Point pt2; // create a point p2
	pt2.x = center.x+10; // set the x coordinate of p2
	pt2.y = center.y+10; // set the y coordinate of p2
	cv::rectangle(img, pt1, pt2, cv::Scalar(255,0 ,255),2); // drawing a rectangle
}