#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {
    // Load the image
    Mat image = imread("input.jpg"); // Replace with your image path
    if (image.empty()) {
        cout << "Error: Could not load image!" << endl;
        return -1;
    }

    Mat rotated;

    int angle;
    cout << "Enter rotation angle (90, 180, 270): ";
    cin >> angle;

    // Rotate according to angle
    if (angle == 90)
        rotate(image, rotated, ROTATE_90_CLOCKWISE);
    else if (angle == 180)
        rotate(image, rotated, ROTATE_180);
    else if (angle == 270)
        rotate(image, rotated, ROTATE_90_COUNTERCLOCKWISE);
    else {
        cout << "Invalid angle! Please choose 90, 180, or 270." << endl;
        return -1;
    }

    // Show images
    imshow("Original Image", image);
    imshow("Rotated Image", rotated);

    // Save rotated image
    imwrite("rotated_output.jpg", rotated);

    waitKey(0);
    return 0;
}
