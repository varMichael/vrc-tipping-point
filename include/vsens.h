/*vex-vision-config:begin*/
#include "vex.h"
vex::vision::signature NGOAL = vex::vision::signature (1, 1035, 1903, 1469, -3745, -3255, -3500, 3, 0);
vex::vision::signature RGOAL = vex::vision::signature (2, 6365, 8025, 7195, -727, -109, -418, 3, 0);
vex::vision::signature BGOAL = vex::vision::signature (3, -3389, -2023, -2706, 6733, 13107, 9920, 2.5, 0);
vex::vision::signature SIG_4 = vex::vision::signature (4, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_5 = vex::vision::signature (5, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_6 = vex::vision::signature (6, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision::signature SIG_7 = vex::vision::signature (7, 0, 0, 0, 0, 0, 0, 2.5, 0);
vex::vision Vision1 = vex::vision (vex::PORT1, 45, NGOAL, RGOAL, BGOAL, SIG_4, SIG_5, SIG_6, SIG_7);
/*vex-vision-config:end*/
