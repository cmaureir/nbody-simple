#include <vector>

struct body
{
    // Position
    float x,y,z;

    // Velocity
    float v_x,v_y,v_z;

    // Acceleration
    float a_x,a_y,a_z;
    float a_x0,a_y0,a_z0;

    // Mass
    float m;
};

extern float ekin, epot;
extern float etot_ini, etot_end;
extern std::vector<body> bodies;
extern int n;
extern float dt;
