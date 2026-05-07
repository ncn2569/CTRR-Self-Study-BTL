#include "PathNode.h"

//TEST CASE TASK 1:
// Test	Expected	Got	
// int start=0;
// int goal=1;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 0 | f: 4 | g: 0 | h: 4
// Node: 4 | f: 4 | g: 1 | h: 3
// Node: 47 | f: 4 | g: 2 | h: 2
// Node: 52 | f: 4 | g: 3 | h: 1
// Node: 1 | f: 4 | g: 4 | h: 0
// Solution Path:
// Node: 0 | f: 4 | g: 0 | h: 4
// Node: 4 | f: 4 | g: 1 | h: 3
// Node: 47 | f: 4 | g: 2 | h: 2
// Node: 52 | f: 4 | g: 3 | h: 1
// Node: 1 | f: 4 | g: 4 | h: 0
// int start=1;
// int goal=0;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 1 | f: 3 | g: 0 | h: 3
// Node: 11 | f: 3 | g: 1 | h: 2
// Node: 28 | f: 3 | g: 2 | h: 1
// Node: 0 | f: 3 | g: 3 | h: 0
// Solution Path:
// Node: 1 | f: 3 | g: 0 | h: 3
// Node: 11 | f: 3 | g: 1 | h: 2
// Node: 28 | f: 3 | g: 2 | h: 1
// Node: 0 | f: 3 | g: 3 | h: 0
// int start=22;
// int goal=28;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 22 | f: 4 | g: 0 | h: 4
// Node: 9 | f: 4 | g: 1 | h: 3
// Node: 17 | f: 4 | g: 2 | h: 2
// Node: 27 | f: 4 | g: 3 | h: 1
// Node: 28 | f: 4 | g: 4 | h: 0
// Solution Path:
// Node: 22 | f: 4 | g: 0 | h: 4
// Node: 9 | f: 4 | g: 1 | h: 3
// Node: 17 | f: 4 | g: 2 | h: 2
// Node: 27 | f: 4 | g: 3 | h: 1
// Node: 28 | f: 4 | g: 4 | h: 0
// int start=28;
// int goal=22;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 28 | f: 3 | g: 0 | h: 3
// Node: 27 | f: 3 | g: 1 | h: 2
// Node: 9 | f: 3 | g: 2 | h: 1
// Node: 22 | f: 3 | g: 3 | h: 0
// Solution Path:
// Node: 28 | f: 3 | g: 0 | h: 3
// Node: 27 | f: 3 | g: 1 | h: 2
// Node: 9 | f: 3 | g: 2 | h: 1
// Node: 22 | f: 3 | g: 3 | h: 0
// int start=14;
// int goal=19;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 14 | f: 4 | g: 0 | h: 4
// Node: 7 | f: 4 | g: 1 | h: 3
// Node: 24 | f: 4 | g: 2 | h: 2
// Node: 30 | f: 4 | g: 3 | h: 1
// Node: 19 | f: 4 | g: 4 | h: 0
// Solution Path:
// Node: 14 | f: 4 | g: 0 | h: 4
// Node: 7 | f: 4 | g: 1 | h: 3
// Node: 24 | f: 4 | g: 2 | h: 2
// Node: 30 | f: 4 | g: 3 | h: 1
// Node: 19 | f: 4 | g: 4 | h: 0
// int start=0;
// int goal=59;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 0 | f: 3 | g: 0 | h: 3
// Node: 4 | f: 3 | g: 1 | h: 2
// Node: 55 | f: 3 | g: 2 | h: 1
// Node: 59 | f: 3 | g: 3 | h: 0
// Solution Path:
// Node: 0 | f: 3 | g: 0 | h: 3
// Node: 4 | f: 3 | g: 1 | h: 2
// Node: 55 | f: 3 | g: 2 | h: 1
// Node: 59 | f: 3 | g: 3 | h: 0
// int start=18;
// int goal=34;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 18 | f: 5 | g: 0 | h: 5
// Node: 1 | f: 5 | g: 1 | h: 4
// Node: 11 | f: 5 | g: 2 | h: 3
// Node: 9 | f: 5 | g: 3 | h: 2
// Node: 22 | f: 5 | g: 4 | h: 1
// Node: 34 | f: 5 | g: 5 | h: 0
// Solution Path:
// Node: 18 | f: 5 | g: 0 | h: 5
// Node: 1 | f: 5 | g: 1 | h: 4
// Node: 11 | f: 5 | g: 2 | h: 3
// Node: 9 | f: 5 | g: 3 | h: 2
// Node: 22 | f: 5 | g: 4 | h: 1
// Node: 34 | f: 5 | g: 5 | h: 0
// int start=34;
// int goal=18;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 34 | f: 2 | g: 0 | h: 2
// Node: 22 | f: 2 | g: 1 | h: 1
// Node: 18 | f: 2 | g: 2 | h: 0
// Solution Path:
// Node: 34 | f: 2 | g: 0 | h: 2
// Node: 22 | f: 2 | g: 1 | h: 1
// Node: 18 | f: 2 | g: 2 | h: 0
// int start=37;
// int goal=33;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 37 | f: 5 | g: 0 | h: 5
// Node: 10 | f: 5 | g: 1 | h: 4
// Node: 20 | f: 5 | g: 2 | h: 3
// Node: 56 | f: 5 | g: 3 | h: 2
// Node: 52 | f: 5 | g: 4 | h: 1
// Node: 33 | f: 5 | g: 5 | h: 0
// Solution Path:
// Node: 37 | f: 5 | g: 0 | h: 5
// Node: 10 | f: 5 | g: 1 | h: 4
// Node: 20 | f: 5 | g: 2 | h: 3
// Node: 56 | f: 5 | g: 3 | h: 2
// Node: 52 | f: 5 | g: 4 | h: 1
// Node: 33 | f: 5 | g: 5 | h: 0
// int start=33;
// int goal=37;
// PathNode* OutPath;
// OutPath=findSocialPath(Mat,start,goal);
// printPath(OutPath);
// Solution Path:
// Node: 33 | f: 2 | g: 0 | h: 2
// Node: 0 | f: 2 | g: 1 | h: 1
// Node: 37 | f: 2 | g: 2 | h: 0
// Solution Path:
// Node: 33 | f: 2 | g: 0 | h: 2
// Node: 0 | f: 2 | g: 1 | h: 1
// Node: 37 | f: 2 | g: 2 | h: 0

