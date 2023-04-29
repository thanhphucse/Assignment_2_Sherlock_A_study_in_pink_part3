/*
* Ho Chi Minh City University of Technology
* Faculty of Computer Science and Engineering
* Initial code for Assignment 2
* Programming Fundamentals Spring 2022
* Author: Vu Van Tien
* Date: 15.02.2022
*/

//The library here is concretely set, students are not allowed to include any other libraries.

#include "studyInPink3a.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // Point: simple test
    /*Point p1;
    cout << p1.toString() << endl;
    Point p2(4, 3);
    cout << p2.toString() << endl;
    cout << p1.distanceTo(p2) << endl;
    cout << p2.distanceTo(p1) << endl;*/
    // Node: simple test
    /*Point p1(4, 7);
    Point p2;
    Node node1(Point(1, 2));
    Node node2(Point(2,3), &node1);
    Node node3(p1);
    Node node4(p2);
    Node node5;
    cout << "node 1:" <<  node1.toString() << endl;
    cout << "node 2:" << node2.toString() << endl;
    cout << "node 3:" << node3.toString() << endl;
    cout << "node 4:" << node4.toString() << endl;
    cout << "node 5:" << node5.toString() << endl;*/
  
    //// Path: simple test
    /*Path path1;
    path1.addPoint(364723, 1);
    path1.addPoint(1, 42353);
    path1.addPoint(2353, 53523);
    path1.addPoint(7, 3);
    cout << path1.toString() << endl;*/

    /*Path path2;
    path2.addPoint(24, 42);
    cout << path2.toString() << endl;
    Point pt1 = path2.getLastPoint();
    cout << pt1.toString() << endl;
    path2.~Path();
    cout << path2.toString();*/
    //
    //path2.addPoint(5, 6);
    //Point pt2 =    path2.getLastPoint();
    //cout << pt2.toString() << endl;
    /*Path path1;
    cout << path1.toString() << endl;
    path1.addPoint(0, 1);
    cout << path1.toString() << endl;
    path1.addPoint(1, 3);
    cout << path1.toString() << endl;
    path1.addPoint(2, 5);
    cout << path1.toString() << endl;
    path1.addPoint(3, 7);
    cout << path1.toString() << endl;*/


    // Character: simple test
    Character chWatson("Watson");
    chWatson.moveToPoint(2, 7);
    chWatson.moveToPoint(1, 4);
    chWatson.moveToPoint(5, 5);
    Character chMurderer("chMurderer");
    chMurderer.moveToPoint(3, 4);
    chMurderer.moveToPoint(5, 8);
    chMurderer.moveToPoint(2, 3);
    int outDis = 0;
    cout << rescueSherlock(chMurderer, chWatson, -3, 6, outDis) << endl;
    cout << outDis << endl;
    return 0;
}