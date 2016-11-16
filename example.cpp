#include <iostream>
#include <vector>
#include "src/csgjs.h"

using namespace std;


int main(int argc,char *argv[]){

    int center1[3] = {0, 0, 0};
    int center2[3] = {2, 0, 0};

    // csgjs model
    struct csgjs_model cube1 = csgjs_cube(3, center1);
    struct csgjs_model cube2 = csgjs_cube(3, center2);

    // csg operation
    struct csgjs_model intersection = csgjs_intersection(cube1, cube2);
    cout << "intersection.vertices.size() = " << intersection.vertices.size() << endl;

    return 0;
}

