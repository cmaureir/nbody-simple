#include "bodies_dynamic.hpp"
#include "common.hpp"
#include <cmath>
#include <iostream>
#include <vector>

void update_position()
{
    for (int i = 0; i < n; i++) {
        bodies[i].a_x0 = bodies[i].a_x;
        bodies[i].a_y0 = bodies[i].a_y;
        bodies[i].a_z0 = bodies[i].a_z;

        bodies[i].x += bodies[i].v_x * dt + 0.5 * bodies[i].a_x * dt * dt;
        bodies[i].y += bodies[i].v_y * dt + 0.5 * bodies[i].a_y * dt * dt;
        bodies[i].z += bodies[i].v_z * dt + 0.5 * bodies[i].a_z * dt * dt;
    }
}

void update_velocity()
{
    for (int i = 0; i < n; i++) {
        bodies[i].v_x += 0.5 * (bodies[i].a_x * dt * dt);
        bodies[i].v_y += 0.5 * (bodies[i].a_y * dt * dt);
        bodies[i].v_z += 0.5 * (bodies[i].a_z * dt * dt);
    }
}

void update_acceleration()
{

    float dx,dy,dz;
    float r, r3, invr3,f;

    for (int i = 0; i < n; i++) {
        bodies[i].a_x0 = bodies[i].a_x;
        bodies[i].a_y0 = bodies[i].a_y;
        bodies[i].a_z0 = bodies[i].a_z;

        bodies[i].a_x = 0.0;
        bodies[i].a_y = 0.0;
        bodies[i].a_z = 0.0;
    }

    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(j != i)
            {
                dx=bodies[i].x-bodies[j].x;
                dy=bodies[i].y-bodies[j].y;
                dz=bodies[i].z-bodies[j].z;

                r = dx*dx + dy*dy + dz*dz;
                r3 = r*r*r;
                invr3 = 1.0/sqrt(r3);
                f=bodies[j].m*invr3;

                bodies[i].a_x -= f*dx;
                bodies[i].a_y -= f*dy;
                bodies[i].a_z -= f*dz;
            }
        }
    }

    std::cout << bodies[0].a_x << std::endl;

}
