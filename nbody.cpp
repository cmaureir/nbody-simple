#include "include/common.hpp"
#include "include/file_utils.hpp"
#include "include/bodies_dynamic.hpp"


int main(int argc, char *argv[]) {

    read_input_file("input/2");

    update_acceleration();
    for (float i = 0; i < dt; i+=dt) {
        update_position();
        update_acceleration();
        update_velocity();
    }

    write_output_file("2.output");
    return 0;
}
