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



//TEST CASE TASK 2
// 	Test	Expected	Got	
// int start=0;
// int goal=1;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (61,69) | f: 38 | g: 0 | h: 38
// Node: (97,47) | f: 22.6 | g: 2.6 | h: 20
// Node: (81,51) | f: 6.5 | g: 6.5 | h: 0
// Solution Path:
// Node: (61,69) | f: 26.9072 | g: 0 | h: 26.9072
// Node: (88,65) | f: 17.7525 | g: 2.1 | h: 15.6525
// Node: (81,51) | f: 11.8 | g: 11.8 | h: 0
// Solution Path:
// Node: 0 | f: 38 | g: 0 | h: 38
// Node: 57 | f: 22.6 | g: 2.6 | h: 20
// Node: 1 | f: 6.5 | g: 6.5 | h: 0
// Solution Path:
// Node: 0 | f: 26.9072 | g: 0 | h: 26.9072
// Node: 25 | f: 17.7525 | g: 2.1 | h: 15.6525
// Node: 1 | f: 11.8 | g: 11.8 | h: 0
// int start=1;
// int goal=0;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (81,51) | f: 38 | g: 0 | h: 38
// Node: (55,74) | f: 14.9 | g: 3.9 | h: 11
// Node: (65,90) | f: 31.7 | g: 6.7 | h: 25
// Node: (61,69) | f: 8.6 | g: 8.6 | h: 0
// Solution Path:
// Node: (81,51) | f: 26.9072 | g: 0 | h: 26.9072
// Node: (44,54) | f: 27.0716 | g: 4.4 | h: 22.6716
// Node: (61,69) | f: 6 | g: 6 | h: 0
// Solution Path:
// Node: 1 | f: 38 | g: 0 | h: 38
// Node: 14 | f: 14.9 | g: 3.9 | h: 11
// Node: 12 | f: 31.7 | g: 6.7 | h: 25
// Node: 0 | f: 8.6 | g: 8.6 | h: 0
// Solution Path:
// Node: 1 | f: 26.9072 | g: 0 | h: 26.9072
// Node: 9 | f: 27.0716 | g: 4.4 | h: 22.6716
// Node: 0 | f: 6 | g: 6 | h: 0
// int start=0;
// int goal=59;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (61,69) | f: 71 | g: 0 | h: 71
// Node: (67,10) | f: 24.2 | g: 6.2 | h: 18
// Node: (72,4) | f: 34.5 | g: 7.5 | h: 27
// Node: (64,12) | f: 32.1 | g: 15.1 | h: 17
// Node: (50,9) | f: 16.7 | g: 16.7 | h: 0
// Solution Path:
// Node: (61,69) | f: 61 | g: 0 | h: 61
// Node: (67,10) | f: 23.2294 | g: 6.2 | h: 17.0294
// Node: (72,4) | f: 30.061 | g: 7.5 | h: 22.561
// Node: (64,12) | f: 29.4178 | g: 15.1 | h: 14.3178
// Node: (50,9) | f: 16.7 | g: 16.7 | h: 0
// Solution Path:
// Node: 0 | f: 71 | g: 0 | h: 71
// Node: 29 | f: 24.2 | g: 6.2 | h: 18
// Node: 17 | f: 34.5 | g: 7.5 | h: 27
// Node: 54 | f: 32.1 | g: 15.1 | h: 17
// Node: 59 | f: 16.7 | g: 16.7 | h: 0
// Solution Path:
// Node: 0 | f: 61 | g: 0 | h: 61
// Node: 29 | f: 23.2294 | g: 6.2 | h: 17.0294
// Node: 17 | f: 30.061 | g: 7.5 | h: 22.561
// Node: 54 | f: 29.4178 | g: 15.1 | h: 14.3178
// Node: 59 | f: 16.7 | g: 16.7 | h: 0
// int start=59;
// int goal=0;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (50,9) | f: 71 | g: 0 | h: 71
// Node: (61,69) | f: 9.9 | g: 9.9 | h: 0
// Solution Path:
// Node: (50,9) | f: 61 | g: 0 | h: 61
// Node: (61,69) | f: 9.9 | g: 9.9 | h: 0
// Solution Path:
// Node: 59 | f: 71 | g: 0 | h: 71
// Node: 0 | f: 9.9 | g: 9.9 | h: 0
// Solution Path:
// Node: 59 | f: 61 | g: 0 | h: 61
// Node: 0 | f: 9.9 | g: 9.9 | h: 0
// int start=8;
// int goal=36;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (64,39) | f: 33 | g: 0 | h: 33
// Node: (65,45) | f: 31.1 | g: 3.1 | h: 28
// Node: (81,51) | f: 28.7 | g: 10.7 | h: 18
// Node: (97,47) | f: 26.3 | g: 18.3 | h: 8
// Node: (99,38) | f: 34.9 | g: 21.9 | h: 13
// Node: (87,42) | f: 33.5 | g: 26.5 | h: 7
// Node: (92,44) | f: 35.6 | g: 35.6 | h: 0
// Solution Path:
// Node: (64,39) | f: 28.4429 | g: 0 | h: 28.4429
// Node: (65,45) | f: 30.1185 | g: 3.1 | h: 27.0185
// Node: (97,67) | f: 33.3372 | g: 9.8 | h: 23.5372
// Node: (92,44) | f: 20.2 | g: 20.2 | h: 0
// Solution Path:
// Node: 8 | f: 33 | g: 0 | h: 33
// Node: 45 | f: 31.1 | g: 3.1 | h: 28
// Node: 1 | f: 28.7 | g: 10.7 | h: 18
// Node: 57 | f: 26.3 | g: 18.3 | h: 8
// Node: 48 | f: 34.9 | g: 21.9 | h: 13
// Node: 55 | f: 33.5 | g: 26.5 | h: 7
// Node: 36 | f: 35.6 | g: 35.6 | h: 0
// Solution Path:
// Node: 8 | f: 28.4429 | g: 0 | h: 28.4429
// Node: 45 | f: 30.1185 | g: 3.1 | h: 27.0185
// Node: 18 | f: 33.3372 | g: 9.8 | h: 23.5372
// Node: 36 | f: 20.2 | g: 20.2 | h: 0
// int start=0;
// int goal=4;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (61,69) | f: 57 | g: 0 | h: 57
// Node: (88,65) | f: 36.1 | g: 2.1 | h: 34
// Node: (96,92) | f: 18.2 | g: 3.2 | h: 15
// Node: (95,68) | f: 45.3 | g: 7.3 | h: 38
// Node: (65,90) | f: 40.8 | g: 8.8 | h: 32
// Node: (88,99) | f: 14.3 | g: 14.3 | h: 0
// Solution Path:
// Node: (61,69) | f: 40.3609 | g: 0 | h: 40.3609
// Node: (88,65) | f: 36.1 | g: 2.1 | h: 34
// Node: (96,92) | f: 13.8301 | g: 3.2 | h: 10.6301
// Node: (95,68) | f: 39.0805 | g: 7.3 | h: 31.7805
// Node: (65,90) | f: 33.4982 | g: 8.8 | h: 24.6982
// Node: (88,99) | f: 14.3 | g: 14.3 | h: 0
// Solution Path:
// Node: 0 | f: 57 | g: 0 | h: 57
// Node: 25 | f: 36.1 | g: 2.1 | h: 34
// Node: 30 | f: 18.2 | g: 3.2 | h: 15
// Node: 3 | f: 45.3 | g: 7.3 | h: 38
// Node: 12 | f: 40.8 | g: 8.8 | h: 32
// Node: 4 | f: 14.3 | g: 14.3 | h: 0
// Solution Path:
// Node: 0 | f: 40.3609 | g: 0 | h: 40.3609
// Node: 25 | f: 36.1 | g: 2.1 | h: 34
// Node: 30 | f: 13.8301 | g: 3.2 | h: 10.6301
// Node: 3 | f: 39.0805 | g: 7.3 | h: 31.7805
// Node: 12 | f: 33.4982 | g: 8.8 | h: 24.6982
// Node: 4 | f: 14.3 | g: 14.3 | h: 0
// int start=35;
// int goal=21;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (34,41) | f: 59 | g: 0 | h: 59
// Node: (45,74) | f: 16.4 | g: 1.4 | h: 15
// Node: (65,90) | f: 23.9 | g: 2.9 | h: 21
// Node: (61,69) | f: 16.8 | g: 4.8 | h: 12
// Node: (55,74) | f: 18.2 | g: 13.2 | h: 5
// Node: (57,77) | f: 21.9 | g: 21.9 | h: 0
// Solution Path:
// Node: (34,41) | f: 42.72 | g: 0 | h: 42.72
// Node: (45,74) | f: 13.7693 | g: 1.4 | h: 12.3693
// Node: (65,90) | f: 18.1643 | g: 2.9 | h: 15.2643
// Node: (61,69) | f: 13.7443 | g: 4.8 | h: 8.94427
// Node: (47,85) | f: 21.0062 | g: 8.2 | h: 12.8062
// Node: (57,77) | f: 18.8 | g: 18.8 | h: 0
// Solution Path:
// Node: 35 | f: 59 | g: 0 | h: 59
// Node: 13 | f: 16.4 | g: 1.4 | h: 15
// Node: 12 | f: 23.9 | g: 2.9 | h: 21
// Node: 0 | f: 16.8 | g: 4.8 | h: 12
// Node: 14 | f: 18.2 | g: 13.2 | h: 5
// Node: 21 | f: 21.9 | g: 21.9 | h: 0
// Solution Path:
// Node: 35 | f: 42.72 | g: 0 | h: 42.72
// Node: 13 | f: 13.7693 | g: 1.4 | h: 12.3693
// Node: 12 | f: 18.1643 | g: 2.9 | h: 15.2643
// Node: 0 | f: 13.7443 | g: 4.8 | h: 8.94427
// Node: 56 | f: 21.0062 | g: 8.2 | h: 12.8062
// Node: 21 | f: 18.8 | g: 18.8 | h: 0
// int start=46;
// int goal=23;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (8,96) | f: 19 | g: 0 | h: 19
// Node: (8,74) | f: 12.1 | g: 1.1 | h: 11
// Node: (17,72) | f: 24.2 | g: 2.2 | h: 22
// Node: (24,86) | f: 37.9 | g: 12.9 | h: 25
// Node: (22,73) | f: 44.5 | g: 18.5 | h: 26
// Node: (4,81) | f: 22.7 | g: 22.7 | h: 0
// Solution Path:
// Node: (8,96) | f: 15.5242 | g: 0 | h: 15.5242
// Node: (25,59) | f: 35.4138 | g: 5 | h: 30.4138
// Node: (4,81) | f: 10.9 | g: 10.9 | h: 0
// Solution Path:
// Node: 46 | f: 19 | g: 0 | h: 19
// Node: 49 | f: 12.1 | g: 1.1 | h: 11
// Node: 22 | f: 24.2 | g: 2.2 | h: 22
// Node: 19 | f: 37.9 | g: 12.9 | h: 25
// Node: 34 | f: 44.5 | g: 18.5 | h: 26
// Node: 23 | f: 22.7 | g: 22.7 | h: 0
// Solution Path:
// Node: 46 | f: 15.5242 | g: 0 | h: 15.5242
// Node: 11 | f: 35.4138 | g: 5 | h: 30.4138
// Node: 23 | f: 10.9 | g: 10.9 | h: 0
// int start=8;
// int goal=18;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (64,39) | f: 61 | g: 0 | h: 61
// Node: (95,80) | f: 22 | g: 7 | h: 15
// Node: (97,47) | f: 29 | g: 9 | h: 20
// Node: (70,61) | f: 43.1 | g: 10.1 | h: 33
// Node: (73,68) | f: 37.7 | g: 12.7 | h: 25
// Node: (97,67) | f: 23.2 | g: 23.2 | h: 0
// Solution Path:
// Node: (64,39) | f: 43.2782 | g: 0 | h: 43.2782
// Node: (96,92) | f: 29.82 | g: 4.8 | h: 25.02
// Node: (87,42) | f: 37.4258 | g: 10.5 | h: 26.9258
// Node: (97,67) | f: 18.9 | g: 18.9 | h: 0
// Solution Path:
// Node: 8 | f: 61 | g: 0 | h: 61
// Node: 39 | f: 22 | g: 7 | h: 15
// Node: 57 | f: 29 | g: 9 | h: 20
// Node: 37 | f: 43.1 | g: 10.1 | h: 33
// Node: 15 | f: 37.7 | g: 12.7 | h: 25
// Node: 18 | f: 23.2 | g: 23.2 | h: 0
// Solution Path:
// Node: 8 | f: 43.2782 | g: 0 | h: 43.2782
// Node: 30 | f: 29.82 | g: 4.8 | h: 25.02
// Node: 55 | f: 37.4258 | g: 10.5 | h: 26.9258
// Node: 18 | f: 18.9 | g: 18.9 | h: 0
// int start=46;
// int goal=20;
// PathNode* OutPath;
// OutPath=findDronePath(Mat, coor, start, goal, 1);
// printPath(OutPath);
// OutPath=findDronePath(Mat, coor, start, goal, 2);
// printPath(OutPath);
// Solution Path:
// Node: (8,96) | f: 87 | g: 0 | h: 87
// Node: (3,22) | f: 19.1 | g: 1.1 | h: 18
// Node: (12,46) | f: 35.1 | g: 2.1 | h: 33
// Node: (11,42) | f: 41.8 | g: 11.8 | h: 30
// Node: (16,26) | f: 27.6 | g: 18.6 | h: 9
// Node: (18,19) | f: 26.1 | g: 26.1 | h: 0
// Solution Path:
// Node: (8,96) | f: 77.6466 | g: 0 | h: 77.6466
// Node: (3,22) | f: 16.3971 | g: 1.1 | h: 15.2971
// Node: (38,37) | f: 30.7072 | g: 3.8 | h: 26.9072
// Node: (16,26) | f: 14.9801 | g: 7.7 | h: 7.28011
// Node: (18,19) | f: 15.2 | g: 15.2 | h: 0
// Solution Path:
// Node: 46 | f: 87 | g: 0 | h: 87
// Node: 28 | f: 19.1 | g: 1.1 | h: 18
// Node: 58 | f: 35.1 | g: 2.1 | h: 33
// Node: 50 | f: 41.8 | g: 11.8 | h: 30
// Node: 38 | f: 27.6 | g: 18.6 | h: 9
// Node: 20 | f: 26.1 | g: 26.1 | h: 0
// Solution Path:
// Node: 46 | f: 77.6466 | g: 0 | h: 77.6466
// Node: 28 | f: 16.3971 | g: 1.1 | h: 15.2971
// Node: 52 | f: 30.7072 | g: 3.8 | h: 26.9072
// Node: 38 | f: 14.9801 | g: 7.7 | h: 7.28011
// Node: 20 | f: 15.2 | g: 15.2 | h: 0