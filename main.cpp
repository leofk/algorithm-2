#include "cs221util/catch.hpp"
#include <limits.h>
#include <vector>
#include <sys/stat.h>
#include <iostream>
#include "cs221util/PNG.h"
#include "cs221util/HSLAPixel.h"
#include "filler.h"
#include "solidColorPicker.h"
#include "gridColorPicker.h"
#include "gradientColorPicker.h"
#include "rainbowColorPicker.h"

using namespace std;
using namespace cs221util;

#define GRADIENTX 50
#define GRADIENTY 50
#define GRADIENTTOLERANCE 0.02
#define GRADIENTFRAMEFREQ 100
#define GRADIENTRADIUS 70


int main() {

//    PNG img;
//    cout << "------------------------------------------" << endl;
//    cout << "Image Name (eg. name) : ";
//    string name;
//    cin >> name;
//
//    img.readFromFile("originals/" + name + ".png");

//    cout << "------------------------------------------" << endl;
//    cout << "Tolerance Amount (eg. 0.25) : ";
//    double tol;
//    cin >> tol;

    PNG img;
    img.readFromFile("originals/test.png");
    string name = "test";

    HSLAPixel px1;
    px1.h = 0; px1.s = 1.0; px1.l = 0.5;
    HSLAPixel px2;
    px2.h = 200; px2.s = 1.0; px2.l = 0.5;

    animation anim;
    anim = filler::fillGradientDFS(img, GRADIENTX, GRADIENTY, px1, px2,
                                   GRADIENTRADIUS, GRADIENTTOLERANCE,
                                   GRADIENTFRAMEFREQ);

    anim.write("images/" + name + ".gif");

    cout << "------------------------------------------" << endl;
    cout << "Done!" << endl;
    cout << "------------------------------------------" << endl;

    return 0;
}

//
//TEST_CASE("fill::basic grad dfs","[weight=1][part=fill]"){
//    PNG img;
//    img.readFromFile(GRADIENTTESTIMAGE);
//    HSLAPixel px1;
//    px1.h = 0; px1.s = 1.0; px1.l = 0.5;
//    HSLAPixel px2;
//    px2.h = 200; px2.s = 1.0; px2.l = 0.5;
//
//    animation anim;
//    anim = filler::fillGradientDFS(img, GRADIENTX, GRADIENTY, px1, px2,
//                                         GRADIENTRADIUS, GRADIENTTOLERANCE,
//                                         GRADIENTFRAMEFREQ);
//    PNG result = anim.write("images/dfsgrad.gif");
//    result.writeToFile("images/dfsgrad.png");
//
//    PNG expected; expected.readFromFile("soln_images/dfsgrad.png");
//    REQUIRE(result==expected);
//}
